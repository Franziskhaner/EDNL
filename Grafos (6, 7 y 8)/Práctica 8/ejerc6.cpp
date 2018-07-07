/** Problema 6: La empresa EMASAJER S.A. tiene que unir mediante canales todas las ciudades del
valle del Jerte (Cáceres), teniendo en cuenta las siguientes premisas:
- El coste de abrir cada nuevo canal es casi prohibitivo, luego la solución final debe
tener un número mínimo de canales.
- El Ministerio de Fomento nos subvenciona por m3/sg de caudal, luego el conjunto
de los canales debe admitir el mayor caudal posible, pero por otra parte, el coste
de abrir cada canal es proporcional a su longitud, por lo que el conjunto de los
canales también debería medir lo menos posible. Así pues, la solución óptima
debería combinar adecuadamente ambos factores.
Dada la matriz de distancias entre las diferentes ciudades del valle del Jerte, otra
matriz con los diferentes caudales máximos admisibles entre estas ciudades teniendo en
cuenta su orografía, la subvención que nos da Fomento por m3/sg. de caudal y el coste
por km. de canal, implementen un subprograma que calcule qué canales y de qué
longitud y caudal deben construirse para minimizar el coste total de la red de canales.
*/

#include "../alg_grafoPMC.h"
#include "../alg_grafo_E-S.h"
#include <iostream>

using namespace std;

template <typename tCoste>
GrafoP<tCoste> emasajerCaudales(const GrafoP<tCoste>& distanciasCiudades, const GrafoP<tCoste>& caudales, tCoste subvencion, tCoste costeKm){

    GrafoP<tCoste> G(distanciasCiudades.numVert());

    for(int i=0; i<distanciasCiudades.numVert(); ++i)
        for(int j=0; j<distanciasCiudades.numVert(); ++j)
            G[i][j] = distanciasCiudades[i][j] * costeKm - caudales[i][j] * subvencion;

    G = Prim(G);

    return G;
}

int main(){

    GrafoP<size_t> distancias("matriz_ej_6_distancias.txt");
    GrafoP<size_t> caudales("matriz_ej_6_caudales.txt");
    size_t subvencion = 5;
    size_t costePorKm = 100;

    GrafoP<size_t> resultado = emasajerCaudales(distancias, caudales, subvencion, costePorKm);

    cout << "Los canales a construir son" << endl;

    cout << "CANAL\tLONGITUD\tCAUDAL" << endl;
    for(int i=0; i< resultado.numVert(); ++i)
        for(int j=i; j<resultado.numVert(); ++j)
            if(resultado[i][j] != GrafoP<int>::INFINITO)
                cout << i << "-" << j << "\t" << distancias[i][j] << " Km\t\t" << caudales[i][j] << " m3/sg" << endl;
}
