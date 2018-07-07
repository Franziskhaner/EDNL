/** Problema 1. Implementa una nueva operación del TAD Abb que tomando un elemento del mismo
elimine al completo el subárbol que cuelga de él.*/

#include <iostream>
#include "abb2.h"
#include "abb_E_S_H.h"

using namespace std;
typedef int tElto;
const tElto fin = -1; // fin de lectura

int main ()
{
    Abb<tElto> A;

    cout << "*** Lectura del árbol A ***\n";
    rellenarAbb(A, fin); // Desde std::cin

    cout << "\n*** Mostrar árbol A ***\n";
     imprimirAbb(A); // En std::cout*/


    int elto = 0;

    cout << "Indique el elemento X: " << endl;
    cin >> elto;

    A.podaSubArbol(elto, A);

    cout << "\n*** Árbol A ya podado ***\n";
    imprimirAbb(A);
}

