# MÓDULO OS en Python

El módulo `os` provee una interfaz para interactuar directamente con las funcionalidades del sistema operativo (variables de entorno, directorios y procesos).

## Gestión de Variables de Entorno

```python
import os

# Obtener una variable de entorno (retorna None si no existe)
path_env = os.environ.get("PATH")

# Obtener con valor por defecto
db_host = os.environ.get("DB_HOST", "localhost")

# Establecer una variable de entorno para el proceso actual
os.environ["VERSION_APP"] = "1.0.0"
```

## Navegación y Rutas (Enfoque tradicional)

> [!TIP]
> Para la mayoría de tareas de rutas se recomienda usar `pathlib`. `os` es útil para operaciones del S.O. directo.

```python
# Obtener directorio de trabajo actual (pwd)
pwd = os.getcwd()

# Cambiar de directorio (cd)
os.chdir("/tmp")

# Listar contenidos de un directorio (ls)
archivos = os.listdir(".")
```

## Manipulación del Sistema

```python
# Crear directorio único
os.mkdir("mi_carpeta")

# Crear directorios de forma recursiva (como mkdir -p)
os.makedirs("rutas/anidadas/nuevas", exist_ok=True)

# Eliminar archivo
os.remove("archivo.txt")

# Eliminar directorio vacío
os.rmdir("mi_carpeta")

# Eliminar directorios de forma recursiva
os.removedirs("rutas/anidadas/nuevas")

# Renombrar archivos o moverlos
os.rename("viejo.txt", "nuevo.txt")
```

## Ejecución de Comandos del Sistema Básicos

Para ejecutar comandos rápidos y simples sin capturar flujos complejos de datos:

```python
# Ejecuta el comando en un subshell nativo y muestra la salida en la terminal estándar
os.system("echo 'Hola desde Terminal'")
```

> [!NOTE]
> Para ejecuciones de comandos avanzadas, captura de flujos, pipes y control seguro de subprocesos, prefiere siempre el módulo `subprocess`.
