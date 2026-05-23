# VARIABLES DE ENTORNO en Bash

Variables disponibles para el proceso y todos sus procesos hijos.

## Ver variables de entorno

```bash
env             # todas las variables de entorno
printenv        # igual que env
printenv PATH   # valor de una variable específica
echo $HOME      # acceder directamente
```

## Variables más importantes

```bash
$HOME       # directorio del usuario (/home/francisco)
$USER       # nombre del usuario actual
$PATH       # rutas donde se buscan ejecutables
$SHELL      # shell actual (/bin/bash)
$PWD        # directorio actual
$OLDPWD     # directorio anterior
$HOSTNAME   # nombre del host
$TERM       # tipo de terminal
$EDITOR     # editor por defecto
$LANG       # idioma del sistema
$TZ         # zona horaria
$PS1        # prompt de la terminal
```

## Definir variable de entorno

```bash
export MI_VAR="valor"
export JAVA_HOME="/usr/lib/jvm/java-17"
```

Sin `export` la variable solo existe en el shell actual, no en procesos hijos.

## PATH — agregar rutas

```bash
export PATH="$PATH:/nueva/ruta"
export PATH="/nueva/ruta:$PATH"    # agregar al inicio (mayor prioridad)
```

## Persistir variables

Para que persistan entre sesiones, agregar a:

```bash
~/.bashrc           # sesiones interactivas no login
~/.bash_profile     # sesiones login
~/.profile          # compatible con otros shells
/etc/environment    # todas las sesiones del sistema (requiere root)
/etc/profile.d/     # scripts de entorno del sistema
```

Ejemplo en `~/.bashrc`:
```bash
export EDITOR="vim"
export PATH="$PATH:$HOME/.local/bin"
export JAVA_HOME="/usr/lib/jvm/java-17"
```

## Aplicar cambios sin reiniciar

```bash
source ~/.bashrc
. ~/.bashrc       # equivalente
```

## Variable en un solo comando

```bash
VAR="valor" comando    # solo disponible para ese comando
DEBUG=1 ./script.sh
```

## unset — eliminar variable

```bash
unset MI_VAR
```

## Ejemplos prácticos

```bash
# Agregar scripts propios al PATH
export PATH="$PATH:$HOME/scripts"

# Configurar editor por defecto
export EDITOR="vim"
export VISUAL="vim"

# Zona horaria para un comando
TZ="America/Santiago" date

# Ver si una variable está definida
[[ -z "${MI_VAR:-}" ]] && echo "no definida"
```
