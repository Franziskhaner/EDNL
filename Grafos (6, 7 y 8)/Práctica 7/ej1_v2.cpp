/** Problema 1: Tu agencia de viajes “OTRAVEZUNGRAFO S.A.” se enfrenta a un curioso cliente.
Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más caro
posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor cantidad de
dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino
del viaje.
Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente
el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino
de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo.*/

#include "alg_grafoPMC.h"
#include "alg_grafo_E-S.h"
#include <iostream>

template <typename tCoste>
tCoste otravezUnGrafo(const GrafoP<tCoste>& G, typename GrafoP<tCoste>::vertice& origen, typename GrafoP<tCoste>::vertice& destino){

    matriz<typename GrafoP<tCoste>::vertice> P;
    tCoste costeMax = 0;

    for(size_t i = 0; i < G.numVert(); i++)
        for(size_t j = 0; j < G.numVert(); j++)
            if(G[i][j] != GrafoP<tCoste>::INFINITO)
                G[i][j] = -G[i][j];

    matriz<tCoste> M = Floyd(G, P);

     for(size_t i = 0; i < M.numVert(); i++)
        for(size_t j = 0; j < M.numVert(); j++){
            if(M[i][j] != GrafoP<tCoste>::INFINITO)
                M[i][j] = -M[i][j];

            if(M[i][j] > costeMax){
                coste = M[i][j];
                origen = i;
                destino = j;
            }
        }

    return costeMax;
}
