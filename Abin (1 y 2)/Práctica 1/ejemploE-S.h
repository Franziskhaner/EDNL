#include <iostream>
#include <fstream>
#include "abin.h"
#include "abin_E-S.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main ()
{
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
}
