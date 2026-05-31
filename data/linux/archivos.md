# GESTIÓN DE ARCHIVOS en Linux

## touch — crear archivo o actualizar fecha

```bash
touch archivo.txt               # crear vacío
touch archivo1 archivo2         # varios a la vez
touch -t 202405210800 archivo   # establecer fecha específica
```

## mkdir — crear directorios

```bash
mkdir directorio
mkdir -p ruta/completa/nueva    # crear padres si no existen
mkdir -p proyecto/{src,tests,docs}   # múltiples subdirectorios
```

## cp — copiar

```bash
cp origen destino
cp archivo.txt /tmp/
cp archivo.txt copia.txt
cp -r directorio/ destino/      # copiar directorio recursivo
cp -p archivo destino           # preservar permisos y fechas
cp -i archivo destino           # preguntar antes de sobreescribir
cp -u origen destino            # copiar solo si origen es más nuevo
```

## mv — mover o renombrar

```bash
mv archivo.txt /tmp/            # mover
mv nombre_viejo.txt nuevo.txt   # renombrar
mv directorio/ /nueva/ruta/     # mover directorio
mv -i origen destino            # preguntar antes de sobreescribir
```

## rm — eliminar

```bash
rm archivo.txt
rm -i archivo.txt               # preguntar antes
rm -f archivo.txt               # forzar sin preguntar
rm -r directorio/               # eliminar directorio recursivo
rm -rf directorio/              # forzar recursivo (cuidado)
```

## rmdir — eliminar directorio vacío

```bash
rmdir directorio_vacio
rmdir -p ruta/completa/vacia    # eliminar padres vacíos también
```

## Ver contenido de archivos

```bash
cat archivo.txt                 # mostrar todo
cat -n archivo.txt              # con números de línea
less archivo.txt                # paginado (q para salir)
more archivo.txt                # paginado simple
head archivo.txt                # primeras 10 líneas
head -n 20 archivo.txt          # primeras 20 líneas
tail archivo.txt                # últimas 10 líneas
tail -n 20 archivo.txt          # últimas 20 líneas
tail -f archivo.log             # seguir en tiempo real
```

## file — tipo de archivo

```bash
file archivo.txt        # ASCII text
file imagen.png         # PNG image data
file /bin/bash          # ELF 64-bit executable
```

## stat — información detallada

```bash
stat archivo.txt
# muestra: tamaño, bloques, permisos, dueño, fechas de acceso/modificación/cambio
```

## wc — contar

```bash
wc archivo.txt          # líneas, palabras, bytes
wc -l archivo.txt       # solo líneas
wc -w archivo.txt       # solo palabras
wc -c archivo.txt       # solo bytes
```

## Ejemplos prácticos

```bash
# Crear estructura de proyecto
mkdir -p proyecto/{src,tests,docs,scripts}
touch proyecto/README.md proyecto/src/main.sh

# Backup antes de editar
cp config.conf config.conf.bak

# Mover logs viejos
mv /var/log/app.log /var/log/app.log.$(date +%Y%m%d)

# Ver últimas líneas de log en tiempo real
tail -f /var/log/syslog

# Contar líneas de código
find . -name "*.sh" | xargs wc -l
```
