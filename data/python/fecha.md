# FECHAS en Python

Manipulación y operaciones de fechas, horas y deltas de tiempo utilizando el módulo incorporado `datetime`.

## Obtener Fecha y Hora Actuales

```python
from datetime import datetime, date, time

# Fecha y hora actual completa
ahora = datetime.now()
print(ahora)  # Ejemplo: 2026-05-22 13:45:00.123456

# Fecha actual (solo año-mes-día)
hoy = date.today()
print(hoy)    # Ejemplo: 2026-05-22
```

## Creación de Objetos datetime

```python
# datetime(año, mes, día, hora, minuto, segundo)
fecha_especifica = datetime(2026, 12, 31, 23, 59, 59)
print(fecha_especifica)
```

## Formatear Fechas como Cadenas (`strftime`)

Convierte un objeto datetime a un string personalizado (F -> String).

```python
ahora = datetime.now()

# Directivas comunes:
# %Y: Año (4 dígitos) | %m: Mes (01-12) | %d: Día (01-31)
# %H: Hora (00-23)    | %M: Minuto (00-59) | %S: Segundo (00-59)

formato1 = ahora.strftime("%d/%m/%Y")
print(formato1)  # Ejemplo: 22/05/2026

formato2 = ahora.strftime("%Y-%m-%d %H:%M:%S")
print(formato2)  # Ejemplo: 2026-05-22 13:45:00
```

## Convertir Cadenas a Fechas (`strptime`)

Analiza un string de texto y lo transforma en un objeto datetime (P -> Parse).

```python
cadena_fecha = "25-12-2026 18:30"
patron_formato = "%d-%m-%Y %H:%M"

fecha_objeto = datetime.strptime(cadena_fecha, patron_formato)
print(fecha_objeto)  # 2026-12-25 18:30:00
```

## Aritmética de Fechas (`timedelta`)

Representa una duración de tiempo (diferencia entre dos fechas u horas).

```python
from datetime import timedelta

ahora = datetime.now()

# Sumar o restar tiempo
en_diez_dias = ahora + timedelta(days=10)
hace_dos_horas = ahora - timedelta(hours=2)

# Diferencia entre dos fechas
navidad = datetime(2026, 12, 25)
año_nuevo = datetime(2027, 1, 1)

diferencia = año_nuevo - navidad
print(diferencia.days)  # 7
```
