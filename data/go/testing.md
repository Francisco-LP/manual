# TESTING en Go

Go incluye soporte nativo integrado de alto nivel para realizar pruebas unitarias y análisis de rendimiento (benchmarking) sin dependencias adicionales a través del paquete `testing` y el comando de CLI `go test`.

## Reglas de las Pruebas en Go

1. **Nombre del Archivo**: Los archivos de prueba deben terminar con el sufijo `_test.go` (ej: `mate.go` y `mate_test.go`).
2. **Nombre de la Función**: Debe comenzar con la palabra `Test` seguida de una letra mayúscula (ej: `TestSumar`).
3. **Firma de la Función**: Debe aceptar exactamente un argumento de tipo `*testing.T`.

---

## Código a Probar (`calculos.go`)

```go
package calculos

func Sumar(a, b int) int {
    return a + b
}
```

---

## Pruebas Unitarias (`calculos_test.go`)

```go
package calculos

import "testing"

func TestSumar(t *testing.T) {
    resultado := Sumar(4, 5)
    esperado := 9

    if resultado != esperado {
        // t.Errorf marca el test como fallido pero permite que continúe ejecutándose
        t.Errorf("Sumar(4, 5) = %d; se esperaba %d", resultado, esperado)
    }
}

// Pruebas Basadas en Tablas (Table-driven tests) - Práctica estándar en Go
func TestSumarMultiplesCasos(t *testing.T) {
    // Definimos una tabla con las entradas y salidas esperadas
    casos := []struct {
        nombre   string
        a, b     int
        esperado int
    }{
        {"Positivos", 2, 3, 5},
        {"Negativos", -1, -1, -2},
        {"Con Cero", 5, 0, 5},
    }

    for _, tc := range casos {
        // t.Run ejecuta cada caso como un subtest independiente
        t.Run(tc.nombre, func(t *testing.T) {
            res := Sumar(tc.a, tc.b)
            if res != tc.esperado {
                // t.Fatalf marca el test como fallido e interrumpe de inmediato este subtest
                t.Fatalf("Fallo en %s: Sumar(%d, %d) = %d; esperado %d", tc.nombre, tc.a, tc.b, res, tc.esperado)
            }
        })
    }
}
```

---

## Ejecutar Pruebas (`go test`)

El comando `go test` compila el paquete actual y sus archivos `_test.go` y ejecuta las funciones de prueba.

```bash
# Ejecutar todas las pruebas del paquete actual
go test

# Ejecutar las pruebas mostrando salida detallada (verboso)
go test -v

# Ejecutar pruebas que coincidan con un patrón o nombre específico
go test -run=TestSumarMultiplesCasos

# Ejecutar pruebas y calcular cobertura de código
go test -cover
```

---

## Benchmarks (Pruebas de Rendimiento)

Los benchmarks sirven para evaluar la velocidad y la eficiencia de consumo de memoria de tu código.
- Los archivos deben llamarse `_test.go`.
- Las funciones deben comenzar con `Benchmark` y aceptar un parámetro `*testing.B`.
- Deben iterar en un bucle utilizando el contador `b.N`.

```go
package calculos

import "testing"

func BenchmarkSumar(b *testing.B) {
    // b.N es ajustado dinámicamente por la herramienta de testing para obtener medidas fiables
    for i := 0; i < b.N; i++ {
        Sumar(100, 200)
    }
}
```

### Ejecutar Benchmarks

```bash
# Ejecutar benchmarks. El patrón "." le dice que ejecute todos los benchmarks del directorio actual
go test -bench=.

# Ejecutar benchmarks y mostrar estadísticas de reservas de memoria en el heap (allocations)
go test -bench=. -benchmem
```
