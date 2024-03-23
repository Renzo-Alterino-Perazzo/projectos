#include "colas.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

static const int TAMANIO_MAXIMO = 100;

struct ColaRep{
    TipoElemento *valores;
    unsigned int frente;
    unsigned int final;
};

int paso (int posicion){
    return ((posicion % TAMANIO_MAXIMO) + 1);
}

Cola c_crear(){
    Cola nueva_cola = (Cola) malloc(sizeof(struct ColaRep));
    nueva_cola->valores = calloc((TAMANIO_MAXIMO + 1), sizeof(TipoElemento));
    nueva_cola->frente = 1;
    nueva_cola->final = TAMANIO_MAXIMO;
    return nueva_cola;
}

void c_encolar (Cola cola, TipoElemento elemento){
    if (c_es_llena(cola)){
        printf("Cola llena.");
        return;
    }
    cola->final = paso(cola->final);
    cola->valores[cola->final] = elemento;
}

TipoElemento c_desencolar (Cola cola){
    TipoElemento elemento;
    if (c_es_vacia(cola)){
        elemento=NULL;
    }
    else{
        elemento = cola->valores[cola->frente];
        cola->frente = paso(cola->frente);
    }    
    return elemento;
}

bool c_es_vacia (Cola cola){
    return (paso(cola->final) == cola->frente);
}

bool c_es_llena (Cola cola){
    return (paso(paso(cola->final)) == cola->frente);
}

TipoElemento c_recuperar (Cola cola){
    TipoElemento X;
    if (c_es_vacia(cola)) { X = NULL; }
    else { X = cola->valores[cola->frente]; }
    return X;
}

void c_mostrar (Cola cola){
    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);
    printf("Contenido de la Cola:\n");

    while (c_es_vacia(cola) != true){
    X = c_desencolar(cola);
    printf("%d ", X->clave);
    c_encolar(Caux, X);
    }   

    while (c_es_vacia(Caux) != true){
    X = c_desencolar(Caux);
    c_encolar(cola, X);
    }
    
    printf("\n");
} 
