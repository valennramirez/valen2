#include <stdio.h>
#include <stdlib.h>
#include "libEnlazadas.h"

///LISTAS
nodo *iniclista()
{
    return NULL;
}

nodo *crearNodo(char nombre[50], int legajo, int nota)
{
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    strcpy(aux->miAlumno.nombre, nombre);
    aux->miAlumno.legajo=legajo;
    aux->miAlumno.nota= nota;

    return aux;
}

nodo *agregarPrincipio (nodo *lista, nodo *nn)
{
    if (lista==NULL)
    {
        lista=nn;
    }
    else
    {
        nn->sig=lista;
        lista=nn;
    }

    return lista;
}

nodo *agregarEnOrden (nodo *lista, nodo *nn)
{
    if(lista==NULL)
    {
        lista=nn;
    }
    else if(lista->miAlumno.legajo > nn->miAlumno.legajo)
    {
        lista=agregarPrincipio(lista, nn);
    }
    else
    {
        nodo *seg=lista;
        nodo *ante=lista;

        while ((seg!=NULL) && (seg->miAlumno.legajo < nn->miAlumno.legajo))
        {
            ante=seg; seg=seg->sig;
            ante->sig=nn; nn->sig=seg;
        }
    }
    return lista;
}
nodo *agregarFinal (nodo *lista, nodo *nn)
{
    nodo *seg=lista;
    while(seg!=NULL)
    {
        if (seg->sig==NULL)
        {
            seg->sig=nn;
        }
        seg=seg->sig;
    }
    return lista;
}
nodo *borrarNodo (nodo *lista, int nota)
{
    if(lista!=NULL)
    {
        nodo *aBorrar;
        if(lista->miAlumno.nota==nota) //eliminar principio
        {
            aBorrar=lista;
            lista=lista->sig;
            free(aBorrar);
        }
        else //elimina los del medio
        {
            nodo *seg=lista;
            nodo *ante=seg;

            while ((seg!=NULL) &&(seg->miAlumno.nota!=nota))
            {
                ante=seg;
                seg=seg->sig;
            }

            if(seg!=NULL)
            {
                ante->sig=seg->sig;
                free(seg);
            }
        }
    }
    return lista;
}

void borrarlista (nodo *lista)
{
    nodo *seg=lista;
    nodo *aBorrar;

    while (seg!=NULL)
    {
        aBorrar=seg;
        seg=seg->sig;
        free(aBorrar);
    }


}
nodo *buscarUltimo (nodo *lista)
{
    nodo *seg=lista;
    while (seg->sig!=NULL)
    {
        seg=seg->sig;
    }
    return seg;
}
int buscarNodo (int dato, nodo *lista)
{
    int flag=0; nodo *seg=lista;
    while (seg!=NULL && flag==0)
    {
        seg=seg->sig;
        if (dato==seg->miAlumno.nota)
        {
            flag=1;
        }
    }
    return flag;
}
void mostrarNodo (nodo *aux)
{
    printf ("\nNombre: %s", aux->miAlumno.nombre);
    printf ("\nLegajo: %i", aux->miAlumno.legajo);
    printf ("\nNota: %i", aux->miAlumno.nota);
}
void mostrarLista (nodo *lista)
{
    nodo *seg=lista;
    while (seg!=NULL)
    {
        mostrarNodo(seg);
        seg=seg->sig;
    }
}

///LISTAS ENLAZADAS
nodoDoble *iniclistaEnlazada () //??
{
    return NULL;
}
nodoDoble *crearNodoDoble (int dato)
{
    nodoDoble *aux= (nodoDoble*)malloc(sizeof(nodoDoble));
    aux->dato=dato;

    return aux;
}

nodoDoble *agregarPrincipioE (nodoDoble *lista, nodoDoble *nn)
{
    nn->sig=lista;

    if (lista!=NULL)
    {
        lista->ante=nn;
    }

    return lista;
}

nodoDoble *agregarFinalE (nodoDoble *lista, nodoDoble *nn)
{
    nodoDoble *ultimo=NULL;

    if (lista==NULL)
    {
        lista=nn;
    }
    else
    {
        ultimo=buscarUltimo(lista);
        nn->ante=ultimo;
        ultimo->sig=nn;
    }

    return lista;
}

nodoDoble *agregarEnOrdenE (nodoDoble *lista, nodoDoble *nn)
{
    if (lista==NULL)
    {
        lista=nn;
    }
    else if (lista->dato>nn->dato)
    {
        lista=agregarPrincipioE(lista, nn);
    }
}
