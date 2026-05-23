# PAQUETE FMT en Go

El paquete `fmt` implementa E/S formateada con funciones análogas a `printf` y `scanf` de C.

## Impresión en Consola

- `fmt.Print` / `fmt.Println`: Imprime texto simple (Println agrega salto de línea).
- `fmt.Printf`: Imprime texto con formato usando **verbos de formato**.

```go
package main

import "fmt"

func main() {
    nombre := "Ana"
    edad := 25

    // Impresión con saltos automáticos
    fmt.Println("Nombre:", nombre, "Edad:", edad)

    // Impresión formateada
    fmt.Printf("Hola, me llamo %s y tengo %d años.\n", nombre, edad)
}
```

## Formatear a Variable (`Sprintf`)

Retorna la cadena formateada como un `string` en lugar de imprimirla en la consola.

```go
mensaje := fmt.Sprintf("Log: %s cargado", "Config")
```

## Verbos de Formato Comunes

| Verbo | Descripción |
|---|---|
| `%v` | Formato por defecto (imprime el valor de casi cualquier cosa de forma automática) |
| `%+v` | Para Structs: Imprime los nombres de los campos además de sus valores |
| `%T` | Imprime el **tipo de dato** de la variable |
| `%t` | Booleano (`true` o `false`) |
| `%d` | Entero en base 10 (decimal) |
| `%f` | Flotante (ej: `%2f` imprime con dos decimales) |
| `%s` | String (Cadena de caracteres) |
| `%p` | Puntero (dirección de memoria hexadecimal) |

## Lectura de Consola (`Scan`, `Scanf`)

```go
var nombre string
var edad int

fmt.Print("Ingresa tu nombre y edad: ")
// Escanea la entrada separada por espacios
fmt.Scan(&nombre, &edad)

// Escanea con formato estricto
fmt.Scanf("Usuario: %s Edad: %d", &nombre, &edad)
```
