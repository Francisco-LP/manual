# CLASES en Python

Programación Orientada a Objetos (POO). Define atributos y métodos estructurados.

## Sintaxis Básica y Constructor

```python
class Persona:
    # Atributo de clase (compartido por todas las instancias)
    especie = "Humano"

    # Constructor
    def __init__(self, nombre, edad):
        # Atributos de instancia
        self.nombre = nombre
        self.edad = edad

    # Método de instancia
    def saludar(self):
        return f"Hola, soy {self.nombre} y tengo {self.edad} años."

# Instanciación
p1 = Persona("Ana", 30)
print(p1.saludar())  # "Hola, soy Ana y tengo 30 años."
print(p1.especie)    # "Humano"
```

## Herencia y `super()`

```python
class Empleado(Persona):
    def __init__(self, nombre, edad, salario):
        # Llama al constructor de la clase padre (Persona)
        super().__init__(nombre, edad)
        self.salario = salario

    # Sobrescribir método
    def saludar(self):
        return f"Hola, soy el empleado {self.nombre} y mi salario es {self.salario}."

emp = Empleado("Luis", 28, 2500)
print(emp.saludar())  # Hola, soy el empleado Luis y mi salario es 2500.
```

## Atributos Privados y Propiedades (`@property`)

En Python no existen modificadores estrictos de acceso (como `private`). Se usa el guión bajo `_` (protegido por convención) o doble guión bajo `__` (privado por Name Mangling).

```python
class Producto:
    def __init__(self, nombre, precio):
        self.nombre = nombre
        self.__precio = precio  # Atributo privado

    # Getter usando @property
    @property
    def precio(self):
        return self.__precio

    # Setter usando @precio.setter
    @precio.setter
    def precio(self, nuevo_precio):
        if nuevo_precio >= 0:
            self.__precio = nuevo_precio
        else:
            raise ValueError("El precio no puede ser negativo")

prod = Producto("Laptop", 1000)
prod.precio = 1200      # Llama al setter
print(prod.precio)      # Llama al getter -> 1200
```

## Métodos Mágicos / Especiales (Dunder Methods)

Permiten definir comportamientos para operadores o funciones internas.

```python
class Punto:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    # Representación en cadena (al usar print() o str())
    def __str__(self):
        return f"({self.x}, {self.y})"

    # Suma entre dos objetos Punto con el operador '+'
    def __add__(self, otro):
        return Punto(self.x + otro.x, self.y + otro.y)

pt1 = Punto(1, 2)
pt2 = Punto(3, 4)
print(pt1 + pt2)  # (4, 6)
```
