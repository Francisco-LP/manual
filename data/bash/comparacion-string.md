# OPERADORES DE COMPARACIÓN DE STRINGS en Bash

Los comparadores de string sirven  para evaluar y comparar cadenas de texto.

## Operadores

```bash
[ "$a" = "$b" ]    # igual
[ "$a" != "$b" ]   # distinto
[ "$a" < "$b" ]    # menor alfabéticamente (escapar con \<)
[ "$a" > "$b" ]    # mayor alfabéticamente (escapar con \>)
[ -z "$a" ]        # string vacío (zero)
[ -n "$a" ]        # string no vacío (non-zero)
```

## Con [[ ]] — forma moderna, preferida

```bash
[[ "$a" == "$b" ]]
[[ "$a" != "$b" ]]
[[ "$a" < "$b" ]]
[[ "$a" > "$b" ]]
[[ -z "$a" ]]
[[ -n "$a" ]]
```

## Ejemplos

```bash
nombre="Francisco"

if [[ -z "$nombre" ]]; then
    echo "nombre vacío"
else
    echo "nombre: $nombre"
fi

if [[ "$nombre" == "Francisco" ]]; then
    echo "coincide"
fi
```

## Comodines con [[ ]]

```bash
archivo="backup_2024.tar.gz"

if [[ "$archivo" == *.tar.gz ]]; then
    echo "es un tar.gz"
fi
```

## Nota

Usa siempre comillas en las variables: "$var"
Esto evita errores si la variable está vacía o tiene espacios.
