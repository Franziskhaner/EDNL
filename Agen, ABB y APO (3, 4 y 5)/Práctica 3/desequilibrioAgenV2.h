/*Problema 3: Se define el desequilibrio de un árbol general como la máxima diferencia entre las alturas
de los subárboles más bajo y más alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un árbol general.*/

#include "AGEN.h"

template <typename T>
int llamadaDesequilibrioAgen(const Agen<T> A){

    if(A.arbolVacio())
        return 0;
    else
        return(desequilibrioAgenRec(A.raiz(), A));
}

template <typename T>
int desequilibrioAgenRec(typename Agen<T>::nodo n, const Agen<T> A, int alturaMax, int alturaMin){

    if(n == A.NODO_NULO)
        return 0;
    else{

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO){ //Recorremos el numero de hijos de n

            if(alturaNodo(n, A) < alturaMin)
                alturaMin = alturaNodo(n, A);
            else if(alturaNodo(n, A) > alturaMax)
                alturaMax = alturaNodo(n, A);

            hijo = A.hermDrcho(hijo);
        }



        desequilibrio = alturaMax - alturaMin;
        return desequilibrio;
    }
}

template <typename T>
int alturaNodo(typename Agen<T>::nodo n, const Agen<T> A){

    int altura = -1;
    if(n == A.NODO_NULO)
        return -1;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        while(hijo != A.NODO_NULO){
            altura =  std::max(altura, alturaNodo(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
    }
}

