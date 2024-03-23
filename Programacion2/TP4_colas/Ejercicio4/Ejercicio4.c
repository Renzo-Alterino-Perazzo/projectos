#include "colas.h"
#include "tipo_elemento.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int MAX = 101;

void cargarCola(Cola cola, int cantidadElementos){
    int i = 1;
    char buffer[100];
    while (cantidadElementos > 0){
        printf("Ingrese la clave para el elemento %d: ", i);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false){
            printf("\nError. Ingreso invalido.\n");
            printf("\nIngrese la clave para el elemento %d: ", i);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        c_encolar(cola, te_crear(atoi(buffer)));
        i++;
        cantidadElementos--;
    }
}

Cola copiarCola(Cola cola){
    Cola colaCopia = c_crear();
    Cola colaAuxiliar = c_crear();
    TipoElemento elemento;
    while (c_es_vacia(cola) == false){
        elemento = c_desencolar(cola);
        c_encolar(colaCopia, elemento);
        c_encolar(colaAuxiliar, elemento);
    }
    while (c_es_vacia(colaAuxiliar) == false){
        elemento = c_desencolar(colaAuxiliar);
        c_encolar(cola, elemento);
    }
    return colaCopia;
}

Cola colaSinRepetir(Cola cola){
    Cola colaOriginal = copiarCola(cola);
    Cola colaResultado = c_crear();
    Cola colaAuxiliar = c_crear();
    TipoElemento elemento;
    TipoElemento elementoAComparar;
    bool seRepite;
    while (c_es_vacia(cola) == false){
        seRepite = false;
        elemento = c_desencolar(cola);
        // Compruebo si se repiten los elementos
        while (c_es_vacia(cola) == false){
            elementoAComparar = c_desencolar(cola);
            if (elemento->clave == elementoAComparar->clave){
                seRepite = true; // Si se repite el elemento, lo descarto para no procesarlo despues
            } else {
                c_encolar(colaAuxiliar, elementoAComparar); // Si no es un elemento repetido lo guardo para procesarlo 
            }
        }
        // Retorno el resto de los elementos a procesar a la cola principal
        while (c_es_vacia(colaAuxiliar) == false){
            c_encolar(cola, c_desencolar(colaAuxiliar));
        }
        // Si el elemento no se repite lo guardo en la cola a retornar
        if (seRepite == false){
            c_encolar(colaResultado, elemento);
        }
    }
    // Retorno los valores originales de la cola pasada por parametro
    while (c_es_vacia(colaOriginal) == false){
        c_encolar(cola, c_desencolar(colaOriginal));
    }
    return colaResultado;
}

int main(){
    // Creo la cola
    Cola cola = c_crear();

    char buffer[100];

    // Pido la cantidad de elementos para cargar la cola
    printf("\nIngrese la cantidad de elementos (0 - %d) para cargar la cola: ", MAX-1);
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > 100){
        printf("\nError. Ingreso invalido.\n");
        printf("\nIngrese la cantidad de elementos (0 - %d) para cargar la cola: ", MAX-1);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }

    // Cargo la cola
    cargarCola(cola, atoi(buffer));

    // Muestro la cola con los elementos sin repetir
    Cola colaResultado = colaSinRepetir(cola);
    printf("\nCola con elementos unicos:\n");
    c_mostrar(colaResultado);

    // Muestro la cola original
    printf("\nCola original:\n");
    c_mostrar(cola);
}
