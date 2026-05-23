# FUNCIONES en Go

Bloques de construcción fundamentales de código reutilizable. Go soporta múltiples valores de retorno y paso de parámetros variádicos.

## Sintaxis Básica y Tipado

Todos los parámetros y los valores de retorno deben estar explícitamente tipados.

```go
package main

import "fmt"

// func Nombre(param1 Tipo, param2 Tipo) TipoRetorno
func sumar(a int, b int) int {
    return a + b
}

// Parámetros consecutivos del mismo tipo se pueden agrupar
func multiplicar(a, b int) int {
    return a * b
}
```

## Múltiples Valores de Retorno

Es el estándar de Go para retornar tanto los resultados exitosos como los posibles errores.

```go
func dividir(dividendo, divisor float64) (float64, error) {
    if divisor == 0 {
        // Retorna valor cero y un objeto de error
        return 0, fmt.Errorf("no se puede dividir por cero")
    }
    // Retorna el cálculo y nil (sin error)
    return dividendo / divisor, nil
}

func main() {
    resultado, err := dividir(10, 2)
    if err != nil {
        fmt.Println("Error:", err)
        return
    }
    fmt.Println("Resultado:", resultado)
}
```

## Parámetros Variádicos (`...`)

Permiten a una función aceptar cualquier cantidad de argumentos adicionales del tipo especificado. Se reciben internamente como un slice del tipo.

```go
// numeros es recibido como un slice []int
func sumarTodos(numeros ...int) int {
    total := 0
    for _, num := range numeros {
        total += num
    }
    return total
}

func main() {
    fmt.Println(sumarTodos(1, 2, 3)) // 6
    
    // Pasar un slice existente expandiendo sus valores con '...'
    valores := []int{4, 5, 6}
    fmt.Println(sumarTodos(valores...)) // 15
}
```
