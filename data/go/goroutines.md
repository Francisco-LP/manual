# GOROUTINES en Go

Una goroutine (gorrutina) es un hilo de ejecución ultra-ligero y asíncrono gestionado directamente por el runtime de Go (y no por el sistema operativo). Ocupan muy pocos kilobytes de memoria y se pueden spawnear por miles de forma eficiente.

## La palabra clave `go`

Para ejecutar cualquier función de forma asíncrona y concurrente en segundo plano, simplemente antepón la palabra clave `go` antes de invocar la función.

```go
package main

import (
    "fmt"
    "time"
)

func hablar(mensaje string) {
    for i := 0; i < 3; i++ {
        fmt.Println(mensaje)
        time.Sleep(100 * time.Millisecond)
    }
}

func main() {
    // Inicia una goroutine en segundo plano
    go hablar("Mundo")

    // Ejecuta en el hilo principal (main goroutine)
    hablar("Hola")

    // NOTA: Si la main goroutine finaliza, todas las goroutines secundarias 
    // se terminan de golpe, sin importar si han finalizado o no.
}
```

## Goroutines con Funciones Anónimas

Es muy común lanzar tareas rápidas asíncronas encapsuladas en funciones anónimas.

```go
func main() {
    go func() {
        fmt.Println("Ejecutando tarea asíncrona rápida...")
    }()
    
    // Pequeña espera para dar tiempo a que se ejecute la tarea
    time.Sleep(50 * time.Millisecond)
}
```

## Sincronización y Comunicación

Las goroutines se ejecutan en el mismo espacio de direcciones de memoria. Compartir variables globales directamente puede producir **condiciones de carrera** (race conditions).

Para sincronizar y comunicar goroutines de forma segura y estructurada, Go proporciona:
1. **Canales (`channels`)**: Para pasar datos de forma segura entre goroutines. (Recomendado).
2. **Primitivas de sincronización (`sync`)**: Mutex, WaitGroup, etc.
