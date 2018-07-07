/** Problema 5: La nueva compañía de telefonía RETEUNI3 tiene que conectar entre sí, con fibra
óptica, todas y cada una de las ciudades del país. Partiendo del grafo que representa las
distancias entre todas las ciudades del mismo, implementad un subprograma que
calcule la longitud mínima de fibra óptica necesaria para realizar dicha conexión.*/


#include "../alg_grafoPMC.h"
#include "../alg_grafo_E-S.h"
#include <iostream>

using namespace std;

template <typename tCoste>
tCoste reteuni3(const GrafoP<tCoste>& G){

    tCoste longitudMinTotal = 0;
    GrafoP<tCoste> costesMin(G.numVert());
    costesMin = Prim(G); //Aplicamos Prim para obtener el grafo conexo con los costes minimos(arbol generador).

    cout << "Arbol generador resultado de aplicar Prim al grafo G: " << costesMin << endl;

    for(size_t i=0; i<costesMin.numVert(); i++)
        for(size_t j=0; j<costesMin.numVert(); j++)
            if(costesMin[i][j] != GrafoP<tCoste>::INFINITO)
                longitudMinTotal += costesMin[i][j];

    return longitudMinTotal/2;
}

int main(){

    size_t longitudFibra;
    GrafoP<int> G("matriz_ej_5.txt");

    cout << "Grafo ponderado con los costes directos entre las ciudades: " << G << endl;

    longitudFibra = reteuni3(G);

    cout << "La longitud minima de todo el cableado de fibra optica seria: " << longitudFibra << " Km." << endl;
}
