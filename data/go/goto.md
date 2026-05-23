# GOTO en Go

La sentencia `goto` permite realizar saltos incondicionales de ejecución hacia etiquetas definidas en el mismo cuerpo de la función actual.

## Sintaxis Básica

```go
package main

import "fmt"

func main() {
    fmt.Println("Paso 1")

    goto EntradaSegura // Salta incondicionalmente a la etiqueta

    fmt.Println("Paso 2 (Omitido)")

EntradaSegura: // Definición de etiqueta
    fmt.Println("Paso 3 (Ejecutado tras el salto)")
}
```

## Restricciones Estrictas de Go

Go implementa restricciones de compilación sumamente estrictas para el uso de `goto` a fin de evitar "código espagueti" ilegible o inseguro.

### 1. No se pueden saltar declaraciones de variables
No se permite usar `goto` para saltar una línea de código donde se declara o inicializa una variable si esa variable se utilizará después de la etiqueta del salto.

```go
    goto Destino // ERROR de compilación
    x := 10
Destino:
    fmt.Println(x)
```

### 2. Ámbito local estricto
La etiqueta de destino del `goto` debe estar definida estrictamente **dentro de la misma función** de la llamada. No se admiten saltos interfuncionales.
