
#include "conjuntos.h"
#include "validaciones.h"
#include <stdio.h>

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

    return pertenece;
}
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

void subconjunto(Conjunto A, Conjunto B, Conjunto C)
{
    if (Comparar_conjuntos(A, B))
    {
        printf("El conjunto A: ");
        cto_mostrar(A);
        printf("Es un subconjunto del B: ");
        cto_mostrar(B);
        printf("\n\n");
    }
    else
    {
        printf("El conjunto A: ");
        cto_mostrar(A);
        printf("No es subconjunto del B");
        cto_mostrar(B);
        if (Comparar_conjuntos(A, C))
        {
            printf("Pero el conjunto A es un subconjunto de C pero no es un subconjunto de B\n");
        }
        else
        {
            printf("El conjunto A tampoco es un subconjunto de C\n");
        }
        return;
    }

    if (Comparar_conjuntos(B, C))
    {
        printf("El conjunto B: ");
        cto_mostrar(B);
        printf("Es un subconjunto del C\n");
        cto_mostrar(C);
        printf("Entonces el conjunto A: ");
        cto_mostrar(A);
        printf("Es un subconjunto del C, por propiedad de la transitividad\n");
    }
    else
    {
        printf("El conjunto B: ");
        cto_mostrar(B);
        printf("No es un subconjunto del C\n");
        if (Comparar_conjuntos(A, C))
        {
            printf("El conjunto A es un subconjunto de C pero no es un subconjunto de B\n");
        }
        else
        {
            printf("El conjunto A tampoco es un subconjunto de C");
        }
    }
}
int main()
{
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    Conjunto C = cto_crear();
    printf("Cargar conjuntos\n");
    printf("Cargar conjunto A: \n");
    cargar_conjunto(A);
    printf("\n\n");
    printf("Cargar conjunto B: ");
    cargar_conjunto(B);
    printf("\n\n");
    printf("Cargar conjunto C: ");
    cargar_conjunto(C);
    printf("Mostrando conjuntos\n\n");
    printf("Conjunto A\n");
    cto_mostrar(A);
    printf("Conjunto B\n");
    cto_mostrar(B);
    printf("Conjunto C\n");
    cto_mostrar(C);
    subconjunto(A, B, C);
    return 0;
}