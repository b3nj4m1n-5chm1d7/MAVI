#include "Pelota.h"

//Apartado de apariencia
Texture2D pelota;

//Apartado de Movimiento
Vector2 pos = { 300, 300 }; //posición inicial
Vector2 velocidad = { 2 , 2 }; //velocidad base que posee la pelota

//Apartado de tamaño
float escala = 0.25f;

//Carga la textura de la pelota
void Pelota::loadPelota() {
	pelota = LoadTexture("Componentes/Sprites/ball.png");
};

//Se le otorga una HitBox a la pelota
Rectangle Pelota::GetRect() {
	return Rectangle{ pos.x, pos.y, float(pelota.width * escala), float(pelota.height * escala)};
}

//Se extablece la detección de los bordes de la ventana
void Pelota::GetCollision(Borde_Ventana& borde){

	Rectangle hit = GetRect();

	float anchoPel = pelota.width * escala;
	float altoPel = pelota.height * escala;

	//Detecta el choque con el límite izquierdo
	if (CheckCollisionRecs(hit, borde.ExtremoIzq())) {
		pos.x = 10.0f;
		velocidad.x = GetRandomValue(2, 4);
		velocidad.y = GetRandomValue(-4, 4);
	}

	//Detecta la colison con la zona derecha
	if (CheckCollisionRecs(hit, borde.ExtremoDer())) {
		pos.x = 800.0f - anchoPel - 10.0f;
		velocidad.x = GetRandomValue(-4, -2);
		velocidad.y = GetRandomValue(-4, 4);
	}

	//Detecta la colision con el límite superior
	if (CheckCollisionRecs(hit, borde.ExtremoArri())) {
		pos.y = 10.0f;
		velocidad.y = GetRandomValue(2, 4);
		velocidad.x = GetRandomValue(-4, 4);
	}

	//Detecta la colision con el borde inferior
	if (CheckCollisionRecs(hit, borde.ExtremoAbajo())) {
		pos.y = 600.0f - altoPel - 10.0f;
		velocidad.y = GetRandomValue(-4, -2);
		velocidad.x = GetRandomValue(-4, 4);
	}
};

//Se dibuja la pelota
void Pelota::drawPelota() {
	DrawTextureEx(pelota, pos, 0.0f, escala, WHITE);
	DrawText(TextFormat("Posicion =  %.0f %.0f", pos.x, pos.y), 10, 10, 15, BLACK);
};

//Se libera el espacio ocupado por la pelota
void Pelota::unloadPelota() {
	UnloadTexture(pelota);
};

//Se establecen los apartados del movimiento de la pelota
void Pelota::movePelota() {

	//Comienza moviendoze en la misma dirección siempre que se ejecute el programa
	pos.x += velocidad.x;
	pos.y += velocidad.y;

	//Se impide que la velocidad en cualquiera de los ejes sea igual a 0
	if (velocidad.x == 0) {
		velocidad.x = 1;
	}
	if (velocidad.y == 0) {
		velocidad.y = 1;
	}
	
	//Se aumenta velocidad
	if (IsKeyPressed(KEY_UP)){
		velocidad.x *= 1.1f;
		velocidad.y *= 1.1f;
	}

	//Se reduce velocidad
	if (IsKeyPressed(KEY_DOWN)) {
		velocidad.x *= 0.9f;
		velocidad.y *= 0.9f;
	}
};