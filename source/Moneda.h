#pragma once
#include "raylib.h"
class Moneda
{
public:
	Rectangle coins();
	void DibujaHitBox(bool Colliding);

	void loadMon();
	void drawMon();
	void unloadMon();
};

