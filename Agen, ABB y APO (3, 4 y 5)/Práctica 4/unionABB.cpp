/** Problema 4: Dados dos conjuntos representados mediante �rboles binarios de b�squeda,
implementa la operaci�n uni�n de dos conjuntos que devuelva como resultado otro
conjunto que sea la uni�n de ambos, representado por un ABB equilibrado.*/

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

    cout << "*** Lectura del �rbol A ***\n";
    rellenarAbb(A, fin);

    cout << "\n*** Mostrar �rbol A ***\n";
    imprimirAbb(A);

    cout << "*** Lectura del �rbol B ***\n";
    rellenarAbb(B, fin);

    cout << "\n*** Mostrar �rbol B ***\n";
    imprimirAbb(B);

    Abb<int> C = llamadaUnion(A, B);

    cout << "\n*** Mostrar �rbol C ***\n";
    imprimirAbb(C);
}
