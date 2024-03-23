#include "arbol-binario.h"
#include "validaciones.h"
#include "listas.h"
#include "colas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//          -------------Prototipos-------------
// Valida el ingreso de numeros
int ingresar_valor();

// Retorna una lista que contiene las claves de del recorrido por anchura
Lista recorrido_por_anchura(ArbolBinario arbol);

// Recorrido recursivo del arbol
void recorridoPorAnchura(NodoArbol nodo, Cola col, Lista li);

// Retorna el el padre de un nodo (se busca por la clave), si no se encontro el padre retorna -1
TipoElemento padre_del_elemento(ArbolBinario arbol, int clave);

// Funcion recursiva para buscar el elemento
void padreDelElemento(NodoArbol prev, NodoArbol nodo, TipoElemento *te, int clave);

// Compara si los arboles tienen la misma estructura
bool arboles_similares(ArbolBinario arbol1, ArbolBinario arbol2);

// Funcion recursiva que comprar la estructura de los arboles
void comparacion(NodoArbol a1, NodoArbol a2, bool *similares);

// Carga el arbol validando los datos y colocando el NULL con un punto " . "
void cargar_arbol(ArbolBinario A, NodoArbol N, int sa);

// Coloca los hermanos del nodo buscado, en el arbol indicado, en una lista y la retorna
// En el caso de ingresar un arbol vacio, o que solo tenga
// la raiz, retornara una lista vacia
Lista Hermanos_de(ArbolBinario arbol, int clave);

// Funcion recursiva que busca los hermanos de un nodo
void hermanosDE(NodoArbol prov, NodoArbol act, Lista list, int clave, bool encontrado);

// Mascara de funcion recursiva para buscar las hojas, retorna la cantidad de hojas que hay en un arbol
// N-ario, si se llama a un arbol vacio retornara -1
int Cantidad_de_hojas(ArbolBinario arbol);

// Funcion recursiva que busca las hojas
void BuscarHojas(NodoArbol act, int *contador);

int main()
{
    printf("\t\t----Ejercicio 4----\n\n");
    ArbolBinario arbol = a_crear();
    printf("\t Ingrese un arbol\n");
    NodoArbol nodo1;
    cargar_arbol(arbol, nodo1, 0);
    if (!a_es_vacio(arbol))
    {
        printf("\n\t---Recorrido por anchura---\n");
        printf("\nEl resultado del recorrido por anchura es: \n");
        Lista Recorrido = l_crear();
        Recorrido = recorrido_por_anchura(arbol);
        l_mostrarLista(Recorrido);

        printf("\n\n\t---Cantidad de hojas---\n\n");
        int cantidad = Cantidad_de_hojas(arbol);

        printf("La cantidad de hojas de su arbol es: %i", cantidad);

        printf("\n\t---Buscar el padre de un elemento---\n");

        TipoElemento te = te_crear(0);
        int elemento = ingresar_valor();
        te = padre_del_elemento(arbol, elemento);
        if (te->clave != elemento && te->clave != -9999999)
        {
            printf("El padre del elemento buscado es: %i\n", te->clave);
        }
        else
        {
            printf("\tAh ocurrido un error\n Esto puede deberse a :\n\t1- se busca el padre de una raiz\n\t2- se busca el padre de un elemento que no existe en el arbol\n");
        }

        printf("\n\t---Hermanos de un nodo---\n");
        Lista hermanos = l_crear();
        hermanos = Hermanos_de(arbol, ingresar_valor());
        if (l_es_vacia(hermanos))
        {
            printf("No se encontro el nodo o este no tiene hermanos");
        }
        else
        {
            printf("Los hermanos del nodo buscado son: \n");
            l_mostrarLista(hermanos);
        }

        printf("\n\n\t---Similitud con otro arbol---\n\n");
        ArbolBinario arbol2 = a_crear();
        NodoArbol nodo2;
        cargar_arbol(arbol2, nodo2, 0);
        if (arboles_similares(arbol, arbol2))
        {
            printf("\n\nLos arboles son similares");
        }
        else
        {
            printf("\n\nLos arboles NO son similares");
        }
    }
    else
    {
        printf("El arbol que ingreso esta vacio");
    }
    return 0;
}

//          -------------Funciones-------------
int ingresar_valor()
{
    printf("\nIngrese una clave con la que desea: ");
    char auxiliar[100];
    fflush(stdin);
    fgets(auxiliar, 100, stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999)
    {
        printf("Error. Reingrese la clave a buscar: ");
        fflush(stdin);
        fgets(auxiliar, 100, stdin);
        borrarEspacios(auxiliar);
    }
    return atoi(auxiliar);
}

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
TipoElemento padre_del_elemento(ArbolBinario arbol, int clave)
{
    TipoElemento te = te_crear(-9999999);
    if (a_es_vacio(arbol))
    {
        printf("El arbol esta vacio");
        return te;
    }
    else
    {

        padreDelElemento(a_raiz(arbol), a_raiz(arbol), &te, clave);
        return te;
    }
}

void padreDelElemento(NodoArbol prev, NodoArbol nodo, TipoElemento *te, int clave)
{
    if (n_recuperar(nodo)->clave != clave)
    {
        if (n_hijoderecho(nodo) != NULL)
        {
            padreDelElemento(prev, n_hijoderecho(nodo), te, clave);
        }
        if (n_hijoizquierdo(nodo) != NULL)
        {
            padreDelElemento(nodo, n_hijoizquierdo(nodo), te, clave);
        }
    }
    else
    {
        *te = n_recuperar(prev);
    }
}

