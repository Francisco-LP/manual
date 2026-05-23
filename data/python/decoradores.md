# DECORADORES en Python

Un decorador es una función que recibe otra función como argumento, le añade alguna funcionalidad extra y retorna una nueva función modificada sin alterar su código fuente directo.

## Estructura Básica

Sintaxis para envolver funciones sin parámetros de entrada.

```python
def mi_decorador(funcion):
    def envoltura():
        print("Antes de ejecutar la función...")
        funcion()
        print("Después de ejecutar la función...")
    return envoltura

# Aplicar decorador con '@'
@mi_decorador
def saludar():
    print("¡Hola Mundo!")

saludar()
# Imprime:
# Antes de ejecutar la función...
# ¡Hola Mundo!
# Después de ejecutar la función...
```

## Decorar Funciones con Argumentos (`*args`, `**kwargs`)

Para que el decorador funcione con cualquier función, se deben pasar los parámetros variables a la función envolvente.

```python
def registrar_log(funcion):
    def envoltura(*args, **kwargs):
        print(f"Llamando a {funcion.__name__} con argumentos {args}")
        resultado = funcion(*args, **kwargs)
        print(f"{funcion.__name__} retornó {resultado}")
        return resultado
    return envoltura

@registrar_log
def sumar(a, b):
    return a + b

sumar(5, 7)
# Imprime:
# Llamando a sumar con argumentos (5, 7)
# sumar retornó 12
```

## Preservar Metadatos con `functools.wraps`

Al decorar una función, esta pierde sus metadatos (como el nombre de la función `__name__` y los docstrings `__doc__`). Para evitarlo, usa `wraps` del módulo `functools`.

```python
from functools import wraps

def mi_decorador(funcion):
    @wraps(funcion)
    def envoltura(*args, **kwargs):
        # código
        return funcion(*args, **kwargs)
    return envoltura
```

## Decorador con Argumentos Propios

Si el decorador en sí mismo necesita recibir parámetros, se debe agregar otro nivel de anidación.

```python
def repetir(veces):
    def decorador(funcion):
        @wraps(funcion)
        def envoltura(*args, **kwargs):
            for _ in range(veces):
                funcion(*args, **kwargs)
        return envoltura
    return decorador

@repetir(veces=3)
def avisar():
    print("¡Alerta!")

avisar()  # Imprime "¡Alerta!" 3 veces.
```
