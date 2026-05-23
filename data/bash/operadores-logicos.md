# OPERADORES LÓGICOS en Bash

## && — AND — ejecutar si el anterior tuvo éxito

El segundo comando solo se ejecuta si el primero devuelve 0 (éxito).

```bash
mkdir directorio && cd directorio
comando1 && comando2 && comando3
```

```bash
# En condicional
if [ -f archivo ] && [ -r archivo ]; then
    echo "existe y es legible"
fi
```

## || — OR — ejecutar si el anterior falló

El segundo comando solo se ejecuta si el primero devuelve distinto de 0 (error).

```bash
cd /ruta || exit 1
comando || echo "falló"
```

```bash
# Valor por defecto
puerto=${1:-8080}
[[ -n "$puerto" ]] || puerto=8080
```

## ! — NOT — negar condición

```bash
if ! comando; then
    echo "el comando falló"
fi

if ! [ -f archivo ]; then
    echo "el archivo no existe"
fi

# Con [[ ]]
if [[ ! -d directorio ]]; then
    mkdir directorio
fi
```

## Combinar

```bash
[ -f archivo ] && [ -r archivo ] || echo "problema con el archivo"

# Verificar y actuar
systemctl is-active nginx &>/dev/null && echo "activo" || echo "inactivo"
```

## Uso en scripts — patrón común

```bash
# Salir si un comando falla
cd /ruta/segura || { echo "Error: ruta no encontrada"; exit 1; }

# Crear si no existe
[ -d /tmp/trabajo ] || mkdir /tmp/trabajo

# Verificar dependencia
command -v curl &>/dev/null || { echo "curl no instalado"; exit 1; }
```

## Código de salida — $?

```bash
comando
echo $?     # 0 = éxito, distinto de 0 = error
```

```bash
if [ $? -eq 0 ]; then
    echo "éxito"
fi

# Mejor forma — directo en if
if comando; then
    echo "éxito"
fi
```

## Prioridad

```bash
# && tiene mayor prioridad que ||
A && B || C
# se evalúa como: (A && B) || C
```
