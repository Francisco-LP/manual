# ARRAYS en Bash

es una estructura de datos que permite almacenar múltiples valores bajo un único nombre de variable. 

## Declaración

```bash
frutas=("manzana" "pera" "uva")
```

## Acceso por índice (empieza en 0)

```bash
echo ${frutas[0]}   # manzana
echo ${frutas[1]}   # pera
```

## Todos los elementos

```bash
echo ${frutas[@]}
```

## Número de elementos

```bash
echo ${#frutas[@]}
```

## Agregar elemento

```bash
frutas+=("naranja")
```

## Eliminar elemento

```bash
unset frutas[1]
```

## Iterar

```bash
for fruta in "${frutas[@]}"; do
    echo $fruta
done
```

## Array asociativo (clave-valor)

```bash
declare -A persona
persona[nombre]="Francisco"
persona[edad]=25

echo ${persona[nombre]}
```
