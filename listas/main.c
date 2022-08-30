#include <stdio.h>
#include <stdlib.h>
#include "libListas.h"

int main()
{
    nodo *lista=iniclista();

    nodo *uno=crearNodo("valen", 60670, 10);

    lista=agregarPrincipio(lista, uno);

    nodo *dos=crearNodo("juli", 4567, 9);

    lista=agregarPrincipio(lista, dos);

    nodo *tres= crearNodo("cami", 5643, 10);

    lista=agregarPrincipio(lista, tres);

    nodo *cuatro=crearNodo("vane", 6436654, 8);

    lista=agregarPrincipio(lista, cuatro);

    nodo *cinco=crearNodo("lu", 35783949, 10);

    lista=agregarPrincipio(lista, cinco);

    borrarLista(lista);

    mostrarLista(lista);

    return 0;
}
