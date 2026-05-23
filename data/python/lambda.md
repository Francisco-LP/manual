# FUNCIONES LAMBDA en Python

Las funciones lambda son funciones anónimas, rápidas y definidas en una sola línea de código.

## Sintaxis Básica

```python
# lambda argumentos: expresion
```

Una función lambda puede tener cualquier número de argumentos, pero **solo una expresión**, la cual es evaluada y retornada automáticamente sin necesidad de usar `return`.

## Ejemplos de Comparación

### Función Tradicional:
```python
def sumar(a, b):
    return a + b

print(sumar(5, 3))  # 8
```

### Función Lambda Equivalente:
```python
sumar_lambda = lambda a, b: a + b

print(sumar_lambda(5, 3))  # 8
```

## Casos de Uso Comunes

Las lambdas brillan cuando se pasan como argumentos a funciones de orden superior (que toman otras funciones como parámetros).

### 1. Ordenamiento Personalizado con `sort()` o `sorted()`

```python
empleados = [
    {"nombre": "Ana", "salario": 3000},
    {"nombre": "Pedro", "salario": 2000},
    {"nombre": "Luis", "salario": 2500}
]

# Ordenar de menor a mayor salario usando lambda
empleados.sort(key=lambda emp: emp["salario"])
print(empleados)
# Resultado: Pedro (2000), Luis (2500), Ana (3000)
```

### 2. Filtrado rápido con `filter()`

```python
numeros = [1, 2, 3, 4, 5, 6, 7, 8]

# Filtrar solo números pares
pares = list(filter(lambda x: x % 2 == 0, numeros))
print(pares)  # [2, 4, 6, 8]
```

### 3. Mapeado rápido con `map()`

```python
numeros = [1, 2, 3, 4]

# Elevar todos los números al cuadrado
cuadrados = list(map(lambda x: x**2, numeros))
print(cuadrados)  # [1, 4, 9, 16]
```
