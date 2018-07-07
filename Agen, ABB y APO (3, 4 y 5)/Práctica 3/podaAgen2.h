
template <typename T>
void llamadaPoda(Agen<T>& A, int x){

    bool encontrado = false;

    if(A.arbolVacio())
        std::cout << "El arbol esta vacio, por favor introduzca al menos un nodo." << std::endl;
    else{
        if(x == A.elemento(A.raiz()))
            podaAgen(A, A.raiz());
        else
            podaAgenRec(A, A.raiz(), x, encontrado);
    }
}

template <typename T>
void podaAgenRec(Agen<T>& A, typename Agen<T>::nodo n, int elto, bool encontrado){

    if(!encontrado && n != A.NODO_NULO){

        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

        while(hijo != A.NODO_NULO){
            if(elto == A.elemento(hijo)){
                encontrado == true;
                podaAgen(A, hijo);
            }
            podaAgenRec(A, hijo, elto, encontrado);
            hijo = A.hermDrcho(hijo);
        }
    }
}

template <typename T>
void podaAgen(Agen<T>& A, typename Agen<T>::nodo n){

    typename Agen<T>::nodo hijo = A.hijoIzqdo(n);

    while(hijo != A.NODO_NULO){
        podaAgen(A, hijo);
        hijo = A.hermDrcho(hijo);
        A.eliminarHijoIzqdo(n);
    }
}
