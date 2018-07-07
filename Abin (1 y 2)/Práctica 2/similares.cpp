/*Problema 1: Dos �rboles binarios son similares cuando tienen id�ntica estructura de ramificaci�n,
es decir, ambos son vac�os, o en caso contrario, tienen sub�rboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos �rboles binarios son
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

    cout << "*** Lectura del �rbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "*** Lectura del �rbol binario B ***\n";
    rellenarAbin(B, fin); // desde std::cin

    cout << "\n*** Mostrar �rbol binario A ***\n";
    imprimirAbin(A); // en std::cout
    cout << "\n*** Mostrar �rbol binario B ***\n";
    imprimirAbin(B);

    if(llamadaSimilares(A, B))
        cout << "Los arboles introducidos son similares" << endl;
    else
        cout << "Los arboles introducidos no son similares." << endl;
}
