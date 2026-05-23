# COLOR en Bash

Los colores en terminal se logran con códigos de escape ANSI.

## Estructura

```bash
echo -e "\e[CODIGO]texto\e[0m"
#              |              |
#              color          reset
```

`\e[0m` al final resetea el color — sin esto el color se aplica a todo lo siguiente.

## Colores de texto

```bash
echo -e "\e[30m Negro   \e[0m"
echo -e "\e[31m Rojo    \e[0m"
echo -e "\e[32m Verde   \e[0m"
echo -e "\e[33m Amarillo\e[0m"
echo -e "\e[34m Azul    \e[0m"
echo -e "\e[35m Magenta \e[0m"
echo -e "\e[36m Cyan    \e[0m"
echo -e "\e[37m Blanco  \e[0m"
```

## Colores brillantes

```bash
echo -e "\e[91m Rojo brillante  \e[0m"
echo -e "\e[92m Verde brillante \e[0m"
echo -e "\e[93m Amarillo brillante \e[0m"
echo -e "\e[94m Azul brillante  \e[0m"
```

## Fondo

```bash
echo -e "\e[41m Fondo rojo   \e[0m"
echo -e "\e[42m Fondo verde  \e[0m"
echo -e "\e[43m Fondo amarillo \e[0m"
echo -e "\e[44m Fondo azul   \e[0m"
```

## Estilos

```bash
echo -e "\e[1m Negrita    \e[0m"
echo -e "\e[2m Tenue      \e[0m"
echo -e "\e[4m Subrayado  \e[0m"
echo -e "\e[7m Invertido  \e[0m"
```

## Combinar

```bash
echo -e "\e[1;32m Verde negrita \e[0m"
echo -e "\e[1;31m Rojo negrita  \e[0m"
echo -e "\e[4;34m Azul subrayado \e[0m"
```

## Buena práctica — definir variables

```bash
ROJO="\e[31m"
VERDE="\e[32m"
AMARILLO="\e[33m"
AZUL="\e[34m"
NEGRITA="\e[1m"
RESET="\e[0m"

echo -e "${VERDE}OK${RESET} Servicio iniciado"
echo -e "${ROJO}ERROR${RESET} Archivo no encontrado"
echo -e "${AMARILLO}AVISO${RESET} Espacio en disco bajo"
```

## Ejemplo — script con output formateado

```bash
#!/bin/bash

VERDE="\e[32m"
ROJO="\e[31m"
AMARILLO="\e[33m"
RESET="\e[0m"

ok()    { echo -e "${VERDE}[OK]${RESET}    $1"; }
error() { echo -e "${ROJO}[ERROR]${RESET} $1"; }
aviso() { echo -e "${AMARILLO}[AVISO]${RESET} $1"; }

ok "Conexión establecida"
aviso "Certificado expira en 7 días"
error "No se pudo escribir en /var/log"
```

## Verificar soporte de color

```bash
if [ -t 1 ] && [ "$(tput colors 2>/dev/null)" -ge 8 ]; then
    VERDE="\e[32m"
    RESET="\e[0m"
else
    VERDE=""
    RESET=""
fi
```
