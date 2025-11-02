#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"

int main(void)
{
    //Abre una ventana de 1024x768 píxeles
    InitWindow(1024, 768, "Sprites en movimiento");

    //inicia el sistema de audio
    InitAudioDevice();

    //Carga las texturas seleccionadas
    Texture2D sprite = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/sans.png");

    //Carga los sonidos seleccionados
    Sound sonido = LoadSound("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/salto.mp3");

    //Añade un filtro bilineal
    SetTextureFilter(sprite, TEXTURE_FILTER_BILINEAR);

    //Propiedades del sprite
    Vector2 pos = { 450.0f, 250.0f };
    Vector2 actual = pos;
    float escala = 0.2f;
    Color color = BLUE;
    float velocidad = 5.0f;

    Color fondo = RED;

    SetTargetFPS(60);

    // Bucle principal
    while (!WindowShouldClose())
    {
        //Detecta si se presiona el espacio para hacer saltar al personaje
        if (IsKeyPressed(KEY_SPACE)) {
            pos.y -= velocidad;
            PlaySound(sonido);
        }

        //Detecta si se presiona la tecla izquierda para mover el personaje en esa dirección
        if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {
            pos.x -= velocidad;
        }

        //Detecta si se presiona la flecha derecha para mover al personaje en esa dirección
        if(IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
            pos.x += velocidad;
        }
        
        //Reinicia la posición
        if (IsKeyPressed(KEY_R)) {
            pos = actual;
        }

        //Detecta si se presionó el click izquierdo del mouse
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
            fondo = BLUE;
        }
        else if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON)) {
            fondo = RED;
        }

        //Comienza a dibujar
        BeginDrawing();

        //Cambia el fondo de la pantalla
        ClearBackground(fondo);

        //Dibuja los sprites
        DrawTextureEx(sprite, pos, 0.0f, escala, color);

        //Se indican los controles
        DrawText("Presiona <- o -> para desplazar al personaje", 10, 700, 20, BLACK);
        DrawText("Presiona ESPACIO para saltar", 10, 730, 20, BLACK);

        //Indica la posición actual del personaje en el eje X
        DrawText(TextFormat("Posicion: %.0f %.0f", pos.x, pos.y), 10, 20, 30, DARKGREEN);

        DrawText("Presiona R para reiniciar posicion", 500, 20, 30, DARKBLUE);

        //Muestra un texto cuando se presiona la tecla M
        if (IsKeyDown(KEY_M)) {
            DrawText("Estoy aprendiendo en Mavi", 400, 500, 20, WHITE);
        }

        //Termina de dibujar
        EndDrawing();
    }

    //Liberar memoria
    UnloadTexture(sprite);
    UnloadSound(sonido);

    //Termina es sistema de audio
    CloseAudioDevice();
    //Cierra la ventana
    CloseWindow();

    return 0;
}

