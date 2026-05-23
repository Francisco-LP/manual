# JSON en Python

Manipulación, codificación (serialización) y decodificación de datos en formato JSON mediante el módulo incorporado `json`.

## Cargar JSON (De texto a Python)

Convierte cadenas JSON en diccionarios o listas nativas de Python.

```python
import json

# JSON en una cadena de texto
json_string = '{"nombre": "Ana", "edad": 25, "activo": true}'

# Deserializar string con json.loads() (Load String)
datos = json.loads(json_string)
print(datos["nombre"])  # "Ana"
print(type(datos))      # <class 'dict'>

# Deserializar directamente desde un archivo JSON con json.load() (Load File)
with open("datos.json", "r") as archivo:
    datos_archivo = json.load(archivo)
```

## Guardar JSON (De Python a texto/archivo)

Convierte diccionarios, listas, etc. a formato de cadena JSON.

```python
usuario = {
    "nombre": "Pedro",
    "roles": ["Admin", "User"],
    "activo": False
}

# Serializar a cadena de texto con json.dumps() (Dump String)
# indent=4 formatea con sangrías y saltos de línea para legibilidad
json_formateado = json.dumps(usuario, indent=4)
print(json_formateado)

# Serializar directamente en un archivo con json.dump() (Dump File)
with open("salida.json", "w") as archivo:
    json.dump(usuario, archivo, indent=4)
```

## Equivalencias de Tipos

| JSON | Python |
|---|---|
| `object` | `dict` |
| `array` | `list` |
| `string` | `str` |
| `number (int / real)` | `int / float` |
| `true / false` | `True / False` |
| `null` | `None` |
