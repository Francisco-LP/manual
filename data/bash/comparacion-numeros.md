# OPERADORES DE COMPARACIÓN NUMÉRICA en Bash

Son operadores utilizados para evaluar relaciones matemáticos. 

Se usan dentro de [ ] o (( )).

## Operadores con [ ]

```bash
[ $a -eq $b ]   # igual (equal)
[ $a -ne $b ]   # distinto (not equal)
[ $a -gt $b ]   # mayor que (greater than)
[ $a -ge $b ]   # mayor o igual (greater or equal)
[ $a -lt $b ]   # menor que (less than)
[ $a -le $b ]   # menor o igual (less or equal)
```

## Operadores con (( )) — estilo C

```bash
(( a == b ))
(( a != b ))
(( a > b ))
(( a >= b ))
(( a < b ))
(( a <= b ))
```

## Ejemplos

```bash
a=10
b=20

if [ $a -lt $b ]; then
    echo "$a es menor que $b"
fi

if (( a != b )); then
    echo "son distintos"
fi
```

## Nota

Dentro de [ ] usa -eq, -gt, etc.
Dentro de (( )) usa ==, >, etc. como en C.
