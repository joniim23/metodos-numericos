#include <iostream>
#include <conio.h>
#include <math.h>

using namespace std;

float funcionDeEquis(const float x) {
	float valorDeRetorno = 0;

	valorDeRetorno = (3 * cos( x )) + 2;
	cout << "La funcion en '" << x << "' retorna el valor " << valorDeRetorno << endl;
	return valorDeRetorno;
}

void ingresar_valores_iniciales(float * x0, float * x1, float * epsilon, float * w) {

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

		if (funcionDeEquis(*x0) * funcionDeEquis(*x1) > 0)
			cout << " f(x0) * f(x1) debe ser menor que 0" << endl;
	} while (funcionDeEquis(*x0) * funcionDeEquis(*x1) > 0);

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
