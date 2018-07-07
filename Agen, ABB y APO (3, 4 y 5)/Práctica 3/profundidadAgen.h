/*Problema 2: Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
la profundidad de éste nodo en el árbol.*/

#include "AGEN.h"

template <typename T>
int llamadaProfundidadAgen(const Agen<T>& A, typename Agen<T>::nodo n){

    if(n == A.raiz())
        return 0;
    else
        return profundidadAgenRec(A, n);
}

template <typename T>
int profundidadAgenRec(const Agen<T>& A, typename Agen<T>::nodo n){

    if(n == A.raiz())
        return 0;
    else
        return 1 + profundidadAgenRec(A, A.padre(n));
}

