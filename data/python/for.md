# FOR en Python

Bucle utilizado para iterar sobre una secuencia (lista, tupla, diccionario, set, string, etc.).

## Sintaxis Básica

```python
frutas = ["manzana", "banana", "cereza"]

for fruta in frutas:
    print(fruta)
```

## Uso de `range()`

Genera una secuencia numérica. `range(inicio, fin, paso)` (el número de `fin` es exclusivo).

```python
# Del 0 al 4
for i in range(5):
    print(i)  # 0, 1, 2, 3, 4

# Del 2 al 8
for i in range(2, 9):
    print(i)  # 2, 3, ..., 8

# Del 0 al 10 de 2 en 2
for i in range(0, 11, 2):
    print(i)  # 0, 2, 4, 6, 8, 10

# Cuenta regresiva del 5 al 1
for i in range(5, 0, -1):
    print(i)  # 5, 4, 3, 2, 1
```

## Funciones Auxiliares de Iteración

### `enumerate()`
Itera obteniendo tanto el índice como el valor actual.
```python
nombres = ["Ana", "Pedro", "Luis"]

for indice, nombre in enumerate(nombres):
    print(f"Índice: {indice}, Nombre: {nombre}")
```

### `zip()`
Itera sobre múltiples secuencias en paralelo de forma simultánea.
```python
nombres = ["Ana", "Pedro"]
edades = [24, 30]

for nombre, edad in zip(nombres, edades):
    print(f"{nombre} tiene {edad} años")
```

## Comprensión de Listas (List Comprehension)

Creación rápida y elegante de nuevas listas a partir de secuencias existentes.

```python
# Sintaxis: [expresion for elemento in secuencia if condicion]

# Tradicional
cuadrados = []
for x in range(5):
    cuadrados.append(x**2)

# Pythonic (Comprensión)
cuadrados = [x**2 for x in range(5)]
# Resultado: [0, 1, 4, 9, 16]

# Comprensión con condición (filtrado)
pares = [x for x in range(10) if x % 2 == 0]
# Resultado: [0, 2, 4, 6, 8]
```
