/** Problema 3: Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
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

    cout << "*** Lectura del árbol A ***\n";
    rellenarAbb(A, fin);

    cout << "\n*** Mostrar árbol A ***\n";
    imprimirAbb(A);

    B = llamadaEquilibrar(A);

    cout << "\n*** Arbol A equilibrado ***\n";
    imprimirAbb(B);
}
