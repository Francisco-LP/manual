# HTTP en Go

El paquete nativo `net/http` de Go proporciona un cliente y un servidor HTTP potentes y de alto rendimiento de forma nativa, sin necesidad de dependencias externas.

## Servidor HTTP Básico

Go facilita la creación de un servidor web concurrente mediante enrutamiento (`HandleFunc`) y escucha del puerto (`ListenAndServe`).

```go
package main

import (
    "fmt"
    "net/http"
)

// Handler para la ruta de inicio
func homeHandler(w http.ResponseWriter, r *http.Request) {
    // w: Permite construir la respuesta (cuerpo, cabeceras, estado)
    // r: Contiene los datos de la petición entrante (método, query params, etc.)
    fmt.Fprintf(w, "¡Bienvenido a mi servidor Go!")
}

func apiHandler(w http.ResponseWriter, r *http.Request) {
    // Comprobar el método HTTP
    if r.Method != http.MethodGet {
        http.Error(w, "Método no permitido", http.StatusMethodNotAllowed)
        return
    }

    w.Header().Set("Content-Type", "application/json")
    w.WriteHeader(http.StatusOK)
    w.Write([]byte(`{"mensaje": "Hola desde la API JSON"}`))
}

func main() {
    // Registrar controladores de rutas
    http.HandleFunc("/", homeHandler)
    http.HandleFunc("/api", apiHandler)

    fmt.Println("Servidor web iniciado en http://localhost:8080")
    
    // Inicia el servidor en el puerto 8080. Es una llamada bloqueante.
    err := http.ListenAndServe(":8080", nil)
    if err != nil {
        fmt.Println("Error al iniciar el servidor:", err)
    }
}
```

---

## Cliente HTTP Básico

Realizar peticiones HTTP a recursos externos es sencillo gracias a funciones directas como `http.Get`.

```go
package main

import (
    "fmt"
    "io"
    "net/http"
)

func main() {
    // Realiza una petición GET
    respuesta, err := http.Get("https://api.github.com")
    if err != nil {
        fmt.Println("Error en la petición:", err)
        return
    }
    
    // IMPORTANTE: Asegurar cerrar el cuerpo de la respuesta
    defer respuesta.Body.Close()

    fmt.Println("Código de estado HTTP:", respuesta.StatusCode)
    fmt.Println("Cabecera Content-Type:", respuesta.Header.Get("Content-Type"))

    // Leer el cuerpo de la respuesta
    cuerpo, err := io.ReadAll(respuesta.Body)
    if err != nil {
        fmt.Println("Error al leer el cuerpo:", err)
        return
    }

    // Mostrar una parte de la respuesta
    fmt.Printf("Respuesta (primeros 150 caracteres):\n%s...\n", string(cuerpo)[:150])
}
```

---

## Cliente Personalizado con Timeouts

Para un entorno de producción, es una mala práctica usar el cliente HTTP por defecto (`http.Get`), ya que no tiene tiempo de espera (timeout) predeterminado y podría bloquear la goroutine indefinidamente.

```go
package main

import (
    "net/http"
    "time"
)

func main() {
    // Cliente configurado con timeout de 5 segundos
    cliente := &http.Client{
        Timeout: 5 * time.Second,
    }

    peticion, _ := http.NewRequest("GET", "https://api.example.com", nil)
    peticion.Header.Set("User-Agent", "MiAppGo/1.0")

    respuesta, err := cliente.Do(peticion)
    if err != nil {
        panic(err)
    }
    defer respuesta.Body.Close()
}
```
