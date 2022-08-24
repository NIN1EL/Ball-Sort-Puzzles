#include "Juego.h"

class Imagen {
private:
	string id;
	Texture *textura;
	Sprite *sprite;
	Vector2i dimensiones;
public:
	Imagen();
	void CargarImagen(string direccion,int x, int y);
	Sprite* getSprite();
};