# WHILE en Python

Bucle condicional que se ejecuta mientras una condición sea verdadera (`True`).

## Sintaxis Básica

```python
contador = 0

while contador < 5:
    print(contador)
    contador += 1  # Es vital modificar la condición para evitar bucles infinitos
```

## Control de Bucles: `break` y `continue`

### `break`
Termina el bucle de inmediato.
```python
i = 1
while i < 10:
    if i == 5:
        break  # Sale del bucle cuando i es 5
    print(i)
    i += 1
# Imprime: 1, 2, 3, 4
```

### `continue`
Salta la iteración actual y pasa a evaluar la condición de nuevo.
```python
i = 0
while i < 6:
    i += 1
    if i == 3:
        continue  # Salta el print de 3
    print(i)
# Imprime: 1, 2, 4, 5, 6
```

## Bucle con Cláusula `else`

La cláusula `else` se ejecuta **únicamente** si el bucle termina de forma natural (cuando la condición se vuelve falsa), y **no** si es interrumpido por un `break`.

```python
intentos = 0
bloqueado = False

while intentos < 3:
    clave = input("Clave: ")
    if clave == "1234":
        print("Acceso concedido")
        break
    intentos += 1
else:
    # Se ejecuta solo si el bucle terminó sin break (3 intentos fallidos)
    print("Cuenta bloqueada. Demasiados intentos.")
```
