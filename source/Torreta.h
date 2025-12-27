#pragma once
#include "raylib.h"

class Torreta
{
public:

	Rectangle bala(); //HitBox de la munición

	void ColisionI(bool isColliding);
	void ColisionII(bool iColliding);
	void ColisionIII(bool Colliding);

	void loadTorreta(); //Carga las texturas

	void unloadTorreta(); //Descarga las texturas

	void moveTorreta(); //Se establece el movimiento de la torreta

	void disparo(); //Se establecen las acciones del disparo

	void drawTorreta(); //Se dibujan los elementos de la torreta

	void victoria(); //Ganar
};

