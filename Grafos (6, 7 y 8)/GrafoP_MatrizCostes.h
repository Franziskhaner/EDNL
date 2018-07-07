#ifndef GRAFOP_MATRIZCOSTES_H
#define GRAFOP_MATRIZCOSTES_H

#include <vector>
#include <limits>

using namespace std;
typedef size_t vertice; // un valor entre 0 y GrafoP::numVert()-1

template <typename tCoste> class GrafoP {// Grafo ponderado

    public:
        static const tCoste INFINITO;
        GrafoP(size_t n): costes(n, vector<tCoste>(n, INFINITO)) {}
        size_t numVert() const {return costes.size();}
        const vector<tCoste>& operator [](vertice v) const {return costes[v];}
        vector<tCoste>& operator [](vertice v) {return costes[v];}

        istream &operator>>(istream &is);
        ostream &operator<<(ostream &os);

    private:
        vector<vector<tCoste> > costes;

};

// Definición de INFINITO
template <typename tCoste>
const tCoste GrafoP<tCoste>::INFINITO = std::numeric_limits<tCoste>::max();


template <typename tCoste>
istream& operator >>(istream& is, GrafoP<tCoste>& G){
    tCoste e;

    for(size_t i=0; i<G.numVert(); ++i)
    {
        for(size_t j=0; j<G.numVert(); ++j)
        {
            is >> e;
            if(e == -1)
                G[i][j] = GrafoP<tCoste>::INFINITO;
            else
                G[i][j] = e;
        }
    }

    return is;
}


template <typename tCoste>
ostream& operator <<(ostream& os, const GrafoP<tCoste> G){
    os << "f/c\t";
    for(size_t i=0; i<G.numVert(); ++i)
        os << i << "\t";
    os << "\n\t";
    for(size_t i=0; i<G.numVert(); ++i)
        os << "_" << "\t";

    os << "\n\n";
    for(size_t i=0; i<G.numVert(); ++i)
    {
        os << i << " |\t";
        for(size_t j=0; j<G.numVert(); ++j)
        {
            if(G[i][j] == GrafoP<tCoste>::INFINITO)
                os << char(126) << "\t";
            else
                os << G[i][j] << "\t";
        }
        os << "\n\n";
    }

    return os;
}

#endif // GRAFOP_MATRIZCOSTES_H
