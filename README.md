# manual

Herramienta de consulta rápida de sintaxis para lenguajes y tecnologías desde la terminal.

## Uso

```bash
manual <lenguaje> <tema>
```

```bash
manual bash if
manual bash for
manual bash arrays
manual bash temas      # lista todos los temas disponibles
```

## Instalación

```bash
git clone https://github.com/tuusuario/manual
cd manual
chmod +x install.sh
./install.sh
```

## Temas disponibles

### Bash

| Comando | Descripción |
|---|---|
| `manual bash if` | Estructura condicional if / else / elif |
| `manual bash for` | Bucle for |
| `manual bash while` | Bucle while |
| `manual bash until` | Bucle until |
| `manual bash case` | Estructura case |
| `manual bash function` | Funciones |
| `manual bash variables` | Variables y variables especiales |
| `manual bash arrays` | Arrays indexados y asociativos |
| `manual bash tipos` | Tipos de datos |
| `manual bash numeros` | Operadores de comparación numérica |
| `manual bash strings` | Operadores de comparación de strings |
| `manual bash archivos` | Operadores de comparación de archivos |

## Agregar temas

Crear un archivo `.md` en la carpeta del lenguaje correspondiente:

```bash
vim data/bash/nuevo-tema.md
```

El tema aparece automáticamente en `manual bash temas`


## Requisitos

- C++17 o superior
- g++
