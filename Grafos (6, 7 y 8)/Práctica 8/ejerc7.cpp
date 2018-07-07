/** Problema 7: El archipiélago de Grecoland (Zuelandia) está formado únicamente por dos islas,
Fobos y Deimos, que tienen N1 y N2 ciudades, respectivamente, de las cuales C1 y C2
ciudades son costeras (obviamente C1 <= N1 y C2 <= N2 ). Se dispone de las coordenadas
cartesianas (x, y) de todas y cada una de las ciudades del archipiélago. El huracán
Isadore acaba de devastar el archipiélago, con lo que todas las carreteras y puentes
construidos en su día han desaparecido. En esta terrible situación se pide ayuda a la
ONU, que acepta reconstruir el archipiélago (es decir volver a comunicar todas las
ciudades del archipiélago) siempre que se haga al mínimo coste.
De cara a poder comparar costes de posibles reconstrucciones se asume lo
siguiente:
1. El coste de construir cualquier carretera o cualquier puente es proporcional a su
longitud (distancia euclídea entre las poblaciones de inicio y fin de la carretera o
del puente).
2. Cualquier puente que se construya siempre será más caro que cualquier carretera
que se construya.
De cara a poder calcular los costes de VIAJAR entre cualquier ciudad del
archipiélago se considerará lo siguiente:
1. El coste directo de viajar, es decir de utilización de una carretera o de un puente,
coincidirá con su longitud (distancia euclídea entre las poblaciones origen y
destino de la carretera o del puente).
En estas condiciones, implementa un subprograma que calcule el coste mínimo
de viajar entre dos ciudades de Grecoland, origen y destino, después de haberse
reconstruido el archipiélago, dados los siguientes datos:
1. Lista de ciudades de Fobos representadas mediante sus coordenadas cartesianas.
2. Lista de ciudades de Deimos representadas mediante sus coordenadas cartesianas.
3. Lista de ciudades costeras de Fobos.
4. Lista de ciudades costeras de Deimos.
5. Ciudad origen del viaje.
6. Ciudad destino del viaje.
*/

typedef typename GrafoP<size_t>::vertice vertice;

struct ciudad{
    size_t x, y;    //Coordenadas cartesianas.
    vertice v;
};

int main(){

    ciudad c0, c1, c2, c3, c4, c5;
    Lista<ciudad> F, D;     //lista de ciudades de fobos y deimos
    Lista<ciudad> Cf, Cd;   //lista de ciudades costeras de fobos y deimos
    vertice origen=1, destino=5;

    //ciudades fobos
    c0.v= 0; c0.x=3 ; c0.y=8;  F.insertar(c0, F.fin());
    c1.v= 1; c1.x=6 ; c1.y=3 ; F.insertar(c1, F.fin()); Cf.insertar(c1, Cf.fin()); //costera
    c2.v= 2; c2.x=9 ; c2.y=9 ; F.insertar(c2, F.fin()); Cf.insertar(c2, Cf.fin()); //costera

    //ciudades deimos
    c3.v= 3; c3.x=28 ; c3.y=9 ; D.insertar(c3, D.fin()); Cd.insertar(c3, Cd.fin()); //costera
    c4.v= 4; c4.x=29 ; c4.y=4 ; D.insertar(c4, D.fin()); Cd.insertar(c4, Cd.fin()); //costera
    c5.v= 5; c5.x=33 ; c5.y=9 ; D.insertar(c5, D.fin());

    cout << "El coste minimo para viajar entre las ciudades origen y destino es: " << GrecolandIsadore<size_t>(F, D, Cf, Cd, origen, destino) << endl;
}
