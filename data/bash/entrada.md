# ENTRADA DEL USUARIO en Bash

## read — leer desde teclado

```bash
read variable
echo "Escribiste: $variable"
```

## Opciones de read

```bash
read -p "Nombre: " nombre          # mostrar prompt
read -s -p "Contraseña: " pass     # -s silencia la entrada
read -t 10 -p "Respuesta: " resp   # -t timeout en segundos
read -n 1 -p "¿Continuar? [s/n]: " op  # -n leer N caracteres
read -r linea                      # -r no interpretar backslashes
```

## Leer múltiples variables

```bash
read -p "Nombre y apellido: " nombre apellido
echo "Nombre: $nombre"
echo "Apellido: $apellido"
```

## Leer array

```bash
read -a colores -p "Colores: "
echo "Primero: ${colores[0]}"
echo "Todos: ${colores[@]}"
```

## Leer con timeout

```bash
if read -t 5 -p "Responde en 5 segundos: " respuesta; then
    echo "Respondiste: $respuesta"
else
    echo "Tiempo agotado"
fi
```

## Menú interactivo

```bash
#!/bin/bash

while true; do
    echo ""
    echo "=== MENÚ ==="
    echo "1) Opción uno"
    echo "2) Opción dos"
    echo "3) Salir"
    read -p "Elige: " opcion

    case $opcion in
        1) echo "Elegiste uno" ;;
        2) echo "Elegiste dos" ;;
        3) echo "Saliendo..."; break ;;
        *) echo "Opción inválida" ;;
    esac
done
```

## Confirmar acción

```bash
read -p "¿Estás seguro? [s/N]: " -n 1 -r
echo
if [[ $REPLY =~ ^[Ss]$ ]]; then
    echo "Confirmado"
fi
```

## Leer archivo línea a línea

```bash
while IFS= read -r linea; do
    echo "$linea"
done < archivo.txt
```

## Leer desde stdin o archivo

```bash
#!/bin/bash

# Acepta tanto pipe como archivo como argumento
if [[ -n "$1" ]]; then
    input="$1"
else
    input="/dev/stdin"
fi

while IFS= read -r linea; do
    echo ">> $linea"
done < "$input"
```

```bash
echo "hola" | ./script.sh
./script.sh archivo.txt
```

## select — menú automático

```bash
opciones=("Bash" "Python" "C++" "Salir")

select opcion in "${opciones[@]}"; do
    case $opcion in
        "Salir") break ;;
        *) echo "Elegiste: $opcion" ;;
    esac
done
```
