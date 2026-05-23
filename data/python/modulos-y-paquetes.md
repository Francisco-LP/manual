# MÓDULOS Y PAQUETES en Python

Estructuración de código en archivos independientes (módulos) y carpetas jerárquicas (paquetes).

## Importaciones de Módulos (`import`)

Supongamos que tenemos un archivo llamado `calculadora.py` en el mismo directorio.

```python
# Importar módulo completo
import calculadora
resultado = calculadora.sumar(5, 3)

# Importar funciones específicas
from calculadora import sumar, restar
resultado = sumar(5, 3)

# Importar con alias (renombrar)
import calculadora as calc
resultado = calc.sumar(5, 3)

# Importar todo (No recomendado por riesgo de colisión de nombres)
from calculadora import *
```

## Punto de Entrada Principal (`__name__`)

Se usa para controlar qué parte del código se ejecuta si el script se llama directamente desde la terminal o si es importado desde otro archivo.

```python
# Contenido de mi_script.py

def main():
    print("El script se ejecutó directamente.")

if __name__ == "__main__":
    # Esto SOLO se ejecuta al correr: python mi_script.py
    # NO se ejecuta si es importado: import mi_script
    main()
```

## Estructura de un Paquete

Un paquete es un directorio que contiene múltiples módulos y, opcionalmente, un archivo `__init__.py`.

```text
mi_paquete/
│
├── __init__.py      # Inicializa el paquete (puede estar vacío)
├── modulo_a.py
└── modulo_b.py
```

Para importar elementos del paquete:
```python
from mi_paquete.modulo_a import funcion_a
```

## Entornos Virtuales (`venv`)

Aíslan las dependencias de tus proyectos individuales para que no interfieran a nivel global en tu sistema operativo.

### 1. Crear entorno virtual
```bash
python -m venv mi_entorno
```

### 2. Activar entorno virtual
- **Linux/macOS**:
  ```bash
  source mi_entorno/bin/activate
  ```
- **Windows (PowerShell)**:
  ```powershell
  .\mi_entorno\Scripts\Activate.ps1
  ```

### 3. Instalar paquetes con `pip`
```bash
pip install requests             # Instalar dependencia
pip freeze > requirements.txt    # Guardar dependencias actuales
pip install -r requirements.txt  # Instalar dependencias guardadas
```

### 4. Desactivar entorno
```bash
deactivate
```
