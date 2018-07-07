/*Problema 4: Añade dos nuevas operaciones al TAD árbol binario, una que calcule la profundidad de un
nodo y otra que calcule la altura de un nodo en un árbol dado. Implementa esta operación para
la representación vectorial (índices del padre, hijo izquierdo e hijo derecho).*/

#include <iostream>
#include "Abin_Vec0_ampliado.h"

int main(){

    using namespace std;
    typedef char tElto;
    const tElto fin = '#'; // fin de lectura

    Abin<tElto> A, B;
    cout << "*** Lectura del árbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    ofstream fs("abin.dat"); // abrir fichero de salida
    imprimirAbin(fs, A, fin); // en fichero
    fs.close();
    cout << "\n*** Árbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // abrir fichero de entrada
    rellenarAbin(fe, B); // desde fichero
    fe.close();
    cout << "\n*** Mostrar árbol binario B ***\n";
    imprimirAbin(B); // en std::cout

    cout << "La altura del arbol es: " << B.alturaB(B.raizB());
    cout << "La profundidad del arbol es: " << B.profundidadB(B.raizB());
}
