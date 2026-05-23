# ARRAYS en Go

Colecciones numeradas de tamaño fijo y de un único tipo de datos. Su tamaño forma parte de su definición de tipo (ej: `[3]int` y `[5]int` son tipos incompatibles).

## Declaración e Inicialización

```go
package main

import "fmt"

func main() {
    // Declaración sin inicializar (toma valores cero)
    var numeros [5]int
    numeros[0] = 10
    numeros[1] = 20

    // Inicialización explícita con valores literales
    colores := [3]string{"Rojo", "Verde", "Azul"}

    // Go calcula el tamaño automáticamente si usamos '...'
    precios := [...]float64{1.99, 2.50, 4.99} // Tamaño fijo calculado de 3

    fmt.Println(numeros, colores, precios)
}
```

## Características Clave

1. **Tamaño Fijo**: No puede crecer ni encogerse después de haber sido declarado.
2. **Paso por Valor**: En Go, al asignar un array a otra variable o al pasarlo como argumento a una función, se crea una **copia completa** en memoria del array (no una referencia).

```go
a := [3]int{1, 2, 3}
b := a // b es una COPIA completa de a

b[0] = 99
fmt.Println(a) // Imprime [1, 2, 3] (a no cambia)
```

## Recorrido e Iteración

```go
colores := [3]string{"Rojo", "Verde", "Azul"}

// Usando for tradicional
for i := 0; i < len(colores); i++ {
    fmt.Println(i, colores[i])
}

// Usando for range (Recomendado)
for indice, valor := range colores {
    fmt.Printf("Índice: %d, Valor: %s\n", indice, valor)
}
```
