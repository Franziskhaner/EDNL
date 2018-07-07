  /*Problema 2: Para un �rbol binario B, podemos construir el �rbol binario reflejado B^R cambiando
los sub�rboles izquierdo y derecho en cada nodo. Implementa un subprograma que
devuelva el �rbol binario reflejado de uno dado.*/

#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"
#include "reflejado.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main(){

    Abin<tElto> A;

    cout << "*** Lectura del �rbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "\n*** Mostrar �rbol binario A ***\n";
    imprimirAbin(A); // en std::cout
    cout << "\n*** Mostrar �rbol reflejado de A ***\n";
    imprimirAbin(llamadaReflejado(A));
}
