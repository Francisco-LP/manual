# AWK en Bash

Herramienta para procesar texto estructurado en columnas.

## Sintaxis

```bash
awk 'programa' archivo
awk -F'delimitador' 'programa' archivo
comando | awk 'programa'
```

## Variables automáticas

```
$0      línea completa
$1      campo 1
$2      campo 2
$NF     último campo
NR      número de línea actual
NF      número de campos en la línea actual
FS      separador de campos (por defecto espacio)
OFS     separador de salida
```

## Imprimir columnas

```bash
awk '{print $1}' archivo          # primera columna
awk '{print $1, $3}' archivo      # columnas 1 y 3
awk '{print $NF}' archivo         # última columna
awk -F: '{print $1}' /etc/passwd  # separador :
```

## Filtrar líneas

```bash
awk '/patrón/ {print}' archivo           # líneas con patrón
awk '$3 > 100 {print}' archivo           # campo 3 mayor que 100
awk '$1 == "root" {print}' /etc/passwd   # campo 1 igual a root
awk 'NR==5' archivo                      # solo línea 5
awk 'NR>=5 && NR<=10' archivo            # líneas 5 a 10
```

## BEGIN y END

```bash
awk 'BEGIN {print "Inicio"} {print} END {print "Fin"}' archivo
```

## Calcular sumas

```bash
awk '{suma += $1} END {print suma}' numeros.txt
awk '{suma += $3} END {print "Total:", suma}' datos.txt
```

## Formatear salida con printf

```bash
awk '{printf "%-10s %5d\n", $1, $2}' archivo
awk -F: '{printf "Usuario: %-15s Shell: %s\n", $1, $7}' /etc/passwd
```

## Variables personalizadas

```bash
awk -v umbral=100 '$3 > umbral {print $1, $3}' archivo
```

## Ejemplos prácticos

```bash
# Uso de CPU por proceso
ps aux | awk 'NR>1 {print $3, $11}' | sort -rn | head -5

# Sumar tamaños de archivos
ls -l | awk '{suma += $5} END {print "Total:", suma, "bytes"}'

# Extraer usuarios y shells
awk -F: '{print $1, $7}' /etc/passwd

# Contar líneas no vacías
awk 'NF > 0 {count++} END {print count}' archivo

# Estadísticas de un campo
awk '{sum+=$1; count++} END {print "Media:", sum/count}' numeros.txt

# Procesar CSV
awk -F, 'NR>1 {print $1, $2}' datos.csv   # saltar cabecera
```
