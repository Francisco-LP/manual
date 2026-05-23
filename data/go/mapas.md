# MAPAS en Go

Los mapas son la implementación nativa de Go para estructuras de datos hash o diccionarios del tipo clave-valor. Son tipos de referencia.

## Inicialización y Creación

```go
package main

import "fmt"

func main() {
    // 1. Crear mapa vacío usando make()
    // make(map[TipoClave]TipoValor)
    edades := make(map[string]int)
    edades["Ana"] = 25
    edades["Pedro"] = 30

    // 2. Literal de mapa con valores iniciales
    capitales := map[string]string{
        "España":   "Madrid",
        "Colombia": "Bogotá",
    }

    fmt.Println(edades, capitales)
}
```

## Operaciones Básicas

```go
colores := map[string]string{"red": "rojo"}

// Insertar o actualizar
colores["blue"] = "azul"

// Eliminar elemento (`delete`)
delete(colores, "red") // No da error si la clave no existe

// Consultar valor de forma segura (Comprobación "comma ok")
// ok es un booleano que indica si la clave existe en el mapa
valor, ok := colores["green"]
if ok {
    fmt.Println("Color encontrado:", valor)
} else {
    fmt.Println("El color no existe") // ok es false, valor es el zero-value ""
}
```

## Iteración y Recorrido

Los mapas **no conservan el orden** de inserción. Cada iteración sobre el mapa puede entregar un orden aleatorio.

```go
inventario := map[string]int{
    "manzanas": 10,
    "plátanos": 5,
}

for clave, valor := range inventario {
    fmt.Printf("Producto: %s - Cantidad: %d\n", clave, valor)
}

// Iterar obteniendo solo las claves
for clave := range inventario {
    fmt.Println("Producto:", clave)
}
```
