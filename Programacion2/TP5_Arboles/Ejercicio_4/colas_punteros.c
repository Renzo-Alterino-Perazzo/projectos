#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"colas.h"
#include"nodo.h"

#define MAX 100

struct Nodo{
    TipoElemento dato;
    struct Nodo *siguiente;
};

struct ColaRep{
    struct Nodo *frente;
    struct Nodo *final;
};

int c_longitud(Cola cola);

Cola c_crear(void){
    Cola nueva_cola=(Cola)malloc(sizeof(struct ColaRep));
    nueva_cola->frente=NULL;
    nueva_cola->final=NULL;
    return nueva_cola;
}

bool c_es_vacia(Cola cola){
    return(c_longitud(cola)==0);
}

bool c_es_llena(Cola cola){
    return (c_longitud(cola)==MAX);
}

void c_encolar(Cola cola, TipoElemento elemento){
    if (c_es_llena(cola)){
        printf("Cola llena.\n");
        return;
    }
    struct Nodo *nuevo_nodo=malloc(sizeof(struct Nodo));
    nuevo_nodo->dato=elemento;
    nuevo_nodo->siguiente=NULL;
    if (c_es_vacia(cola)){
        cola->frente=nuevo_nodo;
    }
    else {
        cola->final->siguiente=nuevo_nodo;
    }
    cola->final=nuevo_nodo;
}

TipoElemento c_desencolar(Cola cola){
    TipoElemento elemento=NULL;
    if (c_es_vacia(cola)){
        printf("Cola vacia.\n");
        return elemento;
    }
    struct Nodo *nodo=cola->frente;
    elemento=nodo->dato;
    cola->frente=nodo->siguiente;
    free(nodo);
    return elemento;
}

TipoElemento c_recuperar (Cola cola){
    TipoElemento elemento=NULL;
    if (c_es_vacia(cola)){
        printf("Cola vacia.\n");
        return elemento;
    }
    elemento=cola->frente->dato;
    return elemento;
}

void c_mostrar(Cola cola){
    TipoElemento elemento=NULL;
    Cola colaAux=c_crear();
    if (c_es_vacia(cola)){
        printf("Cola vacia.\n");
        return;
    }
    printf("Contenido de la cola:\n");
    while (!c_es_vacia(cola)){
        elemento=c_desencolar(cola);
        printf("%d ", elemento->clave);
        c_encolar(colaAux, elemento);
    }
    while (!c_es_vacia(colaAux)){
        elemento=c_desencolar(colaAux);
        c_encolar(cola, elemento);
    }
    printf("\n");
}

int c_longitud(Cola cola){
    int contador=0;
    struct Nodo *nodo=cola->frente;
    while (nodo!=NULL){
        contador++;
        nodo=nodo->siguiente;
    }
    return contador;
}
