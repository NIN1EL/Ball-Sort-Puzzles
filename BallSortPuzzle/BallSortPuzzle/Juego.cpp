#include "Juego.h"

Juego::Juego(int dimension_x, int dimension_y, string titulo) {
	ventana1 = new RenderWindow(VideoMode(dimension_x, dimension_y), titulo);
	lista_movimientos = NULL;
	movimientos_rep = NULL;
	ventana1->setFramerateLimit(60);
	imagenes = new Imagenes();
	hubo_movimiento = false;
	bola_a_mover = NULL;
	evento = new Event;
	nivel = NULL;
	nivelesDesbloqueados = 1;
	movimientosRealizados = 0;
	Refrescar(1,true);
}


void Juego::Dibujar(int opcion,bool nuevo=true)
{
	switch (opcion) {
		case 1: VentanaInicio(); break;
		case 2: VentanaNiveles(); break;
		case 3: VentanaCargar(); break;
		case 4: VentanaAcercaDe(); break;
		case 5:if (nuevo) {
			lista_movimientos = new DoubleList<Movimiento*>();
			
			movimientos_rep = new DoubleList<Movimiento*>();
			nivel = new Nivel(L1);
			} 
			CargarNivel();
			break;
		case 6: VentanaGano(); break;
		default:
			VentanaRep(); break;
	}
}
void Juego::VentanaCargar() {
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::guardar));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	//
	ventana1->display();
}
void Juego::VentanaInicio()
{
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::inicio));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::jugar));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::niveles));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::nueva_partida));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::acerca_de));
	//
	ventana1->display();
}
void Juego::VentanaNiveles()
{
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::juego));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	int j = 1;
	int x = 100;
	for (int i = 1; i <= 5;i++) {
		if (i<=nivelesDesbloqueados) {
			j = i;
		}
		else {
			j = 6;
		}
		switch (j)
		{
		case 1:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::nivel1));
			break;
		case 2:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::nivel2));
			break;
		case 3:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::nivel3));
			break;
		case 4:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::nivel4));
			break;
		case 5:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::nivel5));
			break;
		default:
			ventana1->draw(imagenes->Imagen_Boton(BOTON::bloqueado));
			break;
		}
	}
	//
	ventana1->display();
}
void Juego::VentanaAcercaDe()
{
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::acercaDe));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	//
	ventana1->display();
}
void Juego::VentanaRep() {
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::repeticion));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::check));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::botonX));
	//
	ventana1->display();
}
void Juego::VentanaGano() {
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::gano));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	//
	ventana1->display();
}
void Juego::CargarNivel() {
	ventana1->clear();
	//
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::juego));
	ventana1->draw(imagenes->Imagen_Fondo_Pantalla(FONDO_PANTALLA::metalico));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::anterior));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::salir));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::btnGuardar));
	ventana1->draw(imagenes->Imagen_Boton(BOTON::reiniciar));
	// Tubos
	cargarTubos();
	//
	ventana1->display();
}
void Juego::Refrescar(int controlador_ventana, bool nuevo = true)
{
	Dibujar(controlador_ventana,nuevo);
	while (ventana1->isOpen())
	{
		ProcesarMouse(controlador_ventana);
	}
}

