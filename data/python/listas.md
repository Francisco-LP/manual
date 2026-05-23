# LISTAS en Python

Estructuras de datos ordenadas, mutables y que permiten elementos duplicados.

## Creación y Acceso

```python
# Creación
lista = [1, 2, 3, "cuatro", True]
vacia = []

# Indexación (0-indexed)
lista[0]      # 1
lista[-1]     # True (último elemento)
lista[-2]     # "cuatro" (penúltimo elemento)
```

## Slicing (Rebanado)

`lista[inicio:fin:paso]` (el índice de `fin` es exclusivo).

```python
numeros = [0, 1, 2, 3, 4, 5]

numeros[1:4]    # [1, 2, 3]
numeros[:3]     # [0, 1, 2] (desde el inicio)
numeros[3:]     # [3, 4, 5] (hasta el final)
numeros[::2]    # [0, 2, 4] (de dos en dos)
numeros[::-1]   # [5, 4, 3, 2, 1, 0] (invertir lista)
```

## Operaciones y Métodos Comunes

### Agregar Elementos

```python
frutas = ["manzana", "banana"]

frutas.append("naranja")     # Agrega al final -> ["manzana", "banana", "naranja"]
frutas.insert(1, "uva")      # Inserta en índice -> ["manzana", "uva", "banana", "naranja"]
frutas.extend(["pera", "piña"]) # Une otra lista -> ["manzana", "uva", "banana", "naranja", "pera", "piña"]
```

### Eliminar Elementos

```python
# Por valor (remueve la primera ocurrencia)
frutas.remove("banana")

# Por índice (y retorna el valor)
removido = frutas.pop(2)     # Remueve índice 2
ultimo = frutas.pop()        # Remueve el último elemento

# Por operador del
del frutas[0]                # Elimina índice 0
```

### Búsqueda e Información

```python
numeros = [10, 20, 30, 20]

len(numeros)        # 4 (longitud)
20 in numeros       # True (verificar existencia)
numeros.index(20)   # 1 (primer índice del valor 20)
numeros.count(20)   # 2 (número de ocurrencias del valor 20)
```

### Ordenamiento

```python
valores = [3, 1, 4, 1, 5]

# Modificando la lista original
valores.sort()              # Orden ascendente [1, 1, 3, 4, 5]
valores.sort(reverse=True)  # Orden descendente [5, 4, 3, 1, 1]

# Creando una nueva lista ordenada (sin modificar la original)
ordenados = sorted(valores)
```
