/**Problema 1:

Tu agencia de viajes “OTRAVEZUNGRAFO S.A.” se enfrenta a un curioso cliente.
Es un personaje sorprendente, no le importa el dinero y quiere hacer el viaje más caro
posible entre las ciudades que ofertas. Su objetivo es gastarse la mayor cantidad de
dinero posible (ojalá todos los clientes fueran así), no le importa el origen ni el destino
del viaje.
Sabiendo que es imposible pasar dos veces por la misma ciudad, ya que casualmente
el grafo de tu agencia de viajes resultó ser acíclico, devolver el coste, origen y destino
de tan curioso viaje. Se parte de la matriz de costes directos entre las ciudades del grafo.
 */

 #include "../alg_grafo_E-S.h"
 #include "../alg_grafoPMC.h"
 #include <iostream>

// Algoritmo de Floyd Modificado para que maximice los costes entre cualesquiera
// 2 puntos del grafo, en vez de minimizarlo...
template <typename tCoste>
matriz<tCoste> floydMaximizador(const GrafoP<tCoste>& G, matriz<typename GrafoP<tCoste>::vertice>& P)
{
    typedef typename GrafoP<tCoste>::vertice vertice;
	const size_t n = G.numVert();
	matriz<tCoste> A(n);
	P = matriz<vertice>(n);

	for (vertice i = 0; i < n; i++)
    {
		A[i] = G[i];                    // copia costes del grafo
		A[i][i] = 0;                    // diagonal a 0
		P[i] = vector<vertice>(n, i);   // caminos directos
	}

	// Calcular costes máximos y caminos correspondientes
	// entre cualquier par de vértices i, j
	for (vertice k = 0; k < n; k++)
		for (vertice i = 0; i < n; i++)
			for (vertice j = 0; j < n; j++) {
				tCoste ikj = suma(A[i][k], A[k][j]);
				if (ikj != GrafoP<tCoste>::INFINITO and ((ikj > A[i][j]) or (A[i][j] ==  GrafoP<tCoste>::INFINITO)))
                {
					A[i][j] = ikj;
					P[i][j] = k;
				}
			}

	return A;
}

 template <typename tCoste>
 tCoste viajeMasCaro(const GrafoP<tCoste> G, typename GrafoP<tCoste>::vertice& origen, typename GrafoP<tCoste>::vertice& destino){

    typedef typename GrafoP<tCoste>::vertice vertice;   //Declaracion del tipo vertice para usarlo de forma mas comoda.
    matriz<vertice> P;
    matriz<tCoste> rutasMaximas;
    tCoste costeMax = -1 * GrafoP<tCoste>::INFINITO;

    rutasMaximas = floydMaximizador(G, P); //Ahora tenemos la matriz M con los costes maximizados entre 2 ciudades cualesquiera.

    for(size_t i=0; i<rutasMaximas.dimension(); i++)
        for(size_t j=0; j<rutasMaximas.dimension(); j++)
            if(P[i][j] !=  GrafoP<tCoste>::INFINITO && P[i][j] > costeMax){
                    costeMax = P[i][j];
                    origen = i;
                    destino = j;
            }

    return costeMax;
 }


 int main(){

    GrafoP<size_t> G("matriz_ej_1.txt");
    typename GrafoP<size_t>::vertice origen, destino;
    size_t costeMaximo;

    costeMaximo = viajeMasCaro(G, origen, destino);

    std::cout << "El coste del viaje mas caro es de: " << costeMaximo << " entre la ciudad " << origen << " como origen y la ciudad " << destino << " como destino." << std::endl;
 }
