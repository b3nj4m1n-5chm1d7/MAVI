#ifndef NDEBUG
#include <vld.h>
#endif
#include "raylib.h"

int main(void)
{
    //Crea una ventana de 800x450 píxeles de tamaño
    InitWindow(800, 450, "Proyecto MAVI");

    //Configura el framerate
    SetTargetFPS(60);

    Color fondo = { 154, 0, 79, 1 }; //Color rosa oscuro personalizado
    Color texto1 = BLACK;
    Color texto2 = SKYBLUE;
    Color texto3 = RED;
    bool TeclaEspacio = true;

    //Bucle inicial del juego (se repite hasta presionar )
    while (!WindowShouldClose())
    {
        //Comienza a dibujar
        BeginDrawing();

        //Limpia la pantalla y la cambia al color indicado
        ClearBackground(fondo);

        //Dibuja un texto, indicando posición, tamaño y color
        DrawText("Benjamin Schmidt", 170, 100, 60, texto1);

        //Dibuja un rectangulo, indicando posición, ancho, alto y color
        DrawRectangle(130, 80, 550, 100, Fade(PURPLE, 0.5f)); //Fondo llamativo para resaltar el texto

        //Dibuja un círculo, indicando posición, radio y color
        DrawCircle(390, 310, 80, Fade(DARKGREEN, 0.5f));

        if (IsKeyPressed(KEY_SPACE)) {
            TeclaEspacio = !TeclaEspacio; //Cambia el estado de la variable
        }

        if (TeclaEspacio) {
            DrawText("Hola", 360, 290, 30, texto2);
        }
        else {
            DrawText("Ya aprendi a programar con raylib en MAVI", 80, 290, 30, texto3); //El texto cambia si se presiona la tecla "espacio"
        }

        //Termina de dibujar
        EndDrawing();
    }

    //Cierra la ventana
    CloseWindow();

    return 0;
}