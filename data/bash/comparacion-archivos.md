# OPERADORES DE COMPARACIÓN DE ARCHIVOS en Bash

Son operadores utilizados en los scripts para evaluar los atributos, permisos o el estado de uno o más archivos. Estos operadores permiten que un script tome decisiones condicionales. 

## Existencia y tipo

```bash
[ -e archivo ]   # existe (exist)
[ -f archivo ]   # es archivo regular (file)
[ -d archivo ]   # es directorio (directory)
[ -l archivo ]   # es enlace simbólico (link)
[ -p archivo ]   # es pipe
[ -S archivo ]   # es socket
```

## Permisos

```bash
[ -r archivo ]   # tiene permiso de lectura (read)
[ -w archivo ]   # tiene permiso de escritura (write)
[ -x archivo ]   # tiene permiso de ejecución (execute)
```

## Tamaño

```bash
[ -s archivo ]   # existe y no está vacío (size > 0)
```

## Comparar archivos

```bash
[ archivo1 -nt archivo2 ]   # archivo1 más nuevo (newer than)
[ archivo1 -ot archivo2 ]   # archivo1 más viejo (older than)
[ archivo1 -ef archivo2 ]   # mismo archivo (equal file, mismo inode)
```
