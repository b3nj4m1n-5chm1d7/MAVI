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

    //Carga las texturas seleccionadas
    Texture2D sprite1 = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/dino.png");
    Texture2D sprite2 = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/sans.png");

    //Añade un filtro bilineal
    SetTextureFilter(sprite1, TEXTURE_FILTER_BILINEAR);
    SetTextureFilter(sprite2, TEXTURE_FILTER_BILINEAR);

    //Propiedades del primer sprite
    Vector2 pos1 = { 200.0f, 250.0f };
    Vector2 vel1 = { 2.0f, 1.5f };
    float rot1 = 0.0f;
    float escala1 = 0.6f;
    Color color1 = RED;

    //Propiedades del segundo sprite
    Vector2 pos2 = { 450.0f, 250.0f };
    Vector2 vel2 = { -2.5f, 1.0f };
    float rot2 = 0.0f;
    float escala2 = 0.2f;
    Color color2 = BLUE;

    SetTargetFPS(60);

    // Bucle principal
    while (!WindowShouldClose())
    {
        //Rota los sprites en una determinada velocidad
        rot1 += 0.5f;
        rot2 -= 1.0f;

        //Movimiento automático
        pos1.x += vel1.x;
        pos1.y += vel1.y;
        pos2.x += vel2.x;
        pos2.y += vel2.y;

        //Rebotar en bordes
        if (pos1.x <= 0 || pos1.x + sprite1.width * escala1 >= GetScreenWidth()) vel1.x *= -1;
        if (pos1.y <= 0 || pos1.y + sprite1.height * escala1 >= GetScreenHeight()) vel1.y *= -1;

        if (pos2.x <= 0 || pos2.x + sprite2.width * escala2 >= GetScreenWidth()) vel2.x *= -1;
        if (pos2.y <= 0 || pos2.y + sprite2.height * escala2 >= GetScreenHeight()) vel2.y *= -1;

        //Intercambio de las propiedades de los sprites
        if (IsKeyPressed(KEY_SPACE))
        {
            //Intercambiar todas las propiedades
            Vector2 tempPos = pos1; pos1 = pos2; pos2 = tempPos;
            Vector2 tempVel = vel1; vel1 = vel2; vel2 = tempVel;
            float tempRot = rot1; rot1 = rot2; rot2 = tempRot;
            float tempEscala = escala1; escala1 = escala2; escala2 = tempEscala;
            Color tempColor = color1; color1 = color2; color2 = tempColor;

            //Intercambiar también las texturas (opcional, más “efecto visual”)
            Texture2D tempTex = sprite1; sprite1 = sprite2; sprite2 = tempTex;
        }

        //Comienza a dibujar
        BeginDrawing();

        //Cambia el fondo de la pantalla
        ClearBackground(BLACK);

        //Dibuja los sprites
        DrawTextureEx(sprite1, pos1, rot1, escala1, color1);
        DrawTextureEx(sprite2, pos2, rot2, escala2, color2);

        //Texto informativo
        DrawText("Presiona [ESPACIO] para intercambiar propiedades (Swap visual)", 10, 720, 20, DARKGRAY);

        //Informacion del primer sprite
        DrawText("Sprite 1:", 10, 20, 20, BLUE);
        DrawText(TextFormat("Posicion: (%.1f, %.1f)", pos1.x, pos1.y), 20, 50, 18, GRAY);
        DrawText(TextFormat("Rotacion: %.1f", rot1), 20, 75, 18, GRAY);
        DrawText(TextFormat("Escala: %.2f", escala1), 20, 95, 18, GRAY);
        DrawText(TextFormat("Color (RGBA): (%d, %d, %d, %d)", color1.r, color1.g, color1.b, color1.a), 20, 115, 18, GRAY);
        DrawText(TextFormat("Velocidad: (%.1f, %.1f)", vel1.x, vel1.y), 20, 135, 18, GRAY);

        //informacion del segundo sprite
        DrawText("Sprite 2:", 750, 20, 20, RED);
        DrawText(TextFormat("Posicion: (%.1f, %.1f)", pos2.x, pos2.y), 760, 50, 18, GRAY);
        DrawText(TextFormat("Rotacion: %.1f", rot2), 760, 75, 18, GRAY);
        DrawText(TextFormat("Escala: %.2f", escala2), 760, 95, 18, GRAY);
        DrawText(TextFormat("Color (RGBA): (%d, %d, %d, %d)", color2.r, color2.g, color2.b, color2.a), 760, 115, 18, GRAY);
        DrawText(TextFormat("Velocidad: (%.1f, %.1f)", vel2.x, vel2.y), 760, 135, 18, GRAY);

        //Termina de dibujar
        EndDrawing();
    }

    //Liberar memoria
    UnloadTexture(sprite1);
    UnloadTexture(sprite2);

    //Cierra la ventana
    CloseWindow();

    return 0;
}

