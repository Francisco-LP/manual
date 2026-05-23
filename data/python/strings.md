# STRINGS (Cadenas) en Python

Secuencias de caracteres inmutables utilizadas para manipular texto.

## Creación y Formatos

```python
simple = 'Hola'
doble = "Mundo"
multi_linea = """Este es un texto
que conserva saltos de línea
y formato exacto."""
```

## Métodos Comunes

```python
texto = "  hola mundo de python  "

# Transformación de mayúsculas/minúsculas
print(texto.upper())       # "  HOLA MUNDO DE PYTHON  "
print(texto.lower())       # "  hola mundo de python  "
print(texto.capitalize())  # "  Hola mundo de python  "
print(texto.title())       # "  Hola Mundo De Python  "

# Eliminación de espacios en blanco
print(texto.strip())       # "hola mundo de python" (ambos lados)
print(texto.lstrip())      # "hola mundo de python  " (izquierdo)
print(texto.rstrip())      # "  hola mundo de python" (derecho)

# Búsqueda y reemplazo
print(texto.replace("python", "C++")) # "  hola mundo de C++  "
print("mundo" in texto)               # True (búsqueda rápida)
print(texto.find("mundo"))            # 7 (retorna índice de inicio)

# División y unión
palabras = "uno,dos,tres".split(",")  # ['uno', 'dos', 'tres']
print("-".join(palabras))             # "uno-dos-tres"
```

## Slicing (Rebanado) en Strings

Acceso directo a subpartes de un texto mediante índices `[inicio:fin:paso]`.

```python
frase = "Python"

print(frase[0])     # 'P'
print(frase[-1])    # 'n'
print(frase[0:3])   # 'Pyt' (excluye índice 3)
print(frase[2:])    # 'thon'
print(frase[:4])    # 'Pyth'
print(frase[::-1])  # 'nohtyP' (invertir cadena)
```

## Formateo Moderno: f-strings (Recomendado)

Introducido en Python 3.6, permite evaluar expresiones dentro de cadenas anteponiendo una `f`.

```python
nombre = "Ana"
edad = 25

# Concatenación simple
print(f"Hola, me llamo {nombre} y tengo {edad} años.")

# Evaluación de expresiones aritméticas
print(f"El próximo año tendré {edad + 1} años.")

# Llamar métodos y funciones
print(f"Mi nombre en mayúsculas es: {nombre.upper()}")

# Formateo de decimales y alineaciones
pi = 3.14159265
print(f"PI con dos decimales: {pi:.2f}")  # "3.14"
```
