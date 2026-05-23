# ARITMÉTICA en Bash

## (( )) — evaluación aritmética

```bash
(( resultado = 5 + 3 ))
echo $resultado    # 8

(( a = 10, b = 3 ))
(( suma = a + b ))
```

## $(( )) — sustitución aritmética

Devuelve el resultado como valor.

```bash
echo $(( 5 + 3 ))           # 8
resultado=$(( 10 * 4 ))
echo $resultado              # 40
```

## Operadores

```bash
$(( a + b ))    # suma
$(( a - b ))    # resta
$(( a * b ))    # multiplicación
$(( a / b ))    # división entera
$(( a % b ))    # módulo (resto)
$(( a ** b ))   # potencia
```

## Incremento y decremento

```bash
(( i++ ))    # post-incremento
(( i-- ))    # post-decremento
(( ++i ))    # pre-incremento
(( --i ))    # pre-decremento
(( i += 5 ))
(( i -= 3 ))
(( i *= 2 ))
(( i /= 4 ))
```

## Comparación dentro de (( ))

Devuelve 0 (verdadero) o 1 (falso) como código de salida.

```bash
(( 5 > 3 )) && echo "verdadero"
(( a == b )) || echo "son distintos"

if (( a > b )); then
    echo "$a es mayor"
fi
```

## Operadores bit a bit

```bash
$(( a & b ))    # AND
$(( a | b ))    # OR
$(( a ^ b ))    # XOR
$(( ~a ))       # NOT
$(( a << 2 ))   # shift izquierda
$(( a >> 2 ))   # shift derecha
```

## Punto flotante con bc

Bash no soporta decimales — usa bc para eso.

```bash
echo "scale=2; 10 / 3" | bc           # 3.33
echo "scale=4; sqrt(2)" | bc -l       # 1.4142
echo "scale=2; 3.14 * 2^2" | bc -l   # 12.56

# Guardar resultado
resultado=$(echo "scale=2; 100 / 7" | bc)
echo $resultado
```

## let

Forma alternativa de evaluar expresiones (menos usada).

```bash
let "a = 5 + 3"
let "a++"
```

## Ejemplos prácticos

```bash
# Porcentaje de uso de disco
total=100
usado=73
libre=$(( total - usado ))
echo "Libre: $libre%"

# Contador en bucle
for (( i=1; i<=10; i++ )); do
    echo $i
done

# Verificar si es par
numero=42
if (( numero % 2 == 0 )); then
    echo "par"
fi
```
