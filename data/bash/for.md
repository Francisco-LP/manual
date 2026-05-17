# FOR en Bash

for es una estructura de control que permite ejecutar un bloque de código repetidamente

Bucle que itera sobre una lista de elementos.

## Sintaxis básica

```bash
for variable in lista; do
    # código
done
```

## Iterar rango numérico

```bash
for i in {1..5}; do
    echo $i
done
```

## Iterar con paso

```bash
for i in {0..10..2}; do
    echo $i
done
```

## Estilo C

```bash
for (( i=0; i<5; i++ )); do
    echo $i
done
```

## Iterar archivos

```bash
for archivo in /etc/*.conf; do
    echo $archivo
done
```

## Iterar array

```bash
frutas=("manzana" "pera" "uva")
for fruta in "${frutas[@]}"; do
    echo $fruta
done
```
