# FECHA Y HORA en Bash

## date — comando principal

```bash
date                          # fecha y hora actual completa
date +"%Y-%m-%d"              # 2024-05-21
date +"%H:%M:%S"              # 14:35:02
date +"%Y-%m-%d %H:%M:%S"    # 2024-05-21 14:35:02
date +"%d/%m/%Y"              # 21/05/2024
```

## Formatos más usados

```
%Y    año 4 dígitos (2024)
%m    mes 2 dígitos (05)
%d    día 2 dígitos (21)
%H    hora 24h (14)
%M    minutos (35)
%S    segundos (02)
%s    timestamp Unix (segundos desde 1970-01-01)
%A    día de la semana (Tuesday)
%B    mes completo (May)
%j    día del año (141)
%u    día de la semana número (1=lunes, 7=domingo)
```

## Guardar fecha en variable

```bash
hoy=$(date +"%Y-%m-%d")
ahora=$(date +"%Y-%m-%d_%H-%M-%S")
timestamp=$(date +%s)

echo $hoy        # 2024-05-21
echo $ahora      # 2024-05-21_14-35-02
echo $timestamp  # 1716297302
```

## Fecha relativa

```bash
date -d "yesterday" +"%Y-%m-%d"
date -d "tomorrow" +"%Y-%m-%d"
date -d "1 week ago" +"%Y-%m-%d"
date -d "next monday" +"%Y-%m-%d"
date -d "+3 days" +"%Y-%m-%d"
date -d "-1 month" +"%Y-%m-%d"
```

## Calcular diferencia entre fechas

```bash
fecha1=$(date -d "2024-01-01" +%s)
fecha2=$(date -d "2024-05-21" +%s)
diferencia=$(( (fecha2 - fecha1) / 86400 ))   # 86400 = segundos en un día
echo "Diferencia: $diferencia días"
```

## Medir tiempo de ejecución

```bash
inicio=$(date +%s)

# ... proceso ...
sleep 2

fin=$(date +%s)
echo "Tiempo: $(( fin - inicio )) segundos"
```

## Ejemplos prácticos

```bash
# Nombre de archivo con fecha
backup="backup_$(date +"%Y-%m-%d").tar.gz"
tar -czf "$backup" /etc/

# Log con timestamp
echo "[$(date +"%Y-%m-%d %H:%M:%S")] Proceso iniciado" >> app.log

# Verificar si un archivo es de hoy
hoy=$(date +"%Y-%m-%d")
archivo_fecha=$(date -r archivo.txt +"%Y-%m-%d")
if [[ "$archivo_fecha" == "$hoy" ]]; then
    echo "modificado hoy"
fi
```
