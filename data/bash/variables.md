# VARIABLES en Bash

Las variables son espacios de almacenamiento temporal que guardan datos (texto o números) para ser utilizados, modificados o consultados a lo largo de un script o sesión de terminal.

## Declaración y asignación

Sin espacios alrededor del =

```bash
nombre="Francisco"
edad=25
```

## Acceso

```bash
echo $nombre
echo ${nombre}   # forma explícita, preferida en strings complejos
```

## Variables de entorno

```bash
export MI_VAR="valor"   # disponible para procesos hijos
echo $HOME
echo $USER
echo $PATH
```

## Variables especiales

```bash
$0    # nombre del script
$1    # primer argumento
$#    # número de argumentos
$@    # todos los argumentos
$?    # código de salida del último comando
$$    # PID del proceso actual
```

## Variables de solo lectura

```bash
readonly CONSTANTE="valor"
```

## Eliminar variable

```bash
unset nombre
```

## Valor por defecto

```bash
echo ${variable:-"valor_default"}   # usa default si no existe
echo ${variable:="valor_default"}   # asigna default si no existe
```