//Procesar mouse
void Juego::ProcesarMouse(int controlador_ventana) {
	switch (controlador_ventana) {
		case 1: controladorMouseVentanaInicio(); break;
		case 2: controladorMouseVentanaNiveles(); break;
		case 3: controladorMouseVentanaCargarPartida(); break;
		case 4: controladorMouseVentanaAcercaDe(); break;
		case 5: controladorMouseVentanaNivel(); break;
		case 6: controladorMouseVentanaGano(); break;
		default: controladorMouseVentanaRep(); break;
	}
}
void Juego::controladorMouseVentanaRep() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 954) && (cordenadas.x <= 1049) && (cordenadas.y >= 351) && (cordenadas.y <= 448)) {
					nuevo_nivel(false);
					Refrescar(5, false);
				}
				if ((cordenadas.x >= 341) && (cordenadas.x <= 458) && (cordenadas.y >= 351) && (cordenadas.y <= 448)) {
					repeticion();
					nuevo_nivel(false);
					Refrescar(5,false);
				}
			}
			break;
		}
	}
}
void Juego::controladorMouseVentanaNiveles() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {
					Refrescar(1);
				}
				if ((cordenadas.x >= 251) && (cordenadas.x <= 341) && (cordenadas.y >= 270) && (cordenadas.y <= 362)) {
					lista_movimientos = new DoubleList<Movimiento*>();
					movimientos_rep = new DoubleList<Movimiento*>();
					nivel = new Nivel(L1);
					Refrescar(5, false);
					imagenes->setX(300);
				}
				if ((cordenadas.x >= 402) && (cordenadas.x <= 490) && (cordenadas.y >= 270) && (cordenadas.y <= 362)) {
					if (nivelesDesbloqueados >= 2) {
						lista_movimientos = new DoubleList<Movimiento*>();
						movimientos_rep = new DoubleList<Movimiento*>();
						nivel = new Nivel(L2);
						Refrescar(5, false);
					}
					imagenes->setX(300);
				}
				if ((cordenadas.x >= 547) && (cordenadas.x <= 650) && (cordenadas.y >= 270) && (cordenadas.y <= 362)) {
					if (nivelesDesbloqueados >= 3) {
						lista_movimientos = new DoubleList<Movimiento*>();
						movimientos_rep = new DoubleList<Movimiento*>();
						nivel = new Nivel(L3);
						Refrescar(5, false);
					}
					imagenes->setX(300);
				}
				if ((cordenadas.x >= 698) && (cordenadas.x <= 800) && (cordenadas.y >= 270) && (cordenadas.y <= 362)) {
					if (nivelesDesbloqueados >= 4) {
						lista_movimientos = new DoubleList<Movimiento*>();
						movimientos_rep = new DoubleList<Movimiento*>();
						nivel = new Nivel(L4);
						Refrescar(5, false);
					}
					imagenes->setX(300);
				}
				if ((cordenadas.x >= 848) && (cordenadas.x <= 954) && (cordenadas.y >= 270) && (cordenadas.y <= 362)) {
					if (nivelesDesbloqueados >= 5) {
						lista_movimientos = new DoubleList<Movimiento*>();
						movimientos_rep = new DoubleList<Movimiento*>();
						nivel = new Nivel(L5);
						Refrescar(5, false);
					}
					imagenes->setX(300);
				}
			}
			break;
		}
	}
}
void Juego::controladorMouseVentanaGano() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {
					Refrescar(1);
				}
			}
			break;
		}
	}
}
void Juego::controladorMouseVentanaAcercaDe() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {
					Refrescar(1);
				}
			}
			break;
		}
	}
}
void Juego::controladorMouseVentanaInicio()
{
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 653) && (cordenadas.x <= 750) && (cordenadas.y >= 252) && (cordenadas.y <= 335)) {
					Refrescar(5);
				}
				if ((cordenadas.x >= 1284) && (cordenadas.x <= 1381) && (cordenadas.y >= 504) && (cordenadas.y <= 587)) {
					ventana1->close();
				}
				if ((cordenadas.x >= 353) && (cordenadas.x <= 446) && (cordenadas.y >= 353) && (cordenadas.y <= 437)) {
					Refrescar(2);
				}
				if ((cordenadas.x >= 958) && (cordenadas.x <= 1050) && (cordenadas.y >= 354) && (cordenadas.y <= 436)) {
					nivel = Archivos::Recuperar();
					if (nivel->getNivel() !=  NULL) {
						LEVEL level = nivel->getNivel();
						switch (level)
						{
						case L1:
							nivelesDesbloqueados = 1;
						case L2:
							nivelesDesbloqueados = 2;
						case L3:
							nivelesDesbloqueados = 3;
						case L4:
							nivelesDesbloqueados = 4;
						case L5:
							nivelesDesbloqueados = 5;
						default:
							break;
						}
						imagenes->setX(300);
						Refrescar(5, false);
					}
					else {
						Refrescar(3);
					}
				}
				if ((cordenadas.x >= 50) && (cordenadas.x <= 150) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {
					Refrescar(4);
				}
			}
			break;
		}
	}
}
void Juego::controladorMouseVentanaCargarPartida() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			ventana1->close();
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {
					Refrescar(1);
				}
			}
			break;
		}
	}
}

