#include <stdio.h>
#include <stdlib.h>
//#include "pila.h"
#include "librerias.h"

int main()
{
    char seguir='s';

    int num;

    nodo *lista=iniclista();

    nodo *uno=crearNodo(1);
    lista=agregarPrincipio(lista, uno);
    nodo *dos=crearNodo(4);
    lista=agregarFinal(lista, dos);

    mostrarLista(lista);


    return 0;
}

///4.1
///ejercicio 1

void listaArchivo (char nombreArchivo[], nodo *lista)
{
    nodo *seg=lista;

    int ante;

    FILE *archivo=fopen(nombreArchivo, "rb");

    if(archivo!=NULL)
    {
        fclose(archivo);
    }
}

///ejercicio 2

///ejercicio 3

int buscarNodoS (nodo *lista, int dato)
{
    nodo *seg=lista;
    int flag=0;

    while (seg!=NULL && flag==0)
    {
        if(seg->dato==dato)
        {
            flag=1;
        }
        else
        {
            seg=seg->sig;
        }
    }

    return flag;
}

///ejercicio 4

nodo * intercalaListas (nodo *lista1, nodo *lista2)
{
    nodo *nuevaLista=NULL;

    nodo *seg1=lista1;
    nodo *seg2=lista2;

    while (seg2!=NULL && seg1!=NULL)
    {
        nuevaLista=agregarFinal(nuevaLista, seg1);
        nuevaLista=agregarFinal(nuevaLista, seg2);

        seg1=seg1->sig;
        seg2=seg2->sig;
    }

    return nuevaLista;
}
///ejercicio 6

nodo *invertirListas (nodo *lista)
{
    nodo *seg=lista;
    nodo *nuevaLista=iniclista();

    while (seg!=NULL)
    {
        nuevaLista=agregarFinal(nuevaLista, seg);
        seg=seg->sig;
    }

    return nuevaLista;
}

///ejercicio 7

nodo *pilaALista (Pila aux)
{
    nodo *lista= iniclista();

    while (!pilavacia(aux))
    {
        if (aux%2==0)
        {
            nodo *aux=crearNodo(aux);
            lista=agregarFinal(lista, aux);
        }
    }

    return lista;
}

nodo *eliminarMenores (nodo *lista)
{
    nodo *seg=lista;

    while (seg!=NULL)
    {
        if(seg->dato<10)
        {
            free(seg);
        }
        seg=seg->sig;
    }

    return lista;
}

///4.2
///4.3
///ejercicio 1
void mostrarListaInvertida (nodo *lista)
{
    nodo *seg=lista;

    if (seg!=NULL)
    {
        mostrarListaInvertida(seg->sig);
        printf ("%d", seg->dato);
    }
}

///ejercicio 2

int sumarListaR (nodo *lista)
{
    nodo *seg=lista;
    int suma;

    if(seg!=NULL)
    {
        suma=suma+seg->dato;
        sumarListaR(seg->sig);
    }

    return suma;
}

///ejercicio 3

void mostrarLugaresPares (nodo *lista)
{
    nodo *seg=lista;

    if (seg!=NULL)
    {
        seg=seg->sig;
        printf ("%d", seg->dato);
        mostrarLugaresPares(seg->sig);
    }
}

///ejercicio 4

int borrarNodoEspecificoR (int dato, nodo *lista)
{
    nodo *seg=lista;
    int flag=0;

    if (seg!=NULL && flag==0)
    {
        if (seg->dato==dato)
        {
            free(seg);
            flag=1;
        }
        else
        {
            borrarNodoEspecificoR(dato, seg->sig);
        }
    }

    return flag;
}

///ejercicio 5

nodo *insertarNodoOrdenadoR (nodo *lista, nodo *nn)
{
    nodo *seg=lista;

    if (seg!=NULL)
    {
        if (seg->dato > nn->dato)
        {
            lista=intersarNodoOrdenadoR(seg->sig, nn);
        }
        else
        {
            nn->sig=seg->sig;
            seg->sig=nn;
        }

    }
    else
    {
        lista=nn;
    }

    return lista;
}
/// ejercicio 6

nodo *invertirListaR (nodo *lista, nodo *ante)
{
    nodo *seg=lista;

    if(seg!=NULL)
    {
        invertirListaR(seg->sig, seg);
        seg->sig=seg;
    }

    return lista;
}
