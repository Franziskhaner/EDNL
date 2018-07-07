/** Problema 5: Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación intersección de dos conjuntos, que devuelva como resultado
otro conjunto que sea la intersección de ambos. El resultado debe quedar en un árbol
equilibrado.*/

#include "abb.h"

template <typename T>
Abb<T> llamadaInterseccion (Abb<T>& A, Abb<T>& B){

    Abb<T> C;

    if(A.vacio() && B.vacio())
        return C;   //Devolvemos el arbol C vacio.
    else{
        if(A.vacio()){
            C = B;
            return C;
        }
        else if(B.vacio()){
            C = A;
            return A;
        }
        else
            interseccionAbbRec(A, B, C);
    }

    return C;
}

template <typename T>
void interseccionAbbRec(const Abb<T>& A, const Abb<T>& B, Abb<T>& C){

    if(!A.vacio()){ //Recorremos solo el arbol A y comprobamos que el elemento de la raiz del subarbol en cada llamada recursiva
        if(!B.buscar(A.elemento()).vacio()){    //se encuentra dentro del arbol B, si lo encuentra, entonces lo guardamos en C, ya que forma
            C.insertar(A.elemento());               //parte de la interseccion.
            interseccionAbbRec(A.izqdo(), B, C);
            interseccionAbbRec(A.drcho(), B, C);
        }
        else{
            interseccionAbbRec(A.izqdo(), B, C);
            interseccionAbbRec(A.drcho(), B, C);
        }
    }
}
