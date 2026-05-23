# PATHLIB en Python

El módulo `pathlib` (introducido en **Python 3.4**) proporciona un enfoque orientado a objetos sumamente intuitivo y seguro para manipular rutas de archivos en el sistema operativo, reemplazando las antiguas funciones de `os.path`.

## Importación y Creación de Rutas

```python
from pathlib import Path

# Obtener ruta al directorio actual
actual = Path(".")

# Obtener directorio Home del usuario
home = Path.home()

# Construir rutas (El operador '/' une rutas de forma segura en Windows y Linux/macOS)
ruta_archivo = Path.home() / "documentos" / "datos.txt"
print(ruta_archivo)  # Ejemplo: /home/usuario/documentos/datos.txt
```

## Operaciones de Consulta de Rutas

```python
ruta = Path("/home/usuario/documentos/datos.txt")

print(ruta.name)      # "datos.txt" (Nombre completo)
print(ruta.stem)      # "datos" (Nombre sin extensión)
print(ruta.suffix)    # ".txt" (Extensión)
print(ruta.parent)    # "/home/usuario/documentos" (Directorio padre)
print(ruta.exists())  # True/False (Verifica si el archivo o carpeta existe)
print(ruta.is_file()) # True/False (Verifica si es un archivo regular)
print(ruta.is_dir())  # True/False (Verifica si es un directorio)
```

## Manipulación del Sistema de Archivos

```python
directorio = Path("nuevo_directorio")

# Crear carpeta (parents=True crea padres si no existen; exist_ok=True evita errores si ya existe)
directorio.mkdir(parents=True, exist_ok=True)

# Crear un archivo vacío
archivo = directorio / "notas.txt"
archivo.touch()

# Renombrar / Mover un archivo
nuevo_nombre = directorio / "apuntes.txt"
archivo.rename(nuevo_nombre)

# Eliminar archivo
nuevo_nombre.unlink()

# Eliminar carpeta vacía
directorio.rmdir()
```

## Lectura y Escritura Rápida

`pathlib` permite leer y escribir contenido de texto directamente sin necesidad de usar bloques `with open()` tradicionales para lecturas rápidas:

```python
archivo_rapido = Path("nota_rapida.txt")

# Escribir texto completo
archivo_rapido.write_text("Hola desde Pathlib!", encoding="utf-8")

# Leer texto completo
contenido = archivo_rapido.read_text(encoding="utf-8")
print(contenido)  # "Hola desde Pathlib!"

# Limpiar
archivo_rapido.unlink()
```
