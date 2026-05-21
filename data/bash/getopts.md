# GETOPTS en Bash

Permite parsear flags y opciones en scripts, como los comandos reales de Linux.

```bash
./script.sh -u francisco -p 8080 -v
```

## Sintaxis básica

```bash
while getopts "opciones" variable; do
    case $variable in
        flag) # código ;;
    esac
done
```

## Ejemplo simple

```bash
#!/bin/bash

while getopts "u:p:v" opt; do
    case $opt in
        u) usuario="$OPTARG" ;;
        p) puerto="$OPTARG" ;;
        v) verbose=true ;;
        ?) echo "Opción inválida"; exit 1 ;;
    esac
done

echo "Usuario: $usuario"
echo "Puerto: $puerto"
```

Uso:
```bash
./script.sh -u francisco -p 8080 -v
```

## La cadena de opciones

```bash
getopts "u:p:v"
#         |  | |
#         |  | flag sin argumento (-v)
#         |  flag con argumento (-p valor)
#         flag con argumento (-u valor)
```

El `:` después de una letra significa que esa opción requiere un argumento.
El argumento se almacena en `$OPTARG`.

## Manejo de errores

```bash
#!/bin/bash

# : al inicio silencia los errores automáticos de getopts
while getopts ":u:p:h" opt; do
    case $opt in
        u) usuario="$OPTARG" ;;
        p) puerto="$OPTARG" ;;
        h) 
            echo "Uso: $0 -u usuario -p puerto [-h]"
            exit 0
            ;;
        :)
            echo "La opción -$OPTARG requiere un argumento"
            exit 1
            ;;
        \?)
            echo "Opción desconocida: -$OPTARG"
            exit 1
            ;;
    esac
done
```

## OPTIND — índice del siguiente argumento

Después de getopts, `$OPTIND` apunta al primer argumento posicional restante.

```bash
#!/bin/bash

while getopts "u:v" opt; do
    case $opt in
        u) usuario="$OPTARG" ;;
        v) verbose=true ;;
    esac
done

shift $(( OPTIND - 1 ))   # descartar los flags ya procesados
echo "Argumentos restantes: $@"
```

```bash
./script.sh -u francisco archivo1 archivo2
# Argumentos restantes: archivo1 archivo2
```

## Ejemplo completo — script de backup

```bash
#!/bin/bash
set -euo pipefail

uso() {
    echo "Uso: $0 -s origen -d destino [-v] [-h]"
    echo "  -s  directorio origen"
    echo "  -d  directorio destino"
    echo "  -v  modo verbose"
    echo "  -h  esta ayuda"
    exit 0
}

verbose=false

while getopts ":s:d:vh" opt; do
    case $opt in
        s) origen="$OPTARG" ;;
        d) destino="$OPTARG" ;;
        v) verbose=true ;;
        h) uso ;;
        :) echo "Error: -$OPTARG requiere argumento"; exit 1 ;;
        \?) echo "Error: opción desconocida -$OPTARG"; exit 1 ;;
    esac
done

[[ -z "${origen:-}" ]] && { echo "Error: falta -s origen"; exit 1; }
[[ -z "${destino:-}" ]] && { echo "Error: falta -d destino"; exit 1; }

$verbose && echo "Copiando $origen → $destino"
cp -r "$origen" "$destino"
echo "Backup completado"
```
