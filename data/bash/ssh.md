# SSH en Bash

Protocolo para conexión remota segura.

## Conectar

```bash
ssh usuario@host
ssh usuario@192.168.1.10
ssh -p 2222 usuario@host        # puerto alternativo
ssh -i ~/.ssh/clave usuario@host # clave privada específica
```

## Ejecutar comando remoto

```bash
ssh usuario@host "ls -la /var/log"
ssh usuario@host "systemctl status nginx"
ssh usuario@host "df -h"
```

## Copiar archivos — scp

```bash
scp archivo.txt usuario@host:/ruta/destino/
scp usuario@host:/ruta/archivo.txt .
scp -r directorio/ usuario@host:/ruta/
scp -P 2222 archivo.txt usuario@host:/ruta/   # puerto alternativo
```

## rsync — sincronización eficiente

```bash
rsync -av origen/ usuario@host:/destino/
rsync -av usuario@host:/origen/ destino/
rsync -av --delete origen/ destino/    # eliminar archivos borrados
rsync -avz origen/ usuario@host:/destino/   # comprimir
```

## Generar par de claves

```bash
ssh-keygen -t ed25519 -C "mi@email.com"
ssh-keygen -t rsa -b 4096
```

Genera:
- `~/.ssh/id_ed25519` — clave privada (nunca compartir)
- `~/.ssh/id_ed25519.pub` — clave pública

## Copiar clave pública al servidor

```bash
ssh-copy-id usuario@host
ssh-copy-id -i ~/.ssh/id_ed25519.pub usuario@host
```

## ~/.ssh/config — simplificar conexiones

```
Host miservidor
    HostName 192.168.1.10
    User francisco
    Port 2222
    IdentityFile ~/.ssh/id_ed25519
```

```bash
ssh miservidor    # usa la configuración definida
```

## Túnel SSH

```bash
# Reenvío de puerto local
ssh -L 8080:localhost:80 usuario@host
# Acceder a host:80 a través de localhost:8080

# Túnel inverso
ssh -R 9090:localhost:3000 usuario@host
```

## Ejemplos prácticos

```bash
# Backup remoto con rsync
rsync -avz --delete /datos/ usuario@backup:/backup/datos/

# Ejecutar script local en servidor remoto
ssh usuario@host 'bash -s' < script_local.sh

# Montar sistema de archivos remoto (sshfs)
sshfs usuario@host:/ruta /mnt/remoto

# Verificar conectividad antes de operar
ssh -q -o BatchMode=yes -o ConnectTimeout=5 usuario@host exit && echo "conectado"
```
