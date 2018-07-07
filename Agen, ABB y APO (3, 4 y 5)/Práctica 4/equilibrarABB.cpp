/** Problema 3: Un �rbol binario de b�squeda se puede equilibrar realizando el recorrido en inorden
del �rbol para obtener el listado ordenado de sus elementos y a continuaci�n, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la ra�z y
construyendo recursivamente los sub�rboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB.*/

#include <iostream>
#include "abb.h"
#include "abb_E_S_H.h"
#include "equilibrarABB.h"

using namespace std;
typedef int tElto;
const tElto fin = -1; // fin de lectura

int main ()
{
    Abb<int> A, B;

    cout << "*** Lectura del �rbol A ***\n";
    rellenarAbb(A, fin);

    cout << "\n*** Mostrar �rbol A ***\n";
    imprimirAbb(A);

    B = llamadaEquilibrar(A);

    cout << "\n*** Arbol A equilibrado ***\n";
    imprimirAbb(B);
}
