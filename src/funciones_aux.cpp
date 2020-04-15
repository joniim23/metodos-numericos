#include <iostream>
#include <math.h>

#ifdef __linux__
#include <curses.h>
#else
#include <conio.h>
#endif


using namespace std;

float funcionDeEquis(const float x) {
	float valorDeRetorno = 0;

	valorDeRetorno = (3*cos(x))+2;
//	cout << "La funcion en '" << x << "' retorna el valor " << valorDeRetorno << endl;
	return valorDeRetorno;
}

void ingresar_valores_iniciales(float * x0, float * x1, float * epsilon, float * w) {

	float funcionDeX0 = 0, funcionDeX1 = 0;
	/**
	 * Verificamos que w esté entre 0 y 1
	 */
	do {
		cout << "Ingrese un valor w que este entre 0 y 1" << endl;
		cin >> *w;

		if (*w < 0 || *w > 1)
			cout << "w debe ser un valor entre 0 y 1" << endl;

	} while (*w < 0 || *w > 1);

	/**
	 * Verificamos condiciones para x0 y x1
	 */
	do {
		do {
			cout << "Ingrese un valor X0" << endl;
			cin >> *x0;

			cout << "Ingrese un valor X1" << endl;
			cin >> *x1;

			if(*x0 > *x1)
				cout << "X1 debe ser mayor que X0" << endl;
		} while (*x0 > *x1);

		funcionDeX0 = funcionDeEquis(*x0);
		funcionDeX1 = funcionDeEquis(*x1);

		if ( funcionDeX0 * funcionDeX1 > 0)
			cout << " f(x0) * f(x1) debe ser menor que 0" << endl;
	} while ( funcionDeX0 * funcionDeX1 > 0);

	/**
	 * Verificamos epsilon
	 */
	do {
		cout << "Ingrese un valor epsilon" << endl;
		cin >> *epsilon;

		if ( *epsilon < 0 )
			cout << "El valor epsilon debe ser mayor que 0" << endl;
	} while (*epsilon < 0);
}

int signo(float z) {
	if (z == 0)
		return 0;
	else if (z > 0)
		return 1;
	else
		return -1;
}

void imprimirValoresIteracion(int const iteracionActual, float const x0, float const x1, float const xAux, float const funcionDeXAux) {

	cout << "Iteracion Actual = " << iteracionActual << " | X0 = " << x0 << " | X1 = " << x1 << " | xAuxiliar = " << xAux << " | funcion(xAux) = " << funcionDeXAux << endl;
}
