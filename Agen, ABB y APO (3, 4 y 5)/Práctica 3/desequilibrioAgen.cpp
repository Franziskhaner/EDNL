/*Problema 3: Se define el desequilibrio de un �rbol general como la m�xima diferencia entre las alturas
de los sub�rboles m�s bajo y m�s alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un �rbol general.*/

#include <iostream>
#include "AGEN.h"
#include "agen_E-S.h"
#include <algorithm>
#include "desequilibrioAgen2.h"

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
        cout << "*** Lectura del �rbol A ***\n";
        rellenarAgen(A, fin); // Desde std::cin
        ofstream fs("agen.dat"); // Abrir fichero de salida.
        imprimirAgen(fs, A, fin); // En fichero.
        fs.close();
        cout << "\n*** �rbol A guardado en fichero agen.dat ***\n";
        cout << "\n*** Lectura de �rbol B de agen.dat ***\n";
        ifstream fe("agen.dat"); // Abrir fichero de entrada.
        rellenarAgen(fe, B); // Desde fichero.
        fe.close();
        cout << "\n*** Mostrar �rbol B ***\n";
        imprimirAgen(B); // En std::cout
    }
    else{
        cout << "\n*** Lectura de �rbol B de agen.dat ***\n";
        ifstream fe("agen.dat"); // Abrir fichero de entrada.
        rellenarAgen(fe, B); // Desde fichero.
        fe.close();
        cout << "\n*** Mostrar �rbol B ***\n";
        imprimirAgen(B); // En std::cout
    }

    cout << "El desequilibrio del arbol es: " << llamadaDesequilibrioAgen(B) << endl;
}
