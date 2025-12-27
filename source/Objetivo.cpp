#include "Objetivo.h"
#include <cmath>

//Caracteristicas del jugador
int vidas = 10;
Sound perder;
int malo = false;

//Caracteristicas generales de los objetivos
Texture2D Obj1;
Texture2D Obj2;
Texture2D Obj3;
int vel = 5.0f;

//Caracteristicas individuales de los objetivos
Vector2 posi1 = { 0,GetRandomValue(40,350)};

Vector2 posi2 = { GetRandomValue(100,1280),0};

Vector2 posi3 = {GetRandomValue(100,1230),0};

//Inicio de MRUV
int velocidad = 0.0f;
int gravedad = 400.0f;

//MRUV junto a rebote para el tercer objetivo
float velocityY = 0.0f;
float rebote = 0.8f;
float relajo = 0.95f;

//Primer HitBox
Rectangle Objetivo::Obje1() {

	return Rectangle{ posi1.x, posi1.y, float(Obj1.width * 0.2f), float(Obj1.height * 0.2f) };

};

//Segunda HitBox
Rectangle Objetivo::Obje2() {

	return Rectangle{ posi2.x, posi2.y, float(Obj2.width * 0.1f), float(Obj2.height * 0.1f) };

};

//Tercer HitBox
Rectangle Objetivo::Obje3() {

	return Rectangle{ posi3.x, posi3.y, float(Obj3.width * 0.25f), float(Obj3.height * 0.25f) };

};

void Objetivo::GetColI(bool isColliding) {
	if (isColliding) {
		posi1.x = -20;
		posi1.y = GetRandomValue(40, 350);
	}
};

void Objetivo::GetColII(bool iColliding) {
	if (iColliding) {
		posi2.y = -5;
		posi2.x = GetRandomValue(30, 1230);
		velocidad = 0.0f;
	}
};

void Objetivo::GetColIII(bool Colliding){
	if (Colliding) {
		posi3.y = -5;
		posi3.x = GetRandomValue(30, 1230);
	}
};

//Se carga la textura de los objetivos
void Objetivo::loadObj() {
	Obj1 = LoadTexture("Componentes/Sprites/ball.png");
	Obj2 = LoadTexture("Componentes/Sprites/moneda.png");
	Obj3 = LoadTexture("Componentes/Sprites/capsula.png");
	perder = LoadSound("Componentes/Sonidos/trompeta.mp3");
};

//Se libera el espacio que ocupan los objetivos
void Objetivo::unloadObj() {
	UnloadSound(perder);
	UnloadTexture(Obj1);
	UnloadTexture(Obj2);
	UnloadTexture(Obj3);
};

//Se dibujan los objetivos
void Objetivo::drawObj() {
	DrawTextureEx(Obj1, posi1, 0.0f, 0.2f, WHITE);
	DrawTextureEx(Obj2, posi2, 0.0f, 0.1f, WHITE);
	DrawTextureEx(Obj3, posi3, 0.0f, 0.25f, WHITE);
	DrawText(TextFormat("Vidas: %d", vidas), 10, 10, 20, WHITE);
};

//Se establece el movimiento de los objetivos
void Objetivo::moveObj() {

	posi1.x += vel;

	if (posi1.x >= 1250) {
		posi1.x = -20;
		posi1.y = GetRandomValue(40, 350);
		vidas--;
	}

	velocidad += gravedad * GetFrameTime();
	posi2.y += velocidad * GetFrameTime();

	if (posi2.y >= 720) {
		posi2.y = -5;
		posi2.x = GetRandomValue(70, 1230);
		velocidad = 0.0f;
		vidas--;
	}

	velocityY += gravedad * GetFrameTime();
	posi3.y += velocityY * GetFrameTime();

	if (posi3.y >= 645) {
		posi3.y = 645;
		velocityY = -velocityY * rebote;
		rebote *= relajo;
		if (fabs(velocityY) < 5.0f) {
			posi3.y = -5;
			posi3.x = GetRandomValue(30, 1230);
			velocityY = 0.0f;
			rebote = 0.8f;
			vidas--;
		}
	}
};

void Objetivo::derrota(){
	if (vidas <= 0) {
		malo = true;
		InitWindow(300, 300, "Perdiste");
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(BLACK);
			if (malo) {
				PlaySound(perder);
			}
			DrawText("PERDISTE", 20, 100, 50, RED);
			DrawText("Toca el borde de la ventana del juego", 40, 250, 10, WHITE);
			EndDrawing();
		}
	}
};