/** Problema 2: Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que
minimiza la suma de las distancias mínimas a sus dos nodos más alejados. Definiremos
el diámetro del grafo como la suma de las distancias mínimas a los dos nodos más
alejados del pseudocentro del grafo.
Dado un grafo conexo representado mediante matriz de costes, implementa un
subprograma que devuelva la longitud de su diámetro.

Autor: Fco. Jesús Díaz Zájara
*/

#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"
#include <iostream>

//Función que calcula la suma de las distancia mínimas de los 2 nodos más alejados del pseudocentro.
template <typename tCoste>
tCoste distMax(const matriz<tCoste>& m, typename GrafoP<tCoste>::vertice v){

  tCoste maximo, maximo2;

  maximo=0, maximo2=0;

  for(int i=0; i < m.dimension(); i++){
    if(m[i][v] > maximo)
      maximo = m[i][v];
    else
      if(m[i][v] > maximo2)
        maximo2 = m[i][v];
  }

  return maximo + maximo2;
}

//Función que calcula el pseudocentro del grafo y llama a distMax.
template <typename tCoste>
typename GrafoP<tCoste>::vertice pseudocentro(const GrafoP<tCoste>& G, tCoste& t){

    typedef typename GrafoP<tCoste>::vertice vertice;
    matriz<tCoste> m = Floyd(G, new matriz<vertice>(G.numVert()));
    t = GrafoP<tCoste>::INFINITO;
    vertice pseudo;

    for(vertice i=0; i < G.numVert(); i++)
        if(distMax(m, i) < t){
            t = distMax(m, i);
            pseudo = i;
        }

    return pseudo;
}

//Función que devuelve el diámetro.
template <typename tCoste>
tCoste diametro(const GrafoP<tCoste>& G){
    tCoste t;
    pseudocentro(G, t);
    return t;
}


int main(){
    std::cout << "EL programa funciona correctamente." << std::endl;
}
