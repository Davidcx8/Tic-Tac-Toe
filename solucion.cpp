#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/
int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */
    char** matriz = GetTablero();

    const int lineas[8][3][2] = {
        {{0, 0}, {0, 1}, {0, 2}},
        {{1, 0}, {1, 1}, {1, 2}},
        {{2, 0}, {2, 1}, {2, 2}},
        {{0, 0}, {1, 0}, {2, 0}},
        {{0, 1}, {1, 1}, {2, 1}},
        {{0, 2}, {1, 2}, {2, 2}},
        {{0, 0}, {1, 1}, {2, 2}},
        {{0, 2}, {1, 1}, {2, 0}}
    };

    // Recorre todas las lineas ganadoras posibles.
    for (int k = 0; k < 8; k++)
    {
        int f0 = lineas[k][0][0];
        int c0 = lineas[k][0][1];
        int f1 = lineas[k][1][0];
        int c1 = lineas[k][1][1];
        int f2 = lineas[k][2][0];
        int c2 = lineas[k][2][1];

        char a = matriz[f0][c0];
        char b = matriz[f1][c1];
        char c = matriz[f2][c2];

        if (a != '_' && a == b && b == c)
        {
            return a == 'X' ? GANO_X : GANO_O;
        }
    }

    bool hayVacio = false;
    for (int fila = 0; fila < 3; fila++)
    {
        for (int col = 0; col < 3; col++)
        {
            if (matriz[fila][col] == '_')
            {
                hayVacio = true;
                break;
            }
        }
        if (hayVacio)
        {
            break;
        }
    }

    return hayVacio ? JUEGO_EN_CURSO : EMPATE;
}
