#ifndef NDEBUG
#include <stdlib.h>
#include <time.h>
#include <vld.h>
#include <stdbool.h>
#endif
#include "raylib.h"
#include "Personaje.h"
#include "Plataformas.h"
#include "Moneda.h"
#include "Enemy.h"
#include "Puerta.h"

int main(void)
{
    //Abre una ventana de 1024x768 píxeles
    InitWindow(1280, 720, "Juego con base en Raylib");

    //Se carga una textura para el fondo
    Texture2D atras = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/Sprites/atras.png");

    //Se establece un límite de FPS
    SetTargetFPS(60);

    //Se le otorga una definición a cada clase para llamarla en el main
    Personaje jugador;

    Plataformas plat;

    Moneda coin;

    Enemy malo;

    Puerta puerta;

    //Se carga cada texturaque se utilizará
    jugador.loadPer();

    plat.loadPlat();

    coin.loadMon();

    malo.loadEnem();

        // Bucle principal
        while (!WindowShouldClose())
        {
            //Se detectan las colisiónes entre el jugador, los enemigos y la moneda
            bool isColliding = CheckCollisionRecs(jugador.GetRect(), malo.EnemyHitBox1());

            bool iColliding = CheckCollisionRecs(jugador.GetRect(), malo.EnemyHitBox2());

            bool sColliding = CheckCollisionRecs(jugador.GetRect(), malo.EnemyHitBox3());

            bool Colliding = CheckCollisionRecs(jugador.GetRect(), coin.coins());

            bool Coliding = CheckCollisionRecs(jugador.GetRect(), puerta.tomaRect());

            //Comienza a dibujar
            BeginDrawing();

            //Carga el movimiento y demás acciones que se llevan a cabo dentro del juego
            jugador.movePer();

            malo.moveEnem();

            malo.retryEnem();

            puerta.moveDoor();

            //Se dibuja un una imagen como fondo
            DrawTextureEx(atras, {0,0}, 0.0f, 1024 / 768, WHITE);

            //Se cargan las texturas de cada elemento dentro del juego
            //Personaje
            jugador.drawPer(); //Se dibuja al personaje

            //Se carga cada instancia del personaje al momento de interactuar
            jugador.drawHitBox(isColliding);
            jugador.dawHitBox(iColliding);
            jugador.draHitBox(Colliding);
            jugador.rawHitBox(sColliding);
            jugador.AHitBox(Coliding);

            //Plataformas
            plat.drawPlat();

            //Moneda
            coin.drawMon(); //Dibuja la moneda
            coin.DibujaHitBox(Colliding); //Se carga la hitbox

            //Enemigos
            malo.drawEnem();//Se dibuja al enemigo

            //Puerta
            puerta.drawDoor(); //Se dibuja la puerta

            //Indica al jugador si le quedan oportunidades
            jugador.perder();

            //Se indican los controles
            DrawText("Presiona <- o -> para desplazar al personaje", 10, 670, 20, BLACK);
            DrawText("Presiona ESPACIO para saltar", 10, 700, 20, BLACK);

            //Se indica la manera de reiniciar el juego
            DrawText("Presiona R para reiniciar", 750, 20, 30, DARKBLUE);

            //Termina de dibujar
            EndDrawing();
        }

        //Se libera el espacio utilizado por el fondo personalizado
        UnloadTexture(atras);

        //Se libera el espacio ocupado por los componentes de las clases

        jugador.unloadPer(); //Elimina los elementos del personaje

        plat.unloadPlat(); //Elimina los elementos de las plataformas

        coin.unloadMon(); //Elimina los elementos de la moneda

        malo.unloadEnem(); //Elimina los elementos de los enemigos

        //Cierra la ventana
        CloseWindow();

        return 0;
    }