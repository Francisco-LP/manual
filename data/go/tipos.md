# TIPOS DE DATOS en Go

Tipos de datos básicos y primitivos en Go. No se permiten conversiones implícitas de tipos (incluso si tienen el mismo tamaño, ej. `int` e `int64`).

## Tipos Numéricos

### Enteros
- Con signo: `int`, `int8`, `int16`, `int32`, `int64`.
- Sin signo: `uint`, `uint8`, `uint16`, `uint32`, `uint64`.
- `int` y `uint` tienen el tamaño del sistema operativo de destino (32 o 64 bits).

### Flotantes
- `float32` y `float64` (siempre prefiere `float64` para evitar pérdidas de precisión).

## Booleanos

- `bool`: `true` o `false`.

```go
var activo bool = true
```

## Caracteres Especiales (`byte` y `rune`)

- **`byte`**: Alias de `uint8`. Representa un byte de información (generalmente caracteres ASCII).
- **`rune`**: Alias de `int32`. Representa un punto de código Unicode (un caracter multibyte como emojis o tildes). Se definen entre comillas simples `'`.

```go
var letra byte = 'A'   // Guarda el número ASCII 65
var emoji rune = '🎯'  // Guarda el valor Unicode 127919
```

## Conversión Explicita de Tipos

En Go, toda conversión debe ser declarada explícitamente usando la función constructora del tipo destino.

```go
package main

import "fmt"

func main() {
    var entero int = 42
    var flotante float64 = float64(entero) // Conversión explícita

    var num64 int64 = 100
    // var resultado int = num64 // ERROR: tipos distintos
    var resultado int = int(num64) // CORRECTO
    
    fmt.Println(flotante, resultado)
}
```
