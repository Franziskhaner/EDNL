/**Problema 2: Se dispone de un laberinto de NxN casillas del que se conocen las casillas de entrada
y salida del mismo. Si te encuentras en una casilla sólo puedes moverte en las siguientes
cuatro direcciones (arriba, abajo, derecha, izquierda). Por otra parte, entre algunas de las
casillas hay una pared que impide moverse entre las dos casillas que separa dicha pared
(en caso contrario no sería un verdadero laberinto).
Implementa un subprograma que dados
* N (dimensión del laberinto),
* la lista de paredes del laberinto,
* la casilla de entrada, y
* la casilla de salida,
calcule el camino más corto para ir de la entrada a la salida y su longitud.*/

#include <iostream>
#include <algorithm>
#include "../E_S_Grafos.h"

unsigned tCoste;

struct casilla{
    unsigned fil, col;
};

struct pared{
    casilla c1, c2;
};

casilla NodoToCasilla(unsigned nodo, unsigned N){

    casilla c;

    c.fil = nodo/N;
    c.col = nodo%N;

    return c;
}

unsigned CasillaToNodo(casilla c, unsigned N){

    return c.fil*N + c.col;
}

bool esAdyacente(casilla c1, casilla c2){

    if(c1.fil == c2.fil && (abs(c1.col - c2.col) == 1) || c1.col == c2.col && (abs(c1.fil - c2.fil) == 1))
        return true;
}

bool hayPared(unsigned nodo1, unsigned nodo2, vector<pared> paredes, unsigned N){

    for(unsigned i=0; i < paredes.size(); i++){
        if((CasillaToNodo(paredes[i].c1, N) == nodo1 && CasillaToNodo(paredes[i].c2, N) == nodo2) ||
           (CasillaToNodo(paredes[i].c2, N) == nodo1 && CasillaToNodo(paredes[i].c1, N) == nodo2))
            return true;
    }
    return false;
}

template <typename tCoste>
tCoste laberinto(size_t dimension, const vector<pared> paredes, casilla entrada, casilla salida, typename GrafoP<tCoste>::tCamino& caminoMin){

    //Primero debemos construir nuestro grafo del laberinto según los parámetros recibidos:
    GrafoP<tCoste> G(dimension*dimension);  //Laberinto de dimension NxN

    for(size_t i=0; i<G.numVert(); i++){
        for(size_t j=0; j<G.numVert(); j++){
            if(i == j)
                G[i][j] = 0;
            else if(esAdyacente(NodoToCasilla(i, dimension), NodoToCasilla(j, dimension)) && !hayPared(i, j, paredes, dimension)){
                G[i][j] = 1;
            }
            else
                G[i][j] = GrafoP<tCoste>::INFINITO;
        }
    }

    //Una vez rellenado nuestro laberinto, procedemos a buscar el camino minimo:
    //Para ello, aplicamos Dijkstra

    vector<typename GrafoP<tCoste>::vertice> P;
    vector<tCoste> costesMinimos;
    typename GrafoP<tCoste>::vertice origen, destino;

    origen = CasillaToNodo(entrada, dimension);
    destino = CasillaToNodo(salida, dimension);

    costesMinimos = Dijkstra(G, origen, P); //Obtenemos el vector con los costes minimos desde la entrada hasta cualquier casilla.
    //Ademas, obtenemos el vector caminoMin con el camino minimo desde la entrada hasta la salida.

    //Para obtetener el camino correspondiente al coste minimo desde la casilla origen a la casilla destino utilizaremos la funcion camino:
    typename GrafoP<tCoste>::tCamino caminoMin = camino(origen, destino, P);    //HAY QUE MIRAR BUEN LO DEL TCAMINO

    return costesMinimos[destino];  //Devolvemos la ultima posicion del vector, que contendra el coste minimo desde la entrada a la salida.
}

//HAY QUE MODIFICAR EL MAIN PARA QUE VALGA
int main(){

    size_t N = 3; //laberinto de 3x3
    vector<pared> paredes(4);
    typename GrafoP<tCoste>::tCamino P;
    size_t longitudCamino;
    pared p1, p2, p3, p4;

    p1.c1.fil=0; p1.c1.col=0; p1.c2.fil=1; p1.c2.col=0;
    p2.c1.fil=0; p2.c1.col=1; p2.c2.fil=1; p2.c2.col=1;
    p3.c1.fil=1; p3.c1.col=1; p3.c2.fil=1; p3.c2.col=2;
    p4.c1.fil=2; p4.c1.col=0; p4.c2.fil=2; p4.c2.col=1;

    paredes[0]=p1; paredes[1]=p2; paredes[2]=p3; paredes[3]=p4;

    casilla entrada, salida;
    entrada.fil=0; entrada.col=2;
    salida.fil=2; salida.col=0;

    longitudCamino = laberinto(N, paredes, entrada, salida, P);

    cout << "----------------------" << endl;
    cout << "El camino a seguir es:" << endl;
    cout << "----------------------" << endl;
    cout << "NODO\tCASILLA" << endl;

    cout << "Y la longitud de dicho camino es de: " << longitudCamino << endl;

}
