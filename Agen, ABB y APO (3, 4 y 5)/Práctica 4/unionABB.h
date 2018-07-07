/** Problema 4: Dados dos conjuntos representados mediante árboles binarios de búsqueda,
implementa la operación unión de dos conjuntos que devuelva como resultado otro
conjunto que sea la unión de ambos, representado por un ABB equilibrado.*/

#include "abb.h"

template <typename T>
Abb<T> llamadaUnion (Abb<T>& A, Abb<T>& B){

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
            unionAbbRec(A, B, C);
    }

    return C;
}


template <typename T>
void unionAbbRec (const Abb<T>& A, const Abb<T>& B, Abb<T>& C){

    if(!A.vacio() && !B.vacio()){

        C.insertar(A.elemento());
        C.insertar(B.elemento());
        unionAbbRec(A.izqdo(), B.izqdo(), C);
        unionAbbRec(A.drcho(), B.drcho(), C);
    }
    else{
    if(!A.vacio()){
        C.insertar(A.elemento());
        unionAbbRec(A.izqdo(), B, C);
        unionAbbRec(A.drcho(), B, C);
    }
    else if(!B.vacio()){
        C.insertar(B.elemento());
        unionAbbRec(A, B.izqdo(), C);
        unionAbbRec(A, B.drcho(), C);
    }
    }
}
