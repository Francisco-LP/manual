# SUBPROCESS en Python

El módulo `subprocess` permite spawnear nuevos procesos, conectarse a sus tuberías de entrada/salida/error (stdin, stdout, stderr) y obtener sus códigos de retorno de forma sumamente robusta. Reemplaza a las antiguas llamadas `os.system`.

## Ejecución Básica (`subprocess.run`)

Es el enfoque recomendado y seguro para la mayoría de casos de uso. Espera a que el comando termine y retorna un objeto `CompletedProcess`.

```python
import subprocess

# Pasar comandos como lista de argumentos (Evita inyección de comandos en shell)
resultado = subprocess.run(["ls", "-la"])

# Verificar código de salida (0 significa éxito)
print("Código de salida:", resultado.returncode)
```

## Capturar Salida Estándar (`stdout` y `stderr`)

Por defecto, la salida del proceso se envía directamente al flujo de terminal de tu script. Para capturarla y guardarla en variables internas de Python:

```python
# capture_output=True redirige stdout y stderr para capturarlos
# text=True decodifica los bytes de salida automáticamente a strings (utf-8)
resultado = subprocess.run(["echo", "Hola Mundo"], capture_output=True, text=True)

print("Salida:", resultado.stdout.strip())  # "Hola Mundo"
```

## Lanzar Error si el Comando Falla (`check=True`)

Si quieres que Python lance una excepción (`CalledProcessError`) automáticamente si el comando retorna un código de error distinto a 0:

```python
try:
    subprocess.run(["cat", "archivo_inexistente.txt"], check=True, capture_output=True, text=True)
except subprocess.CalledProcessError as e:
    print(f"El comando falló con código {e.returncode}")
    print(f"Error detallado: {e.stderr}")
```

## Ejecución mediante Shell Nivel de Sistema (`shell=True`)

Si necesitas que el comando se evalúe utilizando un shell nativo (como bash, para expandir variables de entorno `$VAR` o comodines `*`), pasa la bandera `shell=True` y el comando como un único string.

> [!WARNING]
> Usar `shell=True` puede suponer un grave riesgo de seguridad por **inyección de comandos** si se le concatena entrada de usuarios externos no validados.

```python
# Uso con shell (seguro si la cadena es estática)
subprocess.run("echo $USER", shell=True)
```
