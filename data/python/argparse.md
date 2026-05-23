# ARGPARSE en Python

El módulo `argparse` es la herramienta estándar para escribir interfaces de línea de comandos (CLI) sumamente amigables en Python. Genera ayuda automática y valida los parámetros de entrada (equivalente a `getopts` en Bash).

## Esqueleto Básico de CLI

```python
import argparse

def main():
    # 1. Crear el analizador (parser)
    parser = argparse.ArgumentParser(description="Script para procesar datos de usuarios.")

    # 2. Agregar argumentos
    # Argumento posicional (Obligatorio)
    parser.add_argument("archivo", help="Ruta al archivo de entrada.")

    # Argumento opcional / con nombre
    # type valida el tipo automáticamente; default asigna si no se pasa
    parser.add_argument("-n", "--nombre", type=str, default="Invitado", help="Nombre del usuario.")

    # Argumento booleano (Flag / Interruptor)
    # action="store_true" establece la variable en True si la bandera está presente
    parser.add_argument("-v", "--verbose", action="store_true", help="Mostrar salida detallada.")

    # 3. Analizar los argumentos de la consola (sys.argv)
    args = parser.parse_args()

    # 4. Usar los valores recibidos
    print(f"Archivo de entrada: {args.archivo}")
    print(f"Nombre de usuario: {args.nombre}")
    
    if args.verbose:
        print("Modo detallado activado...")

if __name__ == "__main__":
    main()
```

## Ejecución del Script en la Terminal

### 1. Ayuda Autogenerada (`-h` o `--help`)
Argparse crea de forma gratuita una documentación de uso perfecta.
```bash
$ python script.py -h
Uso: script.py [-h] [-n NOMBRE] [-v] archivo

Script para procesar datos de usuarios.

Argumentos posicionales:
  archivo               Ruta al archivo de entrada.

Opciones opcionales:
  -h, --help            mostrar este mensaje de ayuda
  -n NOMBRE, --nombre NOMBRE
                        Nombre del usuario.
  -v, --verbose         Mostrar salida detallada.
```

### 2. Uso Normal
```bash
$ python script.py datos.txt -n Ana -v
Archivo de entrada: datos.txt
Nombre de usuario: Ana
Modo detallado activado...
```

### 3. Argumento Requerido Faltante (Error automático)
```bash
$ python script.py
Uso: script.py [-h] [-n NOMBRE] [-v] archivo
script.py: error: el siguiente argumento es obligatorio: archivo
```
