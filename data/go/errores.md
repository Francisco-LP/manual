# ERRORES en Go

El manejo de errores en Go es explícito. No existen las excepciones tradicionales (try/catch). Los errores son valores ordinarios que implementan la interfaz nativa `error`.

## La Interfaz error

Cualquier tipo que implemente un método `Error() string` se considera un error.

```go
type error interface {
    Error() string
}
```

## Creación de Errores Básicos

Se pueden crear errores simples usando el paquete `errors` o formatear errores detallados con `fmt`.

```go
package main

import (
    "errors"
    "fmt"
)

// Usando errors.New
var ErrDivisionPorCero = errors.New("no se puede dividir por cero")

func dividir(a, b float64) (float64, error) {
    if b == 0 {
        return 0, ErrDivisionPorCero
    }
    return a / b, nil
}

func main() {
    // Patrón típico: verificar el segundo valor retornado
    resultado, err := dividir(10, 0)
    if err != nil {
        fmt.Println("Error detectado:", err)
        return
    }
    fmt.Println("Resultado:", resultado)
}
```

## Formatear Errores Dinámicos (`fmt.Errorf`)

Permite añadir contexto a un error utilizando verbos de formato de `fmt`.

```go
func buscarUsuario(id int) (string, error) {
    usuarioExiste := false
    if !usuarioExiste {
        // Genera un error con formato dinámico
        return "", fmt.Errorf("el usuario con ID %d no fue encontrado", id)
    }
    return "Juan", nil
}
```

## Ajustar Errores y Envolver (Error Wrapping)

A partir de Go 1.13, se puede envolver un error usando el verbo `%w` en `fmt.Errorf`. Esto permite añadir contexto manteniendo el error original intacto para su posterior inspección con `errors.Is` y `errors.As`.

```go
package main

import (
    "errors"
    "fmt"
)

var ErrConexion = errors.New("fallo de conexión")

func consultaDB() error {
    // Envolver el error original ErrConexion
    return fmt.Errorf("error al leer la tabla usuarios: %w", ErrConexion)
}

func main() {
    err := consultaDB()
    
    // errors.Is: Compara si un error envuelto coincide con un error objetivo
    if errors.Is(err, ErrConexion) {
        fmt.Println("Es un error de conexión de red. Reintentando...")
    }

    fmt.Println("Log de error completo:", err)
}
```

## Desempaquetar Errores Personalizados (`errors.As`)

`errors.As` intenta convertir un error genérico a un tipo de error específico para acceder a campos adicionales.

```go
package main

import (
    "errors"
    "fmt"
)

// Tipo de error personalizado
type ErrorDeValidacion struct {
    Campo   string
    Mensaje string
}

func (e *ErrorDeValidacion) Error() string {
    return fmt.Sprintf("campo %s: %s", e.Campo, e.Mensaje)
}

func validarFormulario() error {
    return &ErrorDeValidacion{Campo: "email", Mensaje: "formato inválido"}
}

func main() {
    err := validarFormulario()

    var errVal *ErrorDeValidacion
    // errors.As extrae el error de tipo específico si coincide
    if errors.As(err, &errVal) {
        fmt.Printf("Error de validación en: %s (%s)\n", errVal.Campo, errVal.Mensaje)
    }
}
```
