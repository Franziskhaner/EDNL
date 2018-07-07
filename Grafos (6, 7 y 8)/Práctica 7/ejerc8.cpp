/** Problema 8: �UN SOLO TRANSBORDO, POR FAVOR�. Este es el t�tulo que reza en tu
flamante compa��a de viajes. Tu publicidad explica, por supuesto, que ofreces viajes
combinados de TREN y/o AUTOB�S (es decir, viajes en tren, en autob�s, o usando
ambos), entre N ciudades del pa�s, que ofreces un servicio inmejorable, precios muy
competitivos, y que garantizas ante notario algo que no ofrece ninguno de tus
competidores: que en todos tus viajes COMO M�XIMO se har� un solo transbordo
(cambio de medio de transporte).
Bien, hoy es 1 de Julio y comienza la temporada de viajes.
�Qu� suerte! Acaba de aparecer un cliente en tu oficina. Te explica que quiere viajar
entre dos ciudades, Origen y Destino, y quiere saber cu�nto le costar�.
Para responder a esa pregunta dispones de dos grafos de costes directos (matriz de
costes) de viajar entre las N ciudades del pa�s, un grafo con los costes de viajar en tren y
otro en autob�s.
Implementa un subprograma que calcule la tarifa m�nima en estas condiciones.
Mucha suerte en el negocio, que la competencia es dura.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

typedef typename GrafoP<size_t>::vertice vertice;

template <typename tCoste>
tCoste minimoConUnTransbordo(vector<tCoste> Medio1, vector<tCoste> Medio2)
{
    tCoste minimo;

    minimo = suma(Medio1[0], Medio2[0]);

    for(vertice i=0; i < Medio1.size(); ++i)
        if(suma(Medio1[i], Medio2[i]) < minimo)
            minimo = suma(Medio1[i], Medio2[i]);

    return minimo;
}

template <typename tCoste>
tCoste unSoloTrasbordo(const GrafoP<tCoste>& Tren, const GrafoP<tCoste>& Bus, vertice origen, vertice destino)
{
    vector<vertice> P_tren, Pi_tren, P_bus, Pi_bus;
    vector<tCoste> D_tren, Di_tren, D_bus, Di_bus;
    tCoste CTren, CBus, CTren_Bus, CBus_Tren;

    D_tren = Dijkstra(Tren, origen, P_tren);
    D_bus = Dijkstra(Bus, origen, P_bus);

    Di_tren = DijkstraInv(Tren, destino, Pi_tren);
    Di_bus = DijkstraInv(Bus, destino, Pi_bus);
                                                            //esto no lo pide,..es para ir viendo,...
    CTren = D_tren[destino];                                 cout << "Coste de ir directo en Tren:  " << CTren << endl;
    CBus = D_bus[destino];                                   cout << "Coste de ir directo en Bus:   " << CBus << endl;
    CTren_Bus = minimoConUnTransbordo(D_tren, Di_bus);       cout << "Coste de ir en Tren y en Bus: " << CTren_Bus << endl;
    CBus_Tren = minimoConUnTransbordo(D_bus, Di_tren);       cout << "Coste de ir en Bus y en Tren: " << CBus_Tren << endl;

    return min(min(CTren, CBus), min(CTren_Bus, CBus_Tren));
}

int main(){

    GrafoP<size_t> T("matriz_ej_8Tren.txt");
    GrafoP<size_t> B("matriz_ej_8Bus.txt");

    vertice O = 3;
    vertice D = 1;

    cout << endl << "El coste minimo entre la ciudad " << O << " y " << D << " es: " << unSoloTrasbordo(T, B, O, D) << endl;

}
