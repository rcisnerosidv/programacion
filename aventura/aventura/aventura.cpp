/*
CONTROLES:
a - disparar
flechas - moverse
esc - pausa



BUGS:
-Todos los cuartos tienen los mismos limites
-El menu de pausa no guarda el estado
-No inicia nueva partida, pero si termina el programa
-si se presiona otra tecla que no se utilice desaparece el personaje

FALTA:
-Guardar partida
-Mover las clases al .h


*/






#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <list>

using namespace std;

const int Arriba{ 72 };
const int Izquierda{ 75 };
const int Derecha{ 77 };
const int Abajo{ 80 };
const int Enter{ 13 };
const int Esc{ 27 };

int cuarto{ 0 };
bool check_room{ false }, game_over{ false }, game{ true }, won_game{ false };


char ascii(int num) {			//convierte el numero entero del codigo ascii
	char char_ascii = num;		//a caracter para poder imprimirlo
	return char_ascii;
}

void goToXY(int x, int y) {						//te situa en la coordenada (x,y) de la consola
	HANDLE hCon;									
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;

	SetConsoleCursorPosition(hCon, dwPos);
}


void limites() {								//imprime los límites del escenario

	for (int i{ 2 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
}

void ocultarCursor() {								//oculta el cursor en la consola
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 2;
	cci.bVisible = false;

	SetConsoleCursorInfo(hCon, &cci);

}

void limpiarPantalla() {
	int x{ 2 }, y{ 4 };
	for (int i{ 2 }; i < 78; ++i) {
		goToXY(x, y); cout << " ";
		goToXY(x, y); cout << " ";
		x++;
		y++;
	}
}

class World {
	int tipo{ 0 };
	bool visitado{ false };
public:
	World(int _tipo, bool _visitado) : tipo(_tipo), visitado(_visitado) {}
	void cuarto0();
	void cuarto1();
	void cuarto2();
	void cuarto3();
	void cuarto4();
	void cuarto5();
	void cuarto6();
	void cuarto7();
	void pintarMapa();
};

void World::cuarto0() {
	visitado = true;
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 45; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << " ";
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(9 + 10, 2); cout << ascii(223); //cuarto 0
	goToXY(10 + 10, 2); cout << ascii(223);
}


void World::cuarto1() {
	bool visitado = true;
	if (visitado == true) {
		goToXY(9 + 10, 1); cout << ascii(223); // cuarto 1
		goToXY(10 + 10, 1); cout << ascii(223);
	}
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 44; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << " ";
		goToXY(i, 33); cout << " ";
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 15; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	for (int i{ 15 }; i < 21; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(2, i); cout << " ";
		goToXY(77, i); cout << " ";
	}

	for (int i{ 21 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);


}

void World::cuarto2() {
	for (int i{ 2 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}


	for (int i{ 4 }; i < 15; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	for (int i{ 15 }; i < 21; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(2, i); cout << ascii(186)
			;
		goToXY(77, i); cout << " ";
	}

	for (int i{ 21 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(6 + 10, 1); cout << ascii(223); //cuarto 2
	goToXY(7 + 10, 1); cout << ascii(223);
}

void World::cuarto3() {
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 45; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << " ";
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(9 + 10, 0); cout << ascii(223); // cuarto 3
	goToXY(10 + 10, 0); cout << ascii(223);
}

void World::cuarto4() {
	for (int i{ 2 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 15; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	for (int i{ 15 }; i < 21; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(2, i); cout << " ";
		goToXY(77, i); cout << " ";
	}

	for (int i{ 21 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(12 + 10, 1); cout << ascii(223); //cuarto 4
	goToXY(13 + 10, 1); cout << ascii(223);
}

void World::cuarto5() {
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 44; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << " ";
		goToXY(i, 33); cout << " ";
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 15; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	for (int i{ 15 }; i < 21; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(2, i); cout << " ";
		goToXY(77, i); cout << ascii(186);
	}

	for (int i{ 21 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}


	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(15 + 10, 1); cout << ascii(223); //cuarto 5
	goToXY(16 + 10, 1); cout << ascii(223);
}

void World::cuarto6() {
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 45; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << " ";
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(15 + 10, 0); cout << ascii(223); //cuarto 6
	goToXY(16 + 10, 0); cout << ascii(223);
}

void World::cuarto7() {
	for (int i{ 2 }; i < 37; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 37 }; i < 45; ++i) {			//imprime los pasajes a la siguiente pantalla
		goToXY(i, 3); cout << " ";
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 45 }; i < 78; ++i) {
		goToXY(i, 3); cout << ascii(205);
		goToXY(i, 33); cout << ascii(205);
	}

	for (int i{ 4 }; i < 33; ++i) {
		goToXY(2, i); cout << ascii(186);
		goToXY(77, i); cout << ascii(186);
	}

	goToXY(2, 3); cout << ascii(201);
	goToXY(2, 33); cout << ascii(200);
	goToXY(77, 3); cout << ascii(187);
	goToXY(77, 33); cout << ascii(188);
	goToXY(15 + 10, 2); cout << ascii(223); //cuarto 7
	goToXY(16 + 10, 2); cout << ascii(223);
}

void World::pintarMapa() {
	switch (tipo) {

	case 0:
		cuarto0();
		break;
	case 1:
		cuarto1();
		break;
	case 2:
		cuarto2();
		break;
	case 3:
		cuarto3();
		break;
	case 4:
		cuarto4();
		break;
	case 5:
		cuarto5();
		break;
	case 6:
		cuarto6();
		break;
	case 7:
		cuarto7();
		break;
	}

}

class Mono {
	int x, y, corazones{ 3 };
	bool arriba{ true }, abajo{ true }, izquierda{ true }, derecha{ true };  //muestran en que direccion se dirige el personaje
public:
	Mono(int _x, int _y, int _corazones, bool _arriba,
		bool _abajo, bool _izquierda, bool _derecha) : x(_x), y(_y), corazones(_corazones), arriba(_arriba), abajo(_abajo), izquierda(_izquierda), derecha(_derecha) {}
	int X() { return x; }
	int Y() { return y; }
	bool ARRIBA() { return arriba; }
	bool ABAJO() { return abajo; }
	bool IZQUIERDA() { return izquierda; }
	bool DERECHA() { return derecha; }
	int salud() { return corazones; }
	void cor() { corazones--; }
	void pintarAbajo();
	void pintarArriba();
	void pintarIzq();
	void pintarDer();
	void pintarCorazones();
	void borrar();
	void mover();
	void pause(World &W);
};

void Mono::pause(World &W) {
	if (kbhit()) {
		char tecla = getch();
		if (tecla == Esc) {
			if (tecla == Esc) {								//activa el menu pausa
				limpiarPantalla();
				limites();
				goToXY(37, 16); cout << "P A U S E";
				goToXY(38, 18); cout << "Continue";
				goToXY(38, 20); cout << "Save";
				goToXY(38, 22); cout << "Exit";

				for (int i{ 18 }; i <= 22;) {
					int opcion{ 0 };
					goToXY(37, i); cout << ascii(62);
					if (kbhit()) {
						char tecla_pausa = getch();
						if (tecla_pausa == Abajo && i < 22) {
							i += 2;
							opcion++;
							goToXY(37, i - 2); cout << " ";
							goToXY(37, i); cout << ascii(62);
						}
						if (tecla_pausa == Arriba && i > 18) {
							i -= 2;
							opcion--;
							goToXY(37, i + 2); cout << " ";
							goToXY(37, i); cout << ascii(62);
						}
						if (tecla_pausa == Enter && opcion == 0) {
							limites();
				
							pintarCorazones();
							if (arriba) {
								goToXY(x, y);
								pintarArriba();
								break;
							}
							else if (abajo) {
								goToXY(x, y);
								pintarAbajo();
								break;
							}
							else if (derecha) {
								goToXY(x, y);
								pintarDer();
								break;
							}
							else if (Izquierda) {
								goToXY(x, y);
								pintarIzq();
								break;
							}

						}
					}
				}
			}
		}
	}
}

void Mono::pintarAbajo() {
	goToXY(x, y); cout << " " << ascii(207);
	goToXY(x, y + 1); cout << ascii(47) << ascii(190) << ascii(92);
	goToXY(x, y + 2); cout << " " << ascii(220);
	goToXY(x, y + 3); cout << ascii(217) << " " << ascii(192);
}

void Mono::pintarIzq() {
	goToXY(x, y); cout << " " << ascii(207);
	goToXY(x, y + 1); cout << ascii(47) << ascii(179);
	goToXY(x, y + 2); cout << " " << ascii(254);
	goToXY(x, y + 3); cout << " " << ascii(217);
}

void Mono::pintarDer() {
	goToXY(x, y); cout << " " << ascii(207);
	goToXY(x, y + 1); cout << " " << ascii(179) << ascii(92);
	goToXY(x, y + 2); cout << " " << ascii(254);
	goToXY(x, y + 3); cout << " " << ascii(192);
}

void Mono::pintarArriba() {
	goToXY(x, y); cout << " " << ascii(111);
	goToXY(x, y + 1); cout << ascii(47) << ascii(219) << ascii(92);
	goToXY(x, y + 2); cout << " " << ascii(220);
	goToXY(x, y + 3); cout << ascii(217) << " " << ascii(192);
}
void Mono::borrar() {
	goToXY(x, y); cout << "   ";
	goToXY(x, y + 1); cout << "   ";
	goToXY(x, y + 2); cout << "   ";
	goToXY(x, y + 3); cout << "   ";
}

void Mono::mover() {
	if (kbhit()) {
		char tecla = getch();
		borrar();
		if (tecla == 'a') {
			pintarArriba();
		}

		if (tecla == Izquierda && x > 3) {
			x--;
			pintarIzq();
			izquierda = true;
			arriba = false;
			abajo = false;
			derecha = false;
		}
		if (tecla == Izquierda && x <= 3) {
			borrar();
			pintarIzq();
			izquierda = true;
			arriba = false;
			abajo = false;
			derecha = false;
		}
		if (tecla == Derecha && x + 3 < 77) {
			x++;
			pintarDer();
			izquierda = false;
			arriba = false;
			abajo = false;
			derecha = true;
		}
		
		if (tecla == Derecha && x + 3 <= 77) {
			borrar();
			pintarDer();
			izquierda = false;
			arriba = false;
			abajo = false;
			derecha = true;
		}
		if (tecla == Arriba && y > 4) {
			y--;
			pintarArriba();
			izquierda = false;
			arriba = true;
			abajo = false;
			derecha = false;

		}

		if (tecla == Arriba && y >= 4) {
			borrar();
			pintarArriba();
			izquierda = false;
			arriba = true;
			abajo = false;
			derecha = false;
		}

		if (tecla == Abajo && y + 3 < 32) {
			y++;
			pintarAbajo();
			izquierda = false;
			arriba = false;
			abajo = true;
			derecha = false;
		}

		if (tecla == Abajo && y + 3 <= 32) {
			borrar();
			pintarAbajo();
			izquierda = false;
			arriba = false;
			abajo = true;
			derecha = false;
		}

		if (tecla == Esc) {			
			/*//activa el menu pausa
			limpiarPantalla();
			limites();
			goToXY(37, 16); cout << "P A U S E";
			goToXY(38, 18); cout << "Continue";
			goToXY(38, 20); cout << "Save";
			goToXY(38, 22); cout << "Exit";
			
			for (int i{ 18 }; i <= 22;) {
				int opcion{ 0 };
				goToXY(37, i); cout << ascii(62);
				if (kbhit()) {
					char tecla_pausa = getch();
					if (tecla_pausa == Abajo && i < 22) {
						i+=2;
						opcion++;
						goToXY(37, i - 2); cout << " ";
						goToXY(37, i); cout << ascii(62);
					}
					if (tecla_pausa == Arriba && i > 18) {
						i-=2;
						opcion--;
						goToXY(37, i + 2); cout << " ";
						goToXY(37, i); cout << ascii(62);
					}
					if (tecla_pausa == Enter && opcion == 0) {
						limites();
						//pintarMapa();
						pintarCorazones(); 
						if (arriba) {
							goToXY(x, y);
							pintarArriba();
							break;
						}
						else if (abajo) {
							goToXY(x, y);
							pintarAbajo();
							break;
						}
						else if (derecha) {
							goToXY(x, y);
							pintarDer();
							break;
						}
						else if (izquierda) {
							goToXY(x, y);
							pintarIzq();
							break;
						}
		
					}
				}
			}*/
		}

	}

	//detecta la colision con los limites del escenario para poder hacer el cambio de pantalla
	if (x == 37 && y == 4 && arriba == true || x == 38 && y == 4 && arriba == true || x == 39 && y == 4 && arriba == true || x == 40 && y == 4 && arriba == true ||
		x == 41 && y == 4 && arriba == true || x == 42 && y == 4 && arriba == true || x == 43 && y == 4 && arriba == true) {
		borrar();
		x = 39;
		y = 29;
		pintarArriba();
		if (cuarto == 0) {
			++cuarto;
			check_room = true;
		}
		else if(cuarto == 1){
			cuarto += 2;
			check_room = true;
		}
		if (cuarto == 5) {
			cuarto++;
			check_room = true;
		}
		if (cuarto == 7) {
			cuarto -= 2;
			check_room = true;
		}
	}
	if (x == 37 && y + 3 == 32 && abajo == true || x == 38 && y + 3 == 32 && abajo == true || x == 39 && y + 3 == 32 && abajo == true || x == 40 && y + 3 == 32 && abajo == true ||
		x == 41 && y + 3 == 32 && abajo == true || x == 42 && y + 3 == 32 && abajo == true || x == 43 && y + 3 == 32 && abajo == true) {
		borrar();
		x = 39;
		y = 4;
		pintarAbajo();
		if (cuarto == 1) {
			cuarto--;
			check_room = true;
		} 
		if (cuarto == 3) {
			cuarto -= 2;
			check_room = true;
		}
		if (cuarto == 5) {
			cuarto += 2;
			check_room = true;
		}
		if (cuarto == 6) {
			cuarto--;
			check_room = true;
		}
	}
	if (x == 3 && y == 15 && izquierda == true || x == 3 && y == 16 && izquierda == true || x == 3 && y == 17 && izquierda == true || x == 3 && y == 18 && izquierda == true ||
		x == 3 && y == 19 && izquierda == true || x == 3 && y == 20 && izquierda == true || x == 3 && y == 21 && izquierda == true) {
		borrar();
		x = 74;
		y = 16;
		pintarIzq();
		if (cuarto == 1) {
			cuarto++;
			check_room = true;
		}
		if (cuarto == 4) {
			cuarto -= 3;
			check_room = true;
		}
		if (cuarto == 5) {
			cuarto--;
			check_room = true;
		}
	
	}
	if (x + 3 == 77 && y == 15 && derecha == true || x + 3 == 77 && y == 16 && derecha == true || x + 3 == 77 && y == 17 && derecha == true || x + 3 == 40 && y == 4 && arriba == true ||
		x + 3 == 77 && y == 19 && derecha == true || x + 3 == 77 && y == 20 && derecha == true || x + 3 == 77 && y == 21 && derecha == true) {
		borrar();
		x = 3;
		y = 16;
		pintarDer();
		if (cuarto == 1) {
			cuarto += 3;
			check_room = true;
		}
		else if (cuarto == 4) {
			cuarto++;
			check_room = true;
		}
		if (cuarto == 2) {
			cuarto--;
			check_room = true;
		}
		
	

	}
	
}

void Mono::pintarCorazones() {
	goToXY(10, 1); cout << "Mapa";
	goToXY(64, 1); cout << "Salud";
	goToXY(70, 1); cout << "     ";
	for (int i{ 0 }; i < corazones; ++i) {
		goToXY(70 + i, 1); cout << ascii(3);
	}
}


class BossA {
	int x, y;
public:
	BossA(int _x, int _y) : x(_x), y(_y) {}
	void pintar();
	void mover();
	void choque(class Mono &M);
};

void BossA::pintar() {
	goToXY(x, y); cout << ascii(184);
}

void BossA::mover() {
	goToXY(x, y); cout << " ";
	y++;
	if (y > 32) {
		x = rand() % 71 + 4;
		y = 4;
	}

	pintar();
}

void BossA::choque(class Mono &M) {
	if (x >= M.X() && x < M.X() + 3 && y >= M.Y() && y <= M.Y() + 3) {
		M.cor();
		M.borrar();
		M.pintarArriba();
		M.pintarCorazones();
		x = rand() % 71 + 4;
		y = 4;
	}
}

class Bala {
	int x, y;
public:
	Bala(int _x, int _y) : x(_x), y(_y){}
	int X() { return x; }
	int Y() { return y; }
	void mover();
	bool fuera();
};

void Bala::mover() {
	goToXY(x, y); cout << " ";
	if (y > 4) y--;
	goToXY(x, y); cout << "*";


}

bool Bala::fuera() {
	if (y == 4) return true;
	return false;
}

class Boss {
	int x{35}, y, hp;
	bool won = false;
public:
	Boss(int _x, int _y, int _hp, bool _won) : x(_x), y(_y), hp(_hp), won(_won){}
	void pintarBoss();
	int daño() { return hp--; }
	int vida() { return hp; }
	void wonGame();
};

void Boss::pintarBoss() {
	goToXY(35, 1); cout << "Boss: " << hp;
	goToXY(x, 4);
	for (int i = x; i <= 50; ++i) {
		cout << ascii(219);
	}
	goToXY(x, 5);
	for (int i = x; i <= 50; ++i) {
			cout << ascii(219);
	}
	goToXY(x, 6);
	for (int i = x; i <= 50; ++i) {
		cout << ascii(219);
	}
	goToXY(x, 7);
	for (int i = x; i <= 50; ++i) {
		cout << " ";
	}
	goToXY(x, 8);
	for (int i = x; i <= 50; ++i) {
		cout << ascii(219);
	}
	goToXY(33 +5, 5); cout << ascii(64);
	goToXY(42 +5, 5); cout << ascii(64);
}

void Boss::wonGame() {
	if (hp == 0) {
		won = true;
	}
}

void pintarMapa(int cuarto, World &W) {
	switch (cuarto) {

	case 0:
		W.cuarto0();
		break;
	case 1:
		W.cuarto1();
		break;
	case 2:
		W.cuarto2();
		break;
	case 3:
		W.cuarto3();
		break;
	case 4:
		W.cuarto4();
		break;
	case 5:
		W.cuarto5();
		break;
	case 6:
		W.cuarto6();
		break;
	case 7:
		W.cuarto7();
		break;
	}
}

int main() {

		Mono M(39, 29, 3, true, false, false, false);
		World W(0, false);
		Boss B(35, 5, 100, false);
		ocultarCursor();
		W.pintarMapa();
		//limites();
		M.pintarCorazones();
		//pintarMapa();
		M.pintarArriba();
		list<BossA*> A;
		list<BossA*>::iterator itA;
		for (int i{ 0 }; i < 7; ++i) {
			A.push_back(new BossA(rand() % 75 + 3, rand() % 5 + 4));
		}
		list<Bala*> BA;
		list<Bala*>::iterator it;

		while (!game_over) {

			while (check_room == true) {
				switch (cuarto) {
				case 0:
					W.cuarto0();
					check_room = false;
					break;
				case 1:
					W.cuarto1();
					check_room = false;
					break;
				case 2:
					W.cuarto2();
					check_room = false;
					break;
				case 3:
					W.cuarto3();
					check_room = false;
					break;
				case 4:
					W.cuarto4();
					check_room = false;
					break;
				case 5:
					W.cuarto5();
					check_room = false;
					break;
				case 6:
					W.cuarto6();
					B.pintarBoss();
					if (kbhit()) {
						char tecla = getch();
						if (tecla == Esc) {
							if (tecla == Esc) {								//activa el menu pausa
								limpiarPantalla();
								limites();
								goToXY(37, 16); cout << "P A U S E";
								goToXY(38, 18); cout << "Continue";
								goToXY(38, 20); cout << "Save";
								goToXY(38, 22); cout << "Exit";

								for (int i{ 18 }; i <= 22;) {
									int opcion{ 0 };
									goToXY(37, i); cout << ascii(62);
									if (kbhit()) {
										char tecla_pausa = getch();
										if (tecla_pausa == Abajo && i < 22) {
											i += 2;
											opcion++;
											goToXY(37, i - 2); cout << " ";
											goToXY(37, i); cout << ascii(62);
										}
										if (tecla_pausa == Arriba && i > 18) {
											i -= 2;
											opcion--;
											goToXY(37, i + 2); cout << " ";
											goToXY(37, i); cout << ascii(62);
										}
										if (tecla_pausa == Enter && opcion == 0) {
											limites();
											W.pintarMapa();
											M.pintarCorazones();
											if (M.ARRIBA()) {
												goToXY(M.X(), M.Y());
												M.pintarArriba();
												break;
											}
											else if (M.ABAJO()) {
												goToXY(M.X(), M.Y());
												M.pintarAbajo();
												break;
											}
											else if (M.DERECHA()) {
												goToXY(M.X(), M.Y());
												M.pintarDer();
												break;
											}
											else if (M.IZQUIERDA()) {
												goToXY(M.X(), M.Y());
												M.pintarIzq();
												break;
											}

										}
									}
								}
							}
						}
						if (tecla == 'a') {

							BA.push_back(new Bala(M.X() + 1, M.Y() - 2));

						}
					}
					M.pintarArriba();
					for (it = BA.begin(); it != BA.end();) {

						(*it)->mover();
						if ((*it)->fuera() || ((*it)->X() == 38 && (*it)->Y() == 5) || ((*it)->X() == 47 && (*it)->Y() == 5)) {
							goToXY((*it)->X(), (*it)->Y()); cout << " ";
							if (((*it)->X() == 38 && (*it)->Y() == 5) || ((*it)->X() == 47 && (*it)->Y() == 5)) {
								B.daño();
								B.pintarBoss();


							}
							delete(*it);
							it = BA.erase(it);
						}
						else {
							++it;
						}

					}

					for (itA = A.begin(); itA != A.end(); ++itA) {
						(*itA)->mover();
						(*itA)->choque(M);
					}

					if (B.vida() == 0) {
						check_room = false;
						game_over = true;
						won_game = true;
						game = false;
						break;

					}

					if (M.salud() == 0) {
						check_room = false;
						game_over = true;
						game = false;
					}

					M.mover();
					Sleep(15);
					break;
				case 7:
					W.cuarto7();
					check_room = false;
					break;

				}
			}

			M.mover();

			if (game_over == true && won_game) {
				system("CLS");
				limites();
				goToXY(37, 16); cout << "G A N A S T E !";
			}
			else if (game_over == true) {
				system("CLS");
				limites();
				goToXY(37, 16); cout << "G A M E  O V E R";
			}
			while (game == false) {
				goToXY(37, 17); cout << "Nuevo juego? Y/N";
				if (kbhit()) {
					char tecla = getch();
					if (tecla == 'y') {
						game_over = false;
						game = true;
						cuarto = 0;
						check_room = true;
						M.pintarArriba();
						M.pintarCorazones();

					}
					else if (tecla == 'n') {
						game = true;
						game_over = true;
						break;
					}
				}

			}

		}



	return 0;
}