Lista recorrido_por_anchura(ArbolBinario arbol)
{
    Lista lista = l_crear();
    Cola cola = c_crear();
    if (a_es_vacio(arbol))
    {
        printf("El arbol esta vacio");
        return lista;
    }
    else
    {

        recorridoPorAnchura(a_raiz(arbol), cola, lista);
        return lista;
    }
}

void recorridoPorAnchura(NodoArbol nodo, Cola col, Lista li)
{

    if (n_hijoizquierdo(nodo) != NULL)
    {
        TipoElemento nodoCola = te_crear_con_valor(n_recuperar(nodo)->clave, (NodoArbol)nodo);
        c_encolar(col, nodoCola);
    }
    if (n_hijoderecho(nodo) != NULL)
    {
        l_agregar(li, n_recuperar(nodo));
        recorridoPorAnchura(n_hijoderecho(nodo), col, li);
    }
    if (n_hijoderecho(nodo) == NULL)
    {
        l_agregar(li, n_recuperar(nodo));
        if (!c_es_vacia(col))
        {

            TipoElemento nodoCola = c_desencolar(col);
            recorridoPorAnchura(n_hijoizquierdo(nodoCola->valor), col, li);
        }
    }
}

bool arboles_similares(ArbolBinario arbol1, ArbolBinario arbol2)
{

    if ((a_es_vacio(arbol1) && !(a_es_vacio(arbol2))) || (!(a_es_vacio(arbol1)) && a_es_vacio(arbol2)))
    {
        printf("Un arbol esta vacio y el otro no");
        return false;
    }
    else
    {

        if ((a_raiz(arbol1) != NULL && a_raiz(arbol2) == NULL) || (a_raiz(arbol1) == NULL && a_raiz(arbol2) != NULL))
        {
            return false;
        }
        else
        {

            if (a_cantidad_elementos(arbol1) != a_cantidad_elementos(arbol2))
            {
                return false;
            }
            else
            {
                bool similares = true;
                comparacion(a_raiz(arbol1), a_raiz(arbol2), &similares);
                return similares;
            }
        }
    }
}

void comparacion(NodoArbol a1, NodoArbol a2, bool *similares)
{
    bool dif = *similares;
    if (dif == true)
    {

        // nodo iz
        if (n_hijoizquierdo(a1) != NULL && n_hijoizquierdo(a2) != NULL)
        {

            comparacion(n_hijoizquierdo(a1), n_hijoizquierdo(a2), similares);
        }
        if ((n_hijoizquierdo(a1) != NULL && n_hijoizquierdo(a2) == NULL) || (n_hijoizquierdo(a1) == NULL && n_hijoizquierdo(a2) != NULL))
        {
            *similares = false;
        }
        // nodo der
        if (n_hijoderecho(a1) != NULL && n_hijoderecho(a2) != NULL)
        {

            comparacion(n_hijoderecho(a1), n_hijoderecho(a2), similares);
        }
        if ((n_hijoderecho(a1) != NULL && n_hijoderecho(a2) == NULL) || (n_hijoderecho(a1) == NULL && n_hijoderecho(a2) != NULL))
        {
            *similares = false;
        }
    }
}

int Cantidad_de_hojas(ArbolBinario arbol)
{

    if (a_es_vacio(arbol))
    {
        printf("El arbol esta vacio\n");
        return -1;
    }
    else
    {
        int contador = 0;
        BuscarHojas(a_raiz(arbol), &contador);
        return contador;
    }
}

void BuscarHojas(NodoArbol act, int *contador)
{
    if (n_hijoizquierdo(act) != NULL)
    {
        BuscarHojas(n_hijoizquierdo(act), contador);
    }
    else
    {
        *contador = *contador + 1;
    }
    if (n_hijoderecho(act) != NULL)
    {
        BuscarHojas(n_hijoderecho(act), contador);
    }
}

Lista Hermanos_de(ArbolBinario arbol, int clave)
{
    Lista list = l_crear();
    if (a_es_vacio(arbol))
    {
        printf("El arbol esta vacio\n");

        return list;
    }
    else
    {

        NodoArbol raiz = a_raiz(arbol);

        bool encontrado = false;
        hermanosDE(raiz, raiz, list, clave, encontrado);

        return list;
    }
}

void hermanosDE(NodoArbol prov, NodoArbol act, Lista list, int clave, bool encontrado)
{
    if (encontrado == true)
    {
        if (n_recuperar(act)->clave != clave)
        {
            l_agregar(list, n_recuperar(act));
            if (act->hd != NULL)
            {
                hermanosDE(prov, n_hijoderecho(act), list, clave, encontrado);
            }
        }
        else
        {
            if (act->hd != NULL)
            {
                hermanosDE(prov, n_hijoderecho(act), list, clave, encontrado);
            }
        }
    }
    else
    {
        if (n_recuperar(act)->clave != clave)
        {
            if (act->hi != NULL)
            {
                hermanosDE(act, n_hijoizquierdo(act), list, clave, encontrado);
            }
            if (act->hd != NULL)
            {
                hermanosDE(prov, n_hijoderecho(act), list, clave, encontrado);
            }
        }
        else
        {
            encontrado = true;
            if (prov == act)
            {
                hermanosDE(prov, prov, list, clave, encontrado);
            }
            else
            {

                hermanosDE(prov, n_hijoizquierdo(prov), list, clave, encontrado);
            }
        }
    }
}
