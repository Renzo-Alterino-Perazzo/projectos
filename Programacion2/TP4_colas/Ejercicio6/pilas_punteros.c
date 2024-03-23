#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include <stdbool.h>

#define MAX 100

struct Nodo
{
    TipoElemento datos; // Concepto del Nodo
    struct Nodo *siguiente;
};

struct PilaRep
{
    struct Nodo *tope;
};

Pila p_crear()
{
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    return nueva_pila;
}

void p_apilar(Pila pila, TipoElemento elemento)
{
    if (p_es_llena(pila)){
        printf("Pila llena.\n");
        return; 
    }
    struct Nodo *nuevo_nodo = malloc(sizeof(struct Nodo));
    nuevo_nodo->datos = elemento;
    nuevo_nodo->siguiente = pila->tope;
    pila->tope = nuevo_nodo;
}

TipoElemento p_desapilar(Pila pila)
{
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    free(tope_actual);
    return elemento;
}

TipoElemento p_tope(Pila pila)
{
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}

bool p_es_vacia(Pila pila)
{
    return pila->tope == NULL;
}

void p_mostrar(Pila pila)
{
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);
    printf("Contenido de la pila: \n");
    // Recorro la pila desopilándola y pasándola al auxiliar
    while (p_es_vacia(pila) != true)
    {
        X = p_desapilar(pila);
        printf("%d ", X->clave);
        p_apilar(Paux, X);
    }
    // Recorro la pila auxiliar para pasarla a la original (o bien construyo la utilidad intercambiar)
    while (p_es_vacia(Paux) != true)
    {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }
    printf("\n");
}

int p_longitud(Pila pila){
    Pila paux=p_crear();
    int contador=0;
    TipoElemento t1=te_crear(0);
    while (!p_es_vacia(pila)){
        t1=p_desapilar(pila);
        p_apilar(paux, t1);
        contador++;
    }
    while (!p_es_vacia(paux)){
        t1=p_desapilar(paux);
        p_apilar(pila, t1);
    }

    return contador; 
}

bool p_es_llena(Pila pila){
    return MAX==p_longitud(pila);
}
