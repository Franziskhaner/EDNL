/** Problema 7: Se dispone de dos grafos (matriz de costes) que representan los costes de viajar entre
N ciudades españolas utilizando el tren (primer grafo) y el autobús (segundo grafo).
Ambos grafos representan viajes entre las mismas N ciudades.
Nuestro objetivo es hallar el camino de coste mínimo para viajar entre dos ciudades
concretas del grafo, origen y destino, en las siguientes condiciones:
* La ciudad origen sólo dispone de transporte por tren.
* La ciudad destino sólo dispone de transporte por autobús.
* El sector del taxi, bastante conflictivo en nuestros problemas, sigue en huelga,
por lo que únicamente es posible cambiar de transporte en dos ciudades del
grafo, cambio1 y cambio2, donde las estaciones de tren y autobús están
unidas.
Implementa un subprograma que calcule la ruta y el coste mínimo para viajar entre
las ciudades Origen y Destino en estas condiciones.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

template <typename tCoste>
tCoste viajarTrenBus(const GrafoP<tCoste>& Tren, const GrafoP<tCoste>& Bus, typename GrafoP<tCoste>::vertice origen, typename GrafoP<tCoste>::vertice destino,
                               typename GrafoP<tCoste>::vertice cambio1, typename GrafoP<tCoste>::vertice cambio2)
{
    vector<typename GrafoP<tCoste>::vertice> P_tren, Pi_bus;
    vector<tCoste> D_tren, Di_bus;

    D_tren = Dijkstra(Tren, origen, P_tren);
    Di_bus = DijkstraInv(Bus, destino, Pi_bus);

    return min(suma(D_tren[cambio1], Di_bus[cambio1]), suma(D_tren[cambio2], Di_bus[cambio2])); //Comprobamos donde se realiza el transbordo mas barato, si en la ciudad
                                                                    //del cambio1 o en la ciudad del cambio2.
}

int main(){

    GrafoP<size_t> T("matriz_ej_7Tren.txt");
    GrafoP<size_t> B("matriz_ej_7Bus.txt");

    typename GrafoP<size_t>::vertice origen = 1;
    typename GrafoP<size_t>::vertice destino = 3;
    typename GrafoP<size_t>::vertice c1 = 0;
    typename GrafoP<size_t>::vertice c2 = 2;

    cout << "El coste mínimo para viajar entre las ciudades origen y destino es: " << viajarTrenBus(T, B, origen, destino, c1, c2) << endl;
}
