#include "Enemy.h"

Texture2D enemy;
Vector2 pos1 = { 1175, 350 };
Vector2 pos2 = { 1175, 500 };
Vector2 pos3 = { 1175, 100 };

float velocity = 5.0f;
float scale = 0.25f;

//Carga las texturas del enemigo
void Enemy::loadEnem() {
	enemy = LoadTexture("Componentes/Sprites/vengamosca.png");
};

//Se dibujan a los enemigos
void Enemy::drawEnem() {
	DrawTextureEx(enemy, pos1, 0.0f, 0.25f, WHITE);
	DrawTextureEx(enemy, pos2, 0.0f, 0.25f, WHITE);
	DrawTextureEx(enemy, pos3, 0.0f, 0.25f, WHITE);
};

//Se libera el espacio que ocupan los enemigos
void Enemy::unloadEnem() {
	UnloadTexture(enemy);
};

//Movimiento de los enemigos
void Enemy::moveEnem() {	
	pos1.x -= velocity - 1.0f;

	if (pos1.x == -25) {
		pos1.x = 1250;
	}

	pos2.x -= velocity + 1;

	if (pos2.x == -5) {
		pos2.x = 1250;
	}

	pos3.x -= velocity + 3;

	if (pos3.x == 15) {
		pos3.x = 1250;
	}
};

//Reinicia las posiciones de los enemigos al reiniciar
void Enemy::retryEnem() {
	if (IsKeyPressed(KEY_R)) {
		pos1.x = 1175;
		pos2.x = 1175;
		pos3.x = 1175;
	}
}