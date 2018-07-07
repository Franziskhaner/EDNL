/** Problema 5: Dados dos conjuntos representados mediante �rboles binarios de b�squeda,
implementa la operaci�n intersecci�n de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersecci�n de ambos. El resultado debe quedar en un �rbol
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

    cout << "*** Lectura del �rbol A ***\n";
    rellenarAbb(A, fin);

    cout << "\n*** Mostrar �rbol A ***\n";
    imprimirAbb(A);

    cout << "*** Lectura del �rbol B ***\n";
    rellenarAbb(B, fin);

    cout << "\n*** Mostrar �rbol B ***\n";
    imprimirAbb(B);

    Abb<int> C = llamadaInterseccion(A, B);

    cout << "\n*** Mostrar �rbol C ***\n";
    imprimirAbb(C);
}
