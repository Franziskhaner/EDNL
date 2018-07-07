/** Problema 5: Se dispone de tres grafos que representan la matriz de costes para viajes en un
determinado país pero por diferentes medios de transporte, por supuesto todos los grafos
tendrán el mismo número de nodos. El primer grafo representa los costes de ir por
carretera, el segundo en tren y el tercero en avión. Dado un viajero que dispone de una
determinada cantidad de dinero, que es alérgico a uno de los tres medios de transporte, y
que sale de una ciudad determinada, implementar un subprograma que determine las
ciudades a las que podría llegar nuestro infatigable viajero.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

template <typename tCoste>
vector<bool> viajeroAlergico(const GrafoP<tCoste> carreteras, const GrafoP<tCoste> trenes, const GrafoP<tCoste> aviones, char alergia, size_t dinero, typename GrafoP<tCoste>::vertice origen){

    vector<typename GrafoP<tCoste>::vertice> Pmedio1;
    vector<typename GrafoP<tCoste>::vertice> Pmedio2;
    vector<tCoste> costesMedio1;
    vector<tCoste> costesMedio2;
    vector<bool> ciudades(carreteras.numVert(), false); //Vector que almacenara todas las ciudades y si el viajero puede viajar hacia ellas o no.

    switch(alergia){

        case 'carretera':
                        costesMedio1 = Dijkstra(trenes, origen, Pmedio1);
                        costesMedio2 = Dijkstra(aviones, origen, Pmedio2);
                        break;
        case 'tren':
                        costesMedio1 = Dijkstra(carreteras, origen, Pmedio1);
                        costesMedio2 = Dijkstra(aviones, origen, Pmedio2);
                        break;
        case 'avion':
                        costesMedio1 = Dijkstra(carreteras, origen, Pmedio1);
                        costesMedio2 = Dijkstra(trenes, origen, Pmedio2);
                        break;
    }

    for(size_t i=0; i<ciudades.size(); i++) //Vamos recorriendo el vector con las ciudades y comprobando que nuestro dinero es superior al coste de ir a esa ciudad
        if(costesMedio1[i] <= dinero || costesMedio2[i] <= dinero)    //ya sea en un medio de transporte u otro.
            ciudades[i] = true; //Si tenemos el dinero suficiente, indicamos que podemos viajar a esa ciudad.

    return ciudades;
}


int main(){

    GrafoP<int> C("matriz_ej_5C.txt");
    GrafoP<int> T("matriz_ej_5T.txt");
    GrafoP<int> A("matriz_ej_5A.txt");

    char alergia = 'C';
    int dinero = 100;
    typename GrafoP<int>::vertice origen = 0;

    vector<bool> destinosPosibles = viajeroAlergico(C, T, A, alergia, dinero, origen);

    cout << "Ciudades a las que podría llegar nuestro infatigable viajero" << endl;
    for(int i=0; i<C.numVert(); ++i)
    {
        if(i != origen and destinosPosibles[i] == true)
            cout << "Ciudad " << i << endl;
    }
}
