# DEFER en Go

La sentencia `defer` difiere o retrasa la ejecución de una función hasta que la función contenedora (donde se declaró el `defer`) finalice su ejecución (ya sea por un `return` o por llegar al final).

## Caso de Uso Común: Liberación de Recursos

Es excelente para garantizar que los recursos (archivos abiertos, conexiones a bases de datos, bloqueos de exclusión mutua/mutex) se liberen correctamente al final del proceso.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    archivo, err := os.Open("datos.txt")
    if err != nil {
        return
    }
    // Nos aseguramos de que el archivo se cierre al finalizar main()
    defer archivo.Close()

    // Código para procesar el archivo
    fmt.Println("Archivo procesándose...")
}
```

## Orden de Ejecución (Pila LIFO)

Si declaras múltiples sentencias `defer` dentro de una misma función, Go las apila y las ejecuta en orden **LIFO** (Last In, First Out - Último en entrar, Primero en salir).

```go
func main() {
    defer fmt.Println("Primero declarado (Último en ejecutarse)")
    defer fmt.Println("Segundo decolarado")
    defer fmt.Println("Tercero declarado (Primero en ejecutarse)")

    fmt.Println("Ejecución normal de la función")
}
// Salida en consola:
// Ejecución normal de la función
// Tercero declarado (Primero en ejecutarse)
// Segundo decolarado
// Primero declarado (Último en ejecutarse)
```

## Evaluación Inmediata de Parámetros

Los argumentos pasados a una función diferida con `defer` se evalúan **inmediatamente** en el momento de declarar la sentencia `defer`, no cuando la función finalmente se ejecuta.

```go
x := 10
defer fmt.Println("Valor diferido:", x) // Evaluará y guardará x = 10 aquí

x = 20
fmt.Println("Valor actual:", x)
// Salida:
// Valor actual: 20
// Valor diferido: 10
```
