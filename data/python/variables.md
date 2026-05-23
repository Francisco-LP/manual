# VARIABLES en Python

Soporte para variables con tipado dinámico. No requieren declaración de tipo explícita.

## Asignación Básica

```python
x = 10          # Entero (int)
nombre = "Ana"  # Cadena (str)
activo = True   # Booleano (bool)
```

## Asignación Múltiple

```python
# Mismo valor a múltiples variables
a = b = c = 0

# Distintos valores en una línea
x, y, z = 1, 2.5, "Hola"

# Intercambio de valores (Swap)
x, y = y, x
```

## Ámbito de las Variables

### Local vs Global

Las variables definidas dentro de una función son locales a esa función.

```python
x = 100  # Variable global

def mi_funcion():
    x = 50  # Variable local (no afecta a la global)
    print("Local:", x)

mi_funcion()     # Local: 50
print("Global:", x)  # Global: 100
```

### Modificación de Globales (`global`)

Para modificar una variable global dentro de una función, usa la palabra clave `global`.

```python
contador = 0

def incrementar():
    global contador
    contador += 1

incrementar()
print(contador)  # 1
```

### Modificación de No Locales (`nonlocal`)

Para funciones anidadas, modifica variables del ámbito superior inmediato con `nonlocal`.

```python
def exterior():
    x = "original"
    def interior():
        nonlocal x
        x = "modificado"
    interior()
    print(x)  # modificado

exterior()
```

## Convenciones de Nombres

- **snake_case**: Para variables y funciones (`mi_variable`, `calcular_total`).
- **UPPER_CASE**: Para constantes conceptuales (`PI = 3.1416`, `MAX_USERS = 100`).
