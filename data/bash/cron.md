# CRON en Bash

Programador de tareas que ejecuta comandos en horarios definidos.

## Editar crontab

```bash
crontab -e      # editar crontab del usuario actual
crontab -l      # listar tareas actuales
crontab -r      # eliminar crontab
crontab -u usuario -e   # editar crontab de otro usuario (root)
```

## Formato de una entrada

```
*  *  *  *  *  comando
|  |  |  |  |
|  |  |  |  día de la semana (0-7, 0 y 7 = domingo)
|  |  |  mes (1-12)
|  |  día del mes (1-31)
|  hora (0-23)
minuto (0-59)
```

## Ejemplos de horarios

```bash
# Cada minuto
* * * * * comando

# Cada hora (en el minuto 0)
0 * * * * comando

# Todos los días a las 2:30 AM
30 2 * * * comando

# Todos los lunes a las 8:00 AM
0 8 * * 1 comando

# El primer día de cada mes a medianoche
0 0 1 * * comando

# Cada 15 minutos
*/15 * * * * comando

# A las 8 AM y 6 PM todos los días
0 8,18 * * * comando

# De lunes a viernes a las 9 AM
0 9 * * 1-5 comando
```

## Atajos especiales

```bash
@reboot     # al iniciar el sistema
@hourly     # cada hora (0 * * * *)
@daily      # cada día a medianoche (0 0 * * *)
@weekly     # cada semana (0 0 * * 0)
@monthly    # cada mes (0 0 1 * *)
@yearly     # cada año (0 0 1 1 *)
```

## Redirigir salida

```bash
# Silenciar salida
0 2 * * * comando > /dev/null 2>&1

# Guardar log
0 2 * * * /ruta/script.sh >> /var/log/mitarea.log 2>&1
```

## Archivos del sistema

```bash
/etc/crontab          # crontab del sistema (incluye campo usuario)
/etc/cron.d/          # archivos de cron adicionales
/etc/cron.daily/      # scripts que corren diariamente
/etc/cron.weekly/     # scripts semanales
/etc/cron.monthly/    # scripts mensuales
```

## Ejemplos prácticos

```bash
# Backup diario a las 3 AM
0 3 * * * /scripts/backup.sh >> /var/log/backup.log 2>&1

# Limpiar logs viejos cada domingo
0 1 * * 0 find /var/log -name "*.log" -mtime +30 -delete

# Reiniciar servicio si está caído (cada 5 minutos)
*/5 * * * * systemctl is-active nginx || systemctl start nginx

# Reporte de uso de disco diario
0 8 * * * df -h | mail -s "Disco $(hostname)" admin@empresa.com
```

## Variables en crontab

```bash
SHELL=/bin/bash
PATH=/usr/local/sbin:/usr/local/bin:/sbin:/bin:/usr/sbin:/usr/bin
MAILTO=admin@empresa.com

0 2 * * * /scripts/backup.sh
```
