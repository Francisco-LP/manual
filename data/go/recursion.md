# RECURSIÓN en Go

Go admite funciones recursivas, es decir, funciones que se llaman a sí mismas para resolver problemas de forma iterativa y dividida.

## Ejemplo Clásico: Factorial

```go
package main

import "fmt"

// Factorial(n) = n * Factorial(n-1)
func factorial(n int) int {
    // 1. Caso base (para detener la recursión y evitar bucles de desbordamiento)
    if n == 0 {
        return 1
    }
    // 2. Llamada recursiva
    return n * factorial(n-1)
}

func main() {
    fmt.Println(factorial(5)) // 120 (5 * 4 * 3 * 2 * 1)
}
```

## Ejemplo 2: Serie de Fibonacci

```go
func fibonacci(n int) int {
    // Caso base
    if n <= 1 {
        return n
    }
    // Llamada recursiva doble
    return fibonacci(n-1) + fibonacci(n-2)
}
```

## Recursión con Funciones Anónimas y Closures

Para declarar una función recursiva de forma anónima dentro de otra función, se debe declarar la variable del tipo de la firma de la función primero, para que pueda referenciarse a sí misma.

```go
func main() {
    // Declaración previa obligatoria del tipo de la función
    var cuentaRegresiva func(int)

    cuentaRegresiva = func(n int) {
        if n == 0 {
            fmt.Println("¡Lanzamiento!")
            return
        }
        fmt.Println(n)
        cuentaRegresiva(n - 1) // Llamada recursiva a sí misma
    }

    cuentaRegresiva(3)
}
```
