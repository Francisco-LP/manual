# GREP en Bash

Busca patrones de texto en archivos o stdin.

## Sintaxis

```bash
grep "patrón" archivo
grep "patrón" archivo1 archivo2
grep "patrón" *.txt
```

## Opciones principales

```bash
grep -i "patrón" archivo      # ignorar mayúsculas/minúsculas
grep -r "patrón" directorio/  # recursivo
grep -n "patrón" archivo      # mostrar número de línea
grep -v "patrón" archivo      # invertir — líneas que NO coinciden
grep -c "patrón" archivo      # contar coincidencias
grep -l "patrón" *.txt        # solo nombres de archivos con coincidencia
grep -L "patrón" *.txt        # archivos sin coincidencia
grep -w "patrón" archivo      # solo palabras completas
grep -x "patrón" archivo      # solo líneas completas
grep -o "patrón" archivo      # mostrar solo la parte que coincide
grep -A 3 "patrón" archivo    # 3 líneas después de la coincidencia
grep -B 3 "patrón" archivo    # 3 líneas antes
grep -C 3 "patrón" archivo    # 3 líneas antes y después
```

## grep -E — expresiones extendidas

```bash
grep -E "error|warning" log.txt       # OR
grep -E "^(root|fdx):" /etc/passwd    # grupos
grep -E "[0-9]{2,4}" archivo          # repetición
```

## grep -F — búsqueda literal (sin regex)

```bash
grep -F "texto.literal" archivo    # el . no es metacarácter
```

## Ejemplos prácticos

```bash
# Buscar errores en logs
grep -i "error" /var/log/syslog
grep -E "ERROR|CRITICAL|FATAL" app.log

# Ver usuarios con bash
grep "bash$" /etc/passwd

# Buscar en código fuente
grep -rn "función_buscada" src/

# Excluir líneas comentadas
grep -v "^#" config.conf | grep -v "^$"

# Contar ocurrencias
grep -c "failed" /var/log/auth.log

# Ver contexto de un error
grep -C 5 "Segmentation fault" app.log

# IPs únicas en un log
grep -oE "([0-9]{1,3}\.){3}[0-9]{1,3}" access.log | sort -u
```
