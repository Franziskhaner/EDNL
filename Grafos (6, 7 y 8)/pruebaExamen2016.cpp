#include "alg_grafoPMC.h"
#include "alg_grafoMA.h"

typedef typename GrafoP<size_t>::vertice vertice;

struct ciudad{
    size_t x, y;
    vertice v;
};

struct puente{

    ciudad c1, c2;
};

size_t distEuclidea(ciudad A, ciudad B){

    sqrt(pow(A.x - B.x, 2) + pow(A.y - B.y));
}

GrafoP<tCoste> generarMatrizCoste(const Grafo& adyacencia, vector<ciudad>& ciudadesIsla){

    GrafoP<tCoste> mCostes(adyacencia.numVert());

    for(size_t i=o; i<mCostes.numVert(); i++)
        for(size_t j=0; j<mCostes.numVert(); j++)
            if(adyacencia[i][j])    //Si es true es q hay carretera luego calculamo su coste.
                mCostes[i][j] = distanciaEuclidea(ciudadesIsla[i], ciudadesIsla[j]);

    return mCostes;
}

Puente Nozuelandia(const Grafo& Fobos, const Grafo& Deimos, vector<ciudad>& ciudadesFobos, vector<ciudad>& ciudadesDeimos,
                    vector<bool>& costerasFobos, vector<bool>& costerasDeimos){


    //Generamos las matrices de costes:

    GrafoP<tCoste> mFobos, mDeimos;

    mFobos = generarMatrizCoste(Fobos, ciudadesFobos);
    mDeimos = generarMatrizCoste(Deimos, ciudadesDeimos);

    //Ahora aplicamos Floyd a esas 2 matrices para obtener asi los costes minimos de ambas islas;

    matriz<tCoste> floydFobos, floydDeimos;
    matriz<vertice> pFobos, pDeimos;

    floydFobos = Floyd(mFobos, pFobos);
    floydDeimos = Floyd(mDeimos, pDeimos);

    //Calculamos los costes minimos desde las ciudades costeras de una isla a cualquier otra ciudad de la otra isla, para sacar asi el mejor puente:

    tCoste sumCol;
    tCoste costeMin = GrafoP<tCoste>::INFINITO;
    vertice mejorCiudadFobos, mejorCiudadDeimos;

    //Para Fobos:
    for(size_t i=0; i<floydFobos.dimension(); i++){
        sumCol=0;
        for(size_t j=0; j<floydFobos.dimension(); j++)
            if(costerasFobos[i])    //Calculamos los costes por cada ciudad q sea costera
                sumCol += floydDeimos[i][j];

        if(sumCol < costeMin && costerasFobos){
            costeMin = sumCol;
            mejorCiudadFobos = i;
        }
    }

    //Para Deimos:
     for(size_t i=0; i<floydDeimos.dimension(); i++)
        sumCol=0;
        if(costerasDeimos[i])    //Si la ciudad es costera, calculamos sus costes
            for(size_t j=0; j<floydDeimos.dimension(); j++)
                if(sumCol < costeMin){
                    costeMin = sumCol;
                    mejorCiudadDeimos = i;
                }


    Puente mejorPuente;

    mejorPuente.A.v = mejorCiudadFobos;
    mejorPuente.B.v = mejorCiudadDeimos;

    return mejorPuente;
}
