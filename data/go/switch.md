# SWITCH en Go

Estructura condicional de selección múltiple. En Go, la sentencia `break` al final de cada caso se inserta **automáticamente**, evitando errores comunes de otros lenguajes.

## Estructura Básica

```go
package main

import "fmt"

func main() {
    sistema := "linux"

    switch sistema {
    case "windows":
        fmt.Println("Sistema Windows")
    case "linux", "darwin": // Comas para agrupar múltiples valores en un caso
        fmt.Println("Sistema Unix / macOS")
    default:
        fmt.Println("Sistema desconocido")
    }
}
```

## Switch sin Condición (Equivalente a if-else largos)

Si omitimos la expresión a evaluar, cada `case` se evalúa como una expresión booleana individual.

```go
edad := 25

switch {
case edad < 18:
    fmt.Println("Menor de edad")
case edad >= 18 && edad < 65:
    fmt.Println("Adulto")
default:
    fmt.Println("Adulto mayor")
}
```

## Forzar continuidad con `fallthrough`

Si necesitas explícitamente que la ejecución continúe en el siguiente `case` sin importar si coincide o no (comportamiento tradicional de C/Java), usa la sentencia `fallthrough`.

```go
switch numero := 2; numero {
case 2:
    fmt.Println("Es dos")
    fallthrough // Ejecuta el siguiente bloque 'case 3' automáticamente
case 3:
    fmt.Println("Se ejecutó por fallthrough")
}
```

## Switch de Tipos (Type Switch)

Permite verificar y extraer el tipo real de una variable interfaz.

```go
func clasificar(i interface{}) {
    switch t := i.(type) {
    case int:
        fmt.Println("Es un entero:", t)
    case string:
        fmt.Println("Es una cadena:", t)
    default:
        fmt.Println("Tipo desconocido")
    }
}
```
