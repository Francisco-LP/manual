# CONSTANTES en Go

Valores inmutables conocidos en tiempo de compilación. Se declaran con la palabra clave `const`.

## Sintaxis Básica

Las constantes pueden ser declaradas con tipo explícito (constantes tipadas) o sin tipo (constantes no tipadas). Las constantes no tipadas son extremadamente flexibles y se adaptan al tipo de la variable en la que se usan.

```go
package main

import "fmt"

// Globales
const Pi = 3.14159          // No tipada (infiere al usarse)
const Titulo string = "App" // Tipada

func main() {
    const Limite = 100
    // Limite = 200 // ERROR: no se puede reasignar una constante
    fmt.Println(Pi, Titulo, Limite)
}
```

## Agrupación de Constantes

```go
const (
    EstadoOk       = 200
    EstadoNotFound = 404
)
```

## Generación Automática de Enums (`iota`)

`iota` es un generador numérico secuencial automático que comienza en `0` dentro de un bloque `const (...)` y se incrementa en `1` por cada nueva línea.

```go
const (
    Domingo = iota // 0
    Lunes          // 1 (infiere automáticamente "= iota")
    Martes         // 2
    Miercoles      // 3
)
```

### Omitir valores con el identificador en blanco (`_`)

```go
const (
    _ = iota       // Omitimos el 0
    Enero          // 1
    Febrero        // 2
)
```

### Operaciones con `iota`

```go
const (
    _   = iota
    KB  = 1 << (10 * iota) // 1 << 10 = 1024 bytes
    MB                     // 1 << 20 = 1,048,576 bytes
    GB                     // 1 << 30
)
```
