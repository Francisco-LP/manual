# ARCHIVOS en Python

Operaciones de lectura, escritura y manipulación de archivos y formatos comunes.

## Gestor de Contexto (`with`)

Se recomienda encarecidamente utilizar la sentencia `with`. Esto garantiza que el archivo se cierre automáticamente al finalizar el bloque, incluso si ocurre un error.

## Modos de Apertura

- `'r'`: Lectura (por defecto). Da error si el archivo no existe.
- `'w'`: Escritura. Crea el archivo o sobrescribe su contenido completo.
- `'a'`: Añadir. Añade contenido al final del archivo sin borrar lo anterior.
- `'b'`: Modo binario (ej: `'rb'`, `'wb'`) para imágenes, audio, etc.

## Lectura de Archivos

```python
# Leer todo el archivo
with open("datos.txt", "r", encoding="utf-8") as archivo:
    contenido = archivo.read()
    print(contenido)

# Leer línea por línea
with open("datos.txt", "r", encoding="utf-8") as archivo:
    for linea in archivo:
        print(linea.strip())  # strip() elimina saltos de línea adicionales

# Obtener todas las líneas como una lista
with open("datos.txt", "r", encoding="utf-8") as archivo:
    lineas = archivo.readlines()
```

## Escritura de Archivos

```python
# Escribir (sobrescribe por completo)
with open("salida.txt", "w", encoding="utf-8") as archivo:
    archivo.write("Primera línea de texto\n")
    archivo.write("Segunda línea de texto\n")

# Añadir al final (append)
with open("salida.txt", "a", encoding="utf-8") as archivo:
    archivo.write("Esta línea se añade al final\n")
```

## Formato JSON

Manipulación del formato de datos JSON con el módulo `json`.

```python
import json

datos = {
    "nombre": "Pedro",
    "habilidades": ["Python", "C++"],
    "activo": True
}

# Convertir diccionario a cadena JSON (Serializar)
json_str = json.dumps(datos, indent=4)
print(json_str)

# Escribir directamente en un archivo JSON
with open("usuario.json", "w") as f:
    json.dump(datos, f, indent=4)

# Cargar desde cadena JSON (Deserializar)
datos_cargados = json.loads(json_str)

# Leer desde un archivo JSON
with open("usuario.json", "r") as f:
    datos_archivo = json.load(f)
```
