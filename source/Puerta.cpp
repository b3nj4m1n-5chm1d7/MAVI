#include "Puerta.h"

Vector2 posicion = { 780, 8 };
float alto = 200;
float ancho = 20;

void Puerta::drawDoor()
{
	DrawRectangle(posicion.x, posicion.y, ancho, alto, RED);
}

Rectangle Puerta::tomaRect()
{
	return Rectangle{ posicion.x, posicion.y, ancho, alto};
}

void Puerta::DrawHitBox(bool Coliding)
{
	Color outlineColor = Coliding ? BLUE : BLACK;
	DrawRectangleLinesEx(tomaRect(), 3, outlineColor);
}

void Puerta::moveDoor()
{
	//Detecta si se mantiene el click izquerdo para transformar la puerta en una plataforma
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		posicion.x = 920;
		posicion.y = 240;
		ancho = 180;
		alto = 20;
	}
	if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
		posicion.x = 780;
		posicion.y = 8;
		alto = 200;
		ancho = 20;
	}
}