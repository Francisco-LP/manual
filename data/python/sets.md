# SETS (Conjuntos) en Python

Colecciones desordenadas, mutables, **no indexadas** y que **no permiten duplicados**.

## Creación y Sintaxis

```python
# Creación con llaves
frutas = {"manzana", "banana", "uva"}

# Creación desde otras colecciones
numeros = set([1, 2, 2, 3, 4, 4])  # {1, 2, 3, 4} (duplicados eliminados)

# IMPORTANTE: Para crear un set vacío debes usar set() y no {}
set_vacio = set()
dict_vacio = {}  # Esto crea un diccionario
```

## Operaciones Básicas

```python
colores = {"rojo", "azul"}

# Agregar elementos
colores.add("verde")
colores.add("rojo")       # No tiene efecto, ya existe

# Eliminar elementos
colores.remove("azul")    # Lanza KeyError si no existe
colores.discard("azul")   # Remueve de forma segura (no da error si no existe)

# Vaciar conjunto
colores.clear()
```

## Operaciones de Conjuntos Matemáticos

Sean los conjuntos:
```python
a = {1, 2, 3, 4}
b = {3, 4, 5, 6}
```

### Unión (`|` o `union()`)
Une todos los elementos sin duplicados.
```python
a | b  # {1, 2, 3, 4, 5, 6}
```

### Intersección (`&` o `intersection()`)
Elementos presentes en ambos conjuntos.
```python
a & b  # {3, 4}
```

### Diferencia (`-` o `difference()`)
Elementos en `a` que no están en `b`.
```python
a - b  # {1, 2}
```

### Diferencia Simétrica (`^` o `symmetric_difference()`)
Elementos en `a` o en `b`, pero no en ambos.
```python
a ^ b  # {1, 2, 5, 6}
```

### Subconjuntos y Superconjuntos
```python
c = {1, 2}
c.issubset(a)    # True (c está contenido en a)
a.issuperset(c)  # True (a contiene a c)
```
