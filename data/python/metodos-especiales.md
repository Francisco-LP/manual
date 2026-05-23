# MÉTODOS ESPECIALES en Python

También conocidos como **Dunder Methods** (Double Underline) o métodos mágicos. Permiten dotar a nuestras clases de comportamientos nativos de Python (como impresión, sumas, longitud, indexación).

## Representación (`__str__` y `__repr__`)

- `__str__` : Cadena legible para el usuario final (usado por `print()` y `str()`).
- `__repr__` : Cadena de depuración para desarrolladores (usado en consola interactiva).

```python
class Libro:
    def __init__(self, titulo, autor):
        self.titulo = titulo
        self.autor = autor

    def __str__(self):
        return f"'{self.titulo}' escrito por {self.autor}"

    def __repr__(self):
        return f"Libro(titulo='{self.titulo}', autor='{self.autor}')"

mi_libro = Libro("Don Quijote", "Cervantes")
print(mi_libro)        # Invoca __str__ -> 'Don Quijote' escrito por Cervantes
print(repr(mi_libro))  # Invoca __repr__ -> Libro(titulo='Don Quijote', autor='Cervantes')
```

## Emulación de Contenedores (`__len__` y `__getitem__`)

Permite que una clase actúe como una lista o diccionario.

- `__len__` : Llamado por la función interna `len()`.
- `__getitem__` : Llamado al acceder con corchetes `[indice]`.

```python
class CajaHerramientas:
    def __init__(self):
        self.herramientas = ["Martillo", "Destornillador", "Llave"]

    def __len__(self):
        return len(self.herramientas)

    def __getitem__(self, indice):
        return self.herramientas[indice]

caja = CajaHerramientas()
print(len(caja))     # Invoca __len__ -> 3
print(caja[1])       # Invoca __getitem__ -> Destornillador
```

## Operadores Matemáticos (`__add__`, `__sub__`, etc.)

Permiten sobrecargar operadores matemáticos sobre objetos propios.

```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Sobrecarga de operador '+'
    def __add__(self, otro):
        return Vector(self.x + otro.x, self.y + otro.y)

    def __str__(self):
        return f"Vector({self.x}, {self.y})"

v1 = Vector(1, 2)
v2 = Vector(3, 4)
print(v1 + v2)  # Invoca __add__ -> Vector(4, 6)
```

## Comparaciones (`__eq__`, `__lt__`, etc.)

- `__eq__` : Igualdad (`==`).
- `__lt__` : Menor que (`<`).

```python
class Usuario:
    def __init__(self, username, edad):
        self.username = username
        self.edad = edad

    def __eq__(self, otro):
        return self.edad == otro.edad

u1 = Usuario("Ana", 25)
u2 = Usuario("Pedro", 25)
print(u1 == u2)  # Invoca __eq__ -> True
```
