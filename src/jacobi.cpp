#include <iostream>
#ifdef __linux__
#include <curses.h>
#else
#include <conio.h>
#endif
#include <algorithm>
#include "../Include/funciones_aux.h"

using namespace std;

struct EstructuraMayor {
	int columnaDondeEstaElMayor;
	int cantidadDeMayores;
};

bool debug = false;

const int col = 3;
const int fil = 3;
int matr[fil][col];
EstructuraMayor vectorMayorEnCadaFila[col];

/*
 * Matrices de Jacobi
 */

int matrizL[fil][col];
int matrizU[fil][col];
int matrizLU[fil][col];
int matrizB[fil][1];
int matrizD1[fil][col];
int matrizMenosD1[fil][col];
int matrizV[fil][1];
int matrizH[fil][col];
/*
 * Matrices de prueba
 */

// 3 2 1
// 4 6 5
// 7 8 9
int matrizDominante[fil][col] = {{3,2,1},{4,6,5},{7,8,9}};


//3 3 2
//4 4 3
//2 2 2
int matrizImposibleDominante[fil][col] = {{3,3,2},{4,4,3},{2,2,2}};

//5 6 5
//7 6 7
//1 2 2
int matrizPosibleDominante[fil][col] = {{5,6,5},{7,6,7},{1,2,2}};




/*!
 * Una matriz es dominante cuando:
 * 1. El valorDominante es el mayor de la fila
 * 2. Existe al menos unico mayor valorDominante en cualquiera de las filas
 */
bool esDiagonalDominante(int matr[][col]) {
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

/*!
 * Verificamos que haya por lo menos un valor mayor en todas las filas
 */
bool hayPorLoMenosUnMayor(EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[]) {
	bool hayPorLoMenosUnMayor = false;

	for(int i = 0; i < 3; i++) {
		if (1 == vectorColumnaDondeEstaElMayorEnCadaFila[i].cantidadDeMayores)
			hayPorLoMenosUnMayor = true;
	}

	return hayPorLoMenosUnMayor;
}


void intercambiarFilas(int matr[][col], EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[]) {
	cout << endl;
	int vectorBackup[col];

	for (int k = 0; k < col; k++) {
		int filaDondeTieneQueEstarElMayor = vectorColumnaDondeEstaElMayorEnCadaFila[k].columnaDondeEstaElMayor;
		int mayorEnFila = -1;

		//Debugging
		if(debug) {
			int columnaDondeEstaElMayor[col];

			for (int l = 0; l < col; l++)
				columnaDondeEstaElMayor[l] = vectorColumnaDondeEstaElMayorEnCadaFila[l].columnaDondeEstaElMayor;

			cout << "Las columnas donde esta el mayor en cada fila es ";
			imprimirVector(columnaDondeEstaElMayor);

			cout << "filaDondeTieneQueEstarElMayor = " << filaDondeTieneQueEstarElMayor << endl;
			cout << "k = " << k << endl;
			cout << "columnaDondeEstaElMayor[k] = " << columnaDondeEstaElMayor[k] << endl;
			cout << "columnaDondeEstaElMayor[filaDondeTieneQueEstarElMayor] = " << columnaDondeEstaElMayor[filaDondeTieneQueEstarElMayor] << endl << endl;
		}

		/*
		 * La siguiente condicion se cumple si:
		 *  la fila donde tiene que estar el mayor no es la fila actual
		 *  esa fila donde tiene que estar el mayor es unica
		 */
		if (filaDondeTieneQueEstarElMayor != k && vectorColumnaDondeEstaElMayorEnCadaFila[k].cantidadDeMayores == 1) {
			cout << "Cambiando los datos de la fila " << filaDondeTieneQueEstarElMayor << " por la fila " << k << endl;

			for (int j = 0; j < col; j++) {
				vectorBackup[j] = matr[filaDondeTieneQueEstarElMayor][j];

				matr[filaDondeTieneQueEstarElMayor][j] = matr[k][j];

				matr[k][j] = vectorBackup[j];

				if (mayorEnFila < matr[k][j]) {
					mayorEnFila = matr[k][j];
					vectorColumnaDondeEstaElMayorEnCadaFila[k].columnaDondeEstaElMayor = j;
				}
			}
			imprimirMatriz(matr);
		}
	}

}


/*!
 * Obtengo de la matriz la siguiente información
 *  Mayor de cada fila
 *  Es el unico mayor el dato anterior
 *
 * @param vectorMayorEnCadaFila
 */
void obtenerInformacionDeLasFilas(EstructuraMayor vectorMayorEnCadaFila[]) {

	for (int i = 0; i < 3 ; i++) {
		int mayorEnFila = -1;
		int columnaDondeEstaElMayor = -1;
		int contadorDeMayores = 0;

		//Obtengo el índice y el mayor de la fila
		for (int j = 0; j < 3 ; j++) {
			int valorActual = abs(matr[i][j]);

			if (i != j) {
				if (valorActual > mayorEnFila){
					columnaDondeEstaElMayor = j;
					mayorEnFila = valorActual;
				}
			}
		}

		//Verifico cuantos mayores hay en la fila
		for (int j = 0; j < 3; j++) {
			int valorActual = abs(matr[i][j]);

			if (valorActual == mayorEnFila)
				contadorDeMayores++;
		}

		//Guardo los datos obtenidos
		vectorMayorEnCadaFila[i].columnaDondeEstaElMayor = columnaDondeEstaElMayor;

		vectorMayorEnCadaFila[i].cantidadDeMayores = contadorDeMayores;

	}
}

void obtenerMatricesDeJacobi(int matr[][col]) {

}

int jacobi() {
//	ingresarMatriz(matr);
	duplicarMatriz(matrizPosibleDominante, matr);
	imprimirMatriz(matr);

	if (!esDiagonalDominante(matr)) {
		obtenerInformacionDeLasFilas(vectorMayorEnCadaFila);
		cout << "Como la matriz no es dominante, reviso que por lo menos haya un único mayor en alguna fila" << endl;

		if(hayPorLoMenosUnMayor(vectorMayorEnCadaFila))
			intercambiarFilas(matr, vectorMayorEnCadaFila);
//
		if(!esDiagonalDominante(matr)) {
			cout << "Como ya intentamos transformar a diagonal dominante y no lo logramos, salimos del programa" << endl;
			return -1;
		}
	}
//		armarEcuacionJacobi;


	return 0;
}


