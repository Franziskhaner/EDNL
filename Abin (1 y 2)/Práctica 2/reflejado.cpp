  /*Problema 2: Para un árbol binario B, podemos construir el árbol binario reflejado B^R cambiando
los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que
devuelva el árbol binario reflejado de uno dado.*/

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

    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    cout << "\n*** Mostrar árbol binario A ***\n";
    imprimirAbin(A); // en std::cout
    cout << "\n*** Mostrar árbol reflejado de A ***\n";
    imprimirAbin(llamadaReflejado(A));
}
