#include "Plataformas.h"

Texture2D plat;

//Se carga la textura de las plataformas
void Plataformas::loadPlat() {
	plat = LoadTexture("C:/Users/Desktop/Downloads/Documentos MAVI/Raylib-vs2022 Limpio/Componentes/Sprites/plataformas.png");
};

//Se dibujan las plataformas en sus respectivas posiciones
void Plataformas::drawPlat() {
	DrawTextureEx(plat, { 50,600 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 230,500 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 470,500 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 660,400 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 470,300 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 660,200 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 730,170 }, 0.0f, 0.3f, WHITE);
	DrawTextureEx(plat, { 1170,150 }, 0.0f, 0.3f, WHITE);
};

//Se libera el espacio que ocupan las texturas
void Plataformas::unloadPlat() {
	UnloadTexture(plat);
};
