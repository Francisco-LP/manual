# ESTRUCTURA DE CÓDIGO en Python

Esqueleto típico y organización de un archivo ejecutable de Python bajo las mejores prácticas.

## Estructura Recomendada de un Script

```python
#!/usr/bin/env python3
# -*- coding: utf-8 -*-

"""
Descripción corta del propósito de este script.
Puede detallar el uso, dependencias o autoría.
"""

# 1. Importaciones de la biblioteca estándar
import os
import sys

# 2. Importaciones de terceros (pip)
# import requests

# 3. Importaciones locales (propias del proyecto)
# from utilidades import procesar_datos

# 4. Definición de Constantes globales
CONFIG_GLOBAL = "valores"

# 5. Clases
class MiClase:
    pass

# 6. Funciones
def mi_funcion():
    pass

# 7. Punto de entrada principal (Función Main)
def main():
    print("Script iniciado...")
    mi_funcion()

if __name__ == "__main__":
    # Evita que el código ejecutable corra accidentalmente cuando se importa este módulo
    main()
```

## Reglas Clave de Estructura (PEP 8)

- **Indentación**: Usa siempre 4 espacios por nivel de bloque (nunca uses tabuladores puros o los mezcles).
- **Límite de línea**: Máximo 79 caracteres por línea para facilitar lecturas verticales.
- **Líneas vacías**:
  - 2 líneas en blanco para separar funciones globales y clases.
  - 1 línea en blanco para separar métodos dentro de una misma clase.
- **Codificación**: UTF-8 por defecto en Python 3 (indicada explícitamente en el encabezado `coding: utf-8`).
