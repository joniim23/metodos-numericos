#include <iostream>
#include <math.h>
#include "../Include/biseccion.h"
#include "../Include/funciones_aux.h"

// se tiene una función f : R-> R continua
// input: dos reales a, b tales que a < b, y tales que f(a)*f(b) < 0, y un real epsilon > 0
using namespace std;

void biseccion(float x0, float x1, float xAux, float epsilon) {
	while (x1 - x0 >= epsilon) { //o bien otras condiciones...

		xAux = (x0 + x1) / 2;

		if (funcionDeEquis(xAux) == 0)
//			return *xAux;
			cout << "Devolviendo la raiz '" << xAux << "'." << endl;
		else if (signo(funcionDeEquis(xAux)) * signo(funcionDeEquis(x0)) < 0)
			x1 = xAux;
		else
			x0 = xAux;
	}
	cout << "Devolviendo la raiz '" << xAux << "'." << endl;
}

float variante_de_biseccion(float x0, float x1, const float epsilon, float w) {

	float xAux = 0, funcionDeXAux = 0;
	int i = 1;

	do {

		xAux = w * x0 + (1 - w) * x1;
		funcionDeXAux = funcionDeEquis(xAux);

		imprimirValoresIteracion(i, x0, x1, xAux, funcionDeXAux);

		if (funcionDeXAux == 0) {
			cout << "Devolviendo la raiz '" << xAux << "'." << endl;
			return xAux;
		}
		else if ( signo(funcionDeXAux) * signo(funcionDeEquis(x0)) < 0) {
			x1 = xAux;
			cout << "X1 ahora es XAux" << endl;
		}
		else {
			x0 = xAux;
			cout << "X0 ahora es XAux" << endl;
		}

		i++;

	} while (abs(x1 - x0) >= epsilon || abs(funcionDeEquis(xAux)) >= epsilon); //o bien otras condiciones...

	cout << "Devolviendo la raiz '" << xAux << "'." << endl;
	return xAux;

}
