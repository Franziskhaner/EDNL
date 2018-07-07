/*Problema 4: Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
la poda de A a partir de x. Se asume que no hay elementos repetidos en A.*/

#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"
#include "podaAgen2.h"

using namespace std;
typedef int tElto;
const tElto fin = -1; // fin de lectura

int main ()
{
    char op;
    Agen<tElto> A, B;

    cout << "Desea introducir un nuevo arbol??[S/N]:" << endl;
    cin >> op;

    if(op == 'S'){
        cout << "*** Lectura del árbol A ***\n";
        rellenarAgen(A, fin); // Desde std::cin
        ofstream fs("agen.dat"); // Abrir fichero de salida.
        imprimirAgen(fs, A, fin); // En fichero.
        fs.close();
        cout << "\n*** Árbol A guardado en fichero agen.dat ***\n";
        cout << "\n*** Lectura de árbol B de agen.dat ***\n";
        ifstream fe("agen.dat"); // Abrir fichero de entrada.
        rellenarAgen(fe, B); // Desde fichero.
        fe.close();
        cout << "\n*** Mostrar árbol B ***\n";
        imprimirAgen(B); // En std::cout
    }
    else{
        cout << "\n*** Lectura de árbol B de agen.dat ***\n";
        ifstream fe("agen.dat"); // Abrir fichero de entrada.
        rellenarAgen(fe, B); // Desde fichero.
        fe.close();
        cout << "\n*** Mostrar árbol B ***\n";
        imprimirAgen(B); // En std::cout
    }

    int elto = 0;

    cout << "Indique el elemento X: " << endl;
    cin >> elto;

    llamadaPoda(B, elto);

    cout << "\n*** Árbol B ya podado ***\n";
    imprimirAgen(B); // En std::cout
}
