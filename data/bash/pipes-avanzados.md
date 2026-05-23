# PIPES AVANZADOS en Bash

## xargs — construir comandos desde stdin

Toma la salida de un comando y la pasa como argumentos a otro.

```bash
# Buscar archivos .log y borrarlos
find /tmp -name "*.log" | xargs rm

# Con -I para posicionar el argumento
find . -name "*.txt" | xargs -I {} cp {} /backup/

# Procesar en paralelo
cat lista.txt | xargs -P 4 -I {} proceso {}
#                        |
#                        4 procesos en paralelo
```

## Sustitución de proceso ( <() y >() )

Trata la salida de un comando como si fuera un archivo.

```bash
# Comparar salida de dos comandos
diff <(ls dir1/) <(ls dir2/)

# Ordenar y comparar
diff <(sort archivo1.txt) <(sort archivo2.txt)

# Pasar múltiples entradas
paste <(cut -d: -f1 /etc/passwd) <(cut -d: -f7 /etc/passwd)
```

## tee — duplicar salida

```bash
# Ver en pantalla Y guardar en archivo
comando | tee archivo.log

# Agregar sin sobreescribir
comando | tee -a archivo.log

# Enviar a múltiples archivos
comando | tee archivo1.log archivo2.log

# En medio de un pipe
cat datos.txt | tee intermedio.txt | sort | uniq
```

## Pipe con while read — procesar línea a línea

```bash
cat archivo.txt | while IFS= read -r linea; do
    echo "Procesando: $linea"
done
```

```bash
# Procesar CSV
while IFS=, read -r nombre edad ciudad; do
    echo "$nombre tiene $edad años y vive en $ciudad"
done < datos.csv
```

## Pipe nombrado (FIFO)

Permite comunicación entre procesos sin archivo temporal.

```bash
mkfifo /tmp/mipipe
productor > /tmp/mipipe &
consumidor < /tmp/mipipe
rm /tmp/mipipe
```

## Combinar varios pipes

```bash
# Top 5 IPs con más peticiones en un log
awk '{print $1}' access.log | sort | uniq -c | sort -rn | head -5

# Buscar procesos que más CPU usan
ps aux | sort -k3 -rn | head -10

# Contar extensiones de archivos en un directorio
find . -type f | sed 's/.*\.//' | sort | uniq -c | sort -rn
```

## Ejemplos prácticos

```bash
# Eliminar archivos más viejos de 30 días
find /var/log -name "*.log" -mtime +30 | xargs rm -f

# Reemplazar texto en múltiples archivos
grep -rl "texto_viejo" . | xargs sed -i 's/texto_viejo/texto_nuevo/g'

# Procesar lista de hosts en paralelo
cat hosts.txt | xargs -P 5 -I {} ping -c 1 {} &> /dev/null && echo "{} activo"
```
