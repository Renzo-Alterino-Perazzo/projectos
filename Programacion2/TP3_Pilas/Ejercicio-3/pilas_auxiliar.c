#include "pilas.h"
#include "tipo_elemento.h"
#include "pilas_auxiliar.h"
#include <stdio.h>

void p_intercambiar(Pila P, Pila PAux){
    while (p_es_vacia(PAux) == false){
        p_apilar(P,p_desapilar(PAux));
    }
};

int longitudPila(Pila P){
    int longitud = 0;
    Pila PAux = p_crear();
    TipoElemento elemento;
    while (p_es_vacia(P) == false){
        p_apilar(PAux, p_desapilar(P));
        longitud++;
    }
    p_intercambiar(P, PAux);
    return longitud;
}
