/** Problema 3: Eres el orgulloso dueño de una empresa de distribución. Tu misión radica en
distribuir todo tu stock entre las diferentes ciudades en las que tu empresa dispone de
almacén.
Tienes un grafo representado mediante la matriz de costes, en el que aparece el coste
(por unidad de producto) de transportar los productos entre las diferentes ciudades del
grafo.
Pero además resulta que los Ayuntamientos de las diferentes ciudades en las que
tienes almacén están muy interesados en que almacenes tus productos en ellas, por lo
que están dispuestos a subvencionarte con un porcentaje de los gastos mínimos de
transporte hasta la ciudad. Para facilitar el problema, consideraremos despreciables los
costes de volver el camión a su base (centro de producción).
He aquí tu problema. Dispones de
* el centro de producción, nodo origen en el que tienes tu producto (no tiene
almacén),
* una cantidad de unidades de producto (cantidad),
* la matriz de costes del grafo de distribución con N ciudades,
* la capacidad de almacenamiento de cada una de ellas,
* el porcentaje de subvención (sobre los gastos mínimos) que te ofrece cada
Ayuntamiento.
Las diferentes ciudades (almacenes) pueden tener distinta capacidad, y además la
capacidad total puede ser superior a la cantidad disponible de producto, por lo que
debes decidir cuántas unidades de producto almacenas en cada una de las ciudades.
Debes tener en cuenta además las subvenciones que recibirás de los diferentes
Ayuntamientos, las cuales pueden ser distintas en cada uno y estarán entre el 0% y el
100% de los costes mínimos.
La solución del problema debe incluir las cantidades a almacenar en cada ciudad bajo
estas condiciones y el coste mínimo total de la operación de distribución para tu
empresa.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

typedef typename GrafoP<size_t>::vertice vertice;

struct almacen{
    float subvencion;
    size_t capacidad;
    size_t actual=0;
};

template <typename tCoste>
void empresaDistribucion(typename GrafoP<tCoste>::vertice origen, size_t cantidad, const GrafoP<tCoste> G, vector<almacen>& almacenes){

    vector<vertice> camino;
    vector<tCoste> costes;
    size_t descargas;
    float costeTotal=0;

    //Primero aplicamos Dijkstra para obtener los costes minimos y el camino minimo a recorrer desde el origen al resto de ciudades:

    costes = Dijkstra(G, origen, camino);

    //Costes almacenamiento previo a la subvencion
    cout << "Costes unitarios sin subvenciones" << endl;
    for(size_t i=1; i<costes.size(); ++i)
        cout << "Ciudad " << i << ": " << costes[i] << endl;

    //Costes almacenamiento tras aplicar a la subvencion
    cout << endl << "Costes unitarios aplicando subvenciones" << endl;
    for(size_t i=1; i<costes.size(); ++i){
        costes[i] = costes[i] * (1-almacenes[i].subvencion);
        cout << "Ciudad " << i << ": " << costes[i] << endl;
    }

    descargas = G.numVert() - 1; //Se realizarán tantas descargas como ciudades haya en el grafo menos 1 de la ciudad origen.

    while(cantidad > 0 && descargas > 0){   //Mientras quede producto y nº de descargas continuaremos con la distribución.

        vertice ciudadCosteMin; //Ciudad con el minimo coste unitario almacenamiento y que tenga sitio.
        tCoste costeMin = GrafoP<tCoste>::INFINITO;
        for(vertice i=1; i<costes.size(); i++){
            if(costes[i] < costeMin && almacenes[i].actual < almacenes[i].capacidad){
                ciudadCosteMin = i;
                costeMin = costes[i];
            }
        }

        if(almacenes[ciudadCosteMin].capacidad <= cantidad){    //Si la cantidad de producto es mayor a la capacidad del almacén, guardamos tantas unidades de producto como capacidad tenga dicho almacén.
            cantidad -= almacenes[ciudadCosteMin].capacidad;    //y a continuación se lo restamos a nuestra cantidad.
            almacenes[ciudadCosteMin].actual = almacenes[ciudadCosteMin].capacidad;
        }else{      //Si la cantidad de producto es menor que la capacidad, guardamos toda esa cantidad en el almacén y ponemos nuestra cantidad a 0.
            almacenes[ciudadCosteMin].actual = cantidad;
            cantidad = 0;
        }

        costeTotal = costeTotal + (almacenes[ciudadCosteMin].actual * costeMin);
        descargas--;
    }

    // Distribucion de la cantidad de producto en los almacenes
    cout << endl << "Distribucion de las unidades en los almacenes" << endl;
    for(vertice i=1; i<costes.size(); ++i)
        cout << "Ciudad " << i << ": " << almacenes[i].actual << " unidades" << endl;

    cout << "Coste Minimo Total de la distribucion: " << costeTotal << " euros" << endl;
    cout << "Quedan por repartir " << cantidad << " unidades" << endl;
}


int main(){

    vector<almacen> almacenes(5);
    GrafoP<size_t> G("matriz_ej_3.txt");
    size_t unidades = 2000;
    vertice origen = 0;

    almacenes[0].subvencion = 0;
    almacenes[0].capacidad = 0;
    almacenes[1].subvencion = 0.1; //subvencion del 10%
    almacenes[1].capacidad = 500;
    almacenes[2].subvencion = 0.05; //del 5%
    almacenes[2].capacidad = 600;
    almacenes[3].subvencion = 0.15;
    almacenes[3].capacidad = 400;
    almacenes[4].subvencion = 0.2;
    almacenes[4].capacidad = 800;

    empresaDistribucion(origen, unidades, G, almacenes);
}
