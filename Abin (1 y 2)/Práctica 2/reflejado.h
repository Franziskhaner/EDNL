/*Problema 2: Para un árbol binario B, podemos construir el árbol binario reflejado BR cambiando
los subárboles izquierdo y derecho en cada nodo. Implementa un subprograma que
devuelva el árbol binario reflejado de uno dado.*/

#include "abin.h"

using namespace std;

template <typename T>
Abin<T> llamadaReflejado (const Abin<T>& A){

    Abin<T> B;

    if(A.arbolVacioB())
        return A;
    else{
        B.insertarRaizB(A.elemento(A.raizB()));
        reflejado(A, B, A.raizB(), B.raizB());
        return B;
    }
}

template <typename T>
void reflejado(const Abin<T>& A, Abin<T>& B, typename Abin<T>::nodo n, typename Abin<T>::nodo m){

        if(A.hijoIzqdoB(n) != A.NODO_NULO){ //Si el arbol A tiene hijo izquierdo, insertamos un hijo derecho al arbol B.
            B.insertarHijoDrchoB(m, A.elemento(A.hijoIzqdoB(n)));
            reflejado(A, B, A.hijoIzqdoB(n), B.hijoDrchoB(m));
        }

        if(A.hijoDrchoB(n) != A.NODO_NULO){ //Si el arbol A tiene hijo derecho, insertamos un hijo izquierdo al arbol B.
            B.insertarHijoIzqdoB(m, A.elemento(A.hijoDrchoB(n)));
            reflejado(A, B, A.hijoDrchoB(n), B.hijoIzqdoB(m));
        }
}
