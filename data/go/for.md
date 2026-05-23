# FOR en Go

El bucle `for` es la **única** estructura de control de repetición y bucle disponible en Go. Sin embargo, su diseño versátil permite emular todos los tipos de bucles clásicos de otros lenguajes.

## 1. Bucle For Tradicional

```go
package main

import "fmt"

func main() {
    // Tres componentes: inicialización; condición; post-operación
    for i := 0; i < 5; i++ {
        fmt.Println(i)
    }
}
```

## 2. Bucle Tipo "While"

Se logra omitiendo la inicialización y la post-operación, dejando únicamente la condición.

```go
contador := 0

for contador < 5 {
    fmt.Println(contador)
    contador++
}
```

## 3. Bucle Infinito

Se logra omitiendo todos los componentes. Se suele controlar internamente con sentencias `break`.

```go
for {
    fmt.Println("Ejecutando de forma continua...")
    break // Sale inmediatamente del bucle
}
```

## 4. Recorridos con `for range`

Ideal para iterar sobre colecciones de datos (arrays, slices, mapas, strings, canales).

```go
valores := []string{"A", "B", "C"}

for indice, valor := range valores {
    fmt.Printf("Índice: %d, Valor: %s\n", indice, valor)
}

// Omitir el índice usando el identificador en blanco '_'
for _, valor := range valores {
    fmt.Println(valor)
}
```

## Control de Flujo: `break` y `continue`

- **`break`**: Termina y sale del bucle de inmediato.
- **`continue`**: Salta la iteración actual y pasa a la siguiente.
