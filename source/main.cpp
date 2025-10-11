#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"

int main(void)
{
    //Crea una ventana de 1024x768 píxeles de tamaño
    InitWindow(1024, 768, "Proyecto MAVI");

    Color fondo = { 154, 0, 79, 1 }; //Color rosa oscuro personalizado
    Color texto1 = BLACK;
    Color texto2 = SKYBLUE;
    Color texto3 = RED;
    bool TeclaEspacio = true;
    Color colorPelota = {0, 97, 0, 180};

    //Posición de la pelota en los ejes X e Y
    Vector2 posicion = { 1024 / 2.0f, 768 / 2.0f};
    //Velocidad que se le otorgará a la pelota
    Vector2 velocidad = { 250.0f, 180.0f };

    //Indica si la pelota esta en contacto con algun borde
    bool rebotes = false;
    
    int choque = 0;

    //Configura el framerate
    SetTargetFPS(60);
    srand(time(NULL));

    //Bucle inicial del juego (se repite hasta presionar )
    while (!WindowShouldClose())
    {
        //Se establece un tiempo "real"
        float deltaTime = GetFrameTime();

        //Actualiza la posición con la velocidad y el tiempo
        posicion.x += velocidad.x * deltaTime;
        posicion.y += velocidad.y * deltaTime;

        bool rebotes = false;

        //Detecta la colisión con paredes
        if ((posicion.x + 40) >= 1024) {
            
            posicion.x = 1024 - 40;

            velocidad.x *= -1;

            rebotes = true;
        }
        else if ((posicion.x - 40) <= 0) {

            posicion.x = 40;

            velocidad.x *= -1;

            rebotes = true;
        }

        //Detecta la colisión con el techo o el suelo
        if ((posicion.y + 40) >= 768) {

            posicion.y = 768 - 40;

            velocidad.y *= -1;

            rebotes = true;
        }
        else if ((posicion.y - 40) <= 0) {

            posicion.y = 40;

            velocidad.y *= -1;

            rebotes = true;
        }

        //Cuenta los rebotes y cambia el color
        if (rebotes) {

            choque++;

            //El color se cambiará aleatoriamente
            colorPelota.r = (colorPelota.r + 60) % 256;
            colorPelota.g = (colorPelota.g + 100) % 256;
            colorPelota.b = (colorPelota.b + 150) % 256;
            colorPelota.a = 180; //Mantiene la transparencia
        }

        //Comienza a dibujar
        BeginDrawing();

        //Limpia la pantalla y la cambia al color indicado
        ClearBackground(fondo);

        //Dibuja un rectangulo, indicando posición, ancho, alto y color
        DrawRectangle(165, 180, 700, 110, Fade(PURPLE, 0.5f)); //Fondo llamativo para resaltar el texto

        //Dibuja un texto, indicando posición, tamaño y color
        DrawText("Benjamin Schmidt", 180, 200, 80, texto1);

        //Indica la resolución de la pantalla
        DrawText("Resolucion : 1024 x 768", 10, 20, 20, BLACK);

        //Indica la posicion actual de la pelota
        DrawText(TextFormat("Posicion: (%.1f, %.1f)", posicion.x, posicion.y), 10, 35, 20, RED);

        //Indica la cantidad de veces que rebota
        DrawText(TextFormat("Rebote: %d", choque), 10, 50, 20, Fade(RAYWHITE, 1.0f));

        if (IsKeyPressed(KEY_SPACE)) {
            TeclaEspacio = !TeclaEspacio; //Cambia el estado de la variable
        }

        if (TeclaEspacio) {
            DrawText("Hola", 480, 400, 40, texto2);
        }
        else {
            DrawText("Ya aprendi a programar con raylib en MAVI", 130, 400, 35, texto3); //El texto cambia si se presiona la tecla "espacio"
        }

        //Dibuja un círculo, indicando posición, radio y color
        DrawCircle(posicion.x, posicion.y, 40, colorPelota);

        //Termina de dibujar
        EndDrawing();
    }

    //Cierra la ventana
    CloseWindow();

    return 0;
}