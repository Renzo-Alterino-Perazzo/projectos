#include "listas.h"
#include "pilas.h"
#include "colas.h"
#include "validaciones.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

static const int MAX = 100;

bool buscarClavePila(Pila pila, int clave){
    if (p_es_vacia(pila)){
        return false;
    }
    Pila PAux = p_crear();
    bool fueEncontrada = false;
    TipoElemento elemento;
    while (p_es_vacia(pila) == false && fueEncontrada == false){
        elemento = p_desapilar(pila);
        p_apilar(PAux, elemento);
        if (elemento->clave == clave){
            fueEncontrada = true;
        }
    }
    while (p_es_vacia(PAux) == false){
        elemento = p_desapilar(PAux);
        p_apilar(pila, elemento);
    }
    return fueEncontrada;
};

void cargarPila(Pila pila, int cantidadElementos){
    char buffer[100];
    int clave;
    bool esRepetido = false;
    while (cantidadElementos > 0){
        printf("\nIngrese una clave para el elemento %d: ", cantidadElementos);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        esRepetido = buscarClavePila(pila, atoi(buffer));
        while (validacion(buffer) == false || esRepetido || atoi(buffer) < -99999999 || atoi(buffer) > 99999999){
            if (esRepetido){
                printf("\nError. El valor ingresado ya se encuentra en la pila.\n");
            } else printf("\nError. Ingreso invalido.\n");
            printf("\nIngrese una clave para el elemento %d: ", cantidadElementos);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
            esRepetido = buscarClavePila(pila, atoi(buffer));
        }
        int clave = atoi(buffer);
        p_apilar(pila, te_crear(clave));
        cantidadElementos--;
    }
    printf("\n");
}

void cargarPilaRandom(Pila pila, int cantidadElementos){
    int numeroRandom;
    while (cantidadElementos > 0){
        numeroRandom = (rand() % 101) - 50;
        while (buscarClavePila(pila, numeroRandom)){
            numeroRandom = (rand() % 101) - 50;
        }
        p_apilar(pila, te_crear(numeroRandom));
        cantidadElementos--;
    }
    printf("\n");
};

bool buscarClaveCola(Cola cola, int clave){
    TipoElemento elemento;
    Cola colaAux = c_crear();
    bool encontrado = false;
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        c_encolar(colaAux,elemento);
        if(elemento->clave==clave){
            encontrado = true;
        }
    }
    while(c_es_vacia(colaAux)==false){
        elemento = c_desencolar(colaAux);
        c_encolar(cola,elemento);
    }
    return encontrado;
}

void cargarCola(Cola cola, int cantidadElementos){
    int i = 1;
    char buffer[100];
    bool esRepetido = false;
    while (cantidadElementos > 0){
        printf("\nIngrese la clave para el elemento %d: ", i);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        esRepetido = buscarClaveCola(cola, atoi(buffer));
        while (validacion(buffer) == false || esRepetido){
            if (esRepetido){
                printf("\nError. El valor ingresado ya se encuentra en la cola.");
            } else printf("\nError. Ingreso invalido.");
            printf("\nIngrese la clave para el elemento %d: ", i);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
            esRepetido = buscarClaveCola(cola, atoi(buffer));
        }
        c_encolar(cola, te_crear(atoi(buffer)));
        i++;
        cantidadElementos--;
    }
    printf("\n");
}

void cargarColaRandom(Cola cola, int cantidadElementos){
    int numeroRandom;
    while (cantidadElementos > 0){
        numeroRandom = (rand() % 101) - 50;
        while (buscarClaveCola(cola, numeroRandom)){
            numeroRandom = (rand() % 101) - 50;
        }
        c_encolar(cola, te_crear(numeroRandom));
        cantidadElementos--;
    }
    printf("\n");
}

int pedirCantidadElementos(char estructura[]){
    char buffer[100];
    printf("Ingrese la cantidad de elementos (0 - %d) a cargar en la %s: ", MAX, estructura);
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > 100){
        printf("\nError. Ingreso invalido.\n");
        printf("Ingrese la cantidad de elementos (0 - %d) a cargar en la %s: ", MAX, estructura);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    return atoi(buffer);
}

