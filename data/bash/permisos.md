# PERMISOS en Bash

## Estructura de permisos

```
-rwxr-xr--  1  usuario  grupo  tamaño  fecha  archivo
 ^^^  ^^^  ^^^
 |    |    |
 |    |    otros (others)
 |    grupo
 dueño (user)
```

Cada bloque tiene 3 bits: r (lectura=4), w (escritura=2), x (ejecución=1)

## chmod — cambiar permisos

### Notación octal

```bash
chmod 755 archivo   # rwxr-xr-x
chmod 644 archivo   # rw-r--r--
chmod 600 archivo   # rw-------
chmod 777 archivo   # rwxrwxrwx
```

### Notación simbólica

```bash
chmod u+x archivo   # agregar ejecución al dueño
chmod g-w archivo   # quitar escritura al grupo
chmod o=r archivo   # dejar solo lectura a otros
chmod a+x archivo   # agregar ejecución a todos (a = all)
chmod u+x,g-w archivo  # múltiples cambios
```

### Recursivo

```bash
chmod -R 755 directorio/
```

## chown — cambiar dueño

```bash
chown usuario archivo
chown usuario:grupo archivo
chown -R usuario:grupo directorio/
```

## chgrp — cambiar grupo

```bash
chgrp grupo archivo
chgrp -R grupo directorio/
```

## umask — permisos por defecto

Define qué permisos se restan al crear archivos nuevos.

```bash
umask          # ver umask actual
umask 022      # archivos: 644, directorios: 755
umask 027      # archivos: 640, directorios: 750
```

## Permisos especiales

```bash
chmod u+s archivo   # SUID — se ejecuta como el dueño
chmod g+s dir/      # SGID — archivos heredan el grupo
chmod +t dir/       # Sticky bit — solo el dueño puede borrar sus archivos
```

```bash
# Sticky bit típico en /tmp
ls -ld /tmp
# drwxrwxrwt  — la t al final es el sticky bit
```

## Ver permisos

```bash
ls -l archivo
stat archivo
```

## Ejemplos prácticos

```bash
# Script ejecutable solo por el dueño
chmod 700 script.sh

# Archivo de configuración privado
chmod 600 ~/.ssh/id_rsa

# Directorio compartido por grupo
chmod 770 /srv/proyecto

# Hacer ejecutable rápido
chmod +x script.sh
```
