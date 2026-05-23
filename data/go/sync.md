# SYNC en Go

El paquete `sync` proporciona primitivas básicas de sincronización para controlar la concurrencia entre goroutines de forma más tradicional que los canales.

## sync.WaitGroup

Permite esperar a que un grupo de goroutines termine su ejecución. Funciona como un contador interno.

```go
package main

import (
    "fmt"
    "sync"
    "time"
)

func trabajador(id int, wg *sync.WaitGroup) {
    // Decrementa el contador cuando la función termina
    defer wg.Done()

    fmt.Printf("Trabajador %d comenzando...\n", id)
    time.Sleep(time.Second)
    fmt.Printf("Trabajador %d terminado\n", id)
}

func main() {
    var wg sync.WaitGroup

    for i := 1; i <= 3; i++ {
        wg.Add(1) // Incrementa el contador por cada goroutine
        go trabajador(i, &wg) // Pasar siempre por referencia (puntero)
    }

    // Bloquea la ejecución hasta que el contador sea 0
    wg.Wait()
    fmt.Println("Todos los trabajadores han terminado.")
}
```

## sync.Mutex (Exclusión Mutua)

Evita condiciones de carrera (race conditions) al asegurar que solo una goroutine acceda a una sección crítica de datos a la vez.

```go
package main

import (
    "fmt"
    "sync"
)

type Contador struct {
    mu    sync.Mutex
    valor int
}

func (c *Contador) Incrementar() {
    c.mu.Lock()         // Bloquea el acceso para otras goroutines
    defer c.mu.Unlock() // Desbloquea al salir de la función
    c.valor++
}

func (c *Contador) Obtener() int {
    c.mu.Lock()
    defer c.mu.Unlock()
    return c.valor
}

func main() {
    contador := Contador{}
    var wg sync.WaitGroup

    for i := 0; i < 1000; i++ {
        wg.Add(1)
        go func() {
            defer wg.Done()
            contador.Incrementar()
        }()
    }

    wg.Wait()
    fmt.Println("Valor final:", contador.Obtener()) // 1000 de forma segura
}
```

## sync.RWMutex

Una exclusión mutua de lectura/escritura. Permite que múltiples lectores accedan de forma simultánea, pero bloquea si hay un escritor.

```go
var mu sync.RWMutex
var datos string

// Múltiples goroutines pueden leer a la vez
func Leer() string {
    mu.RLock()
    defer mu.RUnlock()
    return datos
}

// Solo una goroutine puede escribir a la vez
func Escribir(nuevo string) {
    mu.Lock()
    defer mu.Unlock()
    datos = nuevo
}
```

## sync.Once

Garantiza que una función se ejecute **exactamente una vez**, sin importar cuántas goroutines la llamen. Es idóneo para inicializaciones pesadas o Singletons.

```go
var once sync.Once

func inicializar() {
    fmt.Println("Inicialización única ejecutada.")
}

func ejecutarConcurrente() {
    once.Do(inicializar)
}
```
