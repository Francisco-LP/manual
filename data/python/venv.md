# VENV (Entornos Virtuales) en Python

El módulo `venv` permite crear entornos virtuales aislados y autónomos para cada uno de tus proyectos, evitando conflictos de versiones de paquetes entre ellos y con el sistema global.

## 1. Crear un Entorno Virtual

Se recomienda crearlo en la carpeta raíz de tu proyecto bajo el nombre `.venv` o `venv`.

```bash
# Sintaxis: python -m venv <nombre_entorno>
python -m venv .venv
```

## 2. Activar el Entorno

Al activar el entorno virtual, tu terminal pasará a usar el binario de Python y el comando `pip` locales de esa carpeta en lugar de los globales del sistema.

### En Linux / macOS:
```bash
source .venv/bin/activate
```

### En Windows (PowerShell):
```powershell
.venv\Scripts\Activate.ps1
```

### En Windows (Símbolo del sistema - CMD):
```cmd
.venv\Scripts\activate.bat
```

*Una vez activado, verás el nombre del entorno entre paréntesis en tu prompt de terminal:*
`(.venv) usuario@maquina:~$`

## 3. Desactivar el Entorno

Para regresar al Python global del sistema operativo:

```bash
deactivate
```
