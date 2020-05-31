void ingresar_valores_iniciales(float * x0, float * x1, float * epsilon, float * w);
float funcionDeEquis(const float x);
int signo(float z);
void imprimirValoresIteracion(int const iteracionActual, float const x0, float const x1, float const xAux, float const funcionDeXAux);

void ingresarMatriz(int nFil, int nCol, float matr[][10]);
void imprimirMatriz(int nFil, int nCol, float matr[][10]);
void imprimirVector(int vect[]);
void duplicarMatriz(int nFil, int nCol, float m1[][10], float m2[][10]);
void duplicarVector(int v1[], int v2[]);
void sumarMatrices(int nFil, int nCol, float m1[][10], float m2[][10], float mRet[][10]);
void invertirMatrizConDiagonal(int nFil, int nCol, float m1[][10], float mRet[][10]);
void negarMatriz(int nFil, int nCol, float m1[][10], float mRet[][10]);
void multiplicarMatrices(int nFil, int nCol, float m1[][10], float m2[][10], float mRet[][10]);
