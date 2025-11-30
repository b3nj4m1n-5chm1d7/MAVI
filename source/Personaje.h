#pragma once
#include "raylib.h"

class Personaje
{
public:
	Rectangle GetRect();
	void drawHitBox(bool isColliding);
	void dawHitBox(bool iColliding);
	void rawHitBox(bool sColliding);
	void draHitBox(bool Colliding);
	void AHitBox(bool Coliding);

	void movePer();
	void drawPer();
	void perder();
	void loadPer();
	void unloadPer();
};