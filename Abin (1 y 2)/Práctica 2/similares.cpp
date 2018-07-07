/*Problema 1: Dos árboles binarios son similares cuando tienen idéntica estructura de ramificación,
es decir, ambos son vacíos, o en caso contrario, tienen subárboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos árboles binarios son
similares.*/

#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
#include "similares.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main(){

    Abin<tElto> A, B;

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "*** Lectura del árbol binario B ***\n";
    rellenarAbin(B, fin); // desde std::cin

    cout << "\n*** Mostrar árbol binario A ***\n";
    imprimirAbin(A); // en std::cout
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B);

    if(llamadaSimilares(A, B))
        cout << "Los arboles introducidos son similares" << endl;
    else
        cout << "Los arboles introducidos no son similares." << endl;
}