Lista valoresComunes(Pila pila, Cola cola){
    Lista lista = l_crear();
    Pila pilaOriginalInvertida = p_crear();
    Cola colaAuxiliar = c_crear();
    TipoElemento elementoLista;
    TipoElemento elementoPila;
    TipoElemento elementoCola;

    int posicionPila = 1;
    int posicionCola;
    void *posiciones;
    while (p_es_vacia(pila) == false){
        elementoPila = p_desapilar(pila);
        p_apilar(pilaOriginalInvertida, elementoPila);
        posicionCola = 1;
        while (c_es_vacia(cola) == false){
            elementoCola = c_desencolar(cola);
            c_encolar(colaAuxiliar, elementoCola);
            if (elementoPila->clave == elementoCola->clave){
                posiciones = malloc(sizeof(char)*10);
                sprintf(posiciones, "%d:%d", posicionPila, posicionCola);
                elementoLista = te_crear_con_valor(elementoPila->clave, posiciones);
                l_agregar(lista, elementoLista);
            }
            posicionCola++;
        }
        while (c_es_vacia(colaAuxiliar) == false){
            c_encolar(cola, c_desencolar(colaAuxiliar));
        }
        posicionPila++;
    }
    while (p_es_vacia(pilaOriginalInvertida) == false){
        p_apilar(pila, p_desapilar(pilaOriginalInvertida));
    }
    return lista;
}

int main(){
    char buffer[100];

    // Seteo la semilla para rand()
    time_t tiempo;
    srand((unsigned) time(&tiempo));

    // Creo la lista, la pila y la cola
    Lista lista = l_crear();
    Pila pila = p_crear();
    Cola cola = c_crear();

    // Pido como quiere cargar las estructuras
    printf("CARGA DE ELEMENTOS\n");
    printf("0 - Manual\n");
    printf("1 - Random\n");
    printf("Ingrese una opcion: ");
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > 1){
        printf("\nError. Ingreso invalido.\n");
        printf("\nCARGA DE ELEMENTOS\n");
        printf("0 - Manual\n");
        printf("1 - Random\n");
        printf("Ingrese una opcion: ");
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    printf("\n");
    int carga = atoi(buffer);

    // Pido la cantidad de elementos a cargar en la pila
    int cantidadElementosPila = pedirCantidadElementos("pila");

    // Cargo la pila y la muestro
    if (carga == 0){
        cargarPila(pila, cantidadElementosPila);
    } else cargarPilaRandom(pila, cantidadElementosPila);
    if (p_es_vacia(pila)){
        printf("Pila vacia.\n");
    } else p_mostrar(pila);
    printf("\n");

    // Pido la cantidad de elementos a cargar en la cola
    int cantidadElementosCola = pedirCantidadElementos("cola");

    // Cargo la cola y la muestro
    if (carga == 0){
        cargarCola(cola, cantidadElementosCola);
    } else cargarColaRandom(cola, cantidadElementosCola);
    if (c_es_vacia(cola)){
        printf("Cola vacia.\n");
    }else c_mostrar(cola);

    // Cargo la lista con los elementos en comun entre la pila y la cola
    lista = valoresComunes(pila, cola);

    // Muestro los elementos y la posicion en la que se encontraban
    if (l_es_vacia(lista) == false) {
        printf("\nLista con valores comunes: (valor:posicionPila:posicionCola)\n");
        Iterador iter = iterador(lista);
        TipoElemento elemento;
        printf("(");
        while (hay_siguiente(iter)) {
            elemento = siguiente(iter);
            if (hay_siguiente(iter)) {
                printf("%d:%s, ", elemento->clave, (char *) elemento->valor);
            } else printf("%d:%s)\n", elemento->clave, (char *) elemento->valor);
        }
    } else printf("\nLista con valores comunes vacia.\n");

    // Complejidad algoritmica
    printf("\nLa complejidad algoritimica es O(n^2).\n");
}
