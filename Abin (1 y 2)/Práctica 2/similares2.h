/** Ejercicio 1 (p2): Dos �rboles binarios son similares cuando tienen id�ntica estructura de ramificaci�n,
es decir, ambos son vac�os, o en caso contrario, tienen sub�rboles izquierdo y derecho
similares. Implementa un subprograma que determine si dos �rboles binarios son
similares.*/

template <typename T>
bool llamadaSimilares(const Abin<T>& A, const Abin<T>& B){

    if(A.arbolVacioB() && B.arbolVacioB())
        return true;
    else{
        if((A.arbolVacioB() && !B.arbolVacioB()) || (!A.arbolVacioB() && B.arbolVacioB()))
           return false;
        else
            return similaresRec(A, B, A.raizB(), B.raizB());
    }
}

template <typename T>
bool similaresRec(const Abin<T>& A, const Abin<T>& B, typename Abin<T>::nodo a, typename Abin<T>::nodo b){

    if(a == A.NODO_NULO && b == B.NODO_NULO)
        return true;
    else{
        if((a != A.NODO_NULO && b == B.NODO_NULO) || (a == A.NODO_NULO && b != B.NODO_NULO))
            return false;
        else
            return similaresRec(A, B, A.hijoIzqdoB(a), B.hijoIzqdoB(b)) && similaresRec(A, B, A.hijoDrchoB(a), B.hijoDrchoB(b));
    }
}
