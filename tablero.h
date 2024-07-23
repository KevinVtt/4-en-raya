#ifndef TABLERO_H_INCLUDED
#define TABLERO_H_INCLUDED

#include <time.h>
#include <windows.h>
#include <stdbool.h>

void cargar_tablero(int m[7][6]);

void tablero(int m[7][6]);

void juego(int m[7][6]);

bool busquedaSecuencial(int m[7][6],int numBuscado);

int verificar_puntos_tablero(int m[7][6],int jugador);

void verificar_espacio(int m[7][6],int jugador1,int x,int y);

int verificar_x();

int verificar_y();

void color_tablero(int m[7][6],int jugador1,int x,int y);

#endif // TABLERO_H_INCLUDED
