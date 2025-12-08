#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"
#include "Pelota.h"
#include "Borde_Ventana.h"

//Bucle inicial
int main(void){

    //Carga una pantalla de 800 x 600 pixeles
    InitWindow(800,600,"Pelota");
    
    //Se llama a las clases
    Pelota pelo;
    Borde_Ventana borde;

    //Se carga la textura
    pelo.loadPelota();

    //Los FPS se limitan a un máximo de 60
    SetTargetFPS(60);

    //Se inicia un bucle mientras la ventana no se cierre
    while (!WindowShouldClose()) {

        //Se mueve la pelota
        pelo.movePelota();

        pelo.GetCollision(borde);

        //Comeienza a dibujar
        BeginDrawing();

        //Limpia el fondo y lo cambia a color rojo
        ClearBackground(RED);

        //Se dibuja la pelota
        pelo.drawPelota();

        //Se deja de dibujar
        EndDrawing();
    }

    //Se libera el espacio ocupado por la pelota
    pelo.unloadPelota();

    //Se cierra la ventana
    CloseWindow();
    return 0;
}