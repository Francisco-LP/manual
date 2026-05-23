# CUT en Bash

Extrae columnas o caracteres de texto.

## Por columnas con delimitador — -d y -f

```bash
cut -d: -f1 /etc/passwd          # campo 1, separador :
cut -d: -f1,7 /etc/passwd        # campos 1 y 7
cut -d: -f1-3 /etc/passwd        # campos 1 al 3
cut -d, -f2 datos.csv            # campo 2 de un CSV
```

## Por posición de carácter — -c

```bash
cut -c1 archivo          # primer carácter de cada línea
cut -c1-5 archivo        # caracteres 1 al 5
cut -c1,3,5 archivo      # caracteres 1, 3 y 5
```

## Ejemplos prácticos

```bash
# Extraer usuarios del sistema
cut -d: -f1 /etc/passwd

# Extraer IPs de un log
cut -d' ' -f1 access.log

# Primeras 10 letras de cada línea
cut -c1-10 archivo.txt
```

---

# TR en Bash

Traduce, reemplaza o elimina caracteres.

## Sintaxis

```bash
tr 'origen' 'destino' < archivo
echo "texto" | tr 'origen' 'destino'
```

## Reemplazar caracteres

```bash
echo "hola mundo" | tr 'a-z' 'A-Z'    # minúsculas a mayúsculas
echo "HOLA MUNDO" | tr 'A-Z' 'a-z'    # mayúsculas a minúsculas
echo "hola:mundo" | tr ':' ' '         # reemplazar : por espacio
```

## Eliminar caracteres — -d

```bash
echo "h o l a" | tr -d ' '       # eliminar espacios
echo "abc123" | tr -d '0-9'      # eliminar números
echo "texto" | tr -d '\n'        # eliminar saltos de línea
```

## Comprimir repetidos — -s

```bash
echo "hola   mundo" | tr -s ' '    # múltiples espacios a uno
```

## Clases

```bash
tr '[:lower:]' '[:upper:]'    # minúsculas a mayúsculas
tr -d '[:digit:]'             # eliminar números
tr -d '[:punct:]'             # eliminar puntuación
```

---

# SORT en Bash

Ordena líneas de texto.

## Básico

```bash
sort archivo.txt              # orden alfabético
sort -r archivo.txt           # orden inverso
sort -n numeros.txt           # orden numérico
sort -rn numeros.txt          # numérico inverso
sort -u archivo.txt           # eliminar duplicados
```

## Por columna — -k

```bash
sort -k2 archivo              # ordenar por columna 2
sort -k2 -n archivo           # columna 2 numérico
sort -k2 -rn archivo          # columna 2 numérico inverso
sort -t: -k3 -n /etc/passwd   # separador : columna 3
```

## Ejemplos prácticos

```bash
# Ordenar IPs numéricamente
sort -t. -k1,1n -k2,2n -k3,3n -k4,4n ips.txt

# Top procesos por CPU
ps aux | sort -k3 -rn | head -10
```

---

# UNIQ en Bash

Elimina o cuenta líneas duplicadas consecutivas.
Siempre usar después de sort para que funcione correctamente.

## Básico

```bash
sort archivo | uniq             # eliminar duplicados
sort archivo | uniq -c          # contar ocurrencias
sort archivo | uniq -d          # mostrar solo duplicados
sort archivo | uniq -u          # mostrar solo únicos
```

## Ejemplos prácticos

```bash
# IPs más frecuentes en un log
awk '{print $1}' access.log | sort | uniq -c | sort -rn | head -10

# Palabras únicas en un archivo
tr ' ' '\n' < texto.txt | sort | uniq

# Contar extensiones de archivos
find . -type f | sed 's/.*\.//' | sort | uniq -c | sort -rn
```
