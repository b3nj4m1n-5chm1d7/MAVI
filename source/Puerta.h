#pragma once
#include "raylib.h"

class Puerta
{
public:
	Rectangle tomaRect();;

	void drawDoor();
	void moveDoor();
	void DrawHitBox(bool Coliding);
};