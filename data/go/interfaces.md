# INTERFACES en Go

Las interfaces en Go definen conjuntos de firmas de métodos. Proporcionan polimorfismo. A diferencia de otros lenguajes, la implementación de interfaces en Go es **implícita**.

## Implementación Implícita

No existe la palabra clave `implements`. Si un tipo personalizado define todos los métodos que requiere una interfaz, ese tipo implementa la interfaz de forma **automática e implícita**.

## Definición y Uso de Interfaces

```go
package main

import "fmt"

// 1. Definición de la Interfaz
type Hablador interface {
    Hablar() string
}

// 2. Tipos que implementan la interfaz implícitamente
type Perro struct{}
func (p Perro) Hablar() string {
    return "Guau!"
}

type Gato struct{}
func (g Gato) Hablar() string {
    return "Miau!"
}

// 3. Función polimórfica que acepta la interfaz
func hacerHablar(h Hablador) {
    fmt.Println(h.Hablar())
}

func main() {
    perro := Perro{}
    gato := Gato{}

    hacerHablar(perro) // Guau!
    hacerHablar(gato)  // Miau!
}
```

## La Interfaz Vacía (`interface{}` o `any`)

La interfaz vacía no define métodos. Dado que todos los tipos implementan al menos cero métodos, la interfaz vacía puede contener valores de **cualquier tipo de datos**. Desde Go 1.18, se puede usar el alias `any`.

```go
func describir(i any) {
    fmt.Printf("Valor: %v, Tipo: %T\n", i, i)
}

func main() {
    describir(42)      // Valor: 42, Tipo: int
    describir("Hola")  // Valor: Hola, Tipo: string
}
```

## Aserción de Tipos (Type Assertion)

Permite extraer el valor concreto que contiene una interfaz.

```go
var i any = "Hola"

// Comprobación segura comma-ok
s, ok := i.(string)
if ok {
    fmt.Println("Es string:", s)
}
```
