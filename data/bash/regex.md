# EXPRESIONES REGULARES en Bash

## grep — buscar patrones en texto

```bash
grep "patron" archivo.txt
grep -i "patron" archivo.txt    # ignorar mayúsculas
grep -r "patron" directorio/    # recursivo
grep -n "patron" archivo.txt    # mostrar número de línea
grep -v "patron" archivo.txt    # invertir — líneas que NO coinciden
grep -c "patron" archivo.txt    # contar coincidencias
grep -l "patron" *.txt          # solo nombres de archivos
```

## Metacaracteres básicos (BRE)

```
.       cualquier carácter
*       cero o más del carácter anterior
^       inicio de línea
$       fin de línea
[]      conjunto de caracteres
[^]     negación de conjunto
\       escapar metacarácter
```

```bash
grep "^root" /etc/passwd         # líneas que empiezan con root
grep "bash$" /etc/passwd         # líneas que terminan con bash
grep "r..t" /etc/passwd          # r + 2 caracteres + t
grep "[0-9]" archivo.txt         # líneas con algún número
grep "^$" archivo.txt            # líneas vacías
```

## grep -E o egrep — expresiones extendidas (ERE)

```
+       uno o más
?       cero o uno
|       alternativa (or)
()      agrupación
{n}     exactamente n veces
{n,m}   entre n y m veces
```

```bash
grep -E "error|warning" log.txt         # error O warning
grep -E "^(root|fdx):" /etc/passwd      # root o fdx al inicio
grep -E "[0-9]{1,3}\.[0-9]{1,3}" archivo  # patrón IP simple
grep -E "https?://" archivo.txt         # http o https
```

## [[ =~ ]] — regex en condicionales

```bash
cadena="usuario123"

if [[ "$cadena" =~ ^[a-z]+[0-9]+$ ]]; then
    echo "coincide"
fi
```

Capturar grupos con BASH_REMATCH:

```bash
fecha="2024-05-21"

if [[ "$fecha" =~ ^([0-9]{4})-([0-9]{2})-([0-9]{2})$ ]]; then
    echo "Año:  ${BASH_REMATCH[1]}"
    echo "Mes:  ${BASH_REMATCH[2]}"
    echo "Día:  ${BASH_REMATCH[3]}"
fi
```

## Clases de caracteres

```bash
[[:alpha:]]   # letras
[[:digit:]]   # números
[[:alnum:]]   # letras y números
[[:space:]]   # espacios, tabs
[[:upper:]]   # mayúsculas
[[:lower:]]   # minúsculas
[[:punct:]]   # puntuación
```

```bash
grep "[[:digit:]]" archivo.txt
grep "^[[:upper:]]" archivo.txt   # líneas que empiezan con mayúscula
```

## Ejemplos prácticos

```bash
# Buscar IPs en un log
grep -E "([0-9]{1,3}\.){3}[0-9]{1,3}" access.log

# Buscar errores en logs
grep -E "ERROR|CRITICAL|FATAL" /var/log/syslog

# Validar email básico
if [[ "$email" =~ ^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}$ ]]; then
    echo "email válido"
fi

# Extraer números de un archivo
grep -oE "[0-9]+" archivo.txt    # -o muestra solo la coincidencia
```
