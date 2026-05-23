# TIPOS DE DATOS en Python

Python es un lenguaje de tipado dinámico y fuerte.

## Tipos Básicos

- **Entero (`int`)**: Números sin decimales (ej: `42`, `-7`).
- **Flotante (`float`)**: Números con decimales (ej: `3.14`, `-0.001`).
- **Complejo (`complex`)**: Números complejos (ej: `3 + 5j`).
- **Booleano (`bool`)**: `True` o `False`.
- **Cadena (`str`)**: Texto delimitado por comillas simples `'` o dobles `"`.

```python
edad = 30           # int
precio = 19.99      # float
nombre = "Carlos"   # str
activo = True       # bool
```

## Conversión de Tipos (Casting)

Puedes forzar la conversión de tipos usando funciones constructoras.

```python
# A entero
int("10")      # 10
int(4.7)       # 4 (trunca decimales)

# A flotante
float("3.14")  # 3.14
float(10)      # 10.0

# A cadena
str(100)       # "100"
str(True)      # "True"

# A booleano
bool(1)        # True
bool(0)        # False
bool("")       # False (cadenas vacías)
bool([])       # False (colecciones vacías)
bool("Texto")  # True
```

## Verificación de Tipos

### Usando `type()`

Retorna el tipo exacto del objeto.

```python
x = 10
print(type(x))  # <class 'int'>

if type(x) is int:
    print("Es un entero")
```

### Usando `isinstance()` (Recomendado)

Verifica si un objeto es de un tipo determinado (admite herencia).

```python
x = 10.5
isinstance(x, float)            # True
isinstance(x, (int, float))     # True (si es cualquiera de los dos)
```
