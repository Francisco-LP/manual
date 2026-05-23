# ITERTOOLS en Python

El módulo `itertools` provee un conjunto de herramientas altamente eficientes y optimizadas (escritas en C) para la creación y manipulación de iteradores complejos y flujos de datos.

## 1. Iteradores Infinitos

Flujos iterables continuos que no terminan a menos que se interrumpan con un `break`.

```python
import itertools

# count(inicio, paso): Cuenta al infinito
for numero in itertools.count(start=10, step=2):
    if numero > 16:
        break
    print(numero)  # 10, 12, 14, 16

# cycle(iterable): Cicla infinitamente sobre los elementos
contador = 0
for elemento in itertools.cycle(["Rojo", "Verde"]):
    if contador == 4:
        break
    print(elemento)  # Rojo, Verde, Rojo, Verde
    contador += 1
```

## 2. Combinar e Iterar Estructuras

```python
# chain(*iterables): Encadena múltiples colecciones en una sola iteración continua
letras = ["A", "B"]
numeros = [1, 2]
for elemento in itertools.chain(letras, numeros):
    print(elemento)  # 'A', 'B', 1, 2

# zip_longest(*iterables, fillvalue=None): Une iterables en paralelo
# A diferencia de zip(), no se detiene en el más corto, sino que usa un relleno
nombres = ["Ana", "Pedro"]
edades = [25]
for nombre, edad in itertools.zip_longest(nombres, edades, fillvalue="N/A"):
    print(nombre, edad)
    # Ana 25
    # Pedro N/A
```

## 3. Generadores Combinatorios y de Permutaciones

```python
elementos = ["A", "B", "C"]

# product(*iterables, repeat=1): Producto cartesiano
for comb in itertools.product(elementos, repeat=2):
    print(comb)  # ('A', 'A'), ('A', 'B'), ..., ('C', 'C')

# permutations(iterable, r): Permutaciones sin elementos repetidos (el orden importa)
for perm in itertools.permutations(elementos, r=2):
    print(perm)  # ('A', 'B'), ('A', 'C'), ('B', 'A'), ...

# combinations(iterable, r): Combinaciones en orden (el orden no importa)
for comb in itertools.combinations(elementos, r=2):
    print(comb)  # ('A', 'B'), ('A', 'C'), ('B', 'C')
```
