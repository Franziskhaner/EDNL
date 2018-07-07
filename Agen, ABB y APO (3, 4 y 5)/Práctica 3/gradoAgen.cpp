#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"
#include "gradoAgen.h"

using namespace std;
typedef char tElto;
const tElto fin = '#'; // fin de lectura

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

    cout << "El grado del arbol es: " << llamadaGradoAgen(B) << endl;
}
