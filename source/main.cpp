#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"
#include "JUEGO.h"

//Bucle inicial
int main(void){

    //Carga una pantalla de 1280 x 720 pixeles
    InitWindow(1280, 720, "Disparo al objetivo");

    JUEGO Game;

    Game.game();

    return 0;
}