# WHILE en Bash

Bucle que se ejecuta mientras una condición sea verdadera.

## Sintaxis

```bash
while [ condición ]; do
    # código
done
```

## Ejemplo contador

```bash
i=0
while [ $i -lt 5 ]; do
    echo $i
    (( i++ ))
done
```

## Leer archivo línea por línea

```bash
while IFS= read -r linea; do
    echo "$linea"
done < archivo.txt
```

## Bucle infinito

```bash
while true; do
    echo "ejecutando..."
    sleep 1
done
```

## Con break

```bash
while true; do
    read -p "Entrada: " input
    [ "$input" = "salir" ] && break
done
```
