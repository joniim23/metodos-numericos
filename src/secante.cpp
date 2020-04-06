/*
#include <stdio.h>
#include <math.h>

void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones);
double evaluarEn(double x);
double formula(double n0, double n1);
double error(double x0, double x1);

double formula(double n0, double n1) {

	double temp;
	double fx0 = evaluarEn(n0);
	double fx1 = evaluarEn(n1);
	temp = n1 - ((n1 - n0) * fx1) / (fx1 - fx0);

	return temp;

}

double evaluarEn(double x) {

	double temp;
	temp = (3 * sin(x)) + 2;

	return temp;
}

double error(double x0, double x1) {
	return fabs(x1 - x0);
}

void valoresIniciales(double *a, double *b, double *epsilon, int *iteraciones) {

	printf("Ingrese un numero real A:\n");
	scanf("%lf", a);

//Este bucle evita que A y B sean iguales, condicion inicial necesaria pues se requieren dos puntos distintos
	do {
		printf("Ingrese un numero real B:\n");
		scanf("%lf", b);
	} while (*a == *b);

	printf("Ingrese un Epsilon:\n");
	scanf("%lf", epsilon);

	printf("Ingrese la cantidad maxima de iteraciones:");
	scanf("%d", iteraciones);

	printf("\n");
}

int main() {

	int i;
	int iteraciones;

	double a;
	double b;
	double c; //Variable temporal usada para las iteraciones, almacena el resultado de la nueva aproximacion

	double epsilon;

	printf("La funcion elegida es: 3 * sen(x) + 2\n");

	valoresIniciales(&a, &b, &epsilon, &iteraciones);

	for (i = 0; i < iteraciones && error(a, b) > epsilon; i++) {

		c = formula(a, b);

		if (error(c, b) == 0) {
			printf("La funcion presenta una convergencia fuerte en x = %.15f",
					c);
			break;
		}

		printf("\nx%d = %.15lf\n dif: %.15lf\n\n", i + 2, c, error(c, b));

		a = b;
		b = c;

	}

}
*/
