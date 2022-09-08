#ifndef LIBRERIAS_H_INCLUDED
#define LIBRERIAS_H_INCLUDED

typedef struct
{
    int dato;
    struct nodo *sig;
} nodo;

nodo *iniclista();
nodo *crearNodo(int dato) ;

nodo *agregarPrincipio (nodo *lista, nodo *nn) ;
nodo *agregarFinal (nodo *lista, nodo *nn);
nodo *agregarEnOrden (nodo *lista, nodo *nn);

nodo *borrarNodo (nodo *lista, int nota);
void borrarLista (nodo *lista);

nodo *buscarUltimo (nodo *lista);
int buscarNodo (int dato, nodo *lista);

void mostrarNodo (nodo *aux);
void mostrarLista (nodo *lista);

#endif // LIBRERIAS_H_INCLUDED
