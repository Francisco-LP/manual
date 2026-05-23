# DATACLASSES en Python

Las `dataclasses` (introducidas en **Python 3.7**) proporcionan un decorador `@dataclass` y funciones para generar automáticamente métodos especiales como `__init__`, `__repr__`, `__eq__` y otros en clases que almacenan datos.

## Ejemplo de Comparación

### Clase Tradicional para Almacenar Datos:
```python
class UsuarioComun:
    def __init__(self, nombre, email, activo):
        self.nombre = nombre
        self.email = email
        self.activo = activo

    def __repr__(self):
        return f"UsuarioComun(nombre={self.nombre}, email={self.email}, activo={self.activo})"

u = UsuarioComun("Ana", "ana@mail.com", True)
print(u)
```

### Usando Dataclass (Equivalente mucho más limpio):
```python
from dataclasses import dataclass

@dataclass
class UsuarioData:
    nombre: str
    email: str
    activo: bool

u_data = UsuarioData("Ana", "ana@mail.com", True)
print(u_data)  # Genera __repr__ automáticamente -> UsuarioData(nombre='Ana', email='ana@mail.com', activo=True)
```

## Características Incorporadas

El decorador `@dataclass` genera automáticamente:
- **`__init__`**: Acepta los atributos tipados en el mismo orden de declaración.
- **`__repr__`**: Representación bonita y legible en cadena.
- **`__eq__`**: Comparación por valores de atributos entre objetos.

```python
u1 = UsuarioData("Ana", "ana@mail.com", True)
u2 = UsuarioData("Ana", "ana@mail.com", True)
print(u1 == u2)  # True (compara campos de datos automáticamente)
```

## Valores por Defecto

Puedes asignar valores predeterminados directamente a los atributos.

```python
@dataclass
class Producto:
    nombre: str
    precio: float
    stock: int = 0  # Valor por defecto
```

## Clases Inmutables (`frozen=True`)

Puedes forzar que las instancias de la dataclass sean de "solo lectura" (inmutables) añadiendo la bandera `frozen=True`.

```python
@dataclass(frozen=True)
class Coordenada:
    x: float
    y: float

punto = Coordenada(10.5, 20.0)
# punto.x = 15.0  # ERROR: dataclasses.FrozenInstanceError
```
