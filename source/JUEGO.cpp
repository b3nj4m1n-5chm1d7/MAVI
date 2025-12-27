#include "JUEGO.h"
#include "raylib.h"
#include "Torreta.h"
#include "Objetivo.h"

void JUEGO::game() {

    //Se le otorgan "nombres" a las clases dentro del main
    Torreta M;
    Objetivo O;

    //Se cargan las texturas
    M.loadTorreta();
    O.loadObj();

    //Los FPS se limitan a un máximo de 60
    SetTargetFPS(60);

    //Se inicia un bucle mientras la ventana no se cierre
    while (!WindowShouldClose()) {

        //Activa las colisiones
        bool isColliding = CheckCollisionRecs(M.bala(), O.Obje1());
        bool iColliding = CheckCollisionRecs(M.bala(), O.Obje2());
        bool Colliding = CheckCollisionRecs(M.bala(), O.Obje3());

        //Se llama al movimiento
        M.moveTorreta();
        O.moveObj();

        //Colision de la bala
        M.ColisionI(isColliding);
        M.ColisionII(iColliding);
        M.ColisionIII(Colliding);

        //Colision de los objetivos
        O.GetColI(isColliding);
        O.GetColII(iColliding);
        O.GetColIII(Colliding);

        //Se detecta la victoria y derrota del jugador
        M.victoria();
        O.derrota();

        //Comienza a dibujar
        BeginDrawing();

        //Se establece un fondo
        ClearBackground(RED);

        DrawRectangle(0, 0, 180, 110, Fade(BLACK, 0.5));
        DrawRectangleLines(0, 0, 180, 110, BLUE);

        //Se llama al disparo
        M.disparo();

        //Se dibuja la torreta
        M.drawTorreta();

        //Se dibujan los objetivos
        O.drawObj();

        //Termina de dibujar
        EndDrawing();
    }

    //Se libera el espacio ocupado por los objetos/clases
    O.unloadObj();
    M.unloadTorreta();

    //Se cierra la ventana
    CloseWindow();
};