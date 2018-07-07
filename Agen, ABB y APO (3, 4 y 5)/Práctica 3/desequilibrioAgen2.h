/** Ejercicio 3(P3): Se define el desequilibrio de un �rbol general como la m�xima diferencia entre las alturas
de los sub�rboles m�s bajo y m�s alto de cada nivel. Implementa un subprograma que calcule
el grado de desequilibrio de un �rbol general.*/

template <typename T>
 int llamadaDesequilibrioAgen(const Agen<T>& A){

    if(A.arbolVacio())
        return 0;
    else
        return desequilibrioAgenRec(A, A.raiz());
 }

 template <typename T>
 int desequilibrioAgenRec(const Agen<T>& A, typename Agen<T>::nodo n){

    if(n == A.NODO_NULO)
        return 0;
    else{
        int desequilibrio = abs(alturaMax(A, n) - alturaMin(A, n));
        return desequilibrio;
    }
 }

 template <typename T>
 int alturaMax(const Agen<T>& A, typename Agen<T>::nodo n){

     if(n == A.NODO_NULO)
        return -1;
     else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altura = alturaMax(A, hijo);

        while(hijo != A.NODO_NULO){
            altura = std::max(altura, alturaMax(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
     }

 }


 template <typename T>
 int alturaMin(const Agen<T>& A, typename Agen<T>::nodo n){

     if(n == A.NODO_NULO)
        return -1;
     else{
        typename Agen<T>::nodo hijo = A.hijoIzqdo(n);
        int altura = alturaMin(A, hijo);

        while(hijo != A.NODO_NULO){
            altura = std::min(altura, alturaMin(A, hijo));
            hijo = A.hermDrcho(hijo);
        }
        return 1 + altura;
     }
 }
