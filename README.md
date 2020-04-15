# metodos-numericos
## Testing de programa
Para verificar el resultado del programa usar el siguiente [link](https://planetcalc.com/3717/?license=1)

## Consigna
se tiene una función f : R-> R continua
input: dos reales a, b tales que a < b, y tales que f(a)* f(b) < 0, y un real epsilon > 0

En un lenguaje de programación a elección, implementar la siguiente variante del método de bisección para hallar alguna raíz de una función (especificada en el código del programa) que tenga al menos una raíz real.

El método es análogo a bisección, pero en lugar de tomar en cada paso el punto medio del intervalo [a,b] actual, es decir 1/2 * a + 1/2 * b, deberá tomar el punto **w * a + (1-w) * b**, donde la constante w será un input del programa debiendo cumplirse **0 < w < 1**.
 Nótese que este punto también estará entre a y b (si w fuera 1/2, el nuevo punto será el punto medio, de otro modo, será otro dentro de ese intervalo).
 
El programa deberá recibir como input:
 * dos valores reales a y b para el inicio de las iteraciones
 * un real epsilon positivo para acotar el error
 * y un valor w (según lo indicado). 
 
La condición de parada será la primera que se cumpla entre dos de las condiciones comentadas en clase (a elección por parte de Uds.), usando el valor epsilon dado. 

El programa deberá imprimir una tabla donde en cada fila aparezca el número de iteración, los valores a y b actuales, el valor de la raíz aproximada actual y la función aplicada a ese valor. 

El programa deberá verificar si los valores a y b ingresados cumplen con la condición inicial que asegura la existencia de una raíz en ese intervalo; y también la condición mencionada para w. 

De no ser así, informará el error, lo mismo ante cualquier otra eventualidad que lo impida (decidan Uds. cuál o cuáles). 

La salida del programa podrá ser la estándar, o bien un archivo, a elección de Uds.

## Salida del Programa
./metodos-numericos</br>
Ingrese un valor w que este entre 0 y 1</br>
0.5</br></br>
Ingrese un valor X0</br>
-3</br></br>
Ingrese un valor X1</br>
1</br></br>
Ingrese un valor epsilon</br>
0.01</br></br>

Iteracion Actual = 1 | X0 = -3 | X1 = 1 | xAuxiliar = -1 | funcion(xAux) = 3.62091 </br></br>
Iteracion Actual = 2 | X0 = -3 | X1 = -1 | xAuxiliar = -2 | funcion(xAux) = 0.751559 </br></br>
Iteracion Actual = 3 | X0 = -3 | X1 = -2 | xAuxiliar = -2.5 | funcion(xAux) = -0.403431 </br></br>
Iteracion Actual = 4 | X0 = -2.5 | X1 = -2 | xAuxiliar = -2.25 | funcion(xAux) = 0.115479 </br></br>
Iteracion Actual = 5 | X0 = -2.5 | X1 = -2.25 | xAuxiliar = -2.375 | funcion(xAux) = -0.160835 </br></br>
Iteracion Actual = 6 | X0 = -2.375 | X1 = -2.25 | xAuxiliar = -2.3125 | funcion(xAux) = -0.0266352 </br></br>
Iteracion Actual = 7 | X0 = -2.3125 | X1 = -2.25 | xAuxiliar = -2.28125 | funcion(xAux) = 0.0434668 </br></br>
Iteracion Actual = 8 | X0 = -2.3125 | X1 = -2.28125 | xAuxiliar = -2.29688 | funcion(xAux) = 0.00817263 </br></br>
Iteracion Actual = 9 | X0 = -2.3125 | X1 = -2.29688 | xAuxiliar = -2.30469 | funcion(xAux) = -0.0092926 </br></br>

Devolviendo la raiz '-2.30469'.


## Integrantes
Carunchio Mauricio</br>
Mansilla Jonathan

## Fecha de entrega
20/04/2020 por mail