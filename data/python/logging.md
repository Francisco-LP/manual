# LOGGING en Python

El módulo `logging` provee un sistema flexible para emitir mensajes de estado y errores desde tus programas en Python, reemplazando el uso de `print()` en producción.

## Niveles de Gravedad (De menor a mayor)

1. **`DEBUG`**: Información de bajo nivel para depuración exhaustiva.
2. **`INFO`**: Confirmación de funcionamiento ordinario del programa.
3. **`WARNING`**: Indicación de algo inesperado o aviso potencial (nivel por defecto).
4. **`ERROR`**: Fallo grave, el programa no ha podido ejecutar alguna función.
5. **`CRITICAL`**: Error catastrófico, el programa puede cerrarse o fallar por completo.

## Configuración Básica (`basicConfig`)

```python
import logging

# Configurar destino, nivel mínimo y formato
logging.basicConfig(
    level=logging.INFO,                           # Nivel mínimo a procesar
    format="%(asctime)s - %(levelname)s - %(message)s", # Estructura del log
    handlers=[
        logging.FileHandler("app.log"),           # Escribir en archivo
        logging.StreamHandler()                   # Mostrar también en terminal
    ]
)

# Ejemplos de logs
logging.debug("Esto es un mensaje de depuración (no se mostrará por nivel)")
logging.info("El servidor ha iniciado correctamente")
logging.warning("Advertencia: Conexión lenta detectada")
logging.error("No se pudo conectar a la base de datos")
logging.critical("Memoria agotada. Fallo del sistema.")
```

## Capturar Excepciones en el Log (`exc_info`)

Para registrar el rastreo completo del error (Traceback) en caso de que ocurra una excepción:

```python
try:
    resultado = 10 / 0
except ZeroDivisionError:
    # exc_info=True adjunta el stack trace del error de forma automática
    logging.error("Fallo en cálculo matemático", exc_info=True)
```

## Formato del Log (Marcadores comunes)

- `%(asctime)s` : Fecha y hora de creación del mensaje.
- `%(levelname)s` : Nivel del log (`INFO`, `ERROR`, etc.).
- `%(message)s` : El mensaje de texto que has enviado.
- `%(filename)s` : Nombre del archivo de script desde donde se llamó.
- `%(lineno)d` : Número de línea de la llamada al log.
