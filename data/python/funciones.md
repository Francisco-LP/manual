# FUNCIONES en Python

Bloque de código reutilizable y estructurado para realizar tareas específicas.

## Sintaxis Básica y Retorno

```python
# Definición
def saludar(nombre):
    return f"Hola, {nombre}!"

# Llamada
mensaje = saludar("Ana")
print(mensaje)  # "Hola, Ana!"
```

## Argumentos con Valores por Defecto

```python
def conectar(host, puerto=80, ssl=False):
    # puerto y ssl tienen valores predeterminados
    print(f"Conectando a {host}:{puerto} (SSL: {ssl})")

conectar("127.0.0.1")                # Usa valores por defecto
conectar("localhost", puerto=443)     # Argumentos nombrados (keyword arguments)
conectar("10.0.0.1", 8080, True)     # Argumentos posicionales
```

## Argumentos Variables (`*args` y `**kwargs`)

### `*args` (Argumentos Posicionales Variables)
Recibe argumentos adicionales como una tupla.
```python
def sumar_todos(*numeros):
    print(numeros)  # Ejemplo: (1, 2, 3)
    return sum(numeros)

sumar_todos(1, 2, 3)  # Retorna 6
```

### `**kwargs` (Argumentos por Clave Variables)
Recibe argumentos nombrados adicionales como un diccionario.
```python
def crear_perfil(**detalles):
    print(detalles)  # Ejemplo: {'nombre': 'Leo', 'rol': 'Dev'}
    for clave, valor in detalles.items():
        print(f"{clave}: {valor}")

crear_perfil(nombre="Leo", rol="Dev", pais="Perú")
```

## Funciones Anónimas (`lambda`)

Funciones rápidas de una sola línea sin nombre.

```python
# Sintaxis: lambda argumentos: expresion
duplicar = lambda x: x * 2
print(duplicar(5))  # 10

# Muy útiles en funciones de orden superior como sort() o map()
puntos = [(1, 2), (3, 1), (5, 0)]
puntos.sort(key=lambda p: p[1])  # Ordena por la segunda coordenada -> [(5, 0), (3, 1), (1, 2)]
```

## Anotaciones de Tipo (Type Hinting)

Ayudan a documentar los tipos de parámetros y retornos esperados.

```python
def sumar(a: int, b: int) -> int:
    return a + b
```
