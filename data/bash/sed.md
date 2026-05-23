# SED en Bash

Editor de streams — procesa texto línea por línea aplicando comandos.

## Sintaxis

```bash
sed 'comando' archivo
sed 'comando' archivo > nuevo_archivo
comando | sed 'comando'
```

## Sustitución — s/buscar/reemplazar/

```bash
sed 's/hola/adios/' archivo       # primera ocurrencia por línea
sed 's/hola/adios/g' archivo      # todas las ocurrencias (global)
sed 's/hola/adios/i' archivo      # ignorar mayúsculas
sed 's/hola/adios/2' archivo      # solo la segunda ocurrencia
```

## Editar el archivo directamente con -i

```bash
sed -i 's/hola/adios/g' archivo
sed -i.bak 's/hola/adios/g' archivo   # crea backup .bak antes
```

## Delimitador alternativo

Útil cuando el patrón contiene /

```bash
sed 's|/usr/local|/opt|g' archivo
sed 's#/etc/nginx#/etc/apache2#g' archivo
```

## Filtrar líneas

```bash
sed -n '5p' archivo           # imprimir solo línea 5
sed -n '5,10p' archivo        # líneas 5 a 10
sed -n '/patrón/p' archivo    # líneas que coinciden con patrón
sed '5d' archivo              # eliminar línea 5
sed '/patrón/d' archivo       # eliminar líneas con patrón
sed '/^#/d' archivo           # eliminar comentarios
sed '/^$/d' archivo           # eliminar líneas vacías
```

## Insertar y agregar

```bash
sed '3i\línea nueva' archivo    # insertar antes de línea 3
sed '3a\línea nueva' archivo    # agregar después de línea 3
sed '1i\#!/bin/bash' script     # agregar shebang al inicio
```

## Múltiples comandos con -e

```bash
sed -e 's/hola/adios/g' -e '/^#/d' archivo
```

## Ejemplos prácticos

```bash
# Cambiar IP en config
sed -i 's/192.168.1.1/10.0.0.1/g' config.conf

# Eliminar líneas en blanco y comentarios
sed '/^#/d; /^$/d' archivo.conf

# Extraer bloque entre dos patrones
sed -n '/INICIO/,/FIN/p' archivo

# Agregar texto al final de cada línea
sed 's/$/ # comentario/' archivo

# Numerar líneas
sed = archivo | sed 'N; s/\n/\t/'

# Eliminar espacios al inicio y fin
sed 's/^[[:space:]]*//; s/[[:space:]]*$//' archivo
```
