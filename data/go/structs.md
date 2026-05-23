# STRUCTS en Go

Colecciones de campos de datos personalizados y estructurados. Go no tiene clases, por lo que las estructuras son el mecanismo principal para definir objetos.

## Definición e Inicialización

```go
package main

import "fmt"

// Definición de estructura
type Persona struct {
    Nombre string
    Edad   int
}

func main() {
    // 1. Inicialización por nombre de campo (Recomendado)
    p1 := Persona{
        Nombre: "Ana",
        Edad:   28,
    }

    // 2. Inicialización posicional (requiere mantener el orden exacto de los campos)
    p2 := Persona{"Pedro", 30}

    // 3. Crear puntero a estructura con new() o '&'
    p3 := &Persona{Nombre: "Luis", Edad: 40}

    // Acceso a campos
    p1.Edad = 29
    fmt.Println(p1.Nombre, p2.Edad, p3.Nombre)
}
```

## Campos Anónimos (Struct Embedding / Composición)

Go no tiene herencia de clases tradicional, sino que favorece la **composición** mediante la anidación o embedding de estructuras sin darles un nombre de campo.

```go
type Direccion struct {
    Ciudad string
    Pais   string
}

type Empleado struct {
    Nombre    string
    Puesto    string
    Direccion // Campo anónimo (Embedding)
}

func main() {
    emp := Empleado{
        Nombre: "Carlos",
        Puesto: "Dev",
    }
    emp.Ciudad = "Madrid" // Promoción de campos: se puede acceder directamente!
    emp.Pais = "España"

    // Acceso completo estructurado
    fmt.Println(emp.Direccion.Ciudad) // "Madrid"
}
```
