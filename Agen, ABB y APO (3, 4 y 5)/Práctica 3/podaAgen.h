/*Problema 4: Dado un árbol general de enteros A y un entero x, implementa un subprograma que realice
la poda de A a partir de x. Se asume que no hay elementos repetidos en A.*/

#include <iostream>
#include "AGEN.h"

using namespace std;

template <typename T>
void llamadaPoda (Agen<T>& A, int elemento){

    bool encontrado = false;    //Esta variable se pondra a true cuando encontremos el elemento X y hayamos podado
                                //para asi no recorrer el arbol entero
    if(A.arbolVacio())
        cout << "El arbol esta vacío." << endl;
    else{
        if(A.elemento(A.raiz()) == elemento)
            podarHijosRec(A, A.raiz());
        else
            podaAgenRec(A, A.raiz(), elemento, encontrado);
    }
}

template <typename T>
void podaAgenRec (Agen<T>& A, typename Agen<T>::nodo n, int elto, bool encontrado){ //Funcion recursiva que busca el elemento X

    if(encontrado == false){

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO){

            if(A.elemento(hijo) == elto){
                encontrado == true;
                podarHijosRec(A, hijo);
            }

            podaAgenRec(A, hijo, elto, encontrado);
            hijo = A.hermDrcho(hijo);
        }
    }
}

template <typename T>
void podarHijosRec(Agen<T>& A, typename Agen<T>::nodo n){   //Vamos podando en postorden.

    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

    while (hijo != Agen<T>::NODO_NULO) {
        podarHijosRec(A, hijo);
        hijo = A.hermDrcho(hijo);
        A.eliminarHijoIzqdo(n);
    }
}
