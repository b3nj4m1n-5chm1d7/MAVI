#pragma once
#include "raylib.h"

class Enemy
{
public:
	Rectangle EnemyHitBox1();
	Rectangle EnemyHitBox2();
	Rectangle EnemyHitBox3();

	void drawhitbox(bool isColliding);

	void loadEnem();
	void drawEnem();
	void unloadEnem();
	void moveEnem();
	void retryEnem();
};

