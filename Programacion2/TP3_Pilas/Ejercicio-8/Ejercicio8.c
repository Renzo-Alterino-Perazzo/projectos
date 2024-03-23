#include "pilas.h"
#include "pilas_auxiliar.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>

static const int MAX = 100;

Pila invertirPila(Pila pila){
    Pila pilaAux = p_crear();
    Pila pilaInvertida = p_crear();
    TipoElemento elementoAux;
    while (p_es_vacia(pila) == false){
        elementoAux = p_desapilar(pila);
        p_apilar(pilaAux, elementoAux);
        p_apilar(pilaInvertida, elementoAux);
    }
    p_intercambiar(pila, pilaAux);
    return pilaInvertida;
}

Pila elementosRepetidos(Pila pila){
    Pila pilaAux = p_crear();
    Pila pilaResultado = p_crear();
    Pila pilaOriginalInvertida = invertirPila(pila);
    TipoElemento elementoAComparar;
    TipoElemento elementoAux;
    int repeticiones = 1;
    while (p_es_vacia(pila) == false){
        elementoAComparar = p_desapilar(pila);
        while (p_es_vacia(pila) == false){
            elementoAux = p_desapilar(pila);
            if (elementoAux->clave == elementoAComparar->clave) {
                repeticiones++;
            } else {
                p_apilar(pilaAux, elementoAux);
            }
        }
        p_intercambiar(pila, pilaAux);
        elementoAComparar->valor = malloc(sizeof(int));
        *((int *)elementoAComparar->valor) = repeticiones;
        p_apilar(pilaResultado, elementoAComparar);
        repeticiones = 1;
    }
    p_intercambiar(pila, pilaOriginalInvertida);
    return invertirPila(pilaResultado);
}

int main(){

    char buffer[100];

    // Creo la pila
    Pila pila = p_crear();

    // Pido la cantidad de elementos de la pila
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    printf("Ingrese la cantidad de elementos de la pila a crear (0 - %d):  ", MAX);
    fgets(buffer,100,stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > MAX){
        printf("\nError. Ingrese la cantidad de elementos de la pila a crear (maximo %d):", MAX);
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    int cantidadElementos = atoi(buffer);

    // Pido el ingreso de las claves
    TipoElemento elemento;
    Pila pilaAux = p_crear();
    for (int i = 1; i < cantidadElementos+1; i++){
        printf("\nIngrese una clave (numero entero) para el elemento %d: ", i);
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < -99999999 || atoi(buffer) > 99999999){
            printf("\nError. Ingrese una clave (numero entero) para el elemento %d: ", i);
            fgets(buffer,100,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        elemento = te_crear(atoi(buffer));
        p_apilar(pilaAux, elemento);
    }
    p_intercambiar(pila, pilaAux);

    Pila pilaSinRepeticiones = elementosRepetidos(pila);

    // Muestro la pila original y la pila sin repeticiones
    printf("\nPila con repeticiones:\n");
    p_mostrar(pila);
    printf("\nPila sin repeticiones (numero:repeticiones):\n");
    if (p_es_vacia(pilaSinRepeticiones) == true){
        p_mostrar(pilaSinRepeticiones);
    }else{
        TipoElemento elementoAux;
        printf("(");
        while (p_es_vacia(pilaSinRepeticiones) == false){
            elementoAux = p_desapilar(pilaSinRepeticiones);
            p_apilar(pilaAux, elementoAux);
            if (p_es_vacia(pilaSinRepeticiones) == false) {
                printf("%d:%d,", elementoAux->clave, *(int *) elementoAux->valor);
            } else printf("%d:%d)", elementoAux->clave, *(int *) elementoAux->valor);
        }
        p_intercambiar(pilaSinRepeticiones, pilaAux);
    }
    // Complejidad algoritmica
    printf("\n\nLa complejidad algoritmica de la solucion es O(n^2).\n");
}
