# STRINGS (Cadenas) en Go

Secuencias inmutables de bytes que representan texto. El código fuente de Go siempre se codifica en UTF-8.

## Definición de Cadenas

```go
// Con comillas dobles (acepta secuencias de escape como \n, \t)
nombre := "Ana\n"

// Con comillas invertidas / backticks (literal crudo, conserva saltos de línea y tildes)
multiLinea := `Línea 1
Línea 2`
```

## Operaciones Básicas

```go
// Concatenación
saludo := "Hola " + "Mundo"

// Longitud (Retorna longitud en bytes, no caracteres unicode)
largoBytes := len("🎯") // Retorna 4 bytes, no 1 caracter!

// Obtener caracteres reales (Runes)
largoLetras := len([]rune("🎯")) // Retorna 1
```

## Paquete Estándar `strings`

Para manipulación avanzada de cadenas de texto.

```go
package main

import (
    "fmt"
    "strings"
)

func main() {
    texto := "Hola Mundo de Go"

    // 1. Verificación de existencia
    fmt.Println(strings.Contains(texto, "Go"))      // true
    fmt.Println(strings.HasPrefix(texto, "Hola"))   // true
    fmt.Println(strings.HasSuffix(texto, "Go"))     // true

    // 2. Modificaciones y transformaciones
    fmt.Println(strings.ToLower(texto))             // "hola mundo de go"
    fmt.Println(strings.ToUpper(texto))             // "HOLA MUNDO DE GO"
    fmt.Println(strings.Replace(texto, "Go", "C++", 1)) // Reemplaza una ocurrencia

    // 3. Conversiones a listas y uniones
    palabras := strings.Split(texto, " ")           // []string{"Hola", "Mundo", "de", "Go"}
    unido := strings.Join(palabras, "-")            // "Hola-Mundo-de-Go"
    
    // 4. Limpieza
    espaciado := "   texto con espacios   "
    fmt.Println(strings.TrimSpace(espaciado))       // "texto con espacios"
}
```
