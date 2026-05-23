# TUPLAS en Python

Colecciones ordenadas e **inmutables** (no se pueden modificar una vez creadas). Permiten duplicados.

## Creación y Sintaxis

```python
# Creación con paréntesis
mi_tupla = (1, 2, "tres", True)

# Paréntesis opcionales (empaquetado)
otra_tupla = 4, 5, 6

# Tupla de un solo elemento (crucial añadir la coma al final)
tupla_un_elemento = (42,)
no_es_tupla = (42)  # Esto es simplemente un entero
```

## Acceso e Inmutabilidad

```python
coordenadas = (10.0, 20.0, 30.0)

# Acceso idéntico a las listas
print(coordenadas[0])   # 10.0
print(coordenadas[-1])  # 30.0

# Intento de modificación (Lanza TypeError)
# coordenadas[0] = 15.0  # ERROR
```

## Desempaquetado (Unpacking)

Extrae los elementos de la tupla directamente en variables.

```python
punto = (4, 9)
x, y = punto
print(x)  # 4
print(y)  # 9

# Desempaquetado extendido usando '*'
numeros = (1, 2, 3, 4, 5)
a, *medio, e = numeros
print(a)      # 1
print(medio)  # [2, 3, 4]  (se convierte en lista)
print(e)      # 5
```

## Métodos Disponibles

Dado que son inmutables, las tuplas tienen muy pocos métodos incorporados:

```python
valores = (1, 2, 3, 2, 4, 2)

# Contar ocurrencias
print(valores.count(2))  # 3

# Buscar primer índice
print(valores.index(3))  # 2
```

## ¿Cuándo usar tuplas en lugar de listas?

1. **Rendimiento**: Son ligeramente más rápidas y ocupan menos memoria.
2. **Seguridad**: Para datos constantes que no deben ser alterados accidentalmente.
3. **Claves de Diccionarios**: Al ser inmutables (y hashables), pueden usarse como claves en diccionarios, a diferencia de las listas.
