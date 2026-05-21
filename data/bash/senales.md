# SEÑALES en Bash

Las señales son notificaciones que el sistema envía a los procesos.

## Señales más comunes

```
SIGHUP   1    Terminal cerrada o recarga de configuración
SIGINT   2    Interrupción (Ctrl+C)
SIGQUIT  3    Salida con core dump (Ctrl+\)
SIGKILL  9    Terminación forzada — no se puede capturar ni ignorar
SIGTERM  15   Terminación ordenada (kill por defecto)
SIGSTOP  19   Pausa — no se puede capturar ni ignorar
SIGCONT  18   Continuar proceso pausado
SIGUSR1  10   Señal personalizada para el usuario
SIGUSR2  12   Señal personalizada para el usuario
```

## Enviar señales

```bash
kill -SIGTERM PID
kill -15 PID       # equivalente
kill -SIGKILL PID
kill -9 PID        # equivalente
```

## trap — capturar señales en un script

Permite ejecutar código cuando el script recibe una señal.

### Sintaxis

```bash
trap 'comando' SEÑAL
```

### Limpieza al salir

```bash
#!/bin/bash

trap 'echo "Limpiando..."; rm -f /tmp/archivo_temporal; exit' SIGINT SIGTERM

echo "Trabajando..."
sleep 30
```

Si el usuario presiona Ctrl+C, se ejecuta el trap antes de salir.

### EXIT — siempre se ejecuta al terminar

```bash
#!/bin/bash

trap 'rm -f /tmp/mi_lock' EXIT

touch /tmp/mi_lock
# el lock se borra siempre, aunque el script falle
```

### Ignorar una señal

```bash
trap '' SIGINT    # ignorar Ctrl+C
```

### Restaurar comportamiento por defecto

```bash
trap - SIGINT     # restaurar SIGINT
```

### Recargar configuración con SIGHUP

```bash
trap 'echo "Recargando config..."; source config.sh' SIGHUP
```

## Ver señales disponibles

```bash
kill -l
trap -l
```

## Ejemplos prácticos

```bash
#!/bin/bash

# Script con limpieza garantizada
TMPFILE=$(mktemp)

trap 'rm -f $TMPFILE; echo "Saliendo limpio"' EXIT SIGINT SIGTERM

echo "Usando $TMPFILE"
# ... trabajo ...
```

```bash
# Recargar nginx sin reiniciarlo
kill -SIGHUP $(pgrep nginx)
```
