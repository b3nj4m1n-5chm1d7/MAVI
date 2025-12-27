#pragma once
#include "raylib.h"

class Objetivo
{
public:

	//HitBoxes de los objetivos
	Rectangle Obje1();
	Rectangle Obje2();
	Rectangle Obje3();

	//Accion del contacto de las hitboxes
	void GetColI(bool isColliding);
	void GetColII(bool iColliding);
	void GetColIII(bool Colliding);

	void loadObj(); //Carga las texturas

	void unloadObj(); //Descarga las texturas

	void drawObj(); //Dibuja los objetivos

	void moveObj(); //Movimiento de los objetivos

	void derrota(); //Perder
};