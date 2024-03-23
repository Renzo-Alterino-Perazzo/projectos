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

int longitud(Pila pila);

Pila p_crear()
{
    Pila nueva_pila = (Pila)malloc(sizeof(struct PilaRep));
    nueva_pila->tope = NULL;
    return nueva_pila;
}

void p_apilar(Pila pila, TipoElemento elemento)
{
    if (p_es_llena(pila) == true){
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
    if (p_es_vacia(pila) == true){
        return NULL;
    }
    struct Nodo *tope_actual = pila->tope;
    TipoElemento elemento = tope_actual->datos;
    pila->tope = tope_actual->siguiente;
    free(tope_actual);
    return elemento;
}

TipoElemento p_tope(Pila pila)
{
    if (p_es_vacia(pila) == true){
        return NULL;
    }
    struct Nodo *tope_actual = pila->tope;
    return tope_actual->datos;
}

bool p_es_vacia(Pila pila)
{
    return pila->tope == NULL;
}

void p_mostrar(Pila pila)
{
    if (p_es_vacia(pila) == true){
        printf("La Pila esta vacia\n");
        return;
    }
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);
    printf("Contenido de la pila: ");
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

int longitud(Pila pila){
    int contador = 0;
    struct Nodo *N = pila->tope;
    while (N != NULL){
        contador++;
        N = N->siguiente;
    }
    return contador;
}

bool p_es_llena(Pila pila){
    return (longitud(pila) == MAX);
}

