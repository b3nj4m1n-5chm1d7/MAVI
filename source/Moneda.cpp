#include "Moneda.h"

Texture2D moneda;
Vector2 pocition = { 1200,100 };
float escale = 0.085f;

Rectangle Moneda::coins()
{
	return Rectangle{pocition.x,pocition.y, float (moneda.width), float (moneda.height)};
}

void Moneda::DibujaHitBox(bool Colliding){
	if (Colliding) {
		escale = 0.0f;
		InitWindow(500, 300, "Ganaste");
		while (!WindowShouldClose()) {
			BeginDrawing();
			ClearBackground(WHITE);
			DrawText("GANASTE", 50, 100, 50, RED);
			EndDrawing();
		}
	}
}

//Se carga la textura de la moneda
void Moneda::loadMon() {
	moneda = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/Sprites/moneda.png");
};

//Se dibuja la moneda
void Moneda::drawMon() {
	DrawTextureEx(moneda, pocition, 0.0f, escale, BLUE);
};

//Se libera el espacio ocupado
void Moneda::unloadMon() {
	UnloadTexture(moneda);
}