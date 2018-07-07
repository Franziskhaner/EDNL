/** Ejercicio 2(P3): Implementa un subprograma que dados un árbol y un nodo dentro de dicho árbol determine
la profundidad de éste nodo en el árbol.*/

template <typename T>
int llamadaProfundidadAgen(const Agen<T>& A, typename Agen<T>::nodo n){

    if(n == A.NODO_NULO)    //Si llegamos a la raiz, no tendra padre, por tanto restamos 1, ya que la profundidad de la raiz es 0.
        return -1;
    else{
        return 1 + llamadaProfundidadAgen(A, A.padre(n));
    }
}
