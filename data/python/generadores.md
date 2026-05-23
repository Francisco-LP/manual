# GENERADORES en Python

Los generadores son funciones especiales que devuelven un iterador perezoso (lazy iterator). No almacenan los datos en memoria de golpe, sino que los calculan y entregan bajo demanda.

## Funciones Generadoras con `yield`

En lugar de usar `return`, las funciones generadoras usan `yield` para devolver un valor temporalmente suspendiendo la ejecución del estado de la función.

```python
def contador(maximo):
    n = 1
    while n <= maximo:
        yield n  # Devuelve el valor y pausa el estado de la función
        n += 1

# Obtener el iterador
gen = contador(3)

# Obtener valores manualmente con next()
print(next(gen))  # 1
print(next(gen))  # 2
print(next(gen))  # 3
# print(next(gen))  # Lanzaría la excepción StopIteration
```

## Consumo con Bucles

La forma más común y segura de consumir un generador es mediante bucles `for` (que controlan automáticamente el fin del generador).

```python
for numero in contador(5):
    print(numero)  # Imprime del 1 al 5
```

## Expresiones Generadoras (Generator Expressions)

Forma rápida de escribir un generador en una línea. Su sintaxis es idéntica a la comprensión de listas, pero usa **paréntesis** `()` en lugar de llaves de lista `[]`.

```python
# Lista por comprensión (guarda todo en memoria)
lista_cuadrados = [x**2 for x in range(1000000)]

# Expresión generadora (calcula bajo demanda, ahorra memoria)
gen_cuadrados = (x**2 for x in range(1000000))

print(next(gen_cuadrados))  # 0
print(next(gen_cuadrados))  # 1
```

## ¿Por qué usar Generadores?

- **Eficiencia de Memoria**: Ideal para procesar archivos de texto gigantescos, flujos de datos continuos o colecciones inmensas de datos que no caben en RAM.
- **Evaluación Perezosa**: Los elementos solo se calculan cuando se solicitan explícitamente.
