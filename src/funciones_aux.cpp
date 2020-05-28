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

void ingresarMatriz(int matr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "Ingresar valor para " << "matr[" << i << "][" << j << "]" << endl;
			cin >> matr[i][j];
		}
	}
}

void imprimirMatriz(int matr[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << "matr[" << i << "][" << j << "] = " << matr[i][j] << endl;
		}
	}
}

/*
 * 3 2 1
 * 4 6 5
 * 7 8 9
 *
 * 3 3 2
 * 4 4 3
 * 2 2 2
 *
 * 4 3 3
 * 4 4 3
 * 2 2 2
 */

/*
 * Una matriz no es dominante cuando:
 * 1. El valorDominante no es el mayor de la fila
 * 2. El valorDominante nunca es el mayor en ninguna fila
 */
bool esDiagonalDominante(int matr[3][3]) {
	bool esDominante = true;
	int contadorDominante = 0;


	for (int i = 0; i < 3 && esDominante; i++) {
		int valorDominante = abs(matr[i][i]);
		int mayorEnFila = -1;

		for (int j = 0; j < 3 && esDominante; j++) {
			int valorActual = abs(matr[i][j]);

			if (i != j) {
				if (valorDominante < valorActual)
					esDominante = false;

				if (valorActual > mayorEnFila)
					mayorEnFila = valorActual;

				if(valorDominante > mayorEnFila)
					contadorDominante ++;
			}

		}
	}

	if ( 0 >= contadorDominante )
		esDominante = false;

	if (esDominante)
		cout << "La matriz es dominante" << endl;
	else
		cout << "La matriz NO es dominante" << endl;

	return esDominante;
}

struct EstructuraMayor {
	int columnaDondeEstaElMayor;
	bool esMayorDeLaFila;
};

void intercambiarFilas(int matr[3][3], EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[3]) {

	int contador=0;
	int vectorBackup[3];

	// Verificamos que haya por lo menos un valor mayor en todas las filas
	{
		for(int i = 0; i < 3; i++) {
			if (vectorColumnaDondeEstaElMayorEnCadaFila[i].esMayorDeLaFila)
				contador++;
		}

		if (contador == 0)
			cout << "No se puede intercambiar";
	}

	for (int k = 0; k < 3; k++) {

		int filaDondeTieneQueEstarElMayor = vectorColumnaDondeEstaElMayorEnCadaFila[k].columnaDondeEstaElMayor;
		int mayorEnFila = -1;

		if (filaDondeTieneQueEstarElMayor != k){
			for (int j = 0; j < 3; j++) {
				//5 6 5
				vectorBackup[j] = matr[filaDondeTieneQueEstarElMayor][j];
				//4 4 5
				matr[filaDondeTieneQueEstarElMayor][j] = matr[k][j];
				//5 6 5
				matr[k][j] = vectorBackup[j];

				if (mayorEnFila < matr[k][j]) {
					mayorEnFila = matr[k][j];
					vectorColumnaDondeEstaElMayorEnCadaFila[k].columnaDondeEstaElMayor = j;
				}
			}
		}
	}

}


void transformarADiagonalDominante(int matr[3][3]) {

	EstructuraMayor vectorMayorEnCadaFila[3];
	bool hayRepetido = false;

	//Llenar los vectores
	for (int i = 0; i < 3 ; i++) {
		int valorDominante = abs(matr[i][i]);
		int mayorEnFila = -1;
		int columnaDondeEstaElMayor = -1;
		int contadorDeMayores = 0;

		for (int j = 0; j < 3 ; j++) {
			int valorActual = abs(matr[i][j]);

			if (i != j) {
				if (valorActual > mayorEnFila){
					columnaDondeEstaElMayor = j;
					mayorEnFila = valorActual;
				}
			}
		}

		for (int j = 0; j < 3; j++) {
			int valorActual = abs(matr[i][j]);

			if (valorActual == mayorEnFila)
				contadorDeMayores++;
		}

		vectorMayorEnCadaFila[i].columnaDondeEstaElMayor = columnaDondeEstaElMayor;

		if (contadorDeMayores == 1)
			vectorMayorEnCadaFila[i].esMayorDeLaFila = true;
		else
			vectorMayorEnCadaFila[i].esMayorDeLaFila = false;

	}


	/*
	if (sePuedenIntercambiarFilas(vectorFilasACambiar))
		intercambiarFilas(matr, vectorFilasACambiar);
		esDiagonalDominante(matr);
	 */


	esDiagonalDominante(matr);
}




















