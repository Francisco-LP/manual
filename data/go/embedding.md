# EMBEDDING (Composición) en Go

Go no admite la herencia de clases tradicional. En su lugar, promueve el diseño por **composición** utilizando **Struct Embedding** (anidación de estructuras) e **Interface Embedding** (anidación de interfaces).

## 1. Composición de Estructuras (Struct Embedding)

Permite anidar una estructura dentro de otra sin especificar un nombre de campo. Los campos y métodos de la estructura interna se "promocionan" a la externa.

```go
package main

import "fmt"

type Motor struct {
    Caballos int
}

func (m Motor) Encender() {
    fmt.Println("Motor encendido. Brum brum!")
}

type Coche struct {
    Marca string
    Motor // Struct Embedding (anidado)
}

func main() {
    c := Coche{
        Marca: "Toyota",
        Motor: Motor{Caballos: 150},
    }

    // Promoción de Campos y Métodos:
    // Podemos acceder a Caballos y Encender() directamente sin pasar por .Motor!
    fmt.Println(c.Marca, "con", c.Caballos, "CV")
    c.Encender() // Llama a c.Motor.Encender() automáticamente
}
```

## Sobrescribir Métodos Promocionados

Si la estructura externa define un método con el mismo nombre, este tiene prioridad, pero el método de la estructura interna sigue siendo accesible explícitamente.

```go
func (c Coche) Encender() {
    fmt.Println("Coche arrancando con sistemas eléctricos...")
    c.Motor.Encender() // Llamada explícita al método interno
}
```

## 2. Composición de Interfaces (Interface Embedding)

Permite crear interfaces complejas uniendo y componiendo múltiples interfaces más simples.

```go
type Lector interface {
    Read(p []byte) (n int, err error)
}

type Escritor interface {
    Write(p []byte) (n int, err error)
}

// Interface Embedding: Combina Lector y Escritor en una nueva interfaz
type LectorEscritor interface {
    Lector
    Escritor
}
```
