/*Problema 1: Implementa un subprograma que dado un árbol general nos calcule su grado.*/

#include "AGEN.h"

template <typename T>
int llamadaGradoAgen(const Agen<T>& A){

    if(A.arbolVacio())
        return 0;
    else
        return gradoAgenRec(A, A.raiz());
}

template <typename T>
int gradoAgenRec(const Agen<T>& A, typename Agen<T>::nodo n){

    if(n == A.NODO_NULO)
        return 0;
    else{
        int gradoMax = numHijos(A, n);  //Guardamos el numero de nodos que hay en el nivel donde está n.
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO){ //Recorremos el numero de hijos de n
            gradoMax = std::max(gradoMax, gradoAgenRec(A, hijo));  //y guardamos el maximo valor del grado entre el del nivel de n y el nivel de los hijos de n.
            hijo = A.hermDrcho(hijo);
        }

        return gradoMax;   //Devolvemos la variable con el mayor grado del arbol.
    }
}

template <typename T>
int numHijos(const Agen<T>& A, typename Agen<T>::nodo n){   //Con esta funcion calculamos el numero de hijos de cada nodo.

    int gradoHijo = 1;

    if(n == A.NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hermano = A.hermDrcho(n);    //Recorremos de forma iterativa el numero de hermanos de n.
        while(hermano != A.NODO_NULO){
            gradoHijo++;
            hermano = A.hermDrcho(hermano);
        }
        return gradoHijo;   //Cuando n no tengas mas hermanos, devolvemos el grado.
    }
}
