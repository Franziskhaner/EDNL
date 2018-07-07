/** Problema 4: Eres el orgulloso due�o de la empresa �Cementos de Zuelandia S.A�. Empresa
dedicada a la fabricaci�n y distribuci�n de cemento, sita en la capital de Zuelandia. Para
la distribuci�n del cemento entre tus diferentes clientes (ciudades de Zuelandia)
dispones de una flota de camiones y de una plantilla de conductores zuelandeses.
El problema a resolver tiene que ver con el car�cter del zueland�s. El zueland�s es
una persona que se toma demasiadas �libertades� en su trabajo, de hecho, tienes
fundadas sospechas de que tus conductores utilizan los camiones de la empresa para
usos particulares (es decir indebidos, y a tu costa) por lo que quieres controlar los
kil�metros que recorren tus camiones.
Todos los d�as se genera el parte de trabajo, en el que se incluyen el n�mero de
cargas de cemento (1 carga = 1 cami�n lleno de cemento) que debes enviar a cada
cliente (cliente = ciudad de Zuelandia). Es innecesario indicar que no todos los d�as hay
que enviar cargas a todos los clientes, y adem�s, puedes suponer razonablemente que tu
flota de camiones es capaz de hacer el trabajo diario.
Para la resoluci�n del problema quiz� sea interesante recordar que Zuelandia es un
pa�s cuya especial orograf�a s�lo permite que las carreteras tengan un sentido de
circulaci�n.
Implementa una funci�n que dado el grafo con las distancias directas entre las
diferentes ciudades zuelandesas, el parte de trabajo diario, y la capital de Zuelandia,
devuelva la distancia total en kil�metros que deben recorrer tus camiones en el d�a, para
que puedas descubrir si es cierto o no que usan tus camiones en actividades ajenas a la
empresa.
Nota Importante:
A partir del problema 5 (el viajero al�rgico), empiezan a aparecer en los enunciados
el uso de diferentes medios de transporte a la hora de realizar un viaje. En nuestros
problemas (tanto en pr�cticas como en ex�menes) asumiremos que
a) Definici�n de trasbordo : En el contexto de los problemas de la asignatura,
consideraremos trasbordo el cambio de medio de transporte.
b) Trasbordos libres y gratuitos por defecto: Si el enunciado del problema no
indica lo contrario los trasbordos en nuestros problemas son libres y gratuitos.*/

#include "../alg_grafo_E-S.h"
#include "../alg_grafoPMC.h"
#include <iostream>

using namespace std;

typedef typename GrafoP<size_t>::vertice vertice;

template <typename tCoste>
tCoste cementosZuelandia(const GrafoP<tCoste>& G, vertice capital, vector<size_t> partes)
{
    tCoste Km;

    vector<vertice> Pida;
    vector<tCoste> Ida;

    vector<vertice> Pvuelta;
    vector<tCoste> Vuelta;

    //Primero aplicamos Dijkstra para saber los costes minimos de ida desde la capital al resto de ciudades y luego DijkstraInv para saber los costes minimos desde cualquier ciudad a la capital.
    Ida = Dijkstra(G, capital, Pida);
    Vuelta = DijkstraInv(G, capital, Pvuelta);

    Km = 0;
    for(size_t i=0; i<partes.size(); ++i)   //Recorremos el vector partes de trabajo para calcular el coste(kilometros) necesario para distribuir las cargas por cada ciudad,
        Km += partes[i]*(Ida[i] + Vuelta[i]);   // seg�n el n� de cargas(o camiones) que hay por cada una y lo vamos sumando.

    return Km;
}

int main(){
    GrafoP<size_t> G("matriz_ej_4.txt");
    vector<size_t> partes{0, 6, 2, 4, 2};
    cout << "Kilometros totales a recorrer por los camiones: " << cementosZuelandia(G, 0, partes) << " Km" << endl;
}
