# OS en Go

El paquete `os` proporciona una interfaz independiente de la plataforma para interactuar con funcionalidades del sistema operativo (variables de entorno, argumentos de terminal, señales de salida, entre otros).

## Argumentos de Línea de Comandos (`os.Args`)

`os.Args` es un slice de tipo `string` que contiene los argumentos pasados al ejecutar el binario.
- `os.Args[0]` siempre es la ruta o nombre del binario ejecutado.
- `os.Args[1:]` contiene los parámetros provistos por el usuario.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    // Todos los argumentos
    argumentos := os.Args
    fmt.Println("Argumento 0 (nombre programa):", argumentos[0])

    if len(argumentos) > 1 {
        fmt.Println("Argumentos adicionales:")
        for i, arg := range argumentos[1:] {
            fmt.Printf(" [%d]: %s\n", i+1, arg)
        }
    } else {
        fmt.Println("No se pasaron argumentos adicionales.")
    }
}
```

---

## Variables de Entorno

El paquete `os` permite leer, buscar, definir y borrar variables de entorno del sistema.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    // 1. Definir una variable de entorno temporal
    os.Setenv("APP_PORT", "8080")
    defer os.Unsetenv("APP_PORT") // Limpiar al finalizar

    // 2. Obtener el valor de una variable de entorno
    puerto := os.Getenv("APP_PORT")
    fmt.Println("Puerto configurado:", puerto)

    // Si la variable no existe, Getenv() devuelve un string vacío ""
    dbHost := os.Getenv("DB_HOST")
    fmt.Printf("DB Host: %q\n", dbHost)

    // 3. LookupEnv: permite distinguir entre variable vacía y no definida
    val, existe := os.LookupEnv("DB_HOST")
    if !existe {
        fmt.Println("La variable DB_HOST no está definida en el sistema.")
    } else {
        fmt.Printf("La variable DB_HOST está definida con valor: %s\n", val)
    }
}
```

---

## Finalizar la Ejecución (`os.Exit`)

`os.Exit` provoca la detención inmediata del programa con un código de estado especificado.
- **Cero (`0`)** indica éxito (finalización normal).
- **Cualquier número distinto de cero (`1-255`)** denota un error.
- **IMPORTANTE**: Al usar `os.Exit`, las sentencias diferidas (`defer`) registradas en el programa **no se ejecutan**.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    defer fmt.Println("Este mensaje nunca se imprimirá por culpa de os.Exit")

    if err := hacerAlgo(); err != nil {
        fmt.Println("Error crítico:", err)
        os.Exit(1) // Finaliza de inmediato con código de error 1
    }

    fmt.Println("Ejecución exitosa.")
    os.Exit(0) // Código de salida 0
}

func hacerAlgo() error {
    return fmt.Errorf("fallo del sistema")
}
```
