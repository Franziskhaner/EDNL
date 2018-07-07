/** Problema 5: Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado.*/

#include <iostream>
#include "abb.h"
#include "abb_E_S_H.h"
#include "interseccionABB.h"

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

    Abb<int> C = llamadaInterseccion(A, B);

    cout << "\n*** Mostrar árbol C ***\n";
    imprimirAbb(C);
}
