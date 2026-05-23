# MATCH CASE en Python

Coincidencia de patrones estructurales (Structural Pattern Matching) introducida en **Python 3.10**. Es una versión sumamente potente de la sentencia switch-case.

## Estructura Básica

```python
def procesar_estado(codigo):
    match codigo:
        case 200:
            return "OK"
        case 400:
            return "Bad Request"
        case 404:
            return "Not Found"
        case 500 | 503:  # Operador OR para múltiples coincidencias
            return "Server Error"
        case _:  # Comodín (Wildcard), se ejecuta si no coincide nada de lo anterior
            return "Código desconocido"
```

## Coincidencia de Estructuras (Tuplas/Listas)

`match-case` puede descomponer y verificar la forma y el contenido de colecciones.

```python
def comando_consola(comando):
    match comando.split():
        case ["ir", ("norte" | "sur" | "este" | "oeste") as direccion]:
            print(f"Moviéndose al {direccion}")
        case ["mirar"]:
            print("Observas a tu alrededor.")
        case ["tomar", objeto]:
            print(f"Has recogido: {objeto}")
        case ["soltar", objeto, *otros]:
            print(f"Soltando {objeto} y {len(otros)} cosas más.")
        case _:
            print("Comando no reconocido.")

comando_consola("ir norte")     # Moviéndose al norte
comando_consola("tomar espada")  # Has recogido: espada
```

## Condicionales en Cases (Guards)

Puedes añadir una cláusula `if` interna para condicionar la coincidencia.

```python
def clasificar_punto(punto):
    match punto:
        case (0, 0):
            print("Origen")
        case (x, y) if x == y:
            print(f"En la diagonal x=y ({x}, {y})")
        case (x, y):
            print(f"Punto regular ({x}, {y})")
```

## Coincidencia con Clases (Tipos)

Verifica si un objeto es instancia de una clase y extrae sus atributos directamente.

```python
class Usuario:
    def __init__(self, nombre, rol):
        self.nombre = nombre
        self.rol = rol

def verificar_permisos(user):
    match user:
        case Usuario(rol="Admin"):
            print("Acceso total permitido.")
        case Usuario(nombre=nombre, rol="Invitado"):
            print(f"Acceso restringido para el invitado {nombre}.")
        case Usuario(nombre=nombre):
            print(f"Acceso normal para el usuario {nombre}.")
```
