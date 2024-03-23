#include "conjuntos.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//      ----------PROTOTIPOS----------
void cargar_conjunto(Conjunto conjunto);

bool Comparar_conjuntos(Conjunto Acomparar, Conjunto Base);
//
//
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
    bool pertenece;
    printf("\n\n\t\t-----SUBCONJUNTOS-----\n\n");
    // Trata a un conjunto vacio siempre como subconjunto de otro conjunto
    if (cto_cantidad_elementos(conjunto1) == 0 && cto_cantidad_elementos(conjunto2) == 0)
    {
        printf("Los conjuntos estan vacios");
        return 0;
    }
    printf("A subconjunto de B\n");
    pertenece = Comparar_conjuntos(conjunto1, conjunto2);

    printf("\nB subconjunto de A\n");
    pertenece = Comparar_conjuntos(conjunto2, conjunto1);

    printf("\n\n La complejidad algoritmica teniendo en cuenta la implementacion de listas seria O(n^2)\nCon la implementacion de avl seria O(n*log n) sin la implementacion seria de O(n)");
    // siempre teniendo en cuenta solo la fun cion que realiza el proceso
    // NO la funciones de carga de los conjuntos
    return 0;
}

//      ----------FUNCIONES----------
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

bool Comparar_conjuntos(Conjunto Acomparar, Conjunto Base)
{
    int cardinalidad = cto_cantidad_elementos(Acomparar);
    bool pertenece = true;
    int i = 1;
    while (cardinalidad >= i && pertenece == true)
    {
        TipoElemento te = te_crear(0);
        te = cto_recuperar(Acomparar, i);
        if (cto_cantidad_elementos(Base) > i)
        {

            pertenece = cto_pertenece(Base, te->clave);
            i++;
        }
        else
        {
            pertenece = false;
        }
    }

    if (pertenece)
    {
        cto_mostrar(Acomparar);
        printf("Es un subconjunto el conjunto\n");
        cto_mostrar(Base);
    }
    else
    {
        cto_mostrar(Acomparar);
        printf("NO es un subconjunto el conjunto\n");
        cto_mostrar(Base);
    }

    return pertenece;
}