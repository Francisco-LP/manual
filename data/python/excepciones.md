# EXCEPCIONES en Python

Mecanismo para controlar y gestionar errores en tiempo de ejecución.

## Estructura Completa: `try-except-else-finally`

```python
try:
    # Código que puede fallar
    dividendo = int(input("Dividendo: "))
    divisor = int(input("Divisor: "))
    resultado = dividendo / divisor
except ZeroDivisionError:
    # Se ejecuta si ocurre una división por cero
    print("Error: No se puede dividir entre cero.")
except ValueError:
    # Se ejecuta si la conversión a int falla
    print("Error: Debes ingresar un número válido.")
except Exception as e:
    # Atrapa cualquier otra excepción no contemplada
    print(f"Ocurrió un error inesperado: {e}")
else:
    # Se ejecuta SOLO si no ocurrió ninguna excepción en el bloque try
    print(f"Operación exitosa. Resultado: {resultado}")
finally:
    # Se ejecuta SIEMPRE, haya error o no (ideal para liberar recursos)
    print("Fin del bloque de control.")
```

## Lanzar Excepciones (`raise`)

Permite forzar la interrupción del programa debido a un error de lógica de negocio.

```python
def registrar_edad(edad):
    if edad < 0:
        raise ValueError("La edad no puede ser un número negativo.")
    print(f"Edad registrada: {edad}")

try:
    registrar_edad(-5)
except ValueError as e:
    print(f"Error capturado: {e}")
```

## Excepciones Personalizadas

Se crean heredando de la clase base `Exception`.

```python
class SaldoInsuficienteError(Exception):
    """Excepción para cuando un cliente no tiene saldo suficiente."""
    def __init__(self, saldo_actual, monto_requerido):
        self.saldo_actual = saldo_actual
        self.monto_requerido = monto_requerido
        super().__init__(f"Intento de retiro fallido: Saldo actual: {saldo_actual}, Requerido: {monto_requerido}")

def retirar_dinero(saldo, monto):
    if monto > saldo:
        raise SaldoInsuficienteError(saldo, monto)
    return saldo - monto

try:
    retirar_dinero(100, 150)
except SaldoInsuficienteError as e:
    print(e)
```
