#include "conjuntos.h"
#include "validaciones.h"
#include <stdio.h>
void cargar_conjunto(Conjunto conjunto)
{
    char auxiliar[100];
    int clave;
    char cardinalix[100];
    int cardinalidad;
    printf("Ingrese la Cardinalidad de los conjuntos: ");
    fflush(stdin);
    fgets(cardinalix, 100, stdin);
    borrarEspacios(cardinalix);
    while ((validacion(cardinalix) == false) || (atoi(cardinalix) < 0) || (atoi(cardinalix) > 100))
    {
        printf("\nError. Reingrese la Cardinalidad de los conjuntos : ");
        fflush(stdin);
        fgets(cardinalix, 100, stdin);
        borrarEspacios(cardinalix);
    }
    cardinalidad = atoi(cardinalix);

    for (int i = 1; i <= cardinalidad; i++)
    {
        printf("\nIngrese el elemento n %d del conjunto: ", i);
        fflush(stdin);
        fgets(auxiliar, 100, stdin);
        borrarEspacios(auxiliar);
        while ((validacion(auxiliar) == false) || (cto_pertenece(conjunto, atoi(auxiliar)) == true) || (atoi(auxiliar) < 1) || (atoi(auxiliar) > 99999999))
        {
            if (validacion(auxiliar) == false || (atoi(auxiliar) < 1) || (atoi(auxiliar) > 99999999))
            {
                printf("Error. Reingrese la clave del conjunto : ");
                fflush(stdin);
                fgets(auxiliar, 100, stdin);
                borrarEspacios(auxiliar);
            }
            else
            {
                printf("Error. La clave ingresada ya pertenece al conjunto, Reingrese la clave : ");
                fflush(stdin);
                fgets(auxiliar, 100, stdin);
                borrarEspacios(auxiliar);
            }
        }
        clave = atoi(auxiliar);
        TipoElemento elem = te_crear(clave);
        cto_agregar(conjunto, elem);
    }
}

Conjunto diferenciaSimetrica(Conjunto conjunto1, Conjunto conjunto2)
{
    Conjunto conjuntoResultado = cto_crear();
    int cantidadElementos1 = cto_cantidad_elementos(conjunto1);
    int cantidadElementos2 = cto_cantidad_elementos(conjunto2);
    TipoElemento elemento;
    for (int i = 1; i < cantidadElementos1 + 1; i++)
    {
        elemento = cto_recuperar(conjunto1, i);
        for (int j = 1; j < cantidadElementos2 + 1; j++)
        {
            if (!cto_pertenece(conjunto2, elemento->clave))
            {
                cto_agregar(conjuntoResultado, elemento);
            }
        }
    }
    for (int i = 1; i < cantidadElementos2 + 1; i++)
    {
        elemento = cto_recuperar(conjunto2, i);
        for (int j = 1; j < cantidadElementos1; j++)
        {
            if (!cto_pertenece(conjunto1, elemento->clave))
            {
                cto_agregar(conjuntoResultado, elemento);
            }
        }
    }
    return conjuntoResultado;
}

int main()
{
    printf("\t\t-----CARGA DE CONJUNTOS-----\n\n");
    printf("!*Conjunto1*!\n");
    Conjunto conjunto1 = cto_crear();
    cargar_conjunto(conjunto1);
    printf("\n!*Conjunto2*!\n");
    Conjunto conjunto2 = cto_crear();
    cargar_conjunto(conjunto2);
    printf("\n\t\t\t--CONJUNTO 1--\n");
    cto_mostrar(conjunto1);
    printf("\n\t\t\t--CONJUNTO 2--\n");
    cto_mostrar(conjunto2);
    printf("\t\t-----Diferencia simetrica-----\n\n");
    cto_mostrar(diferenciaSimetrica(conjunto1, conjunto2));
}