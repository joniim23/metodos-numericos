#include <iostream>
#ifdef __linux__
#include <curses.h>
#else
#include <conio.h>
#endif
#include <algorithm>
#include "../Include/funciones_aux.h"
#include "../Include/jacobi.h"

using namespace std;

struct EstructuraMayor {
	int columnaDondeEstaElMayor;
	int cantidadDeMayores;
};

bool debug = false;

float matr[fil][10];
EstructuraMayor vectorMayorEnCadaFila[col];

/*
 * Matrices de Jacobi
 */

float matrizL[fil][10];
float matrizU[fil][10];
float matrizLU[fil][10];
float matrizB[fil][10];
float matrizD[fil][10];
float matrizInversaD[fil][10];
float matrizMenosInversaD[fil][10];
float matrizV[fil][10];
float matrizH[fil][10];
/*
 * Matrices de prueba
 */

// 3 2 1
// 4 6 5
// 7 8 9
float matrizDominante[fil][10] = {{3,2,1},{4,6,5},{7,8,9}};


//3 3 2
//4 4 3
//2 2 2
float matrizImposibleDominante[fil][10] = {{3,3,2},{4,4,3},{2,2,2}};

//5 6 5
//7 6 7
//1 2 2
float matrizPosibleDominante[fil][10] = {{5,6,5},{7,6,7},{1,2,2}};

//2 2 3
//7 6 6
//3 3 2
float matrizPosibleDominante2[fil][10] = {{2,2,3},{7,6,6},{3,3,2}};




/*!
 * Una matriz es dominante cuando:
 * 1. El valorDominante es el mayor de la fila
 * 2. Existe al menos unico mayor valorDominante en cualquiera de las filas
 */
bool esDiagonalDominante(float matr[][10]) {
	bool esDominante = true;
	int contadorDominante = 0;


	for (int i = 0; i < fil && esDominante; i++) {
		int valorDominante = abs(matr[i][i]);
		int mayorEnFila = -1;

		for (int j = 0; j < col && esDominante; j++) {
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

	for(int i = 0; i < fil; i++) {
		if (1 == vectorColumnaDondeEstaElMayorEnCadaFila[i].cantidadDeMayores)
			hayPorLoMenosUnMayor = true;
	}

	return hayPorLoMenosUnMayor;
}


void intercambiarFilas(float matr[][10], EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[]) {
	cout << endl;
	int vectorBackup[col];
	EstructuraMayor mayorDeFilaBackup;

	for (int k = 0; k < col; k++) {
		int filaDondeTieneQueEstarElMayor = vectorColumnaDondeEstaElMayorEnCadaFila[k].columnaDondeEstaElMayor;

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

			}

			/*
			 * Cambiando la información entre las dos filas que estamos analizando
			 */
			mayorDeFilaBackup = vectorColumnaDondeEstaElMayorEnCadaFila[k];
			vectorColumnaDondeEstaElMayorEnCadaFila[k] = vectorColumnaDondeEstaElMayorEnCadaFila[filaDondeTieneQueEstarElMayor];
			vectorColumnaDondeEstaElMayorEnCadaFila[filaDondeTieneQueEstarElMayor] = mayorDeFilaBackup;

			imprimirMatriz(fil, col, matr);
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

	for (int i = 0; i < fil ; i++) {
		int mayorEnFila = -1;
		int columnaDondeEstaElMayor = -1;
		int contadorDeMayores = 0;

		//Obtengo el índice y el mayor de la fila
		for (int j = 0; j < col ; j++) {
			int valorActual = abs(matr[i][j]);

			if (i != j) {
				if (valorActual > mayorEnFila){
					columnaDondeEstaElMayor = j;
					mayorEnFila = valorActual;
				}
			}
		}

		//Verifico cuantos mayores hay en la fila
		for (int j = 0; j < col; j++) {
			int valorActual = abs(matr[i][j]);

			if (valorActual == mayorEnFila)
				contadorDeMayores++;
		}

		//Guardo los datos obtenidos
		vectorMayorEnCadaFila[i].columnaDondeEstaElMayor = columnaDondeEstaElMayor;

		vectorMayorEnCadaFila[i].cantidadDeMayores = contadorDeMayores;

	}
}

void armarMatrizD(const float m[][10]) {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (i > j || i < j)
				matrizD[i][j] = 0;
			else
				matrizD[i][j] = matr[i][j];
		}
	}
}

void armarMatrizU(const float m[][10]) {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (i >= j)
				matrizU[i][j] = 0;
			else
				matrizU[i][j] = matr[i][j];
		}
	}
}

void armarMatrizL(const float m[][10]) {
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			if (i <= j)
				matrizL[i][j] = 0;
			else
				matrizL[i][j] = matr[i][j];
		}
	}
}
//1 2 3
//4 5 6
//7 8 9

void armarEcuacionesJacobi() {
	armarMatrizL(matr);
	armarMatrizU(matr);
	armarMatrizD(matr);
	sumarMatrices(fil, col, matrizL, matrizU, matrizLU);
	invertirMatrizConDiagonal(fil, col, matrizD, matrizInversaD);
	negarMatriz(fil, col, matrizInversaD, matrizMenosInversaD);
	multiplicarMatrices(fil, col, matrizMenosInversaD, matrizLU, matrizH);
	cout << "Ingresar los valores para la matriz B" << endl;
	ingresarMatriz(fil, 1, matrizB);
	multiplicarMatrices(fil, 1, matrizInversaD, matrizB, matrizV);
}

void imprimirEcuacionesJacobi() {
	cout << "Matriz L" << endl;
	imprimirMatriz(fil, col, matrizL);
	cout << "Matriz U" << endl;
	imprimirMatriz(fil, col, matrizU);
	cout << "Matriz D" << endl;
	imprimirMatriz(fil, col, matrizD);
	cout << "Matriz LU" << endl;
	imprimirMatriz(fil, col, matrizLU);
	cout << "Matriz D Inversa" << endl;
	imprimirMatriz(fil, col, matrizInversaD);
	cout << "Matriz - D Inversa" << endl;
	imprimirMatriz(fil, col, matrizMenosInversaD);
	cout << "Matriz H" << endl;
	imprimirMatriz(fil, col, matrizH);
	cout << "Matriz V" << endl;
	imprimirMatriz(fil, 1, matrizV);
}

int jacobi() {
	ingresarMatriz(fil, col, matr);
//	duplicarMatriz(fil, col, matrizPosibleDominante2, matr);
	imprimirMatriz(fil, col, matr);

	if (!esDiagonalDominante(matr)) {
		obtenerInformacionDeLasFilas(vectorMayorEnCadaFila);
		cout << "Como la matriz no es dominante, reviso que por lo menos haya un único mayor en alguna fila" << endl;

		if(hayPorLoMenosUnMayor(vectorMayorEnCadaFila))
			intercambiarFilas(matr, vectorMayorEnCadaFila);

		if(!esDiagonalDominante(matr)) {
			cout << "Como ya intentamos transformar a diagonal dominante y no lo logramos, salimos del programa" << endl;
			return -1;
		}
	}
		armarEcuacionesJacobi();
		imprimirEcuacionesJacobi();

	return 0;
}


