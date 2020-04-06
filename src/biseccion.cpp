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

		if ( funcionDeEquis(xAux) == 0 )
//			return *xAux;
			cout << "Devolviendo la raiz '" << xAux <<"'." << endl;
		else if ( signo(funcionDeEquis(xAux)) * signo(funcionDeEquis(x0)) < 0)
			x1 = xAux;
		else
			x0 = xAux;
	}
	cout << "Devolviendo la raiz '" << xAux <<"'." << endl;
}

//Devuelve una raíz
void variante_de_biseccion(const float x0, const float x1, const float epsilon, float w) {

}
