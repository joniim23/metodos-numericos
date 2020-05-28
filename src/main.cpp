#include <iostream>
#ifdef __linux__
#include <curses.h>
#else
#include <conio.h>
#endif
#include "../Include/biseccion.h"
#include "../Include/funciones_aux.h"
#include "../Include/menu.h"

using namespace std;

int main() {

	float x0 = 0, x1 = 0, epsilon = 0, w = 0;

	int opcion = 0;

	opcion = menu(opcion);

	if (opcion == 1) {
		ingresar_valores_iniciales(&x0, &x1, &epsilon, &w);
		variante_de_biseccion(x0, x1, epsilon, w);
	} else {
		int matr[3][3];
		ingresarMatriz(matr);
		imprimirMatriz(matr);
		if (!esDiagonalDominante(matr))
			transformarADiagonalDominante(matr);
		/*
		if (esDiagonalDominante(matr))
			armarEcuacionJacobi;
		; */

//		esDiagonalDominante(matr);
	}



	/*
	cout << "Obtuve los siguientes valores" << endl;
	cout << "X0 = " << x0 << endl;
	cout << "X1 = " << x1 << endl;
	cout << "Epsilon = " << epsilon << endl;
	cout << "W = " << w << endl;

	cout << "Se utilizara la formula '3 * cos(x) + 2'" << endl;
	*/


//	getch();
	return 0;
}
