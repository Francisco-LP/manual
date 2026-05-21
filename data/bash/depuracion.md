# DEPURACIÓN en Bash

## set -x — modo trace

Muestra cada comando antes de ejecutarlo. El más útil para depurar.

```bash
set -x    # activar
set +x    # desactivar
```

```bash
#!/bin/bash
set -x

nombre="Francisco"
echo "Hola $nombre"
```

Salida:
```
+ nombre=Francisco
+ echo 'Hola Francisco'
Hola Francisco
```

## set -e — salir en error

El script termina si cualquier comando devuelve código de salida distinto de 0.

```bash
set -e
```

```bash
#!/bin/bash
set -e

cp archivo.txt destino/    # si falla, el script para aquí
echo "esto no se ejecuta si cp falló"
```

## set -u — error en variables no definidas

Trata las variables no definidas como error en lugar de string vacío.

```bash
set -u

echo $VARIABLE_NO_DEFINIDA   # error: unbound variable
```

## set -o pipefail — error en pipes

Por defecto, un pipe solo falla si el último comando falla.
Con pipefail, falla si cualquier parte del pipe falla.

```bash
set -o pipefail

cat archivo_inexistente | sort   # ahora sí devuelve error
```

## Combinación recomendada para scripts de producción

```bash
#!/bin/bash
set -euo pipefail
```

## Ejecutar script en modo debug desde fuera

```bash
bash -x script.sh
```

## Ver código de salida

```bash
comando
echo $?    # 0 = éxito, distinto de 0 = error
```

## Depurar sección específica

```bash
#!/bin/bash

echo "esto corre normal"

set -x
# solo esta sección se muestra en trace
cp origen destino
mv archivo otro
set +x

echo "esto corre normal de nuevo"
```

## trap ERR — capturar errores

```bash
#!/bin/bash
set -e

trap 'echo "Error en línea $LINENO"' ERR

cp archivo_inexistente /tmp/
echo "esto no se ejecuta"
```

## Imprimir número de línea

```bash
echo "Debug línea $LINENO: valor=$variable"
```

## Buenas prácticas

```bash
#!/bin/bash
set -euo pipefail

# Siempre verificar dependencias al inicio
command -v curl &> /dev/null || { echo "curl no instalado"; exit 1; }

# Usar variables con nombres claros
readonly CONFIG_FILE="/etc/miapp/config.conf"

# Verificar archivos antes de usarlos
[[ -f "$CONFIG_FILE" ]] || { echo "Config no encontrada"; exit 1; }
```
