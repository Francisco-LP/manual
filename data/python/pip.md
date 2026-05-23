# PIP en Python

`pip` es el instalador y gestor de paquetes de librerías y dependencias externas de Python desde el repositorio oficial PyPI (Python Package Index).

## Comandos Básicos de Instalación

```bash
# Instalar un paquete en su última versión disponible
pip install requests

# Instalar una versión específica
pip install requests==2.31.0

# Actualizar un paquete a la última versión
pip install --upgrade requests

# Desinstalar un paquete
pip uninstall requests
```

## Gestión de Archivos de Requerimientos (`requirements.txt`)

Permite replicar con exactitud el entorno de dependencias de un proyecto en otra máquina de desarrollo.

### 1. Guardar las dependencias instaladas actualmente
```bash
pip freeze > requirements.txt
```

*Esto crea un archivo plano como:*
```text
requests==2.31.0
urllib3==2.0.7
```

### 2. Instalar todas las dependencias listadas en un archivo
```bash
pip install -r requirements.txt
```

## Consulta de Información

```bash
# Listar todos los paquetes instalados en el entorno actual
pip list

# Mostrar detalles de un paquete instalado específico (versión, autor, dependencias)
pip show requests

# Listar paquetes obsoletos que tienen actualizaciones disponibles
pip list --outdated
```
