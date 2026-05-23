# SELECT en Go

La sentencia `select` permite a una goroutine esperar y multiplexar múltiples operaciones de canales simultáneamente. Se bloquea hasta que alguno de sus casos de canal esté listo para procesar.

## Estructura y Funcionamiento

Si múltiples canales están listos al mismo tiempo, Go selecciona uno de ellos de forma completamente **aleatoria**.

```go
package main

import (
    "fmt"
    "time"
)

func main() {
    canal1 := make(chan string)
    canal2 := make(chan string)

    go func() {
        time.Sleep(1 * time.Second)
        canal1 <- "Mensaje Uno"
    }()

    go func() {
        time.Sleep(2 * time.Second)
        canal2 <- "Mensaje Dos"
    }()

    // Esperar y responder al primer canal que esté listo
    for i := 0; i < 2; i++ {
        select {
        case msg1 := <-canal1:
            fmt.Println("Recibido de canal1:", msg1)
        case msg2 := <-canal2:
            fmt.Println("Recibido de canal2:", msg2)
        }
    }
}
```

## Operación de Salida / Caso por Defecto (`default`)

El caso `default` en un `select` se ejecuta inmediatamente si ninguno de los canales tiene datos listos, evitando que la ejecución se bloquee. Es excelente para sondeos no bloqueantes (polling).

```go
select {
case msg := <-canal1:
    fmt.Println("Dato:", msg)
default:
    fmt.Println("Ningún canal listo. Continuando...")
}
```

## Control de Tiempos Límite (Timeouts)

Combinando `select` con el paquete `time`, podemos implementar fácilmente límites máximos de espera (timeouts) para operaciones de canales.

```go
select {
case msg := <-canal1:
    fmt.Println("Recibido:", msg)
case <-time.After(500 * time.Millisecond):
    // Se ejecuta si canal1 no responde en 500ms
    fmt.Println("Error: Tiempo de espera agotado (Timeout)")
}
```
