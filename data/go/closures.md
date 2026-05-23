# CLOSURES en Go

Go admite funciones anónimas que pueden formar **closures** (clausuras). Un closure es una función que captura y hace referencia a variables externas definidas fuera de su propio cuerpo de código.

## Funciones Anónimas

Funciones declaradas directamente en línea sin un nombre identificador.

```go
package main

import "fmt"

func main() {
    // Declaración y ejecución inmediata
    func() {
        fmt.Println("Ejecución inmediata!")
    }()

    // Asignación de función anónima a una variable
    saludar := func(nombre string) {
        fmt.Println("Hola", nombre)
    }
    saludar("Ana")
}
```

## Creación de Closures

El closure mantiene su propio estado de las variables capturadas de forma independiente cada vez que se genera.

```go
// Generador que retorna una función (un closure)
func creadorIncremento() func() int {
    contador := 0 // Variable capturada por el closure
    
    // Retorna una función anónima que "cierra" sobre la variable contador
    return func() int {
        contador++
        return contador
    }
}

func main() {
    incrementar := creadorIncremento()

    fmt.Println(incrementar()) // 1
    fmt.Println(incrementar()) // 2
    fmt.Println(incrementar()) // 3

    // Generar un generador completamente nuevo e independiente
    otroIncrementar := creadorIncremento()
    fmt.Println(otroIncrementar()) // 1 (Su propio contador empieza en 1)
}
```
