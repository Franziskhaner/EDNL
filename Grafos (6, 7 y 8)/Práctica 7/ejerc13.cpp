/** Problema 13: El archipiélago de las Huríes acaba de ser devastado por un maremoto de
dimensiones desconocidas hasta la fecha. La primera consecuencia ha sido que todos y
cada uno de los puentes que unían las diferentes ciudades de las tres islas han sido
destruidos. En misión de urgencia las Naciones Unidas han decidido construir el
mínimo número de puentes que permitan unir las tres islas. Asumiendo que el coste de
construcción de los puentes implicados los pagará la ONU, por lo que se considera
irrelevante, nuestro problema es decidir qué puentes deben construirse. Las tres islas de
las Huríes tienen respectivamente N1, N2 y N3 ciudades, de las cuales C1, C2 y C3 son
costeras (obviamente C1 ≤ N1 , C2 ≤ N2 y C3 ≤ N3) . Nuestro problema es elegir los
puentes a construir entre todos los posibles. Por tanto, escogeremos aquellos puentes
que minimicen el coste global de viajar entre todas las ciudades de las tres islas,
teniendo en cuenta las siguientes premisas:
1. Se asume que el coste viajar entre las ciudades que unan los puentes es 0.
2. La ONU subvencionará únicamente el número mínimo de puentes necesario
para comunicar las tres islas.
3. Para poder plantearse las mejoras en el transporte que implica la construcción de
un puente frente a cualquier otro, se asume que se realizarán exactamente el
mismo número de viajes entre cualesquiera ciudades del archipélago. Dicho de
otra forma, todos los posibles trayectos a realizar dentro del archipiélago son
igual de importantes.
Dadas las matrices de costes directos de las tres islas y las listas de ciudades costeras
del archipiélago, implementad un subprograma que calcule los puentes a construir en las
condiciones anteriormente descritas.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"

typedef typename GrafoP<size_t>::vertice vertice;

struct Puente{
    vertice A;
    vertice B;
};

struct presupuesto{
    size_t  precio;
    Puente P;
};

template <typename tCoste>
tCoste mejorPuente(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, vertice ciudad1, vertice ciudad2, size_t N3){

    tCoste costeMin;    //Valor de la suma de costes minimos de la matriz de costes que devolvera Floyd al aplicarselo al supergrafo del archipielago.
    matriz<tCoste> F;   //Matriz de costes minimos devuelta por Floyd una vez aplicado al supergrafo.
    matriz<vertice> P;  //Matriz de vertices con el camino minimo que utilizaremos para Floyd.
    size_t N1 = isla1.numVert();
    size_t N2 = isla2.numVert();
    GrafoP<tCoste> archipielago(N1+N2+N3);

    //Rellenamos los costes de la isla 1.
    for(int i=0; i<N1; ++i)
        for(int j=0; j<N1; ++j)
        archipielago[i][j] = isla1[i][j];

    //Rellenamos los costes de la isla 2.
    for(int i=N1; i<N1+N2; ++i)
        for(int j=N1; j<N1+N2; ++j)
            archipielago[i][j] = isla2[i-N1][j-N1];

    //Rellenamos el coste del puente (0) que une a las 2 ciudades que hemos pasado:
    archipielago[ciudad1][ciudad2] = 0;
    archipielago[ciudad2][ciudad1] = 0;

    F = Floyd(archipielago, P);

    //Ahora necesitamos la suma de todos los costes de la matriz F devuelta por Floyd, para ello solo tenemos que aplicar un sumatorio a dicha matriz:
    for(int i=0; i<F.dimension(); ++i)
        for(int j=0; j<F.dimension(); ++j){
            if(F[i][j] != GrafoP<tCoste>::INFINITO)
                costeMin += F[i][j];
        }

    return costeMin;
}

template <typename tCoste>
presupuesto presupuestoPuente(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, Lista<vertice>& ciudades1, Lista<vertice>& ciudades2, size_t N3){

    presupuesto Pres;
    Puente mejorPuente;
    tCoste costeActual;
    tCoste mejorCoste = GrafoP<tCoste>::INFINITO;
    Lista<vertice>::posicion pos1;
    Lista<vertice>::posicion pos2;

    pos1 = ciudades1.primera();
    while(pos1 != ciudades1.fin()){ //Recorremos la lista de ciudades costeras de la isla1

        pos2 = ciudades2.primera();
        while(pos2 != ciudades2.fin()){ //Recorremos la lista de ciudades costeras de la isla2

            //Calculamos el coste minimo de recorrer todo el archipielago con las 2 ciudades de cada lista:
            costeActual = mejorPuente(isla1, isla2, ciudades1.elemento(pos1), ciudades2.elemento(pos2), N3);

            if(costeActual < mejorCoste){    //Si obtenemos un coste menor, lo actualizamos.
                mejorCoste = costeActual;
                mejorPuente.A = ciudades1.elemento(pos1);   //Tambien actualizamos las ciudades que unirá nuestro puente.
                mejorPuente.B = ciudades2.elemento(pos2);
            }

            pos2 = ciudades2.siguiente(pos2);
        }

        pos1 = ciudades1.siguiente(pos1);
    }

    //Guardamos el puente y el precio referentes al mejor presupuesto:

    Pres.P = mejorPuente;
    Pres.precio = mejorCoste;

    return Pres;
}

template <typename tCoste>
vector<Puente> huriesDevastado(const GrafoP<tCoste>& isla1, const GrafoP<tCoste>& isla2, const GrafoP<tCoste>& isla3,
                            Lista<vertice>& ciudades1, Lista<vertice>& ciudades2,
                            Lista<vertice>& ciudades3){

    vector<Puente> mejoresPuentes(2);   //Minimo nº de puentes para hacer posible la conexion entre las 3 islas, seran los 2 con menor presupuesto.
    vector<presupuesto> presupuesto(3); //presupuestos para 3 puentes p1: C1-C2; p2: C1-C3; p3: C2-C3
    vector<presupuesto> DosPres(2); //los 2 presupuestos mas baratos

    //Debemos calcular cuales los presupuestos de los 3 posibles puentes:
    presupuesto[0] = presupuestoPuente(isla1, isla2, ciudades1, ciudades2, isla3.numVert());
    presupuesto[1] = presupuestoPuente(isla1, isla3, ciudades1, ciudades3, isla2.numVert());
    presupuesto[2] = presupuestoPuente(isla2, isla3, ciudades2, ciudades3, isla1.numVert());

    //Ahora solo queda, de los 3 presupuestos obtener los 2 mas baratos:

    DosPres[0] = presupuesto[0];
    DosPres[1] = presupuesto[1];

    if(presupuesto[2].precio < presupuesto[0].precio)
        DosPres[0] = presupuesto[2];
    else if(presupuesto[2].precio < presupuesto[1].precio)
        DosPres[1] = presupuesto[2];

    //Guardamos los 2 puentes con mejores presupuestos:
    mejoresPuentes[0] = DosPres[0].P;
    mejoresPuentes[1] = DosPres[1].P;

    return mejoresPuentes;
}

int main(){

    GrafoP<int> i1("matriz_ej_11_isla1.txt");
    GrafoP<int> i2("matriz_ej_11_isla2.txt");
    GrafoP<int> i3("matriz_ej_11_isla3.txt");

    vector<Puente> puentes;
    Lista<vertice> C1, C2, C3;

    C1.insertar(0, C1.fin());
    C1.insertar(1, C1.fin());
    C2.insertar(2, C2.fin());
    C2.insertar(4, C2.fin());
    C3.insertar(5, C3.fin());
    C3.insertar(7, C3.fin());

    puentes = HuriesDevastacion(i1, i2, i3, C1, C2, C3);

    cout << "Puente 1 va de " << puentes[0].A << " a " << puentes[0].B << endl;
    cout << "Puente 2 va de " << puentes[1].A << " a " << puentes[1].B << endl;
}
