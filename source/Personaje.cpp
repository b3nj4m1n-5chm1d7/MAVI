#include "Personaje.h"

//Posición
Vector2 pos = { 55.0f, 557.0f };
Vector2 actual = pos;

//Estadísticas
float velocidad = 5.0f;
float velocidadY = 0.0f;
bool salto = true;
float altura = 200.0f;
float gravedad = 6.0f;
float vidas = 3;

//Extras
Sound sonido;
Texture2D sprite;
float escala = 0.15f;
Color color = WHITE;

//Se carga el audio y apariencia del personaje
void Personaje::loadPer() {
    InitAudioDevice();
    sonido = LoadSound("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/Sonidos/salto.mp3");
    sprite = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/Sprites/hollow.png");
};

//Se le otorga una HitBox al jugador
Rectangle Personaje::GetRect(){
    return Rectangle{ pos.x, pos.y, float(sprite.width * escala), float(sprite.height * escala) };
}

//Se dibuja la HitBox en determinado momento
void Personaje::drawHitBox(bool isColliding){
    if (isColliding) {
        pos = actual;
        vidas -= 1;
    }
}

void Personaje::dawHitBox(bool iColliding){
    if (iColliding) {
        pos = actual;
        vidas -= 1;
    }
}

void Personaje::rawHitBox(bool sColliding){
    if (sColliding) {
        pos = actual;
        vidas -= 1;
    }
}

void Personaje::draHitBox(bool Colliding){
    if (Colliding) {
        pos = actual;
    }
}

void Personaje::AHitBox(bool Coliding){
    if (Coliding) {
        pos.y = 155;
        salto = false;
    }
}

void Personaje::movePer(){

    //Se hace que la HitBox se actualiza junto con el jugador
    Rectangle jugadorBox = { pos.x, pos.y, sprite.width * escala, sprite.height * escala };

    //Mueve al jugador a la izquierda si se prtesiona alguna tecla
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A)) {       
        pos.x -= velocidad;       
    }

    //Mueve al jugador a la derecha si se presiona alguna tecla
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D)) {
        pos.x += velocidad;
    }

    //Reinicia la posición del jugador
    if (IsKeyPressed(KEY_R)) {
        pos = actual;
    }

    //Detecta si se presiona alguna tecla para activar el salto
    if (IsKeyPressed(KEY_SPACE) || IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
        pos.y -= altura;
        PlaySound(sonido);
        salto = true;
    }

    //Gravedad
    if (salto){
        pos.y += gravedad;
    }

    //Detecta las plataformas
    if (pos.y > 556 && pos.x >= 15 && pos.x <= 115 && pos.y < 565) {
        pos.y = 557;
    }
    if (pos.y > 459 && pos.x >= 190 && pos.x <= 295 && pos.y < 470) {
        pos.y = 460;
    }
    if (pos.y > 459 && pos.x >= 430 && pos.x <= 530 && pos.y < 470) {
        pos.y = 460;
    }
    if (pos.y > 359 && pos.x >= 625 && pos.x <= 730 && pos.y < 370) {
        pos.y = 360;
    }
    if (pos.y > 259 && pos.x >= 435 && pos.x <= 535 && pos.y < 269){
        pos.y = 260;
    }
    if (pos.y > 159 && pos.x >= 625 && pos.x <= 720 && pos.y < 169) {
        pos.y = 160;
    }
    if (pos.y > 129 && pos.x >= 690 && pos.x <= 800 && pos.y < 161) {
        pos.y = 130;
    }

    //Final
    if (pos.y > 109 && pos.x >= 1135 && pos.x <= 1220&& pos.y < 120){
        pos.y = 110;
    }

    //Detecta si la colición con el exterior de la pantalla y detiene al jugador
    if (pos.x == -25.0f) {
        pos.x += velocidad;
    }
    else if (pos.x == 1225.0f) {
        pos.x -= velocidad;
    }
};

//Dibuja al personaje e indica sus coordenadas y vidas restantes
void Personaje::drawPer() {    
    DrawTextureEx(sprite, pos, 0.0f, escala, color);
    
    DrawText(TextFormat("Posicion: %.0f %.0f", pos.x, pos.y), 10, 20, 30, DARKGREEN);
    DrawText(TextFormat("Tienes: %.0f", vidas, " vidas"), 10, 45, 25, DARKGREEN);
};

//Se libera espacio
void Personaje::unloadPer() {
    UnloadTexture(sprite);
    UnloadSound(sonido);
    CloseAudioDevice;
};

//Se indica cuando el jugador perdió
void Personaje::perder() {
    //El personaje cambia de color si se encuentra en la parte inferior de la pantalla
    if (pos.y >= 650.0f) {
        salto = false;
        DrawText("PERDISTE", 280, 300, 150, RED);
        DrawText("presiona 'r' para reiniciar", 340, 450, 50, BLACK);
        color = RED;
    }
    else if (pos.y < 650.0f) {
        //El color del personaje regresa a la "normalidad" cuando reinicia
        color = WHITE;
    }
    //Si el jugador reinicia, perderá una vida
    if (IsKeyPressed(KEY_R)) {
        vidas -= 1;
    } if (vidas == 0|| vidas < 0){
        //Si el jugador se queda sin vidas, saltará un mensaje.
        DrawText("Tequedaste sin opostunidades", 16,300, 80, WHITE);
    } if (vidas <= -1) {
       CloseWindow();
    }
};