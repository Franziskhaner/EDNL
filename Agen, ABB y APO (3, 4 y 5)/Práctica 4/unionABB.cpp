/** Problema 4: Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.*/

#include <iostream>
#include "abb.h"
#include "abb_E_S_H.h"
#include "unionABB.h"

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

    cout << "*** Lectura del árbol B ***\n";
    rellenarAbb(B, fin);

    cout << "\n*** Mostrar árbol B ***\n";
    imprimirAbb(B);

    Abb<int> C = llamadaUnion(A, B);

    cout << "\n*** Mostrar árbol C ***\n";
    imprimirAbb(C);
}
