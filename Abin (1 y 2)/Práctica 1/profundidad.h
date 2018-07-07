/*Problema 3: Implementa un subprograma que, dados un �rbol binario y un nodo del mismo, determine
la profundidad de este nodo en dicho �rbol.*/

#include <iostream>
#include "abin.h"

template <typename T>
int llamadaProfundidad(const Abin<T>& A, typename Abin<T>::nodo a){

    if(A.arbolVacioB())
        return -1;
    else{
        if(a == A.NODO_NULO)
            return 0;
        else
            return profundidad(A, a);
    }
}

template <typename T>
int profundidad(const Abin<T>& A, typename Abin<T>::nodo a){

    if(a == A.raizB())
        return 0;
    else
        return 1 + (profundidad(A, A.padreB(a)));
}
