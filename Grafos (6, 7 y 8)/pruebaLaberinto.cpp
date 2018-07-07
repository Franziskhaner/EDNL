
typedef typename GrafoP<tCoste>::vertice vertice;

struct casilla{

    size_t fil, col;
};

bool hayPiedra(vertice v1, vertice v2, const vector<casilla>& listaPiedras, size_t N){

    for(size_t i=0; i < listaPiedras.size(); i++)
        if(CasillaToNodo(listaPiedras[i], N) == vertice v1 || CasillaToNodo(listaPiedras[j], N) == vertice v2)
            return true;
}

bool esAdyacente(casilla c1, casilla c2){

    if(c1.fil == c2.fil && abs(c1.col - c2.col) == 1)
        return true;
    else if(c1.col == c2.col && abs(c1.fil - c2.fil == 1))
        return true;
    else
        return false;
}

casilla NodoToCasilla(vertice v, size_t N){

    casilla c;

    c.fil = v/N;
    c.col = v%N;

    return c;
}

vertice CasillaToNodo(casilla c, size_t N){

    vertice v;

    v = c.fil*N + c.col;

    return v;
}

tCoste laberinto(size_t N, const vector<casilla>& piedras, casilla entrada, casilla salida, typename GrafoP<tCoste>::tCamino& caminoMin){

    GrafoP<tCoste> laberinto(N*N);

    //En primer lugar vamos a crear el laberinto con los costes correspondientes:
    for(size_t i=0; i < laberinto.numVert(); i++)
        for(size_t j=0; j < laberinto.numVert(); j++)
            if(i == j)  //Si estaos en la misma casilla el coste es cero
                laberinto[i][j] = 0;
            else if(esAdyacente(NodoToCasilla(i, N), NodoToCasilla(j, N)) && !hayPiedra(i, j, piedras, N))    //Si la casilla es adyacente y no hay piedra en ella,
                laberinto[i][j] = 1;                           //entonces podemos movernos a ella y el coste es 1.
            else
                laberinto[i][j] = GrafoP<tCoste>::INFINITO; //En cualquier otro caso, no podemos movernos en el laberinto y el coste es
                                                            //infinito.

    //Ahora aplicamos Dijkstra para obtner el camino de costes minimos:
    vertice origen = CasillaToNodo(entrada, N);
    vertice destino = CasillaToNodo(salida, N);
    vector<vertice> P;

    vector<tCoste> costesLaberinto = Dijkstra(laberinto, origen, P);

    //Para el camino minimo hacia la salida utilizamos la funcion camino:

    caminoMin = camino(origen, destino, P);

    return costesLaberinto[destino];
}
