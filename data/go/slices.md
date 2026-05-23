# SLICES en Go

Los slices (segmentos) son envoltorios dinámicos, flexibles y de tamaño variable sobre arrays subyacentes. Son el estándar absoluto para colecciones de datos secuenciales en Go.

## Estructura de un Slice

Un slice no guarda datos directamente, sino que describe una sección de un array subyacente. Contiene:
- **Puntero**: Dirección al primer elemento del array que abarca.
- **Longitud (`len`)**: Número de elementos actualmente guardados en el slice.
- **Capacidad (`cap`)**: Número total de elementos que puede contener antes de requerir redimensionar el array subyacente.

## Declaración e Inicialización

```go
package main

import "fmt"

func main() {
    // 1. Literal de slice (se parece a un array pero sin especificar tamaño)
    s1 := []int{1, 2, 3}

    // 2. Creación con make() (especificando longitud y capacidad opcional)
    // make([]Tipo, longitud, capacidad)
    s2 := make([]int, 3, 5) // len=3, cap=5, inicializado con [0, 0, 0]

    // 3. Creado a partir de un Array (Rebanado)
    array := [5]int{10, 20, 30, 40, 50}
    s3 := array[1:4] // Contiene [20, 30, 40] (índice final es exclusivo)

    fmt.Println(s1, s2, s3)
}
```

## Operaciones Fundamentales

### Agregar Elementos (`append`)

`append` agrega elementos al final del slice. Si la longitud supera la capacidad actual, Go crea automáticamente un nuevo array subyacente más grande y copia los datos.

```go
var s []int // Slice vacío (nil), len=0, cap=0

s = append(s, 10)     // [10]
s = append(s, 20, 30) // [10, 20, 30]

// Unir un slice a otro usando el operador de expansión '...'
otros := []int{40, 50}
s = append(s, otros...) // [10, 20, 30, 40, 50]
```

### Copiar Slices (`copy`)

Dado que los slices son referencias, asignar `s1 = s2` apunta al mismo array en memoria. Para clonar un slice de forma independiente:

```go
origen := []int{1, 2, 3}
// Debes inicializar el destino con el tamaño necesario
destino := make([]int, len(origen))

// Retorna el número de elementos copiados
elementosCopiados := copy(destino, origen)

destino[0] = 99
fmt.Println(origen)  // [1, 2, 3] (El original no cambia)
fmt.Println(destino) // [99, 2, 3]
```
