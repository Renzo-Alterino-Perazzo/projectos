#include "nodo.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

NodoArbol n_hijoizquierdo(NodoArbol N){
    if (N == NULL){
        return NULL;
    } else return N->hi;
}

NodoArbol n_hijoderecho(NodoArbol N){
    if (N == NULL){
        return NULL;
    } else return N->hd;
}

NodoArbol n_crear(TipoElemento te){
    NodoArbol nuevo_nodo = (NodoArbol) malloc(sizeof(struct NodoArbolRep));
    nuevo_nodo->datos = te;
    nuevo_nodo->hd = NULL;
    nuevo_nodo->hi = NULL;
    nuevo_nodo->FE = 0;
    return nuevo_nodo;
}

TipoElemento n_recuperar(NodoArbol N){
    if (N == NULL){
        return NULL;
    } else return N->datos;
}
