# ESTRUCTURA DE ARCHIVOS en Linux

Linux sigue el estándar FHS (Filesystem Hierarchy Standard).
Todo parte de / (raíz) — no hay letras de unidad como en Windows.

## Directorios principales

```
/
├── bin       binarios esenciales del sistema (ls, cp, mv, bash)
├── sbin      binarios de administración (fdisk, mount, reboot)
├── boot      archivos de arranque (kernel, GRUB, initramfs)
├── dev       dispositivos del sistema (discos, terminales, null)
├── etc       configuración del sistema
├── home      directorios personales de usuarios (/home/francisco)
├── lib       librerías compartidas esenciales
├── lib64     librerías de 64 bits
├── media     montaje automático de medios (USB, CD)
├── mnt       montaje manual temporal
├── opt       software opcional de terceros
├── proc      sistema de archivos virtual — info del kernel y procesos
├── root      directorio home del usuario root
├── run       datos de runtime desde el arranque
├── srv       datos de servicios (web, ftp)
├── sys       sistema de archivos virtual — info de hardware
├── tmp       archivos temporales (se borra al reiniciar)
├── usr       programas y datos de usuario
└── var       datos variables (logs, bases de datos, colas)
```

## /etc — configuración

```
/etc/passwd         usuarios del sistema
/etc/shadow         contraseñas cifradas
/etc/group          grupos
/etc/hostname       nombre del host
/etc/hosts          resolución local de nombres
/etc/resolv.conf    configuración DNS
/etc/fstab          sistemas de archivos a montar al arrancar
/etc/crontab        tareas programadas del sistema
/etc/ssh/           configuración SSH
/etc/systemd/       configuración de systemd
```

## /usr — programas de usuario

```
/usr/bin        comandos de usuario (python, git, vim)
/usr/sbin       comandos de administración no esenciales
/usr/lib        librerías
/usr/local/     software instalado manualmente (bin, lib, share)
/usr/share/     datos compartidos (docs, man pages, iconos)
/usr/include/   cabeceras de desarrollo (archivos .h)
```

## /var — datos variables

```
/var/log/       logs del sistema y servicios
/var/lib/       datos persistentes de aplicaciones
/var/cache/     caché de aplicaciones
/var/spool/     colas (impresión, correo, cron)
/var/tmp/       temporales que persisten entre reinicios
/var/www/       raíz web típica de Apache/Nginx
```

## /proc — información del kernel

```
/proc/cpuinfo       información del procesador
/proc/meminfo       uso de memoria
/proc/mounts        sistemas de archivos montados
/proc/uptime        tiempo desde el arranque
/proc/PID/          información de cada proceso
```

## /dev — dispositivos

```
/dev/sda        primer disco SATA/SCSI
/dev/sda1       primera partición del primer disco
/dev/nvme0n1    disco NVMe
/dev/null       descarta todo lo que se envía
/dev/zero       genera bytes nulos infinitos
/dev/random     genera datos aleatorios
/dev/tty        terminal actual
```

## Rutas absolutas vs relativas

```bash
/etc/passwd         # absoluta — desde la raíz
etc/passwd          # relativa — desde el directorio actual
./script.sh         # relativa — en el directorio actual
../config.conf      # relativa — directorio padre
~/documentos        # relativa al home del usuario
```
