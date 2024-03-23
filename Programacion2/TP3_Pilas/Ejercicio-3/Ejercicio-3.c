#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include <stdbool.h>
#include "validaciones.h"
void crear_pila(Pila pila)
{

    printf("Crea una pila con claves ENTERAS (no mayor a 50 elementos)\n\n");

    char clave[20];
    char respuesta[100];

    TipoElemento elemento = te_crear(0);
    bool seguir = true;
    bool val = true;
    int contador = 0;

    printf("Cuantos valores desea ingresar: ");
    fflush(stdin);
    fgets(respuesta, 100, stdin);
    val = validacion_enterosNegativos(respuesta);
    fflush(stdin);

    while (val == false || atoi(respuesta) < 0 || atoi(respuesta) > 50)
    {
        fflush(stdin);
        system("cls");
        printf("Valor invalido\n\n");
        printf("Cuantos valores desea ingresar: ");
        fgets(respuesta, 100, stdin);
        printf("\n");

        val = validacion_enterosNegativos(respuesta);
    }

    while (contador < atoi(respuesta))
    {

        printf("Ingresar clave para el valor que deseas agregar\n");
        printf("\n\tLas claves debe ser un numero ENTERO\n\n");
        fflush(stdin);
        fgets(clave, 20, stdin);
        val = validacion_enterosNegativos(clave);
        if (clave[0] == '\n')
        {
            val = false;
        }
        while (val == false)
        {
            fflush(stdin);
            system("cls");
            printf("Valor incorrecto\n");
            printf("Ingresar clave para el valor que deseas agregar\n");
            printf("\n\tLas claves debe ser un numero ENTERO\n");
            fgets(clave, 20, stdin);
            val = validacion_enterosNegativos(clave);
            if (clave[0] == '\n')
            {
                val = false;
            }
        }
        elemento = te_crear(atoi(clave));
        contador++;
        p_apilar(pila, elemento);
        system("cls");
        printf("Agregado correctamente\n");
        p_mostrar(pila);
    }
}

bool pilas_iguales(Pila pila1, Pila pila2)
{
    Pila aux = p_crear();
    TipoElemento elementoP1 = te_crear(10000), elementoP2 = te_crear(-10000);
    bool iguales = true;

    if (p_es_vacia(pila1) != true && p_es_vacia(pila2) != true)
    {
        elementoP1 = p_desapilar(pila1);
        elementoP2 = p_desapilar(pila2);

        while ((p_es_vacia(pila1) != true || p_es_vacia(pila2) != true) && elementoP1->clave == elementoP2->clave)
        {
            p_apilar(aux, elementoP1);
            p_apilar(aux, elementoP2);
            elementoP1 = p_desapilar(pila1);
            elementoP2 = p_desapilar(pila2);
        }
        if (elementoP1->clave != elementoP2->clave)
        {
            iguales = false;
        }
    }
    else
    {
        if (p_es_vacia(pila1) == true && p_es_vacia(pila2) == true)
        {
            return iguales;
        }
        else
        {
            iguales = false;
            return iguales;
        }
    }

    if (!p_es_vacia(pila1) && p_es_vacia(pila2))
    {
        p_apilar(pila2, elementoP2);
    }

    if (!p_es_vacia(pila2) && p_es_vacia(pila1))
    {
        p_apilar(pila1, elementoP1);
    }
    if (elementoP2->clave != elementoP1->clave)
    {
        p_apilar(pila1, elementoP1);
        p_apilar(pila2, elementoP2);
    }
    if (elementoP1->clave == elementoP2->clave)
    {
        p_apilar(pila1, elementoP1);
        p_apilar(pila2, elementoP2);
    }

    while (p_es_vacia(aux) != true)
    {
        elementoP1 = p_desapilar(aux);
        elementoP2 = p_desapilar(aux);
        p_apilar(pila1, elementoP1);
        p_apilar(pila2, elementoP2);
    }
    return iguales;
}

int main()
{
    printf("\n\t--COMPARADOR DE PILAS--\n\n");
    bool iguales;
    Pila p1, p2;
    printf("Cree la PILA 1: \n\n");
    p2 = p_crear();
    p1 = p_crear();
    crear_pila(p1);
    printf("Cree la PILA 2: \n\n");
    crear_pila(p2);
    iguales = pilas_iguales(p1, p2);
    system("cls");
    if (iguales == true)
    {
        printf("Las pilas son IGUALES\n\n");
    }
    else
    {
        printf("Las pilas son DISTINTAS\n\n");
    }
    printf("Estado de las pilas:\nPILA 1: ");
    p_mostrar(p1);
    printf("PILA 2: ");
    p_mostrar(p2);

    printf("\nla complejidad del algoritmo en la notacion Big O es de :\n\t --- O(n) ---");
    return 0;
}
