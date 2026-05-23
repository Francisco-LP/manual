# IF en Go

Estructura de control condicional. En Go, no se requieren paréntesis `()` alrededor de las condiciones, pero las llaves `{}` del bloque de código son obligatorias.

## Sintaxis Básica

```go
package main

import "fmt"

func main() {
    edad := 18

    if edad < 18 {
        fmt.Println("Menor de edad")
    } else if edad == 18 {
        fmt.Println("Acabas de cumplir la mayoría de edad")
    } else {
        fmt.Println("Mayor de edad")
    }
}
```

## Declaración Corta Precondicional

Go permite ejecutar una sentencia de declaración corta directamente antes de evaluar la condición. Las variables declaradas en esta sentencia solo existen en el ámbito (scope) del condicional `if-else`.

```go
// Sintaxis: if inicializacion; condicion { ... }

if err := ejecutarProceso(); err != nil {
    // err solo es visible dentro de este bloque de llaves
    fmt.Println("Ocurrió un error:", err)
}
// err ya no está definido aquí
```

## Comparaciones Permitidas

Las condiciones en los `if` deben resolverse estrictamente a un valor booleano (`true` o `false`). No existe la conversión implícita de "truthy" o "falsy" como en JS o Python (ej: un número `1` o una cadena no vacía no equivalen a `true`).

```go
// if 1 { ... } // ERROR de compilación en Go
```
