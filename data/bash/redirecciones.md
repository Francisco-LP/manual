# REDIRECCIONES en Bash

Mecanismo para controlar de dónde vienen y a dónde van los datos de un comando.

## Descriptores de archivo

```
0   stdin   entrada estándar
1   stdout  salida estándar
2   stderr  salida de errores
```

## Redirigir salida ( > )

Redirige stdout a un archivo. Si el archivo existe lo sobreescribe.

```bash
ls > lista.txt
echo "hola" > archivo.txt
```

## Redirigir salida agregando ( >> )

Agrega al final del archivo sin sobreescribir.

```bash
echo "línea nueva" >> archivo.txt
```

## Redirigir entrada ( < )

El comando lee desde un archivo en lugar de teclado.

```bash
sort < lista.txt
wc -l < archivo.txt
```

## Redirigir stderr ( 2> )

```bash
comando 2> errores.txt
```

## Redirigir stdout y stderr al mismo archivo

```bash
comando > salida.txt 2>&1
# forma moderna (bash 4+):
comando &> salida.txt
```

## Descartar salida

/dev/null es un agujero negro — lo que se envía ahí desaparece.

```bash
comando > /dev/null          # descartar stdout
comando 2> /dev/null         # descartar stderr
comando &> /dev/null         # descartar todo
```

## Pipe ( | )

Conecta la salida de un comando con la entrada del siguiente.

```bash
ls | grep ".txt"
cat archivo.txt | sort | uniq
ps aux | grep nginx
```

## Here Document ( << )

Pasa un bloque de texto multilínea como stdin.

```bash
cat << EOF
línea 1
línea 2
línea 3
EOF
```

```bash
# Ejemplo útil: crear archivo con contenido
cat << EOF > config.txt
host=localhost
puerto=8080
EOF
```

## Here String ( <<< )

Pasa un string corto como stdin.

```bash
grep "hola" <<< "hola mundo"
wc -w <<< "contar estas palabras"
```

## Redirigir a múltiples destinos ( tee )

Envía la salida a pantalla Y a un archivo al mismo tiempo.

```bash
comando | tee archivo.txt
comando | tee -a archivo.txt   # -a para agregar sin sobreescribir
```

## Ejemplos prácticos

```bash
# Guardar log de errores
./script.sh 2> errores.log

# Guardar todo (stdout + stderr)
./script.sh &> todo.log

# Ver y guardar al mismo tiempo
./script.sh | tee salida.log

# Separar stdout y stderr
./script.sh > salida.txt 2> errores.txt

# Silenciar completamente un comando
comando &> /dev/null
```
