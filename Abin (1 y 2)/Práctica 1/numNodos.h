/*Problema 1: Implementa un subprograma que calcule el número de nodos de un árbol binario.*/

#include <iostream>
#include "abin.h"

template <typename T>
int llamadaNumNodos(const Abin<T>& A){

    return numNodos(A, A.raizB());
}

template <typename T>
int numNodos(const Abin<T>& A, typename Abin<T>::nodo a){

    if(a == A.NODO_NULO)
        return 0;
    else
        return 1 + numNodos(A, A.hijoIzqdoB(a)) + numNodos(A, A.hijoDrchoB(a));
}

