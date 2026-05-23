# MÓDULOS en Go

Un módulo es una colección de paquetes de Go relacionados que se versionan y distribuyen juntos. Es el estándar moderno para la gestión de dependencias en Go.

## Crear un Nuevo Módulo (`go mod init`)

Para iniciar la gestión de dependencias de un proyecto, ejecuta el comando `go mod init` en la raíz del proyecto, especificando la ruta/nombre del módulo (típicamente su ruta de repositorio de Git).

```bash
# Inicializa el módulo
go mod init github.com/usuario/mi-proyecto
```

Esto crea el archivo fundamental `go.mod`.

---

## El Archivo `go.mod`

Declara la ruta de importación del módulo, la versión de Go mínima requerida y la lista de dependencias con sus versiones exactas.

```go
// Ejemplo de archivo go.mod
module github.com/usuario/mi-proyecto

go 1.21.0

require (
    github.com/google/uuid v1.4.0
    golang.org/x/crypto v0.14.0 // indirect
)
```

- **`module`**: El prefijo/ruta para importar los paquetes internos del proyecto.
- **`require`**: Lista de dependencias directas e indirectas externas.
- **`// indirect`**: Indica que la dependencia es requerida por otra dependencia externa, no directamente por nuestro código.

---

## El Archivo `go.sum`

Es autogenerado y contiene los hashes criptográficos (checksums) de todas las versiones de las dependencias descargadas.
- **Garantiza la inmutabilidad y seguridad**: Asegura que el código de la dependencia que descargas hoy sea exactamente el mismo que se descargue en el futuro o en otros entornos.
- **Nota**: Este archivo **debe** incluirse en el control de versiones (Git) junto con `go.mod`.

---

## Comandos Esenciales de Go Modules

### 1. `go mod tidy`
Limpia el archivo `go.mod` de forma automática.
- Descarga y agrega cualquier dependencia nueva que hayas importado en tus archivos `.go`.
- Remueve las dependencias declaradas en `go.mod` que ya no estén en uso en tu código.

```bash
go mod tidy
```

### 2. `go get`
Agrega o actualiza dependencias específicas.

```bash
# Descarga e instala una biblioteca en una versión específica o la más reciente
go get github.com/gin-gonic/gin@latest

# Descargar una versión exacta
go get github.com/gin-gonic/gin@v1.9.0

# Eliminar una dependencia específica del módulo
go get github.com/gin-gonic/gin@none
```

### 3. `go mod vendor`
Crea un directorio local llamado `vendor/` que contiene copias de todas las dependencias necesarias. Permite compilar el proyecto sin necesidad de conectarse a internet.

```bash
go mod vendor
```

---

## Flujo de Trabajo Típico

1. Crear el directorio del proyecto y entrar en él.
2. Iniciar el módulo: `go mod init <nombre_modulo>`.
3. Escribir código Go e importar bibliotecas de terceros.
4. Ejecutar `go mod tidy` para descargar automáticamente dependencias y generar `go.sum`.
5. Ejecutar `go build` o `go run main.go` para compilar o ejecutar el proyecto.
