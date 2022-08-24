#pragma once
#include<iostream>
#include<string>
#include<sstream>
#include "SFML/Graphics.hpp"
#include "SFML/Window.hpp"
#include "Utiles.h"

using namespace sf;

using namespace std;

enum COLOR { pink, blue, green, red, yellow, white, brown };
enum POSITION { ini_x = 10, ini_y = 100, inc_x = 100, inc_y = 50, add_x_bola = 47, add_y_bola = 150, last_y = 250, down_tubo = 53 };
enum VENTANA { x = 0, y = 0 };
enum BOTON { jugar, niveles, nueva_partida, anterior, acerca_de ,salir, nivel1, nivel2, nivel3, nivel4, nivel5, bloqueado, check, botonX, btnGuardar, reiniciar};
enum FONDO_PANTALLA { inicio, juego, metalico ,acercaDe, repeticion ,gano , guardar};


class Utiles
{
public:
	static string getImageToColor(COLOR);//bola
	static string getImage();//tubo
	static String getFondoPantalla(FONDO_PANTALLA);
	static String getImageMetalica();
	static String getImageBoton(BOTON boton);
};