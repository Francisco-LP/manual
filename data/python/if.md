# IF en Python

Estructura de control condicional básica. La sangría (indentación) es obligatoria y define los bloques de código.

## Sintaxis Básica

```python
edad = 18

if edad < 18:
    print("Menor de edad")
elif edad == 18:
    print("Acabas de cumplir la mayoría de edad")
else:
    print("Mayor de edad")
```

## Operadores de Comparación

- `==` : Igual a
- `!=` : Diferente de
- `>`  : Mayor que
- `<`  : Menor que
- `>=` : Mayor o igual que
- `<=` : Menor o igual que

## Operadores Lógicos

- `and` : Retorna `True` si ambas condiciones son verdaderas.
- `or`  : Retorna `True` si al menos una condición es verdadera.
- `not` : Invierte el valor booleano.

```python
tengo_dinero = True
tengo_tiempo = True

if tengo_dinero and tengo_tiempo:
    print("Ir de viaje")

if not tengo_dinero:
    print("Ahorrar")
```

## Operadores de Identidad y Membresía

### `is` / `is not`
Verifica si dos variables apuntan al mismo objeto en memoria.
```python
a = [1, 2, 3]
b = a
c = [1, 2, 3]

a is b      # True
a is c      # False (tienen el mismo contenido pero son objetos diferentes)
a == c      # True (valores iguales)
```

### `in` / `not in`
Verifica si un elemento se encuentra dentro de una colección (lista, tupla, diccionario, set, string).
```python
frutas = ["uva", "fresa", "pera"]

if "fresa" in frutas:
    print("Hay fresa")
```

## Operador Ternario (Expresión Condicional)

Sintaxis simplificada para asignar valores en una sola línea.

```python
# valor_si_verdadero if condicion else valor_si_falso
estado = "Activo" if activo else "Inactivo"
```
