/** Problema 1: El archipiélago de Tombuctú, está formado por un número indeterminado de islas,
cada una de las cuales tiene, a su vez, un número indeterminado de ciudades. En
cambio, sí es conocido el número total de ciudades de Tombuctú (podemos llamarlo N,
por ejemplo).
Dentro de cada una de las islas existen carreteras que permiten viajar entre todas
las ciudades de la isla. Se dispone de las coordenadas cartesianas (x, y) de todas y cada
una de las ciudades del archipiélago. Se dispone de un grafo (matriz de adyacencia) en
el que se indica si existe carretera directa entre cualesquiera dos ciudades del
archipiélago. El objetivo de nuestro problema es encontrar qué ciudades de Tombuctú
pertenecen a cada una de las islas del mismo y cuál es el coste mínimo de viajar entre
cualesquiera dos ciudades de una misma isla de Tombuctú.
Así pues, dados los siguientes datos:
- Lista de ciudades de Tombuctú representada cada una de ellas por sus
coordenadas cartesianas.
- Matriz de adyacencia de Tombuctú, que indica las carreteras existentes en
dicho archipiélago.
Implementen un subprograma que calcule y devuelva la distribución en islas de las
ciudades de Tombuctú, así como el coste mínimo de viajar entre cualesquiera dos
ciudades de una misma isla del archipiélago.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include "../alg_grafoMA.h"
#include "../grafoMA.cpp"
#include "../particion.h"
#include "../particion.cpp"
#include <iostream>
#include <algorithm>

using namespace std;

typedef typename Grafo::vertice vertice;

struct ciudad{
    size_t x, y;    //Coordenadas cartesianas.
    vertice v;
};

size_t distanciaEuclidea(ciudad& A, ciudad& B)
{
    return sqrt(pow(B.x - A.x, 2) + pow(B.y - A.y, 2));
}

template <typename tCoste>
Particion archipielagoTombuctu(vector<ciudad>& ciudadesTombuctu, const Grafo& carreterasTombuctu, matriz<tCoste>& F, size_t N){

    Particion Part(N);
    GrafoP<tCoste> G(N);   //Grafo ponderado que crearemos a partir de la matriz de adyacencia de Tombuctu y que luego pasaremos a Floyd.
    matriz<vertice> P(N);  //Matriz de vertice que pasaremos a Floyd.

    //Vamos a crear el grafo ponderado con los costes directos entre las ciudades que estan comunicadas, es decir, entre las q existe carretera.
    for(size_t i=0; i<N; i++)
        for(size_t j=0; j<N; j++)
            if(carreterasTombuctu[i][j]){   //Si existe carretera, calculamos su coste y lo guardamos en el grafo ponderado G.
                G[i][j] = distanciaEuclidea(ciudadesTombuctu[i], ciudadesTombuctu[j]);
                if(Part.encontrar(i) != Part.encontrar(j))
                    Part.unir(Part.encontrar(i), Part.encontrar(j));
            }

    //Una vez tenemos el grafo con los costes directos de todo el archipielago, aplicamos Floyd para minimizar dichos costes:

    F = Floyd(G, P);

    return Part;
}

int main(){

    size_t N = 6;  //Número de ciudades en el archipiélago.
    ciudad c0, c1, c2, c3, c4, c5;
    vector<ciudad> ciudades(N);     //Lista de ciudades.
    Grafo A(N);     //Matriz de adyacencia de Tombuctu(carreteras existente).
    matriz<size_t> F(N);    //Matriz de costes devuelta por Floyd que contendrá los costes mínimos entre cualesquiera 2 ciudades de una misma isla.
    Particion P(N); //Partición con la distribución de las ciudades en las islas.

    //Indicamos las coordenadas de las ciudades:
    c0.v= 0; c0.x=2 ; c0.y=5;
    c1.v= 1; c1.x=3 ; c1.y=3;
    c2.v= 2; c2.x=5 ; c2.y=5;
    c3.v= 3; c3.x=10 ; c3.y=4;
    c4.v= 4; c4.x=12 ; c4.y=7;
    c5.v= 5; c5.x=13 ; c5.y=5;

    //Rellenamos la lista de ciudades:
    ciudades[0] = c0 ; ciudades[1] = c1 ; ciudades[2] = c2 ;
    ciudades[3] = c3 ; ciudades[4] = c4 ; ciudades[5] = c5 ;

    //Rellenamos las carreteras existentes:
    A[0][1]= true;    A[1][0]= true;
    A[0][2]= true;    A[2][0]= true;
    A[1][2]= true;    A[2][1]= true;
    A[3][4]= true;    A[4][3]= true;
    A[3][5]= true;    A[5][3]= true;
    A[4][5]= true;    A[5][4]= true;

    cout << "Matriz de adyacencia con las carreteras existentes de Tombuctu:\n" << A << endl;

    P = archipielagoTombuctu(ciudades, A, F, N);

    cout << "Coste minimo de viajar entre cualesquiera dos ciudades de una misma isla del archipielago:\n\n" << F << endl;

    cout << endl << "Distribucion en islas de las ciudades de Tombuctu:\n" << endl;
    for(size_t i=0; i<N; ++i)
        cout << "Representante de ciudad " << i << " es la ciudad " << P.encontrar(i) << endl;
}
