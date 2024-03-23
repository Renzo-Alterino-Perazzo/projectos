#include "conjuntos.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

//      ----------PROTOTIPOS----------
void cargar_conjunto(Conjunto conjunto);

void Comparar_conjuntos(Conjunto Acomparar, Conjunto Base, Conjunto Base2);
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
    printf("\n!*Conjunto3*!\n");
    Conjunto conjunto3 = cto_crear();
    cargar_conjunto(conjunto3);
    printf("\n\t\t\t--CONJUNTO 1--\n");
    cto_mostrar(conjunto1);
    printf("\n\t\t\t--CONJUNTO 2--\n");
    cto_mostrar(conjunto2);
    printf("\n\t\t\t--CONJUNTO 3--\n");
    cto_mostrar(conjunto3);

    printf("\n\n\t\t-----SUBCONJUNTOS-----\n\n");
    // Trata a un conjunto vacio siempre como subconjunto de otro conjunto
    if (cto_cantidad_elementos(conjunto1) == 0 && cto_cantidad_elementos(conjunto2) == 0 && cto_cantidad_elementos(conjunto3) == 0)
    {
        printf("Los conjuntos estan vacios");
        return 0;
    }
    printf("A contra B y C\n");
    Comparar_conjuntos(conjunto1, conjunto2, conjunto3);

    printf("\nB contra A y C\n");
    Comparar_conjuntos(conjunto2, conjunto1, conjunto3);

    printf("\nC contra A y B\n");
    Comparar_conjuntos(conjunto3, conjunto2, conjunto1);
    printf("\n\n La complejidad algoritmica teniendo en cuenta la implementacion seria O(n^3)\nCon la implementacion de avl seria de O(n*log (n)*2) sin la implementacion seria de O(n)\n\n El programa consididera la mitad de un numero impar como el \nnumero natural menor mas cercano ");
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
void Comparar_conjuntos(Conjunto Acomparar, Conjunto Base, Conjunto Base2)
{
    int cardinalidad = cto_cantidad_elementos(Acomparar);
    int contador1 = 0;
    int contador2 = 0;

    bool pertenece;
    int i = 1;
    while (cardinalidad >= i)
    {
        TipoElemento te = te_crear(0);
        te = cto_recuperar(Acomparar, i);
        pertenece = cto_pertenece(Base, te->clave);
        if (pertenece)
        {
            contador1++;
        }

        pertenece = cto_pertenece(Base2, te->clave);
        if (pertenece)
        {
            contador2++;
        }

        i++;
    }

    if (contador1 == cto_cantidad_elementos(Acomparar))
    {
        cto_mostrar(Acomparar);
        printf("Es un subconjunto TOTAL del conjunto\n");
        cto_mostrar(Base);
    }
    else
    {
        if (contador1 >= (cto_cantidad_elementos(Acomparar) / 2))
        {

            cto_mostrar(Acomparar);
            printf("Es un subconjunto PARCIAL del conjunto\n");
            cto_mostrar(Base);
        }
        else
        {

            cto_mostrar(Acomparar);
            printf("NO es un subconjunto el conjunto\n");
            cto_mostrar(Base);
        }
    }

    printf("\n\n");

    if (contador2 == cto_cantidad_elementos(Acomparar))
    {
        cto_mostrar(Acomparar);
        printf("Es un subconjunto TOTAL del conjunto\n");
        cto_mostrar(Base2);
    }
    else
    {
        if (contador2 >= (cto_cantidad_elementos(Acomparar) / 2))
        {

            cto_mostrar(Acomparar);
            printf("Es un subconjunto PARCIAL del conjunto\n");
            cto_mostrar(Base2);
        }
        else
        {

            cto_mostrar(Acomparar);
            printf("NO es un subconjunto el conjunto\n");
            cto_mostrar(Base2);
        }
    }

    return;
}