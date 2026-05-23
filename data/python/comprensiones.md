# COMPRENSIONES en Python

Sintaxis ágil, concisa y optimizada para generar nuevas estructuras de datos (listas, diccionarios y conjuntos) a partir de secuencias iterables existentes.

## 1. Comprensión de Listas (List Comprehension)

Genera una nueva lista evaluando o filtrando elementos.

```python
# Sintaxis: [expresion for elemento in iterable if condicion]

# Tradicional:
cuadrados = []
for x in range(5):
    cuadrados.append(x ** 2)

# Pythonic:
cuadrados = [x ** 2 for x in range(5)]
# Resultado: [0, 1, 4, 9, 16]

# Con filtrado condicional (solo pares)
pares = [x for x in range(10) if x % 2 == 0]
# Resultado: [0, 2, 4, 6, 8]

# Con estructura condicional if-else (se coloca ANTES del for)
# [valor_si_true if condicion else valor_si_false for elemento in iterable]
etiquetas = ["Par" if x % 2 == 0 else "Impar" for x in range(5)]
# Resultado: ['Par', 'Impar', 'Par', 'Impar', 'Par']
```

## 2. Comprensión de Diccionarios (Dict Comprehension)

Genera diccionarios clave-valor de forma dinámica.

```python
# Sintaxis: {clave_expr: valor_expr for elemento in iterable if condicion}

# Ejemplo 1: Mapear longitudes de strings
nombres = ["Ana", "Pedro", "María"]
longitudes = {nombre: len(nombre) for nombre in nombres}
# Resultado: {'Ana': 3, 'Pedro': 5, 'María': 5}

# Ejemplo 2: Filtrar y modificar diccionarios
precios = {"pan": 1.0, "leche": 1.5, "vino": 10.0}
# Aumentar precio un 10% solo para productos con costo superior a 1.2
precios_caros = {prod: precio * 1.1 for prod, precio in precios.items() if precio > 1.2}
# Resultado: {'leche': 1.65, 'vino': 11.0}
```

## 3. Comprensión de Sets (Set Comprehension)

Genera un conjunto de elementos únicos aplicando la misma lógica que las listas, pero delimitado por llaves `{}`.

```python
# Sintaxis: {expresion for elemento in iterable if condicion}

# Filtrar letras únicas y convertirlas a mayúsculas
palabra = "abracadabra"
letras_unicas = {letra.upper() for letra in palabra}
# Resultado: {'A', 'B', 'C', 'D', 'R'} (desordenado, sin duplicados)
```
