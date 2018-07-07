/** Problema 6: Al dueño de una agencia de transportes se le plantea la siguiente situación. La
agencia de viajes ofrece distintas trayectorias combinadas entre N ciudades españolas
utilizando tren y autobús. Se dispone de dos grafos que representan los costes (matriz de
costes) de viajar entre diferentes ciudades, por un lado en tren, y por otro en autobús
(por supuesto entre las ciudades que tengan línea directa entre ellas). Además coincide
que los taxis de toda España se encuentran en estos momentos en huelga general, lo que
implica que sólo se podrá cambiar de transporte en una ciudad determinada en la que,
por casualidad, las estaciones de tren y autobús están unidas.
Implementa una función que calcule la tarifa mínima (matriz de costes mínimos) de
viajar entre cualesquiera de las N ciudades disponiendo del grafo de costes en autobús,
del grafo de costes en tren, y de la ciudad que tiene las estaciones unidas.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

typedef typename GrafoP<size_t>::vertice vertice;

template <typename tCoste>
matriz<tCoste> agenciaTransportes(const GrafoP<tCoste>& T, const GrafoP<tCoste>& A, typename GrafoP<tCoste>::vertice unidas)
{
    const size_t n = T.numVert();
    matriz<vertice> Pt, Pa;
    matriz<tCoste> costesT, costesA;
    matriz<tCoste> costes(n);

    costesT = Floyd(T, Pt);
    costesA = Floyd(A, Pa);

    for(vertice i=0; i<n; i++){
        for(vertice j=0; j<n; j++){
            costes[i][j] = min(min(suma(costesT[i][unidas], costesA[unidas][j]), suma(costesA[i][unidas], costesT[unidas][j])),
                               min(costesT[i][j], costesA[i][j]));
        }
    }

    return costes;
}

int main(){

    GrafoP<size_t> Gt("matriz_ej_6T.txt");
    GrafoP<size_t> Ga("matriz_ej_6A.txt");
    typename GrafoP<size_t>::vertice unidas = 3;

    cout << agenciaTransportes(Gt, Ga, unidas) << endl;
}
