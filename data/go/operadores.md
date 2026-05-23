# OPERADORES en Go

Operadores aritméticos, lógicos, de comparación y asignaciones de Go.

## Operadores Aritméticos

| Operación | Operador | Ejemplo |
|---|---|---|
| Suma | `+` | `a + b` |
| Resta | `-` | `a - b` |
| Multiplicación | `*` | `a * b` |
| División | `/` | `a / b` (Entera si ambos son enteros, float si uno lo es) |
| Módulo | `%` | `a % b` |

### Incremento e Decremento (Sentencias, no expresiones)

En Go, `++` y `--` son sentencias individuales y **no** pueden usarse como parte de expresiones o asignaciones. Solo existe la forma postfix.

```go
x := 1
x++  // Correcto: x es ahora 2
// y := x++ // ERROR: no se permite asignar la expresión de incremento
```

## Operadores de Comparación

Comparan valores y retornan un booleano (`true` o `false`).

- `==` : Igual a.
- `!=` : Diferente de.
- `>`  : Mayor que.
- `<`  : Menor que.
- `>=` : Mayor o igual que.
- `<=` : Menor o igual que.

## Operadores Lógicos

- `&&` : Operador AND (Y lógico).
- `||` : Operador OR (O lógico).
- `!`  : Operador NOT (Negación).

```go
activo := true
tienePermiso := false

if activo && tienePermiso {
    // Código
}
```

## Operador de Dirección (Punteros Básicos)

Go admite punteros directos, aunque no aritmética de punteros.

- `&` : Obtiene la dirección de memoria de una variable.
- `*` : Desreferencia (accede al valor en la dirección de memoria apuntada).

```go
x := 10
puntero := &x  // puntero es de tipo *int
fmt.Println(*puntero) // Imprime 10
```
