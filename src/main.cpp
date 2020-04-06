#include <iostream>
#include <conio.h>
#include "../Include/biseccion.h"
#include "../Include/funciones_aux.h"

using namespace std;

int main() {

	float x0 = 0, x1 = 0, epsilon = 0, w = 0;

	ingresar_valores_iniciales(&x0, &x1, &epsilon, &w);

	cout << "Obtuve los siguientes valores" << endl;
	cout << "X0 = " << x0 << endl;
	cout << "X1 = " << x1 << endl;
	cout << "Epsilon = " << epsilon << endl;
	cout << "W = " << w << endl;

	cout << "Se utilizara la formula '3 * cos(x) + 2'" << endl;

	getch();
	return 0;
}
