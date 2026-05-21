# Tic Tac Toe (C++)

Proyecto academico de Tic Tac Toe en C++ para consola. Incluye la logica de juego, deteccion de ganador/empate y tareas de build en VS Code.

## Requisitos

- Windows con TDM-GCC (g++)
- VS Code (opcional, para usar las tareas)

## Compilacion y ejecucion (VS Code)

1. Abrir la carpeta del proyecto en VS Code.
2. Ejecutar `Ctrl+Shift+B` para compilar y correr.

La tarea por defecto compila todos los `.cpp` del directorio raiz y genera `output/main.exe`.

## Compilacion manual (PowerShell)

```powershell
g++ -Wall -Wextra -g3 *.cpp -o output/main.exe
./output/main.exe
```

## Estructura

- `main.cpp`: flujo principal del juego.
- `logica.cpp/.h`: manejo del tablero y entradas del usuario.
- `solucion.cpp/.h`: evaluacion del estado del juego.
- `.vscode/tasks.json`: tareas para build y run.

## Notas

Si mueves los `.cpp` a subcarpetas, ajusta la tarea de compilacion para incluir esas rutas.
