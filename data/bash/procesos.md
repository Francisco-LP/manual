# PROCESOS en Bash

## Ver procesos

```bash
ps aux              # todos los procesos del sistema
ps aux | grep nginx # filtrar por nombre
ps -ef              # formato alternativo con PPID
pgrep nginx         # solo el PID por nombre
```

### Columnas de ps aux

```
USER   PID  %CPU  %MEM  VSZ  RSS  TTY  STAT  START  TIME  COMMAND
```

## top / htop

```bash
top     # monitor en tiempo real
htop    # versión mejorada (puede no estar instalado)
```

## Terminar procesos

```bash
kill PID            # envía SIGTERM (cierre ordenado)
kill -9 PID         # envía SIGKILL (cierre forzado)
kill -15 PID        # SIGTERM explícito
killall nginx       # matar todos los procesos por nombre
pkill nginx         # igual pero más flexible
```

## Procesos en segundo plano

```bash
comando &           # ejecutar en background
jobs                # listar procesos en background
fg                  # traer al foreground
fg %2               # traer el job número 2
bg                  # continuar en background un proceso pausado
```

## Ctrl+Z / Ctrl+C

```bash
Ctrl+C    # terminar proceso en foreground (SIGINT)
Ctrl+Z    # pausar proceso y enviarlo a background (SIGSTOP)
```

## nohup — proceso que sobrevive al cierre de sesión

```bash
nohup ./script.sh &
nohup ./script.sh > salida.log 2>&1 &
```

## nice / renice — prioridad de CPU

```bash
nice -n 10 comando        # iniciar con prioridad baja (10)
nice -n -10 comando       # prioridad alta (requiere root)
renice 10 -p PID          # cambiar prioridad de proceso existente
```

Rango: -20 (mayor prioridad) a 19 (menor prioridad)

## Ejemplos prácticos

```bash
# Ver qué proceso usa el puerto 80
ss -tlnp | grep :80

# Matar proceso por nombre
pkill -f "python script.py"

# Ejecutar tarea larga en background y guardar log
nohup ./backup.sh > backup.log 2>&1 &
echo "PID: $!"    # $! es el PID del último proceso en background

# Esperar a que termine un proceso
wait PID
```
