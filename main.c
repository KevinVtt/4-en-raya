#include <stdio.h>
#include <stdlib.h>
#include "tablero.h"
/*
 * Crea el juego conecta cuatro.
 *
 * Requisitos:
 * - Tablero de 7x6 (7 en el eje "x" y 6 en el "y").
 * - Fichas Rojas y Amarillas. La primera partida la comienza siempre la Roja
 *   (la segunda la Amarilla, la tercera la Roja...).
 * - No hay que implementar una funcionalidad que te permita jugar contra la App.
 *   Se asume que jugar�n dos personas reales altern�ndose.
 * - Al seleccionar la columna se coloca la ficha en la parte inferior.
 * - Guardar el n�mero partidas ganadas de cada equipo mientras la App no se finaliza.
 * - Dos botones para reiniciar la partida en marcha y para resetear el
 *   contador de victorias y derrotas.
 * - Puedes a�adirle todas las funcionalidades extra que consideres.
 */

int main()
{
    int matriz[7][6];

    cargar_tablero(matriz);
    juego(matriz);
    return 0;
}
