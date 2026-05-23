# FIND en Bash

Busca archivos y directorios en el sistema de archivos.

## Sintaxis

```bash
find [ruta] [criterios] [acción]
```

## Por nombre

```bash
find . -name "archivo.txt"        # nombre exacto
find . -name "*.log"              # comodín
find . -iname "*.LOG"             # ignorar mayúsculas
find / -name "passwd"             # buscar en todo el sistema
```

## Por tipo

```bash
find . -type f    # archivos regulares
find . -type d    # directorios
find . -type l    # enlaces simbólicos
```

## Por tamaño

```bash
find . -size +100M     # mayor de 100MB
find . -size -10k      # menor de 10KB
find . -size 50M       # exactamente 50MB
```

Unidades: c (bytes), k (KB), M (MB), G (GB)

## Por tiempo

```bash
find . -mtime -7       # modificado en los últimos 7 días
find . -mtime +30      # modificado hace más de 30 días
find . -atime -1       # accedido en las últimas 24 horas
find . -newer archivo  # más reciente que archivo
```

## Por permisos

```bash
find . -perm 644       # permisos exactos
find . -perm -u+x      # ejecutable por el dueño
find / -perm -4000     # archivos SUID
```

## Por dueño

```bash
find . -user francisco    # archivos del usuario
find . -group www-data    # archivos del grupo
```

## Acciones

```bash
find . -name "*.log" -delete              # eliminar
find . -name "*.sh" -exec chmod +x {} \; # ejecutar comando
find . -name "*.txt" -exec cp {} /backup/ \;
find . -type f -print                     # imprimir ruta (por defecto)
```

## Combinar criterios

```bash
find . -name "*.log" -size +10M           # AND implícito
find . -name "*.log" -o -name "*.txt"     # OR
find . -not -name "*.log"                 # NOT
find . ! -name "*.log"                    # NOT alternativo
```

## Ejemplos prácticos

```bash
# Archivos grandes que ocupan espacio
find / -type f -size +500M 2>/dev/null

# Logs viejos para limpiar
find /var/log -name "*.log" -mtime +30 -delete

# Scripts sin permiso de ejecución
find . -name "*.sh" -not -perm -u+x

# Archivos modificados hoy
find . -type f -mtime 0

# Buscar y comprimir logs
find /var/log -name "*.log" -mtime +7 -exec gzip {} \;
```
