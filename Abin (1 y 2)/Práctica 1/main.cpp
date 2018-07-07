#include <iostream>
#include <fstream>
#include "abin_ampliado.h"
#include "abin_E-S.h"
#include "numNodos.h"
#include "altura.h"
#include "profundidad.h"
#include "desequilibrio.h"
#include "pseudocompleto.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

int main ()
{
    char op;
    Abin<tElto> A, B;

    cout << "Desea introducir un nuevo arbol?[S/N]:" << endl;
    cin >> op;

    if(op == 'S'){
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
    }
    else{
        cout << "\n*** Lectura de árbol binario B de abin.dat ***\n";
        ifstream fe("abin.dat"); // abrir fichero de entrada
        rellenarAbin(fe, B); // desde fichero
        fe.close();
        cout << "\n*** Mostrar árbol binario B ***\n";
        imprimirAbin(B); // en std::cout

    }

    cout << "\n*** Problema 1 ***\n"
    << "El numero de nodos del arbol es: " << llamadaNumNodos(B) << endl;

    cout << "\n*** Problema 2 ***\n"
    << "La altura del arbol es: " << llamadaAltura(B) << endl;

    cout << "\n*** Problema 3 ***\n"
    <<"La profundidad del nodo indicado es: "
    << llamadaProfundidad(B, B.hijoIzqdoB(B.hijoIzqdoB(B.raizB()))) << endl;

    cout << "\n*** Problema 6 ***\n"
    <<"El desequilibrio del arbol es: " << llamadaDesequilibrio(B) << endl;

    cout << "\n*** Problema 7 ***" << endl;
    if(llamadaPseudocompleto(B))
        cout << "El arbol introducido es pseudocompleto." << endl;
    else
        cout << "El arbol introducido no es pseudocompleto." << endl;
}
