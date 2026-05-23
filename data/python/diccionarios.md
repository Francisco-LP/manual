# DICCIONARIOS en Python

Colecciones desordenadas (u ordenadas por inserción desde Python 3.7), mutables y mapeadas mediante clave-valor.

## Creación y Acceso

```python
# Creación
usuario = {
    "nombre": "Ana",
    "edad": 25,
    "ciudad": "Madrid"
}

# Acceso directo (puede lanzar KeyError si la clave no existe)
print(usuario["nombre"])  # "Ana"

# Acceso seguro con .get()
print(usuario.get("email"))        # None
print(usuario.get("email", "N/A")) # "N/A" (valor por defecto)
```

## Modificación y Adición

```python
# Modificar o crear clave
usuario["edad"] = 26
usuario["profesion"] = "Ingeniera"  # Se crea la clave si no existía

# Fusionar diccionarios (método update)
usuario.update({"ciudad": "Barcelona", "activo": True})
```

## Eliminación de Elementos

```python
# Usando del
del usuario["ciudad"]

# Usando .pop() (retorna el valor eliminado)
edad = usuario.pop("edad")

# Usando .popitem() (elimina e identifica el último par insertado)
clave, valor = usuario.popitem()

# Vaciar el diccionario por completo
usuario.clear()
```

## Iteración y Métodos Útiles

```python
info = {"nombre": "Luis", "rol": "Admin", "pais": "Chile"}

# Iterar solo sobre claves
for clave in info:
    print(clave)

# Iterar sobre claves
for k in info.keys():
    print(k)

# Iterar sobre valores
for v in info.values():
    print(v)

# Iterar sobre pares clave-valor
for k, v in info.items():
    print(f"Clave: {k}, Valor: {v}")
```

## Diccionarios por Comprensión

```python
# Generar diccionario a partir de una lista
nombres = ["Ana", "Juan", "Pedro"]
longitudes = {nombre: len(nombre) for nombre in nombres}
# Resultado: {'Ana': 3, 'Juan': 4, 'Pedro': 5}
```
