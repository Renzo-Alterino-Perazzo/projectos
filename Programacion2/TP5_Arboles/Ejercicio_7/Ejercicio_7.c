#include "arbol-binario.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

void cargar_arbol(ArbolBinario A, NodoArbol N, int sa);

void insertar_nodo(ArbolBinario arbol, NodoArbol nodo, TipoElemento te);

void comparar_nodos(NodoArbol nodoArbol1, NodoArbol nodoArbol2, bool resultado, bool* algo);

bool arboles_equivalentes(ArbolBinario a1, ArbolBinario a2);

void cargar_arbol(ArbolBinario A, NodoArbol N, int sa)
{ // funcion para cargar los nodos al arbol
    char auxiliar[100];
    TipoElemento elem;
    NodoArbol nodo;
    int clave;
    if (a_es_lleno(A) == false)
    {
        printf("ingrese la clave o un . para NULL: ");
        fflush(stdin);
        fgets(auxiliar, 100, stdin);
        borrarEspacios(auxiliar);
        while (validacion_arboles(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999)
        {
            printf("Error. Reingrese la clave del nodo a cargar: ");
            fflush(stdin);
            fgets(auxiliar, 100, stdin);
            borrarEspacios(auxiliar);
        }
        if (auxiliar[0] == '.' && strlen(auxiliar) == 1)
        { // si es un . no hace nada
        }
        else
        { // sino carga el nodo al hijo correspondiente o a la raiz
            clave = atoi(auxiliar);
            elem = te_crear(clave);
            if (sa == -1)
            {
                nodo = a_conectar_hi(A, N, elem);
            }
            else if (sa == 1)
            {
                nodo = a_conectar_hd(A, N, elem);
            }
            else
            {
                nodo = a_establecer_raiz(A, elem);
            }
            cargar_arbol(A, nodo, -1);
            cargar_arbol(A, nodo, 1);
        }
    }
}

void insertar_nodo(ArbolBinario arbol, NodoArbol nodo, TipoElemento te)
{
    int elemento = te->clave;
    int clavenodo = nodo->datos->clave;
    if ((elemento) > (clavenodo))
    {
        if (nodo->hd == NULL)
        {
            a_conectar_hd(arbol, nodo, te);
        }
        else
        {
            insertar_nodo(arbol, nodo->hd, te);
        }
    }
    if (elemento < clavenodo)
    {
        if (nodo->hi == NULL)
        {
            a_conectar_hi(arbol, nodo, te);
        }
        else
        {
            insertar_nodo(arbol, nodo->hi, te);
        }
    }
    if (nodo->datos->clave == te->clave)
    {
        printf("ERROR NO SE PUEDEN INGRESAR DATOS REPETIDOS\n");
    }
}

void comparar_nodos(NodoArbol nodoArbol1, NodoArbol nodoArbol2, bool resultado, bool *algo)
{
    if (resultado == false)
    {

        if (n_recuperar(nodoArbol1)->clave == n_recuperar(nodoArbol2)->clave)
        {
            // nodo iz
            if (n_hijoizquierdo(nodoArbol1) != NULL && n_hijoizquierdo(nodoArbol2) != NULL)
            {

                comparar_nodos(n_hijoizquierdo(nodoArbol1), n_hijoizquierdo(nodoArbol2),resultado,algo);
            }
            if ((n_hijoizquierdo(nodoArbol1) != NULL && n_hijoizquierdo(nodoArbol2) == NULL) || (n_hijoizquierdo(nodoArbol1) == NULL && n_hijoizquierdo(nodoArbol2) != NULL))
            {
                resultado = true;
                *algo = resultado;
            }
            // nodo der
            if (n_hijoderecho(nodoArbol1) != NULL && n_hijoderecho(nodoArbol2) != NULL)
            {

                comparar_nodos(n_hijoderecho(nodoArbol1), n_hijoderecho(nodoArbol2),resultado,algo);
            }
            if ((n_hijoderecho(nodoArbol1) != NULL && n_hijoderecho(nodoArbol2) == NULL) || (n_hijoderecho(nodoArbol1) == NULL && n_hijoderecho(nodoArbol2) != NULL))
            {
                resultado = true;
                *algo = resultado;
            }
        }
        else
        {
            resultado = true;
            *algo = resultado;
        }
    }
}

bool arboles_equivalentes(ArbolBinario a1, ArbolBinario a2)
{
    bool resultado = false;
    bool algo = false;
    comparar_nodos(a_raiz(a1), a_raiz(a2), resultado, &algo);
    return algo;
}

int main()
{
    ArbolBinario arbol1, arbol2;
    arbol1 = a_crear();
    arbol2 = a_crear();
    NodoArbol nodo1;
    printf("\t--Primer arbol--\n");
    cargar_arbol(arbol1, nodo1, 0);
    printf("\t--Segundo arbol--\n");
    NodoArbol nodo2;
    cargar_arbol(arbol2, nodo2, 0);
    if (a_raiz(arbol1) == NULL && a_raiz(arbol2) == NULL)
    {
        printf("\n\t--Los arboles son equivalentes--\n");
        return 0;
    }
    if ((a_raiz(arbol1) == NULL && a_raiz(arbol2) != NULL) || (a_raiz(arbol1) != NULL && a_raiz(arbol2) == NULL))
    {
        printf("\n\t--Los arboles NO son equivalentes--\n");
        return 0;
    }
    bool respuesta = arboles_equivalentes(arbol1, arbol2);
    if (!respuesta)
    {
        printf("\n\t--Los arboles son equivalentes--\n");
    }
    else
    {
        printf("\n\t--Los arboles NO son equivalentes--\n");
    }
    return 0;
}
