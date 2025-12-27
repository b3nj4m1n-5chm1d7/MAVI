#include "Torreta.h"

//Caracteristicas del juego
int puntos = 0;
int ayuda = false;
Sound victory;

//Caracteristicas de la torreta
Texture2D torreta;
Sound shoot;
Vector2 pos = { 0,650 };
//Rotación de la torreta
int rot = 0.0f;
int move = 1;

//Caracteristicas del proyectil
Texture2D proyectil;
Vector2 posicion = { 100.0f, 670.0f };
float escala = 0.05f;
int velX = 700.0f;
int velY = -550.0f;
int grav = 650.0f;
int potencia = 0;

//Lineas de recuperación
Vector2 posiActual = posicion;
int velYorigen = velY;
int velXorigen = velX;
int GravOrigen = grav;

float activo = false;

//Se le otorga una HitBox a la bala
Rectangle Torreta::bala() {

	return Rectangle{ posicion.x, posicion.y, float(proyectil.width * escala), float(proyectil.height * escala) };

};

void Torreta::ColisionI(bool isColliding) {
	if (isColliding) {
		activo = false;
		puntos += 100;
	}
};

void Torreta::ColisionII(bool iColliding) {
	if (iColliding) {
		activo = false;
		puntos += 100;
	}
};

void Torreta::ColisionIII(bool Colliding){
	if (Colliding) {
		activo = false;
		puntos += 100;
	}
};

//Carga todos los elementos correspondientes a la torreta
void Torreta::loadTorreta() {
	InitAudioDevice();
	torreta = LoadTexture("Componentes/Sprites/pistola.png");
	shoot = LoadSound("Componentes/Sonidos/disparo.mp3");
	proyectil = LoadTexture("Componentes/Sprites/bola8.png");
	victory = LoadSound("Componentes/Sonidos/aplausos.mp3");
};

//Se libera el espacio ocupado por la torreta
void Torreta::unloadTorreta() {
	UnloadTexture(torreta);
	UnloadSound(shoot);
	UnloadTexture(proyectil);
	UnloadSound(victory);
	CloseAudioDevice();
};

//Se establece el movimiento de la torreta
void Torreta::moveTorreta(){

	//La torreta se desplaza hacia arriba o hacia abajo
	if (IsKeyDown(KEY_UP)) {
		rot -= move * 5;
	}
	else if (IsKeyDown(KEY_DOWN)) {
		rot += move * 5;
	}

	//Se otorga un límite a la rotación que puede tener la torreta
	if (rot >= 0 || IsKeyPressed(KEY_SPACE)) {
		rot = 0;
	} if (rot <= -60) {
		rot = -60;
	}
}

//Se establece el disparo
void Torreta::disparo(){

	if (!activo) { //Mientras no se encuentre activo ...

		//Mayor altura
		if (IsKeyDown(KEY_UP)) {
			velY -= move * 600 * GetFrameTime();
			grav -= move * 100 * GetFrameTime();
		}

		//Menor altura
		if (IsKeyDown(KEY_DOWN)) {
			velY += move * 600 * GetFrameTime();
			grav += move * 100 * GetFrameTime();
		}

		//Menor potencia
		if (IsKeyDown(KEY_LEFT)) {
			velX -= move * 600 * GetFrameTime();
		}

		//Mayor potencia
		if (IsKeyDown(KEY_RIGHT)) {
			velX += move * 600 * GetFrameTime();
			grav -= move * 100 * GetFrameTime();
		}

		potencia = velX + velY;

		//Al presionarse espacio...
		if (IsKeyPressed(KEY_SPACE)) {

			PlaySound(shoot);

			//Se reinician todos los valores
			posicion = posiActual;
			velY = velYorigen;
			velX = velXorigen;

			activo = true;
		}
	}
	//Mientras se encuentre activo
	else {

		posicion.x += velX * GetFrameTime();

		velY += grav * GetFrameTime();
		posicion.y += velY * GetFrameTime();

		DrawTextureEx(proyectil, posicion, 0.0f, escala, WHITE);

		//Detecta si el disparo sale de la pantalla
		if (posicion.x >= 1300 || posicion.y >= 800 || posicion.y <= 0) {
			activo = false;
			grav = GravOrigen;
		}
	}
};

//Se dibujan los elementos correspondientes a la torreta
void Torreta::drawTorreta() {
	DrawTextureEx(torreta, pos, rot, 0.5f, WHITE);
	DrawText(TextFormat("rotacion: %d", rot), 10, 85, 20, BLACK);
	DrawText(TextFormat("Potencia: %d", potencia), 10, 60, 20, BLUE);
	DrawText(TextFormat("Puntos: %d", puntos), 10, 35, 20, BLACK);
	DrawRectangle(390, 10, 320, 20, Fade(GREEN, 0.3));
	DrawText("Objetivo: LLegar a 500 puntos", 400, 10, 20, BLUE);
};

void Torreta::victoria(){
	if (puntos >= 500) {
		ayuda = true;
		InitWindow(300, 300, "Ganaste");
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLUE);
			if (ayuda) {
				PlaySound(victory);
			}
			DrawText("GANASTE", 20, 100, 50, DARKGREEN);
			DrawText("Toca el borde de la ventana del juego", 40, 250, 10, WHITE);
			EndDrawing();
		}
	}
};