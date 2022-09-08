#include <stdio.h>
#include <stdlib.h>
#include "librerias.h"

nodo *iniclista()
{
    return NULL;
}

nodo *crearNodo(int datox)
{
    nodo *aux=(nodo*)malloc(sizeof(nodo));
    aux->dato=datox;

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
    else if(lista->dato > nn->dato)
    {
        lista=agregarPrincipio(lista, nn);
    }
    else
    {
        nodo *seg=lista;
        nodo *ante=lista;

        while ((seg!=NULL) && (seg->dato < nn->dato))
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
        if(lista->dato==nota) //eliminar principio
        {
            aBorrar=lista;
            lista=lista->sig;
            free(aBorrar);
        }
        else //elimina los del medio
        {
            nodo *seg=lista;
            nodo *ante=seg;

            while ((seg!=NULL) &&(seg->dato!=nota))
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
        if (dato==seg->dato)
        {
            flag=1;
        }
    }
    return flag;
}
void mostrarNodo (nodo *aux)
{
    printf ("%d-", aux->dato);
}
void mostrarLista (nodo *lista)
{
    nodo *seg=lista;
    if (seg!=NULL)
    {
        mostrarNodo(seg);
        seg=seg->sig;
    }
}
