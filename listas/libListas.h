#ifndef LIBLISTAS_H_INCLUDED
#define LIBLISTAS_H_INCLUDED

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

#endif // LIBLISTAS_H_INCLUDED
