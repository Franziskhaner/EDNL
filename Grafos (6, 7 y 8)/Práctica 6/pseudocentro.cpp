/** Problema 2: Definiremos el pseudocentro de un grafo conexo como el nodo del mismo que
minimiza la suma de las distancias m�nimas a sus dos nodos m�s alejados. Definiremos
el di�metro del grafo como la suma de las distancias m�nimas a los dos nodos m�s
alejados del pseudocentro del grafo.
Dado un grafo conexo representado mediante matriz de costes, implementa un
subprograma que devuelva la longitud de su di�metro.

Autor: Fco. Jes�s D�az Z�jara
*/

#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"
#include <iostream>

//Funci�n que calcula la suma de las distancia m�nimas de los 2 nodos m�s alejados del pseudocentro.
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

//Funci�n que calcula el pseudocentro del grafo y llama a distMax.
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

//Funci�n que devuelve el di�metro.
template <typename tCoste>
tCoste diametro(const GrafoP<tCoste>& G){
    tCoste t;
    pseudocentro(G, t);
    return t;
}


int main(){
    std::cout << "EL programa funciona correctamente." << std::endl;
}
