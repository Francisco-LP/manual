# VARIABLES en Go

Declaración y asignación de variables. Go es un lenguaje de tipado estático y fuerte.

## Declaración Explícita (`var`)

Se usa para declarar variables con o sin valor inicial. Si no se especifica el valor, se le asigna el valor cero (zero-value) del tipo.

```go
package main

import "fmt"

func main() {
    // Declaración con tipo y valor
    var edad int = 30

    // Declaración con tipo, sin valor (toma valor cero: 0)
    var altura int

    // Go infiere el tipo automáticamente si hay un valor inicial
    var nombre = "Ana"

    fmt.Println(edad, altura, nombre)
}
```

## Declaración Corta (`:=`)

Sintaxis simplificada y rápida. Solo es válida **dentro de funciones**. Infiere el tipo automáticamente.

```go
func main() {
    // Declara e inicializa
    precio := 19.99  // float64
    activo := true   // bool

    // Asignación múltiple corta
    x, y := 1, 2
    
    // Swap rápido (intercambio)
    x, y = y, x
}
```

## Declaración Múltiple

```go
// Con var
var a, b, c int = 1, 2, 3

// Bloque de declaración (muy útil para agrupar variables globales)
var (
    rol    = "Admin"
    intentos = 3
    activo   = false
)
```

## Valores Cero (Zero Values)

Si una variable se declara sin valor inicial, Go le asigna un valor por defecto seguro:

- `0` para tipos numéricos (`int`, `float`, etc.).
- `""` (cadena vacía) para `string`.
- `false` para `bool`.
- `nil` para punteros, interfaces, slices, mapas y canales.
