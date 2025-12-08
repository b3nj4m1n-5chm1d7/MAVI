#pragma once
#include "raylib.h"

class Borde_Ventana
{
public:
	//HitBoxes de cada extremo de la pantalla
	Rectangle ExtremoIzq();
	Rectangle ExtremoDer();
	Rectangle ExtremoArri();
	Rectangle ExtremoAbajo();
};