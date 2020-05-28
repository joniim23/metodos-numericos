#include <iostream>

using namespace std;


int menu(int opcion) {
	cout << "Elegir una opcion" << endl;
	cout << "1 -> Metodo biseccion" << endl;
	cout << "2 -> Metodo Jacobi" << endl;
	cin >> opcion;

	return opcion;
}
