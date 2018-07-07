/*Problema 7: Implementa un subprograma que determine si un árbol binario es o no pseudocompleto.
En este problema entenderemos que un árbol es pseudocompleto, si en el penúltimo nivel
del mismo cada uno de los nodos tiene dos hijos o ninguno.*/

#include "abin_ampliado.h"

template <typename T>
bool llamadaPseudocompleto (const Abin<T>& A){

    if(A.arbolVacioB())    //Si el arbol esta vacio diremos que se considera pseudocompleto.
        return true;
    else{
        if(A.hijoIzqdoB(A.raizB()) == A.NODO_NULO && A.hijoDrchoB(A.raizB()) == A.NODO_NULO)    //Si el arbol solo tiene el nodo raiz tambien
            return true;    //lo consideraremos como pseudocompleto.
        else{
            if(A.hijoIzqdoB(A.raizB()) == A.NODO_NULO || A.hijoDrchoB(A.raizB()) == A.NODO_NULO)    //Si la raiz solo tiene un nodo hijo
                return false;   //entenderemos que el arbol no puede ser pseudocompleto.
            else
                return recursiva(A, A.raizB());
        }
    }
}

template <typename T>
bool recursiva (const Abin<T>& A, typename Abin<T>::nodo n){

    if(A.profundidadB(n) == (A.alturaB(n) - 1)){    //Comprobamos que el nodo esta en el penultimo nivel si la profundidad de dicho nodo
        return pseudocompleto(A, n);                   //es igual a la altura del arbol menos 1.
    }
    else{   //Si no esta en el penultimo nivel, hacemos las llamadas recursivas hasta encontrarlo.
        if(A.alturaB(A.hijoIzqdoB(n)) > A.alturaB(A.hijoDrchoB(n))) //Nos interesa centrarnos en el penúltimo nivel, por tanto no debemos fijarnos
            return recursiva(A, A.hijoIzqdoB(n));    //en la rama mas corta, si no que buscaremos el nodo en la rama cuya altura sea mayor.
        else{
            if(A.alturaB(A.hijoIzqdoB(n)) < A.alturaB(A.hijoDrchoB(n)))
                return recursiva(A, A.hijoDrchoB(n));
            else
                return recursiva(A, A.hijoIzqdoB(n)) && recursiva(A, A.hijoDrchoB(n)); //Si las dos ramas son igual de largas llamamos a las dos para hacer la comprobación en el mismo nivel.
        }
    }
}

template <typename T>
bool pseudocompleto(const Abin<T>& A, typename Abin<T>::nodo n){

    //Comprobamos que el nodo del penultimo nivel cumple las condiciones necesarias para que el arbol sea pseudocompleto
    if(A.hijoIzqdoB(n) == A.NODO_NULO && A.hijoDrchoB(n) == A.NODO_NULO)    //Si el nodo tiene 2 hijos.
        return true;
    else{
        if(A.hijoIzqdoB(n) != A.NODO_NULO && A.hijoDrchoB(n) != A.NODO_NULO)    //o si no tiene hijos.
            return true;
        else
            return false;
    }
}
