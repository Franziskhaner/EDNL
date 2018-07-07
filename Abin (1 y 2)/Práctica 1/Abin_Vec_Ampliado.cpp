/*Problema 4: A�ade dos nuevas operaciones al TAD �rbol binario, una que calcule la profundidad de un
nodo y otra que calcule la altura de un nodo en un �rbol dado. Implementa esta operaci�n para
la representaci�n vectorial (�ndices del padre, hijo izquierdo e hijo derecho).*/

#include <iostream>
#include "Abin_Vec0_ampliado.h"

int main(){

    using namespace std;
    typedef char tElto;
    const tElto fin = '#'; // fin de lectura

    Abin<tElto> A, B;
    cout << "*** Lectura del �rbol binario A ***\n";
    rellenarAbin(A, fin); // desde std::cin
    ofstream fs("abin.dat"); // abrir fichero de salida
    imprimirAbin(fs, A, fin); // en fichero
    fs.close();
    cout << "\n*** �rbol A guardado en fichero abin.dat ***\n";
    cout << "\n*** Lectura de �rbol binario B de abin.dat ***\n";
    ifstream fe("abin.dat"); // abrir fichero de entrada
    rellenarAbin(fe, B); // desde fichero
    fe.close();
    cout << "\n*** Mostrar �rbol binario B ***\n";
    imprimirAbin(B); // en std::cout

    cout << "La altura del arbol es: " << B.alturaB(B.raizB());
    cout << "La profundidad del arbol es: " << B.profundidadB(B.raizB());
}
