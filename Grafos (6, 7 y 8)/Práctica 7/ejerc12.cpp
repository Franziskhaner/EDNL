/** Problema 12: El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 ≤ N1 y C2 ≤ N2). Se desea construir un puente
que una ambas islas. Nuestro problema es elegir el puente a construir entre todos los
posibles, sabiendo que el coste de construcción del puente se considera irrelevante. Por
tanto, escogeremos aquel puente que minimice el coste global de viajar entre todas las
ciudades de las dos islas, teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las dos ciudades que una el puente es 0.
2. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipiélago. Por
ejemplo, se considerará que el número de viajes entre la ciudad P de Fobos y la
Q de Deimos será el mismo que entre las ciudades R y S de la misma isla. Dicho
de otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de Fobos y Deimos y las listas de ciudades
costeras de ambas islas, implementa un subprograma que calcule las dos ciudades que
unirá el puente.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

struct puente{
    typename GrafoP<unsigned>::vertice A;
    typename GrafoP<unsigned>::vertice B;
};

template <typename tCoste>
tCoste mejorPuente(const GrafoP<tCoste>& Fobos, const GrafoP<tCoste>& Deimos, typename GrafoP<tCoste>::vertice ciudadFobos, typename GrafoP<tCoste>::vertice ciudadDeimos){

    tCoste mejorCoste;
    size_t N1 = Fobos.numVert();
    size_t N2 = Deimos.numVert();
    GrafoP<tCoste> Grecoland(N1+N2);    //Supergrafo con las ciudades de las 2 islas.
    matriz<tCoste> F(Grecoland.numVert());  //Matriz que contendra los costes minimos de aplicar Floyd a Grecoland.
    matriz<typename GrafoP<tCoste>::vertice> P(Grecoland.numVert());    //Matriz que contendra el camino minimo entre cualesquiera ciudades de Grecoland despues de aplicarle Floyd.

    //Rellenamos el cuadrante correspondiente a Fobos:
    for(size_t i=0; i<N1; i++)
        for(size_t j=0; j<N1; j++)
            Grecoland[i][j] = Fobos[i][j];

    //Rellenamos el cuadrante correspondiente a Deimos:
    for(size_t i=N1; i<N1+N2; i++)
        for(size_t j=N1; j<N1+N2; j++)
            Grecoland[i][j] = Deimos[i-N1][j-N2];

    //Ahora introducimos el coste de crear el puente entre las 2 ciudades que hemos recibido(ciudadFobos y ciudadDeimos):
    Grecoland[ciudadFobos][ciudadDeimos] = 0;
    Grecoland[ciudadDeimos][ciudadFobos] = 0;

    //Aplicamos Floyd para obtener la matriz de costes minimos de Grecoland
    F = Floyd(Grecoland, P);

    //Pero necesitamos la suma de todos los costes minimos de esa matriz(F). por tanto realizamos un sumatorio de la matriz F:

    for(int i=0; i<F.dimension(); ++i)
        for(int j=0; j<F.dimension(); ++j){
            if(F[i][j] != GrafoP<tCoste>::INFINITO)
                mejorCoste += F[i][j];
        }

    return mejorCoste;  //Este será el coste minimo total que obtenemos con este puente.
}


template <typename tCoste>
puente puenteGrecoland(const GrafoP<tCoste>& Fobos, const GrafoP<tCoste>& Deimos, Lista<typename GrafoP<tCoste>::vertice>& ciudadesFobos, Lista<typename GrafoP<tCoste>::vertice>& ciudadesDeimos, tCoste& costeMin){

    puente mejorPuente;
    tCoste costeActual;
    tCoste mejorCoste = GrafoP<tCoste>::INFINITO;
    typename Lista<typename GrafoP<tCoste>::vertice>::posicion posF;
    typename Lista<typename GrafoP<tCoste>::vertice>::posicion posD;

    //En primer lugar, vamos a ir recorriendo la lista de ciudades de Fobos y de Deimos para comprobar que puente seria la mejor opcion para minimizar el coste total de recorrer las 2 islas
    posF = ciudadesFobos.primera();
    while(posF != ciudadesFobos.fin()){

        posD = ciudadesDeimos.primera();
        while(posD != ciudadesDeimos.fin()){

            costeActual = mejorPuente(Fobos, Deimos, ciudadesFobos.elemento(posF), ciudadesDeimos.elemento(posD));   //Aqui llamamos a mejorPuente para obtener el coste minimo global de recorrer las 2 islas utilizando como puente el que une a las 2 ciudades que le pasamos(posF y posD).
            if(costeActual < mejorCoste){    //Si encontramos un puente que minimice aun mas el coste total,
                mejorCoste = costeActual;   //lo actualizamos.

                mejorPuente.A = ciudadesFobos.elemento(posF);   //Tambien actualizamos las ciudades que unirá nuestro puente.
                mejorPuente.B = ciudadesDeimos.elemento(posD);
            }
            posD = ciudadesDeimos.siguiente(posD);  //Avanzamos a la siguiente ciudad de la lista de Deimos.
        }

        posF = ciudadesFobos.siguiente(posF);   //Avanzamos a la siguiente ciudad de la lista de Fobos.
    }

    costeMin = mejorCoste;  //Tambien devolvemos por referencia el coste minimo total.

    return mejorPuente;
}

int main(){
    GrafoP<int> F("matriz_ej_12_fobos.txt");
    GrafoP<int> D("matriz_ej_12_deimos.txt");
    puente mejorPuente;
    int precio;

    Lista<typename GrafoP<int>::vertice> costerasF, costerasD;

    costerasF.insertar(1, costerasF.fin());
    costerasF.insertar(2, costerasF.fin());
    costerasD.insertar(3, costerasD.fin());
    costerasD.insertar(4, costerasD.fin());

    mejorPuente = puenteGrecoland(F, D, costerasF, costerasD, precio);

    cout << "El mejor puente va de la ciudad " << mejorPuente.A << " a la ciudad " << mejorPuente.B << endl;
    cout << "El precio global es de: " << precio << endl;
}


