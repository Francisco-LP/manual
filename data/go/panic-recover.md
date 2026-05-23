# PANIC y RECOVER en Go

Go no usa excepciones tradicionales. En su lugar, usa un sistema de pánicos (`panic`) y recuperación (`recover`) para errores irrecuperables del sistema o situaciones excepcionales del flujo de ejecución.

## Panic

Un pánico detiene el flujo ordinario de control. Cuando una función entra en pánico, interrumpe su ejecución, ejecuta cualquier función diferida (`defer`) y luego sube por la pila de llamadas del hilo (goroutine) actual repitiendo el proceso hasta finalizar el programa.

### Provocar un Panic de Forma Manual

```go
package main

import "fmt"

func conectarBaseDatos(url string) {
    if url == "" {
        // Detiene la ejecución del programa
        panic("URL de base de datos vacía. Imposible continuar.")
    }
    fmt.Println("Conectado con éxito")
}

func main() {
    conectarBaseDatos("")
}
```

### Panic Implícito del Runtime

Ciertas operaciones inválidas en tiempo de ejecución disparan pánicos automáticamente:

```go
// Dispara un pánico: "panic: runtime error: index out of range"
numeros := []int{1, 2}
_ = numeros[5] 

// Dispara un pánico: "panic: runtime error: integer divide by zero"
a, b := 10, 0
_ = a / b

// Dispara un pánico: "panic: runtime error: invalid memory address or nil pointer dereference"
var p *int
_ = *p
```

## Recover

`recover` es una función incorporada que permite recuperar el control de una goroutine en pánico. 
- Solo es útil si se invoca **dentro de una función diferida (`defer`)**.
- Si el programa está en pánico, la llamada a `recover()` detendrá el pánico y devolverá el valor pasado a la función `panic`.
- Si el programa no está en pánico, `recover()` devuelve simplemente `nil`.

```go
package main

import "fmt"

func manejarPanico() {
    // recover() captura el pánico
    if r := recover(); r != nil {
        fmt.Println("Recuperado con éxito del pánico:", r)
    }
}

func operacionRiesgosa() {
    defer manejarPanico() // Debe registrarse antes del pánico

    fmt.Println("Iniciando operación...")
    panic("algo salió terriblemente mal") // Detiene la función
    fmt.Println("Esta línea nunca se ejecutará")
}

func main() {
    operacionRiesgosa()
    fmt.Println("El flujo continúa normalmente en main.")
}
```

## Buenas Prácticas

1. **Evitar pánicos para control de flujo**: Se prefiere siempre retornar `error` como valor ordinario. Usa `panic` solo ante errores irrecuperables del sistema (ej. falta de archivos de configuración esenciales o puertos bloqueados).
2. **Panic no cruza Goroutines**: Si una goroutine secundaria entra en pánico y no tiene un `recover` propio en su pila de llamadas, terminará el programa entero, incluso si `main` tiene un `recover`. Cada goroutine debe autogestionar su recuperación.

```go
// Uso correcto de recover en goroutines
go func() {
    defer func() {
        if r := recover(); r != nil {
            fmt.Println("Pánico recuperado dentro de la goroutine:", r)
        }
    }()
    // Código concurrente que puede fallar
    panic("error en tarea secundaria")
}()
```
