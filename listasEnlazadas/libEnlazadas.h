#ifndef LIBENLAZADAS_H_INCLUDED
#define LIBENLAZADAS_H_INCLUDED

///LISTAS
typedef struct
{
    int legajo;
    int nota;
    char nombre[50];
} alumno;

typedef struct
{
    alumno miAlumno;
    struct nodo *sig;
} nodo;

nodo *iniclista();
nodo *crearNodo(char nombre[50], int legajo, int nota) ;

nodo *agregarPrincipio (nodo *lista, nodo *nn) ;
nodo *agregarFinal (nodo *lista, nodo *nn);
nodo *agregarEnOrden (nodo *lista, nodo *nn);

nodo *borrarNodo (nodo *lista, int nota);
void borrarLista (nodo *lista);

nodo *buscarUltimo (nodo *lista);
int buscarNodo (int dato, nodo *lista);

void mostrarNodo (nodo *aux);
void mostrarLista (nodo *lista);

///LISTAS ENLAZADAS
typedef struct
{
    int dato;
    struct nodoDoble *sig;
    struct nodoDoble *ante;
} nodoDoble;

nodoDoble *crearNodoE(int dato);
nodoDoble *agregarPrincipioE(nodoDoble *lista, nodoDoble* nn);
nodoDoble *agregarFinalE(nodoDoble* lista, nodoDoble *nn);
nodoDoble *agregarEnOrdenE(nodoDoble *lista, nodoDoble *nn);

#endif // LIBENLAZADAS_H_INCLUDED
