# MÉTODOS en Go

En Go, un método es simplemente una función que contiene un parámetro especial extra llamado **receptor** (receiver), el cual asocia la función a un tipo específico (generalmente una estructura).

## Receptores de Valor vs Receptores de Puntero

- **Receptor de Valor (`T`)**: Opera sobre una **copia** del objeto. No puede modificar los campos originales del objeto.
- **Receptor de Puntero (`*T`)**: Opera sobre una **referencia** al objeto original. Puede modificar los campos del objeto y evita copiar estructuras grandes en memoria.

## Sintaxis de Métodos

```go
package main

import "fmt"

type Rectangulo struct {
    Ancho, Alto float64
}

// 1. Método con Receptor de Valor (No modifica el struct original)
// func (nombre_receptor TipoReceptor) NombreMetodo() Retorno
func (r Rectangulo) Area() float64 {
    return r.Ancho * r.Alto
}

// 2. Método con Receptor de Puntero (Sí modifica el struct original)
func (r *Rectangulo) Escalar(factor float64) {
    r.Ancho *= factor
    r.Alto *= factor
}

func main() {
    rect := Rectangulo{Ancho: 10, Alto: 5}

    // Llamada a método de valor
    fmt.Println("Área:", rect.Area()) // 50

    // Llamada a método de puntero
    // Go simplifica automáticamente '(&rect).Escalar(2)' a 'rect.Escalar(2)'
    rect.Escalar(2)
    fmt.Println("Nuevo Ancho:", rect.Ancho) // 20
}
```

## Métodos sobre Tipos No Estructurados

Puedes definir métodos sobre cualquier tipo de datos declarado en tu paquete (excepto tipos primitivos directos o de otros paquetes externos).

```go
// Definimos un tipo personalizado a partir de un float64
type MiFloat float64

// Método sobre el tipo personalizado MiFloat
func (f MiFloat) EsPositivo() bool {
    return f > 0
}

func main() {
    num := MiFloat(-3.14)
    fmt.Println(num.EsPositivo()) // false
}
```
