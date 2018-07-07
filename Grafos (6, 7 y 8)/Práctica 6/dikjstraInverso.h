/**Problema 1: A�adir una funci�n gen�rica, llamada DijkstraInv, en el fichero
alg_grafoPMC.h para resolver el problema inverso al de Dijkstra, con los mismos
tipos de par�metros y de resultado que la funci�n ya incluida para �ste. La nueva
funci�n, por tanto, debe hallar el camino de coste m�nimo hasta un destino desde cada
v�rtice del grafo y su correspondiente coste.
*/

template <typename tCoste>
vector<tCoste> DijkstraInv(const GrafoP<tCoste>& G,
                        typename GrafoP<tCoste>::vertice destino,
                        vector<typename GrafoP<tCoste>::vertice>& P)
// Calcula los caminos de coste m�nimo entre todos los v�rtices destinos y el origen del grafo G.
// En el vector D de tama�o G.numVert() devuelve estos costes m�nimos y P es un vector de tama�o
// G.numVert() tal que P[i] es el �ltimo v�rtice del camino
// de origen a i.
{
   typedef typename GrafoP<tCoste>::vertice vertice;
   vertice v, w;
   const size_t n = G.numVert();
   vector<bool> S(n, false);                  // Conjunto de v�rtices vac�o.
   vector<tCoste> D;                          // Costes m�nimos desde origen.

   // Iniciar D y P con caminos directos hasta el destino.
   for(int fila=0; fila<n; fila++)
      D[fila] = G[fila][destino];

   D[destino] = 0;                             // Coste origen-origen es 0.
   P = vector<vertice>(n, destino);

   // Calcular caminos de coste m�nimo desde cada v�rtice.
   S[destino] = true;                          // Incluir v�rtice destino en S.
   for (size_t i = 1; i <= n-1; i++) {
      // Seleccionar v�rtice w no incluido en S
      // con menor coste desde origen.
      tCoste costeMin = GrafoP<tCoste>::INFINITO;
      for (v = 0; v < n; v++)
         if (!S[v] && D[v] <= costeMin) {
            costeMin = D[v];
            w = v;
         }
      S[w] = true;                          // Incluir v�rtice w en S.
      // Recalcular coste hasta cada v no incluido en S a trav�s de w.
      for (v = 0; v < n; v++)
         if (!S[v]) {
            tCoste Owv = suma(D[w], G[v][w]);
            if (Owv < D[v]) {
               D[v] = Owv;
               P[v] = w;
            }
         }
   }
   return D;
}
