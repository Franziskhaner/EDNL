/*Problema 6: Implementa un subprograma que determine el nivel de desequilibrio de un árbol binario,
definido como el máximo desequilibrio de todos sus nodos. El desequilibrio de un nodo se
define como la diferencia entre las alturas de los subárboles del mismo.*/

#include "abin_ampliado.h"
#include <stdlib.h>

using namespace std;

template <typename T>
int llamadaDesequilibrio(const Abin<T>& A){

    int desequilibrio = 0;
    return Desequilibrio(A, A.raizB(), desequilibrio);
}

template <typename T>
int Desequilibrio(const Abin<T>& A, typename Abin<T>::nodo n, int desequilibrio){

    if(n == A.NODO_NULO)
        return 0;
    else{
        int aux = abs(A.alturaB(A.hijoIzqdoB(n)) - A.alturaB(A.hijoDrchoB(n)));

        if(A.hijoIzqdoB(n) != A.NODO_NULO)
            return abs(max(desequilibrio, Desequilibrio(A, A.hijoIzqdoB(n), aux)));
        else
            return abs(max(desequilibrio, Desequilibrio(A, A.hijoDrchoB(n), aux)));
    }
}
