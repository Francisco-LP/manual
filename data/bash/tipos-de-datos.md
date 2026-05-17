# TIPOS DE DATOS en Bash

Bash no tiene tipos estrictos — todo es string por defecto.
El tipo depende del contexto en que se usa la variable.

## String (por defecto)

```bash
nombre="Francisco"
mensaje="Hola mundo"
```

## Entero

Bash no tiene tipo int nativo, pero puedes declarar con declare -i
para que la variable solo acepte enteros.

```bash
declare -i numero=42
numero=10+5     # se evalúa: numero=15
numero="hola"   # se asigna 0
```

## Aritmética

Para operar números usa (( )) o $(()):

```bash
a=10
b=3

echo $(( a + b ))   # 13
echo $(( a - b ))   # 7
echo $(( a * b ))   # 30
echo $(( a / b ))   # 3  (división entera)
echo $(( a % b ))   # 1  (módulo)
echo $(( a ** b ))  # 1000 (potencia)
```

## Punto flotante

Bash no soporta decimales nativamente. Usa bc:

```bash
echo "scale=2; 10 / 3" | bc   # 3.33
echo "scale=4; sqrt(2)" | bc -l
```

## Array

```bash
declare -a lista=("uno" "dos" "tres")
```

## Array asociativo

```bash
declare -A mapa
mapa["clave"]="valor"
```

## Solo lectura

```bash
declare -r CONSTANTE="valor"
```

## Exportada (variable de entorno)

```bash
declare -x MI_VAR="valor"
# equivalente a:
export MI_VAR="valor"
```

## Ver tipo de una variable

```bash
declare -p nombre   # muestra atributos de la variable
```
