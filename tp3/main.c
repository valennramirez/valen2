#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num=0, rta=0;

    int arreglo[5]={8,3,7,9,5};

    int ejercicio;

    printf ("Cual?");
    scanf ("%i", &ejercicio);

    switch (ejercicio)
    {
    case 1: //calcular factorial
        {
            printf ("Ingrese un numero para calcular su factorial");
            scanf("%i", &num);

            rta=calcularFactorialR(num);

            printf ("El resultado es: %i", rta);
        }break;
    case 2: //calcular la potencia de u numero
        {
            int exponente=0;

            printf ("Ingrese un numero para calcular su potencia");
            scanf ("%i", &num);

            printf ("Ingrese el exponente");
            scanf ("%i", &exponente);

            rta=calcularPotenciaR(num, exponente);

            printf ("El resultado de %i elevado a %i es: %i", num, exponente, rta);
        }break;
    case 3: //mostrar arreglo
        {
            mostrarArregloR (arreglo, 5, 0);
        }
    case 4: //mostrar arreglo invertido
        {
            mostrarArregloInvertidoR (arreglo, 5, 0);
        }
    case 5: //determinar si un arreglo es capicua
        {
            ///hacer
        }
    case 6: //sumar todos los elementos de un arreglo
        {
            mostrarArregloR(arreglo, 5, 0);

            rta= sumarArregloR (arreglo, 5, 0);

            printf ("\La suma de todos los elementos del arreglo es: %i", rta);
        }break;
    case 7:
        {
            rta=buscarElementoMenorR(arreglo, 5, 0);

            printf ("\el menor es: %i", rta);
        }
    case 8:
        {
            ///hacer
        }
    case 9:
        {
            ///hacer
        }
    case 10:
        {
            ///hacer
        }
    case 11:
        {
            mostrarCharInversoR("s");
        }break;
    case 12:
        {
            rta=buscarElementoR(arreglo, 5, 0, 1);

            if (rta==1)
            {
                printf ("\El elemento se encuentra en el arreglo");
            }
            else
            {
                printf ("\El elemento no se encuentra en el arreglo");
            }

        }break;
    }

    return 0;
}

///1- calcular el factorial de un numero

int calcularFactorialR (int num)
{
    int rta=0;

    if (num==0)
    {
        rta=1;
    }
    else
    {
        rta=num*calcularFactorialR(num-1);
    }

    return rta;
}

///2- calcular la potencia de un numero

int calcularPotenciaR (int num, int exponente)
{
    int rta=0;

    if (exponente==0)
    {
        rta=1;
    }
    else
    {
        rta=num* calcularPotenciaR (num, exponente-1);
    }

    return rta;
}

///3- mostrar un arreglo

void mostrarArregloR (int arreglo[], int validos, int pos)
{
    if (pos==validos)
    {
        printf ("Fin del arreglo");
    }
    else
    {
        printf ("%d", arreglo[pos]);
        mostrarArregloR (arreglo, validos, pos+1);
    }
}

///4- mostrar un arreglo comenzando con la posicion 0, pero de manera invertida
void mostrarArregloInvertidoR (int arreglo[], int validos, int pos)
{
    if (pos==validos)
    {
        printf ("Fin del arreglo");
    }
    else
    {
        mostrarArregloR (arreglo, validos, pos+1);
        printf ("%d", arreglo[pos]);
    }
}

///5- determinar si un arreglo es capicua

///6- sumar los elementos de un arreglo

int sumarArregloR (int arreglo[], int validos, int pos)
{
    int suma=0;

    if (pos<validos)
    {
        suma=arreglo[pos]+sumarArregloR(arreglo, validos, pos+1);
    }

    return suma;
}

///7- buscar el elemento menor de un arreglo

int buscarElementoMenorR (int arreglo[], int validos, int pos)
{
    int rta=0;

    if (pos<validos)
    {
         if(arreglo[pos+1]>arreglo[pos])
         {
             rta=arreglo[pos];
         }
         else
         {
             rta=buscarElementoMenorR(arreglo, validos, pos+1);
         }
    }

    return rta;
}

///8- buscar el menor elemento de un archivo

///9- archivos

///10- archivos

///11- ingresar valores de variable char y mostrarlos en orden inverso (sin arreglo)

void mostrarCharInversoR (char letra)
{
    char seguir;

    printf ("Ingrese una letra: ");
    fflush(stdin);
    scanf("%c", &letra);

    printf ("Desea continuar?s/n: ");
    fflush(stdin);
    scanf("%c", &seguir);


    if (seguir=='s')
    {
        mostrarCharInversoR(seguir);
        printf ("\n%c", letra);
    }
    else
    {
        printf ("\n%c", letra);
    }
}

///12- determinar si un arreglo tiene determinado elemento

int buscarElementoR (int arreglo[], int validos, int pos, int dato)
{
    int rta=0;

    if (pos<validos)
    {
        if (arreglo[pos]==dato)
        {
            rta=1;
        }
        else
        {
            rta=buscarElementoR(arreglo, validos, pos+1, dato);
        }
    }

    return rta;
}
