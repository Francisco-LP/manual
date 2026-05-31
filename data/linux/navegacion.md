# NAVEGACIÓN DEL SISTEMA DE ARCHIVOS en Linux

## pwd — directorio actual

```bash
pwd
# /home/francisco/proyectos
```

## cd — cambiar directorio

```bash
cd /etc                  # ruta absoluta
cd documentos/           # ruta relativa
cd ..                    # subir un nivel
cd ../..                 # subir dos niveles
cd ~                     # ir al home
cd                       # ir al home (sin argumento)
cd -                     # volver al directorio anterior
cd /var/log              # ruta absoluta
```

## ls — listar contenido

```bash
ls                      # listar directorio actual
ls /etc                 # listar otro directorio
ls -l                   # formato largo (permisos, dueño, tamaño, fecha)
ls -a                   # mostrar archivos ocultos (empiezan con .)
ls -la                  # largo + ocultos
ls -lh                  # tamaños legibles (KB, MB, GB)
ls -lt                  # ordenar por fecha de modificación
ls -ltr                 # ordenar por fecha inverso
ls -R                   # recursivo
ls -d */                # solo directorios
```

### Interpretar ls -l

```
-rwxr-xr--  1  francisco  francisco  4096  may 21 14:30  archivo.sh
|           |  |          |          |     |             |
tipo+perms  |  dueño      grupo      tamaño fecha        nombre
            nlinks
```

Tipos: `-` archivo, `d` directorio, `l` enlace simbólico, `b` dispositivo bloque, `c` dispositivo carácter

## tree — árbol de directorios

```bash
tree                    # árbol del directorio actual
tree /etc               # árbol de otro directorio
tree -L 2               # máximo 2 niveles de profundidad
tree -a                 # incluir ocultos
tree -d                 # solo directorios
```

## Rutas especiales

```
.       directorio actual
..      directorio padre
~       home del usuario actual
~user   home de otro usuario
-       directorio anterior (solo con cd)
```

## Ejemplos prácticos

```bash
# Ver dónde estás y qué hay
pwd && ls -la

# Navegar y volver
cd /var/log
ls -lth | head -10      # logs más recientes
cd -                    # volver

# Ver estructura de un proyecto
tree -L 3 ~/proyectos/manual

# Buscar en qué directorio está un comando
which bash              # /usr/bin/bash
whereis nginx           # binario, fuente y man page
type ls                 # si es alias, función o binario
```
