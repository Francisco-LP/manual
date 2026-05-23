# ARCHIVOS en Go

Go utiliza los paquetes nativos `os`, `io` y `bufio` para interactuar con el sistema de archivos del sistema operativo, ofreciendo lectura y escritura tanto directa como en búfer.

## Lectura Completa de Archivos (`os.ReadFile`)

Para archivos pequeños, la forma más sencilla es cargar todo su contenido en memoria de una sola vez.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    // Lee todo el archivo y retorna un slice de bytes ([]byte)
    contenido, err := os.ReadFile("datos.txt")
    if err != nil {
        fmt.Println("Error al leer el archivo:", err)
        return
    }

    // Convertir el []byte a string para imprimirlo
    fmt.Println(string(contenido))
}
```

---

## Escritura Completa de Archivos (`os.WriteFile`)

Crea un archivo o sobrescribe uno existente con el contenido especificado de una sola vez.

```go
package main

import (
    "fmt"
    "os"
)

func main() {
    texto := []byte("Hola, mundo desde Go!\n")
    
    // Escribe el archivo. El último argumento define los permisos Unix (0644 = rw-r--r--)
    err := os.WriteFile("salida.txt", texto, 0644)
    if err != nil {
        fmt.Println("Error al escribir el archivo:", err)
        return
    }
}
```

---

## Lectura Línea por Línea (`bufio.Scanner`)

Es ideal para procesar archivos grandes que no caben enteros en la memoria RAM.

```go
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Abre el archivo
    archivo, err := os.Open("grande.txt")
    if err != nil {
        fmt.Println("Error al abrir:", err)
        return
    }
    // Asegurar siempre el cierre del archivo
    defer archivo.Close()

    // Crear un escáner bufferizado
    scanner := bufio.NewScanner(archivo)

    // Iterar línea por línea
    for scanner.Scan() {
        linea := scanner.Text()
        fmt.Println("Línea leída:", linea)
    }

    // Verificar si ocurrió algún error durante la lectura
    if err := scanner.Err(); err != nil {
        fmt.Println("Error durante el escaneo:", err)
    }
}
```

---

## Escritura Controlada en Búfer (`bufio.Writer`)

Permite acumular escrituras en memoria antes de volcarlas al disco físico, mejorando significativamente el rendimiento de E/S.

```go
package main

import (
    "bufio"
    "fmt"
    "os"
)

func main() {
    // Crear el archivo o truncarlo si ya existe (permiso de escritura)
    archivo, err := os.Create("registro.log")
    if err != nil {
        fmt.Println("Error al crear:", err)
        return
    }
    defer archivo.Close()

    // Crear escritor bufferizado
    escritor := bufio.NewWriter(archivo)

    // Escribir cadenas en el búfer
    escritor.WriteString("Primera línea del log.\n")
    escritor.WriteString("Segunda línea del log.\n")

    // CRÍTICO: vaciar el búfer de memoria al disco real
    err = escritor.Flush()
    if err != nil {
        fmt.Println("Error al hacer Flush:", err)
    }
}
```

---

## Modos de Apertura Avanzados (`os.OpenFile`)

Si necesitas abrir un archivo en modo anexar (append), lectura/escritura simultánea, etc.

```go
// Abrir en modo anexar (O_APPEND), creando el archivo si no existe (O_CREATE)
archivo, err := os.OpenFile("historial.log", os.O_APPEND|os.O_CREATE|os.O_WRONLY, 0644)
```
