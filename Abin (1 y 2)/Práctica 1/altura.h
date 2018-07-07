/*Problema 2: Implementa un subprograma que calcule la altura de un árbol binario.*/

#include <iostream>
#include "abin.h"

template <typename T>
int llamadaAltura(const Abin<T>& A){

    if(A.arbolVacioB())
        return -1;
    else
        return altura(A, A.raizB());
}

template <typename T>
int altura(const Abin<T>& A, typename Abin<T>::nodo a){

    if(a == A.NODO_NULO)
        return -1;
    else
        return 1 + std::max(altura(A, A.hijoIzqdoB(a)), altura(A, A.hijoDrchoB(a)));
}
