# OPERADORES en Python

Sintaxis de los operadores fundamentales en Python.

## Operadores Aritméticos

| Operación | Operador | Ejemplo | Resultado |
|---|---|---|---|
| Suma | `+` | `5 + 3` | `8` |
| Resta | `-` | `5 - 3` | `2` |
| Multiplicación | `*` | `5 * 3` | `15` |
| División | `/` | `5 / 2` | `2.5` (Siempre float) |
| División Entera | `//` | `5 // 2` | `2` (Trunca el decimal) |
| Módulo (Residuo) | `%` | `5 % 2` | `1` |
| Exponente (Potencia)| `**` | `2 ** 3` | `8` (2 elevado a 3) |

## Operadores de Asignación Compuesta

```python
x = 10
x += 5  # Equivalente a: x = x + 5 (15)
x -= 2  # Equivalente a: x = x - 2 (13)
x *= 2  # Equivalente a: x = x * 2 (26)
x /= 2  # Equivalente a: x = x / 2 (13.0)
```

## Operadores de Comparación

Comparan valores y retornan un booleano (`True` o `False`).

- `==` : Igual a (compara valores, no referencias de memoria).
- `!=` : Diferente de.
- `>`  : Mayor que.
- `<`  : Menor que.
- `>=` : Mayor o igual que.
- `<=` : Menor o igual que.

```python
# Comparaciones encadenadas (Válido en Python)
edad = 25
if 18 <= edad < 30:
    print("Joven adulto")
```

## Operadores Lógicos

- `and` : Retorna `True` si ambas expresiones a la izquierda y derecha son verdaderas.
- `or`  : Retorna `True` si al menos una de las expresiones es verdadera.
- `not` : Invierte el valor booleano.

```python
activo = True
tiene_permiso = False

print(activo and tiene_permiso) # False
print(activo or tiene_permiso)  # True
print(not activo)               # False
```
