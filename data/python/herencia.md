# HERENCIA en Python

Concepto de Programación Orientada a Objetos que permite a una clase nueva (hija) adquirir las propiedades y métodos de otra clase existente (padre).

## Sintaxis Básica de Herencia

```python
# Clase Padre (Superclase)
class Vehiculo:
    def __init__(self, marca, modelo):
        self.marca = marca
        self.modelo = modelo

    def describir(self):
        return f"Vehículo: {self.marca} {self.modelo}"

# Clase Hija (Subclase)
class Coche(Vehiculo):
    # La clase Coche hereda todos los métodos y atributos de Vehiculo
    pass

mi_coche = Coche("Toyota", "Corolla")
print(mi_coche.describir())  # "Vehículo: Toyota Corolla"
```

## Uso de `super()` y Constructor `__init__`

Para extender o modificar el comportamiento del constructor padre, llamamos a `super().__init__()` al inicio de la subclase.

```python
class CocheElectrico(Vehiculo):
    def __init__(self, marca, modelo, capacidad_bateria):
        # Llama al constructor de la superclase (Vehiculo)
        super().__init__(marca, modelo)
        # Agrega atributos nuevos propios de CocheElectrico
        self.capacidad_bateria = capacidad_bateria

    # Sobrescribir (override) método
    def describir(self):
        # Podemos usar el comportamiento padre y extenderlo
        descripcion_padre = super().describir()
        return f"{descripcion_padre} (Batería: {self.capacidad_bateria} kWh)"

tesla = CocheElectrico("Tesla", "Model 3", 75)
print(tesla.describir())  # "Vehículo: Tesla Model 3 (Batería: 75 kWh)"
```

## Herencia Múltiple

Python admite la herencia de más de una clase simultáneamente.

```python
class Volador:
    def volar(self):
        return "Volando por el cielo"

class Nadador:
    def nadar(self):
        return "Nadando en el agua"

# Hereda de ambas clases
class Pato(Volador, Nadador):
    pass

lucas = Pato()
print(lucas.volar())  # "Volando por el cielo"
print(lucas.nadar())  # "Nadando en el agua"
```

## Orden de Resolución de Métodos (MRO)

En herencia múltiple, Python define el orden de llamada a métodos idénticos mediante el algoritmo C3. Puedes verificar el orden con `Clase.mro()`.

```python
print(Pato.mro())
# [<class '__main__.Pato'>, <class '__main__.Volador'>, <class '__main__.Nadador'>, <class 'object'>]
```
