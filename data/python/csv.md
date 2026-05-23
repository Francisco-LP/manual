# CSV en Python

Lectura y escritura rápida de archivos en formato de valores separados por comas (CSV) utilizando el módulo incorporado `csv`.

## Lectura de Archivos CSV

### 1. Como listas (`csv.reader`)
Entrega cada fila como una lista de strings.

```python
import csv

with open("usuarios.csv", "r", encoding="utf-8") as f:
    lector = csv.reader(f)
    for fila in lector:
        print(fila)  # Ejemplo: ['Nombre', 'Edad', 'Ciudad']
```

### 2. Como diccionarios (`csv.DictReader`)
Entrega cada fila mapeada como un diccionario usando la cabecera como claves.

```python
with open("usuarios.csv", "r", encoding="utf-8") as f:
    lector_dict = csv.DictReader(f)
    for fila in lector_dict:
        print(fila["Nombre"], fila["Ciudad"])
```

## Escritura de Archivos CSV

### 1. Como listas (`csv.writer`)

```python
datos = [
    ["Nombre", "Edad", "Rol"],
    ["Ana", "25", "Desarrolladora"],
    ["Luis", "30", "Diseñador"]
]

# newline="" evita líneas vacías adicionales en Windows
with open("salida.csv", "w", newline="", encoding="utf-8") as f:
    escritor = csv.writer(f)
    # Escribir una sola fila
    # escritor.writerow(["Nombre", "Edad"])
    # Escribir múltiples filas
    escritor.writerows(datos)
```

### 2. Como diccionarios (`csv.DictWriter`)

```python
cabecera = ["Nombre", "Edad", "Rol"]
filas = [
    {"Nombre": "Ana", "Edad": 25, "Rol": "Desarrolladora"},
    {"Nombre": "Luis", "Edad": 30, "Rol": "Diseñador"}
]

with open("salida_dict.csv", "w", newline="", encoding="utf-8") as f:
    escritor = csv.DictWriter(f, fieldnames=cabecera)
    
    # Escribir cabecera obligatoria
    escritor.writeheader()
    
    # Escribir las filas de datos
    escritor.writerows(filas)
```
