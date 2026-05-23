# EXPRESIONES REGULARES en Python

Búsqueda, extracción y manipulación de patrones de texto utilizando el módulo integrado `re`.

## Funciones Principales

- `re.search()`: Busca en toda la cadena la primera coincidencia del patrón.
- `re.match()`: Determina si el patrón coincide al **inicio** exacto de la cadena.
- `re.findall()`: Retorna una lista con todas las ocurrencias encontradas.
- `re.finditer()`: Retorna un iterador de objetos Match con detalles (posición, etc.).
- `re.sub()`: Reemplaza una o más ocurrencias del patrón en una cadena de texto.

## Búsqueda y Validación (`search` y `match`)

```python
import re

texto = "El número secreto es 404 y mi código es 200"

# re.search (Cualquier parte de la cadena)
# Usar cadenas crudas r"..." evita conflictos con la barra invertida \
coincidencia = re.search(r"\d+", texto)  # Busca uno o más dígitos

if coincidencia:
    print(coincidencia.group())  # "404" (primer número encontrado)
    print(coincidencia.span())   # (21, 24) (índices de inicio y fin)

# re.match (Solo al inicio de la cadena)
print(re.match(r"El", texto))   # Objeto Match
print(re.match(r"404", texto))  # None (404 no está al principio)
```

## Extracción de Coincidencias Múltiples (`findall` e `iter`)

```python
texto = "Contacto: info@test.com o soporte@empresa.org"
patron_email = r"[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[a-zA-Z]{2,}"

# findall retorna lista de strings
emails = re.findall(patron_email, texto)
print(emails)  # ['info@test.com', 'soporte@empresa.org']
```

## Reemplazo de Patrones (`sub`)

```python
texto = "Tengo 5 manzanas y 10 plátanos"

# Reemplaza cualquier dígito por una 'X'
texto_censurado = re.sub(r"\d+", "X", texto)
print(texto_censurado)  # "Tengo X manzanas y X plátanos"
```

## Grupos de Captura `()`

Permiten subdividir y extraer partes específicas del patrón coincidente.

```python
texto = "2026-05-22"
patron_fecha = r"(\d{4})-(\d{2})-(\d{2})"  # Grupos: Año, Mes, Día

coincidencia = re.search(patron_fecha, texto)
if coincidencia:
    print(coincidencia.group(0))  # "2026-05-22" (Todo el patrón)
    print(coincidencia.group(1))  # "2026" (Primer grupo)
    print(coincidencia.group(2))  # "05" (Segundo grupo)
    print(coincidencia.group(3))  # "22" (Tercer grupo)
    print(coincidencia.groups())  # ('2026', '05', '22') (Tupla con grupos)
```
