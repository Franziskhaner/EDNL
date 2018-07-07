/** Problema 3: Un árbol binario de búsqueda se puede equilibrar realizando el recorrido en inorden
del árbol para obtener el listado ordenado de sus elementos y a continuación, repartir
equitativamente los elementos a izquierda y derecha colocando la mediana en la raíz y
construyendo recursivamente los subárboles izquierdo y derecho de cada nodo.
Implementa este algoritmo para equilibrar un ABB.*/

#include <vector>
#include "abb.h"

using namespace std;

template <typename T>
Abb<T> llamadaEquilibrar(Abb<T> A){

    Abb<T> equilibrado;
    vector<T> v;

    recorridoInordenAbb(A, v);   //Recorremos A en inorden y vamos guardando los elementos en el vector v de forma ordenada.
/*
    for(unsigned it=0; v.size(); it++)
        cout<< v[it] << endl;
    cout << "Vector terminado" << endl;
*/
    equilibrarAbbRec(equilibrado, v);    //Vamos generando el arbol equilibrado a partir de los elementos de v.

    return equilibrado;
}

template <typename T>
void recorridoInordenAbb(Abb<T> A, vector<T>& v){

    if(!A.vacio()){
        recorridoInordenAbb(A.izqdo(), v);
        v.push_back(A.elemento());
        recorridoInordenAbb(A.drcho(), v);
    }
}


template <typename T>
void equilibrarAbbRec(Abb<T>& Equi, vector<T>& v){

    if(v.size() == 1)   //Si sólo queda un elemento en el vector lo insertamos directamente en el árbol.
        Equi.insertar(v.front());
    else{
        if(v.size() != 0){

            vector<T> vIzq, vDer;
            T mediana = v.size()/2;
            Equi.insertar(v[mediana]);

            for(int i=0; i < mediana; i++)
                vIzq.push_back(v[i]);

            for(int i=mediana+1; i < v.size(); i++)
                vDer.push_back(v[i]);

            equilibrarAbbRec(Equi, vIzq);
            equilibrarAbbRec(Equi, vDer);
        }
    }
}
