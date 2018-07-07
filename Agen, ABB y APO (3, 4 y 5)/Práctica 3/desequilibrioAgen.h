/*Problema 3: Se define el desequilibrio de un �rbol general como la m�xima diferencia entre las alturas
de los sub�rboles m�s bajo y m�s alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un �rbol general.*/

template <typename T>
int llamadaDesequilibrioAgen(const Agen<T> A){

    if(A.arbolVacio())
        return 0;
    else
        return(desequilibrioAgenRec(A.raiz(), A));
}

template <typename T>
int desequilibrioAgenRec(typename Agen<T>::nodo n, const Agen<T> A){

    if(n == A.NODO_NULO)
        return 0;
    else{
        int desequilibrio = alturaMax(n, A) - alturaMin(n, A);
        return desequilibrio;
    }
}

template <typename T>
int alturaMax(typename Agen<T>::nodo n, const Agen<T> A){

    if(n == A.NODO_NULO)
        return -1;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altura = alturaMax(hijo, A);

        while(hijo != A.NODO_NULO){
            altura =  std::max(altura, alturaMax(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
    }
}

template <typename T>
int alturaMin(typename Agen<T>::nodo n, const Agen<T> A){

    if(n == A.NODO_NULO)
        return -1;
    else
    {
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altura = alturaMin(hijo, A);

        while(hijo != A.NODO_NULO){
            altura =  std::min(altura, alturaMin(hijo, A));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
    }
}
