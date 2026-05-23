# PAQUETES en Go

Go organiza el código fuente en paquetes (`packages`) para facilitar la modularidad, reutilización de código y encapsulación. Cada archivo de código de Go debe declarar a qué paquete pertenece al inicio.

## Declaración de un Paquete

Un paquete es un directorio que contiene uno o más archivos de extensión `.go`. Todos los archivos dentro de la misma carpeta física **deben pertenecer al mismo paquete**.

```go
// Archivo: math.go (dentro del directorio "matematicas")
package matematicas

// Función exportable (comienza con Mayúscula)
func Sumar(a, b int) int {
    return a + b
}
```

---

## Importación de Paquetes (`import`)

Para usar funciones o estructuras de otros paquetes, se utiliza la directiva `import`. Las rutas se especifican en base al nombre de módulo definido en `go.mod`.

```go
package main

import (
    "fmt"
    
    // Importación de un paquete interno del módulo local
    "github.com/usuario/proyecto/matematicas"
)

func main() {
    resultado := matematicas.Sumar(5, 10)
    fmt.Println("Suma:", resultado)
}
```

### Importación Múltiple y Alias

```go
import (
    f "fmt"       // Alias: ahora se usa f.Println(...)
    "math/rand"
    _ "github.com/lib/pq" // Importación en blanco (solo por efectos secundarios / inicializaciones)
)
```

---

## Reglas de Visibilidad (Exportación)

Go no tiene palabras clave como `public`, `private` o `protected`. La visibilidad de un identificador (variable, constante, función, struct, interfaz, método) se decide únicamente por **la capitalización de su primera letra**:

1. **Exportado (Público)**: Comienza con una letra **mayúscula**. Puede ser accedido desde otros paquetes que importen el paquete contenedor.
2. **No Exportado (Privado al paquete)**: Comienza con una letra **minúscula** (o guion bajo). Solo es visible para los archivos del mismo paquete.

```go
package config

// Exportado: Visible fuera del paquete
const Version = "1.0.0"

// No Exportado: Privado al paquete config
var clavePrivada = "secreto"

// Struct con campos públicos y privados
type Usuario struct {
    Nombre string // Público
    email  string // Privado (no accesible desde otros paquetes)
}
```

---

## La Función `init()`

Cada archivo Go puede definir opcionalmente una función especial llamada `init()`.
- **Ejecución Automática**: Se ejecuta automáticamente después de evaluar las variables del paquete y antes de la función `main()`.
- **Sin Parámetros**: No recibe argumentos ni retorna valores.
- **Múltiples init**: Puede haber múltiples funciones `init()` dentro de un mismo archivo o paquete; se ejecutarán en el orden en que aparecen.
- **Caso de uso típico**: Inicialización de conexiones a bases de datos, lectura de archivos de configuración iniciales, o validación de dependencias del entorno.

```go
package main

import "fmt"

var Config string

func init() {
    // Configuración inicial
    Config = "Perfil de desarrollo cargado"
    fmt.Println("init() ejecutado")
}

func main() {
    fmt.Println("main() ejecutado")
    fmt.Println("Estado:", Config)
}
```
