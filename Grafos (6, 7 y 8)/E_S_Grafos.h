#ifndef E_S_GRAFOS_H
#define E_S_GRAFOS_H

#include <fstream>
#include "GrafoP_MatrizCostes.h"


// Lectura de un grafo desde un fichero de texto de nombre nf,
// que contiene el n�mero de v�rtices seguido de los pesos
// de las aristas.
template <typename tCoste>
GrafoP<tCoste> leerFicheroGrafo(const std::string& nf)
{
    std::ifstream fg(nf.c_str()); // apertura del fichero
    unsigned n;         // n�m. v�rtices
    fg >> n;
    GrafoP<tCoste> g(n);// grafo ponderado de n v�rtices
    fg >> g;            // lectura de aristas
    fg.close();         // cierre del fichero
    return g;
}

#endif // E_S_GRAFOS_H