//Niveles
void Juego::agregar_movimientos(Movimiento* movimiento) {
	if (lista_movimientos->size() > 5) {
		lista_movimientos->remove(0);
	}
	lista_movimientos->add(movimiento);
	movimientos_rep->add(movimiento);
	if (movimientosRealizados <= 5) {
		movimientosRealizados++;
	}
}
bool Juego::gano() {
	Iterator<Tubo*>* ite = nivel->getTubos()->iterator();
	bool gano = true;
	COLOR color;
	int count;
	while (ite->hasNext())
	{
		count = 0;
		Iterator<Bola*>* it = ite->object()->iterator();
		if (!ite->object()->empty()) {
			count++;
			color = it->object()->getColor_();
			it->next();
		}
		while (it->hasNext()) {
			count++;
			if (it->object()->getColor_() != color) {
				gano = false;
				break;
			}
			it->next();
		}
		delete it;
		if (0 < count && count < 4) { gano = false; break; }
		ite->next();
	}
	delete ite;
	return gano;
}
void Juego::movimientoAutomatico(Tubo* Mov1, Tubo* Mov2,bool dibujar) {
	bola_a_mover = nivel->getTubos()->get(Mov2->getI())->pop();
	bola_a_mover->setY(40);

	if (dibujar) {Dibujar(5, false);}

	float y;
	if (nivel->getTubos()->get(Mov1->getI())->empty()) {y = last_y;}
	else {	y = (nivel->getTubos()->get(Mov1->getI())->top()->getY() - inc_y);}
	bola_a_mover->setPosition_(nivel->getTubos()->get(Mov1->getI())->getX() + add_x_bola, y);
	nivel->getTubos()->get(Mov1->getI())->push(bola_a_mover);
	bola_a_mover = NULL;

	if (dibujar) {	Dibujar(5, false);}
}
void Juego::repeticion()
{
	Iterator<Movimiento*>* iteMov = movimientos_rep->iteratorLast();
	Iterator<Movimiento*>* iteMovAux = movimientos_rep->iterator();
	while (iteMov->hasNext()) {//reordenar
		movimientoAutomatico(iteMov->object()->getTuboOrigen(), iteMov->object()->getTuboDestino(),false);
		iteMov->last();
	}
	Dibujar(5, false);
	while (iteMovAux->hasNext()) {//repetir
		movimientoAutomatico(iteMovAux->object()->getTuboDestino(), iteMovAux->object()->getTuboOrigen(), true);
		iteMovAux->next();
	}
	delete iteMov;
	delete iteMovAux;
}
void Juego::retroceder() {
	Iterator<Tubo*>* ite = nivel->getTubos()->iterator();
	while (ite->hasNext() && !lista_movimientos->empty()) {

		if (lista_movimientos->getLast()->getTuboDestino()->getI() == ite->object()->getI()) {
			nivel->getTubos()->set(ite->index(), lista_movimientos->getLast()->getTuboDestino());
			nivel->getTubos()->get(ite->index())->pop();
		}
		if (lista_movimientos->getLast()->getTuboOrigen()->getI() == ite->object()->getI()) {
			nivel->getTubos()->set(ite->index(), lista_movimientos->getLast()->getTuboOrigen());
			nivel->getTubos()->get(ite->index())->push(lista_movimientos->getLast()->getBola());
		}
		ite->next();
	}
	if (!lista_movimientos->empty()) lista_movimientos->removeLast();
	delete ite;
	Dibujar(5, false);
}
void Juego::tuboRange() {
	ite = nivel->getTubos()->iterator();
	while (ite->hasNext()) {
		if (((ite->object()->getX() + 130 <= cordenadas.x) && (cordenadas.x <= (ite->object()->getX() + 130 + 50)))
			&& ((ite->object()->getY() + 133 <= cordenadas.y) && (cordenadas.y <= ite->object()->getY() + 133 + 250))) {
			if (!(ite->object()->empty()) && !hubo_movimiento) {
				hubo_movimiento = true;
				bola_a_mover = ite->object()->pop();
				agregar_movimientos(new Movimiento(ite->object(), bola_a_mover));
				bola_a_mover->setY(100);
			}

			else if (hubo_movimiento && (((ite->object()->empty()) || (bola_a_mover->getColor_() == ite->object()->top()->getColor_())) && ite->object()->size() < 4)) {

				hubo_movimiento = false;
				float y;
				if (ite->object()->empty()) { y = last_y; }
				else { y = ite->object()->top()->getY() - inc_y; }
				bola_a_mover->setPosition_(ite->object()->getX() + add_x_bola, y);
				ite->object()->push(bola_a_mover);
				lista_movimientos->getLast()->setTuboDestino(ite->object());
				movimientos_rep->getLast()->setTuboDestino(ite->object());
				if (gano()) nuevo_nivel(true);
				bola_a_mover = NULL;
			}

			else {
				if (hubo_movimiento) {
					hubo_movimiento = false;
					float y;
					if ( nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI())->empty()) { y = last_y; }
					else { y = nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI())->top()->getY() - inc_y; }
					bola_a_mover->setPosition_(nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI())->getX() + add_x_bola, y);
					nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI())->push(bola_a_mover);
					lista_movimientos->getLast()->setTuboDestino(nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI()));
					movimientos_rep->getLast()->setTuboDestino(nivel->getTubos()->get(lista_movimientos->getLast()->getTuboOrigen()->getI()));
					if (gano()) nuevo_nivel(true);
					bola_a_mover = NULL;
				}
			}
			break;
		}
		ite->next();
	}
	delete ite;
	Dibujar(5, false);
}
void Juego::controladorMouseVentanaNivel() {
	while (ventana1->pollEvent(*evento)) {
		switch (evento->type) {
		case Event::Closed:
			//Se debe eliminar los recursos que usan en las ventanas
			ventana1->close();
			delete nivel;
			delete ventana1;
			ventana1 = NULL;
			exit(1);
			break;
		case Event::MouseButtonPressed:
			if (Mouse::isButtonPressed(Mouse::Left)) {
				CordenadasMouse();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 0) && (cordenadas.y <= 100) && !hubo_movimiento) {
					retroceder();
				}
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 128) && (cordenadas.y <= 227)) {
					Archivos::Guardar(nivel);
				}
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 267) && (cordenadas.y <= 359)) {
					LEVEL level = nivel->getNivel();
					delete nivel;
					delete bola_a_mover;
					delete lista_movimientos;
					delete movimientos_rep;
					lista_movimientos = new DoubleList<Movimiento*>();
					movimientos_rep = new DoubleList<Movimiento*>();
					nivel = new Nivel(level);
					Refrescar(5, false);
				}
				tuboRange();
				if ((cordenadas.x >= 1300) && (cordenadas.x <= 1400) && (cordenadas.y >= 500) && (cordenadas.y <= 600)) {// boton salir
					Refrescar(1);
					delete nivel;
					delete bola_a_mover;
					delete lista_movimientos;
					delete movimientos_rep;
				}
			}
			break;
		}
	}
}
void Juego::CordenadasMouse()
{
	//ubicacion de lo que selecciono
	cordenadas = Mouse::getPosition(*ventana1);
	cordenadas = (Vector2i)ventana1->mapPixelToCoords(cordenadas);
	cout << cordenadas.x << "," << cordenadas.y << endl;
}
void Juego::cargarTubos() {
	// Tubos
	Iterator<Tubo*>* iteT = nivel->getTubos()->iterator();
	while (iteT->hasNext())
	{
		ventana1->draw(*iteT->object()->setScale_(300, 500));
		Iterator<Bola*>* ite = iteT->object()->iterator();
		while (ite->hasNext())
		{
			//Bolas
			ventana1->draw(*ite->object()->setScale_(200, 200));//si los tubos contienen bolas va a pintar las bolas en la ventana
			ite->next();
		}
		delete ite;
		iteT->next();
	}
	if (bola_a_mover != NULL) {
		if (hubo_movimiento) {
			bola_a_mover->setPosition(bola_a_mover->getX(), 50);
		}
		ventana1->draw(*bola_a_mover);
	}
	delete iteT;
	//cout << nivel->getTubos()->toString();
}
void Juego::nuevo_nivel(bool rep) {
	if (rep){
		Refrescar(7);
	}
	LEVEL level = Nivel::nextLevel(nivel->getNivel());
	if (level == FIN) {
		Refrescar(6);
		delete nivel;
		delete imagenes;
		delete bola_a_mover;
		delete lista_movimientos;
		delete movimientos_rep;
	}else {
		nivelesDesbloqueados++;
		delete imagenes;
	    delete nivel;
		delete bola_a_mover;
		delete lista_movimientos;
		delete movimientos_rep;
		hubo_movimiento = false;
		nivel = NULL;
		bola_a_mover = NULL;
		nivel = new Nivel(level);
		lista_movimientos = new DoubleList<Movimiento*>();
		movimientos_rep = new DoubleList<Movimiento*>();
		imagenes = new Imagenes;
	}
}