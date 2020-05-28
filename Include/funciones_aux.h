void ingresar_valores_iniciales(float * x0, float * x1, float * epsilon, float * w);
float funcionDeEquis(const float x);
int signo(float z);
void imprimirValoresIteracion(int const iteracionActual, float const x0, float const x1, float const xAux, float const funcionDeXAux);

void ingresarMatriz(int matr[][3]);
void imprimirMatriz(int matr[][3]);
bool esDiagonalDominante(int matr[][3]);
void intercambiarFilas(int matr[3][3], int vect[3]);
void transformarADiagonalDominante(int matr[][3]);

