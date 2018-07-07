/** Problema 4 [ZUELANDIA]: Se necesita hacer un estudio de las distancias mínimas necesarias para viajar entre
dos ciudades cualesquiera de un país llamado Zuelandia. El problema es sencillo pero
hay que tener en cuenta unos pequeños detalles:

a) La orografía de Zuelandia es un poco especial, las carreteras son muy estrechas
y por tanto solo permiten un sentido de la circulación.
b) Actualmente Zuelandia es un país en guerra. Y de hecho hay una serie de
ciudades del país que han sido tomadas por los rebeldes, por lo que no pueden
ser usadas para viajar.
c) Los rebeldes no sólo se han apoderado de ciertas ciudades del país, sino que
también han cortado ciertas carreteras, (por lo que estas carreteras no pueden ser
usadas).
d) Pero el gobierno no puede permanecer impasible ante la situación y ha exigido
que absolutamente todos los viajes que se hagan por el país pasen por la capital
del mismo, donde se harán los controles de seguridad pertinentes.
Dadas estas cuatro condiciones, se pide implementar un subprograma que dados:

* el grafo (matriz de costes) de Zuelandia en situación normal,
* la relación de las ciudades tomadas por los rebeldes,
* la relación de las carreteras cortadas por los rebeldes
* y la capital de Zuelandia,

calcule la matriz de costes mínimos para viajar entre cualesquiera dos ciudades
zuelandesas en esta situación.*/

#include "../alg_grafoPMC.h"
#include "../alg_grafo_E-S.h"
#include <iostream>

using namespace std;

typedef typename GrafoP<size_t>::vertice vertice;

template <typename tCoste>
matriz<tCoste> Zuelandia(const GrafoP<tCoste>& G, const vector<bool>& ciudades, const matriz<bool>& carreteras, vertice capital){

    vector<tCoste> desdeCapital, haciaCapital;
    vector<vertice> PDijkstra, PDijkstraInv;
    matriz<tCoste> costesMin;
    GrafoP<tCoste> copiaG(G);   //Trabajaremos con una copia del grafo G.

    //Establecemos las ciudades tomadas por los rebeldes.
    for(size_t i=0; i < ciudades.size(); i++){
        if(ciudades[i]) //Si la ciudad i esta tomada
        {
            for(int j=0; j < copiaG.numVert(); j++){    //La indicamos en la matriz de costes con un coste de infinito
                copiaG[i][j] = GrafoP<tCoste>::INFINITO;//usando esa ciudad como origen
                copiaG[j][i] = GrafoP<tCoste>::INFINITO;//tanto como destino.
            }
        }
    }

    //Establecemos las carreteras cortadas por los rebeldes.
    for(size_t i=0; i < carreteras.dimension(); i++)
        for(size_t j=0; j < carreteras.dimension(); j++)
            if(carreteras[i][j])    //Si esta en true ponemos el coste de esa carretera a infinito.
                copiaG[i][j] = GrafoP<tCoste>::INFINITO;


    //Ahora nuestro ciudad de Zoelandia quedaria asi;

    cout << "Zuelandia relleno:\n" << copiaG;

    //Calculamos los costes minimos desde todas las ciudades hasta la capital y desde la capital hasta todas las ciudades.
    desdeCapital = Dijkstra(copiaG, capital, PDijkstra);
    haciaCapital = DijkstraInv(copiaG, capital, PDijkstraInv);

    //Creamos la matriz con los costes de ir desde i hasta la capital + los de ir desde la capital hasta j.
      for (size_t i = 0; i < copiaG.numVert(); i++) {
        for (size_t j = 0; j < copiaG.numVert(); j++) {
          costesMin[i][j] = haciaCapital[i] + desdeCapital[j];
        }
      }

      return costesMin;
}

int main(){

    GrafoP<int> G("matriz_Zue.txt");
    vector<bool> ciudades(G.numVert(), false);
    ciudades[2] = true;                // la ciudad 2 está tomada

    matriz<bool> carreteras(G.numVert(), false);     // carreteras cortadas
    carreteras[3][4] = true;        // cortamos la carretera de 3->4
    carreteras[3][0] = true;        // y la 3->0

    vertice capital = 0;            // la capital es la ciudad 0

    cout << "Costes minimos de Zuelandia:" << Zuelandia(G, ciudades, carreteras, capital) << endl;
}
