/** Problema 1. Implementa una nueva operaci�n del TAD Abb que tomando un elemento del mismo
elimine al completo el sub�rbol que cuelga de �l.*/

#include <iostream>
#include "abb2.h"
#include "abb_E_S_H.h"

using namespace std;
typedef int tElto;
const tElto fin = -1; // fin de lectura

int main ()
{
    Abb<tElto> A;

    cout << "*** Lectura del �rbol A ***\n";
    rellenarAbb(A, fin); // Desde std::cin

    cout << "\n*** Mostrar �rbol A ***\n";
     imprimirAbb(A); // En std::cout*/


    int elto = 0;

    cout << "Indique el elemento X: " << endl;
    cin >> elto;

    A.podaSubArbol(elto, A);

    cout << "\n*** �rbol A ya podado ***\n";
    imprimirAbb(A);
}

