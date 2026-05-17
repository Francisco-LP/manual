# FUNCIONES en Bash

Es un bloque de código reutilizable que agrupa una serie de comandos. Sirve para realizar tareas específicas dentro de un script

## Sintaxis

```bash
nombre_funcion() {
    # código
}
```

## Llamada

```bash
nombre_funcion
nombre_funcion arg1 arg2
```

## Con parámetros

Los argumentos se acceden con $1, $2, etc.

```bash
saludar() {
    echo "Hola, $1"
}

saludar "Francisco"
```

## Con return

return solo devuelve códigos de salida (0-255).
Para devolver un valor usa echo.

```bash
sumar() {
    echo $(( $1 + $2 ))
}

resultado=$(sumar 3 4)
echo $resultado   # 7
```

## Variables locales

```bash
mi_funcion() {
    local variable="solo existe aquí"
    echo $variable
}
```
