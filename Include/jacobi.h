const int col = 3;
const int fil = 3;

struct EstructuraMayor;
bool esDiagonalDominante(float matr[][col]);
bool hayPorLoMenosUnMayor(EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[]);
void intercambiarFilas(float matr[][10], EstructuraMayor vectorColumnaDondeEstaElMayorEnCadaFila[]);
void obtenerMatricesDeJacobi(float matr[][col]);
void armarMatrizD(const float m[][10]);
void armarMatrizU(const float m[][10]);
void armarMatrizL(const float m[][10]);
int jacobi();
