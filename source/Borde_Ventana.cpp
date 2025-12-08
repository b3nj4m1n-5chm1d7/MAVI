#include "Borde_Ventana.h"

static const float g = 10.0f;

static const float ancho = 800;
static const float alto = 600;

//HitBox de la izquierda de la pantalla
Rectangle Borde_Ventana::ExtremoIzq() {
	return Rectangle{ 0, 0, g, alto };
};

//HitBox de la derecha de la pantalla
Rectangle Borde_Ventana::ExtremoDer() {
	return Rectangle{ ancho - g, 0, g, alto }; 
};

//HitBox de arriba de la pantalla
Rectangle Borde_Ventana::ExtremoArri() {
	return Rectangle{ 0, 0, ancho, g };
};

//HitBox de abajo de la pantalla
Rectangle Borde_Ventana::ExtremoAbajo() {
	return Rectangle{ 0, alto - g, ancho, g };
};