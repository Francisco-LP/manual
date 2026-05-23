# CHANNELS (Canales) en Go

Los canales son conductos de comunicación seguros y tipados a través de los cuales las goroutines pueden enviarse y recibirse valores entre sí, sincronizando sus ejecuciones de forma automática.

> [!NOTE]
> *“No comuniques compartiendo memoria; comparte memoria comunicando.”* — Mantra de Go.

## Creación y Operaciones Básicas

Los canales deben crearse siempre utilizando la función `make` especificando el tipo de datos que transportarán.

- **Crear**: `ch := make(chan Tipo)`
- **Enviar datos**: `ch <- valor` (operador de flecha hacia el canal)
- **Recibir datos**: `valor := <-ch` (operador de flecha saliendo del canal)

```go
package main

import "fmt"

func enviarMensaje(ch chan string) {
    // Envía un string al canal
    ch <- "Hola desde Goroutine!"
}

func main() {
    // Crear canal de strings
    ch := make(chan string)

    go enviarMensaje(ch)

    // La lectura del canal es una operación BLOQUEANTE.
    // La main goroutine se detiene aquí y espera hasta que haya un dato disponible.
    mensaje := <-ch
    fmt.Println(mensaje)
}
```

## Canales con Búfer (Buffered Channels)

Por defecto, los canales no tienen búfer (capacidad 0). Las operaciones de envío se bloquean inmediatamente hasta que otra goroutine lea el dato.
Un canal con búfer permite enviar hasta una capacidad especificada de elementos sin requerir una lectura inmediata.

```go
// make(chan Tipo, capacidad)
ch := make(chan int, 2)

ch <- 1 // No se bloquea
ch <- 2 // No se bloquea
// ch <- 3 // ¡ERROR de deadlock si no hay lector asíncrono, el búfer está lleno!
```

## Cerrar Canales (`close`) y Rango (`range`)

Solo el emisor debe cerrar un canal para indicar que no se enviarán más datos. Los receptores pueden verificar si el canal sigue abierto mediante una asignación de dos valores:

```go
package main

import "fmt"

func main() {
    ch := make(chan int, 3)
    ch <- 10
    ch <- 20
    close(ch) // Cerrar el canal de forma segura

    // Comprobación segura comma-ok al leer
    valor, abierto := <-ch
    fmt.Println(valor, abierto) // 10 true

    // Iterar sobre un canal usando for range.
    // El bucle lee datos y se detiene automáticamente cuando el canal es cerrado.
    for val := range ch {
        fmt.Println(val) // Imprime 20 y luego termina el bucle
    }
}
```
