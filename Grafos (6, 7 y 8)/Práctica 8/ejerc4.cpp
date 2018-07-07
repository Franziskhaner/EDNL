/** Problema 4: La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del
valle del Jerte (Cáceres). Calcula qué canales y de qué longitud deben construirse
partiendo del grafo con las distancias entre las ciudades y asumiendo las siguientes
premisas:
- el coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final
debe tener un número mínimo de canales.
- el Ministerio de Fomento nos subvenciona por Kms de canal, luego los canales
deben ser de la longitud máxima posible.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

template <typename tCoste>
GrafoP<tCoste> emasajer(GrafoP<tCoste>& distanciasCiudades, tCoste Km){

    size_t n=distanciasCiudades.numVert();
    GrafoP<tCoste> canales(n);

    for(size_t i=0; i<n; i++)
        for(size_t j=0; j<n; j++)
            canales[i][j] = distanciasCiudades[i][j]*Km;

    canales = Prim(canales);    //HABRÍA QUE HACERLO CON PRIM_MÁXIMO(EJERC 3) PARA OBTENER ASÍ LOS CANALES MÁS LARGOS

    return canales;
}

int main(){

    GrafoP<size_t> distancias("matriz_ej_6_distancias.txt");
    size_t costePorKm = 100;

    GrafoP<size_t> resultado = emasajer(distancias, costePorKm);

    cout << "Los canales a construir son" << endl;

    cout << "CANAL\tLONGITUD" << endl;
    for(size_t i=0; i< resultado.numVert(); ++i)
        for(size_t j=i; j<resultado.numVert(); ++j){
            if(resultado[i][j] != GrafoP<size_t>::INFINITO){
                cout << i << "-" << j << "\t" << distancias[i][j] << endl;
            }
        }
}
