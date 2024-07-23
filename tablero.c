#include <stdlib.h>
#include <stdio.h>
#include "tablero.h"


void cargar_tablero(int m[7][6]){

    // Tablero nulo con 0.
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++){
            m[i][j] = 0;
        }
    }

}

void tablero(int m[7][6]) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD rojo = FOREGROUND_RED;
    WORD amarillo = FOREGROUND_RED | FOREGROUND_GREEN;
    WORD blanco = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

    printf("\n\n");
    printf("     Y |1  2  3  4  5  6  \n");
    printf("   X  |-----------------------\n");

    for (int i = 0; i < 7; i++) {
        printf("   %d  |", i + 1);
        for (int j = 0; j < 6; j++) {
            if (m[i][j] == 0) {
                SetConsoleTextAttribute(hConsole, blanco);
                printf(" %d ", m[i][j]);
            }
            if (m[i][j] == 1) {
                SetConsoleTextAttribute(hConsole, rojo);
                printf(" %d ", m[i][j]);
            }
            if (m[i][j] == 2) {
                SetConsoleTextAttribute(hConsole, amarillo);
                printf(" %d ", m[i][j]);
            }
        }
        printf("|\n");
    }
    printf(" --------------------------------\n");
}



void verificar_espacio(int m[7][6], int jugador, int x, int y) {
    while (m[x - 1][y - 1] != 0) {
        printf("\nLugar ya ocupado, ingrese otro !!\n");
        y = verificar_y();
        x = verificar_x();
    }

    m[x - 1][y - 1] = jugador; // Actualizar la matriz con la nueva ficha
}

int verificar_x(){

    int x;

    printf("\nIngrese la ubicacion de la X\n");
    scanf("%d",&x);

    while(x >= 7 || x <= 0){
        printf("Fuera del limite\nIngrese nuevamente");
        printf("\nIngrese la ubicacion de la X\n");
        scanf("%d",&x);

    };

    return x;
}

int verificar_y(){

    int y;

    printf("\nIngrese la ubicacion de la Y\n");
    scanf("%d",&y);

    while(y >= 6 || y <= 0){
        printf("Fuera del limite\nIngrese nuevamente");
        printf("\nIngrese la ubicacion de la Y\n");
        scanf("%d",&y);

    };

    return y;
}

void juego(int m[7][6]){

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    WORD rojo = FOREGROUND_RED;
    WORD amarillo = FOREGROUND_RED | FOREGROUND_GREEN;
    WORD blanco = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;
    int jugador1 = 1,jugador2 = 2;
    int x,y;
    int bandera = 0;
    do{

        SetConsoleTextAttribute(hConsole,rojo);
        printf("\n       Empiezan las Rojas\n\n");
        SetConsoleTextAttribute(hConsole,blanco);
        tablero(m);
        SetConsoleTextAttribute(hConsole,blanco);
        x = verificar_x();
        y = verificar_y();

        verificar_espacio(m,jugador1,x,y);
        bandera = verificar_puntos_tablero(m,jugador1);

        if(bandera == 1 || bandera == 2){
            break;
        }

        system("cls");
        SetConsoleTextAttribute(hConsole,amarillo);
        printf("\n       Empiezan las amarillas\n");
        SetConsoleTextAttribute(hConsole,blanco);
        tablero(m);
        SetConsoleTextAttribute(hConsole,blanco);

        x = verificar_x();
        y = verificar_y();


        verificar_espacio(m,jugador2,x,y);
        bandera = verificar_puntos_tablero(m,jugador2);

        system("cls");

    }while(bandera == 0);

    system("cls");
    tablero(m);

    if(bandera == 1){
        SetConsoleTextAttribute(hConsole, rojo);
        printf("Ganador jugador 1!!!\n");
        SetConsoleTextAttribute(hConsole, blanco);
    }

    if(bandera == 2){
        SetConsoleTextAttribute(hConsole, amarillo);
        printf("Ganador jugador 2!!!\n");
        SetConsoleTextAttribute(hConsole, blanco);
    }


}

int verificar_puntos_tablero(int m[7][6],int jugador){
    int encontrado = 0;
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 4; j++){
                // Verificacion en horizontal hacia la derecha
            if(m[i][j] == jugador && m[i][j+1] == jugador && m[i][j+2] == jugador && m[i][j+3] == jugador){

                if(jugador == 1){
                    encontrado = 1;
                }
                    if(jugador == 2){
                        encontrado = 2;
                    }

                }
            }
        }

        // Verificacion en vertical
        for(int i = 0; i < 6; i++){
            for(int j = 0; j < 6; j++){
                if(m[i][j] == jugador && m[i+1][j] == jugador && m[i+2][j] == jugador && m[i+3][j] == jugador){
                    if(jugador == 1){
                    encontrado = 1;
                }
                    if(jugador == 2){
                        encontrado = 2;
                    }
                }
            }
        }

        // verificacion en diagonal arriba a la derecha
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(m[i][j] == jugador && m[i+1][j+1] == jugador && m[i+2][j+2] == jugador && m[i+3][j+3] == jugador){
                if(jugador == 1){
                    encontrado = 1;
                }
                    if(jugador == 2){
                        encontrado = 2;
                    }

                }
            }
        }
        // verificacion en diagonal arriba a la izquierda
        for(int i = 0; i < 4; i++){
            for(int j = 3; j < 6; j++){
                if(m[i][j] == jugador && m[i+1][j-1] == jugador && m[i+2][j-2] == jugador && m[i+3][j-3] == jugador){
                if(jugador == 1){
                    encontrado = 1;
                }
                    if(jugador == 2){
                        encontrado = 2;
                    }
                }
            }
        }

    return encontrado;
};

bool busquedaSecuencial(int m[7][6],int numBuscado){

    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 6; j++){

            if(m[i][j] == numBuscado){
                return true;
            }

        }
    }

    return false;


}
