#include <iostream>
#ifdef __linux__
#include <curses.h>
#else
#include <conio.h>
#endif

using namespace std;


int menu(int opcion) {
	cout << "Elegir una opcion" << endl;
	cout << "1 -> Metodo biseccion" << endl;
	cout << "2 -> Metodo Jacobi" << endl;
	cin >> opcion;

	return opcion;
}
