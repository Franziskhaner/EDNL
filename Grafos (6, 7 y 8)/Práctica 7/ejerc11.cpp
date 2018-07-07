/** Problema 11: Disponemos de tres grafos (matriz de costes) que representan los costes directos de
viajar entre las ciudades de tres de las islas del archipiélago de las Huríes (Zuelandia).
Para poder viajar de una isla a otra se dispone de una serie de puentes que conectan
ciudades de las diferentes islas a un precio francamente asequible (por decisión del
Prefecto de las Huríes, el uso de los puentes es absolutamente gratuito).
Si el alumno desea simplificar el problema, puede numerar las N1 ciudades de la isla
1, del 0 al N1-1, las N2 ciudades de la isla 2, del N1 al N1+N2-1, y las N3 de la última, del
N1+ N2 al N1+N2+ N3-1.
Disponiendo de las tres matrices de costes directos de viajar dentro de cada una de
las islas, y la lista de puentes entre ciudades de las mismas, calculad los costes mínimos
de viajar entre cualesquiera dos ciudades de estas tres islas.
¡¡¡ QUE DISFRUTÉIS EL VIAJE !!!*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;


struct puente{
    typename GrafoP<unsigned>::vertice A;
    typename GrafoP<unsigned>::vertice B;
};

template <typename tCoste>
matriz<tCoste> archipielagoHuries(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3, Lista<puente>& puentes){

    size_t N1 = isla1.numVert();
    size_t N2 = isla2.numVert();
    size_t N3 = isla3.numVert();

    GrafoP<tCoste> archipielago(N1+N2+N3);  //Supergrafo que contendra la suma de ciudades de las 3 islas.
    matriz<tCoste> F(archipielago.numVert());   //Matriz de costes que devolveremos como resultado y que contendra los costes minimos una vez apliquemos Floyd al supergrafo.
    matriz<typename GrafoP<tCoste>::vertice> P(archipielago.numVert()); //Matriz de vertices que pasamos a Floyd y que correspondera al camino minimo una vez se le aplique Floyd al supergrafo.

    Lista<puente>::posicion pos;

    //En primer lugar, tenemos que rellenar nuestro supergrafo 'archipielago' con los costes correspondientes a las 3 islas:
    //Isla 1
    for(size_t i=0; i < N1; i++)
        for(size_t j=0; j < N1; j++)
            archipielago[i][j] = isla1[i][j];

    //Isla 2
    for(size_t i=N1; i < N1+N2; i++)
        for(size_t j=N1; j < N1+N2; j++)
            archipielago[i][j] = isla2[i-N1][j-N1];

    //Isla 3
    for(size_t i=N1+N2; i < N1+N2+N3; i++)
        for(size_t j=N1+N2; j < N1+N2+N3; j++)
            archipielago[i][j] = isla3[i-N1-N2][j-N1-N2];

    //En segundo lugar, los costes correspondientes a los puentes que unen las diferentes ciudades de las 3 islas.
    pos = puentes.primera();

    while(pos != puentes.fin()){
        archipielago[puentes.elemento(pos).A][puentes.elemento(pos).B] = 0; //Como dice el enunciado el coste de tomar un puente es 0.
        archipielago[puentes.elemento(pos).B][puentes.elemento(pos).A] = 0;

        pos = puentes.siguiente(pos);
    }

    //Por último, aplicamos Floyd a nuestro supergrafo ya relleno para obtener así los costes minimos entre cualsquiera 2 ciudades del archipielago.
    F = Floyd(archipielago, P);

    return F;
}

int main(){

    GrafoP<unsigned> i1("matriz_ej_11_isla1.txt");
    GrafoP<unsigned> i2("matriz_ej_11_isla2.txt");
    GrafoP<unsigned> i3("matriz_ej_11_isla3.txt");
    matriz<unsigned> archipielago;
    puente p1, p2, p3;
    Lista<puente> puentes;

    p1.A=0; p1.B=2;
    p2.A=1; p2.B=5;
    p3.A=4; p3.B=7;

    puentes.insertar(p1, puentes.fin());
    puentes.insertar(p2, puentes.fin());
    puentes.insertar(p3, puentes.fin());

    archipielago = archipielagoHuries(i1, i2, i3, puentes);

    cout << "Costes minimos de viajar entre cualesquiera dos ciudades de estas tres islas es:\n"  << archipielago << endl;
    /*
    for(size_t i=0; i<archipielago.dimension(); i++)
        for(size_t j=0; j<archipielago.dimension(); j++)
            cout << archipielago[i][j] << " ";
        */
}
