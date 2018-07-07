/** Ejercicio 1(P3):  Implementa un subprograma que dado un árbol general nos calcule su grado.*/

template <typename T>
int llamadaGradoAgen(const Agen<T>& A){

    int numMaxHijos = 0;

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
        int numMaxHijos = contarHijos(A, n);
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO){
            numMaxHijos = std::max(numMaxHijos, gradoAgenRec(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return numMaxHijos;
    }
}

template <typename T>
int contarHijos(const Agen<T>& A, typename Agen<T>::nodo n){

    int numHijos = 1;

    if(n == A.NODO_NULO)
        return 0;
    else{
        typename Agen<T>::nodo hermano = A.hermDrcho(n);
        while(hermano != A.NODO_NULO){
            numHijos++;
            hermano = A.hermDrcho(hermano);
        }
        return numHijos;
    }
}

