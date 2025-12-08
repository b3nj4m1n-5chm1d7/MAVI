#pragma once
#include "raylib.h"
#include "Borde_Ventana.h"

class Pelota
{
public:
	Rectangle GetRect(); //HitBox de la pelota
	void GetCollision(Borde_Ventana& borde); //Detección de colisiones

	void drawPelota(); //Se dibuja la pelota
	void loadPelota(); //Se carga la textura de la pelota
	void unloadPelota(); //Se libera el espacio
	void movePelota(); //Se establece el mocimiento
};