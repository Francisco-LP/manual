# ENLACES en Linux

## Tipos de enlaces

### Hard link — enlace duro

Apunta directamente al mismo inode (los datos reales del archivo).
Ambos nombres son el mismo archivo — no hay original ni copia.

```bash
ln archivo.txt enlace_duro.txt
```

Características:
- Mismo inode, mismo contenido
- Si borras el original, el enlace sigue funcionando
- No puede apuntar a directorios
- No puede cruzar sistemas de archivos distintos

### Soft link / Symlink — enlace simbólico

Apunta al nombre del archivo, no al inode.
Es como un acceso directo en Windows.

```bash
ln -s /ruta/original enlace_simbolico
ln -s /usr/local/bin/python3 /usr/local/bin/python
```

Características:
- Inode propio, apunta a otra ruta
- Si borras el original, el enlace queda roto
- Puede apuntar a directorios
- Puede cruzar sistemas de archivos
- Muestra la flecha en ls -l: `enlace -> /ruta/original`

## Crear enlaces

```bash
ln archivo.txt hard.txt              # hard link
ln -s /etc/nginx/nginx.conf nginx.conf   # symlink con ruta absoluta
ln -s ../config/app.conf app.conf        # symlink con ruta relativa
```

## Ver enlaces

```bash
ls -li archivo.txt hard.txt     # -i muestra el inode — serán iguales
ls -la directorio/              # los symlinks muestran la flecha
readlink enlace_simbolico       # ver a dónde apunta
readlink -f enlace              # ruta canónica completa
```

## Verificar si un enlace está roto

```bash
[ -L enlace ] && echo "es symlink"
[ -e enlace ] && echo "el destino existe"

# Encontrar symlinks rotos
find . -type l ! -e
```

## Casos de uso comunes

```bash
# Versiones de software
ln -s /opt/python3.12/bin/python3 /usr/local/bin/python3

# Configuración accesible desde múltiples rutas
ln -s /etc/nginx/sites-available/miapp /etc/nginx/sites-enabled/miapp

# Directorio de trabajo fijo
ln -s /mnt/datos/proyecto ~/proyecto
```

## Hard link vs Symlink

| | Hard link | Symlink |
|---|---|---|
| Cruza particiones | ❌ | ✅ |
| Apunta a directorios | ❌ | ✅ |
| Funciona si se borra original | ✅ | ❌ |
| Mismo inode | ✅ | ❌ |
| Visible en ls -l | no se distingue | muestra -> |
