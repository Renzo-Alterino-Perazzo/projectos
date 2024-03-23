#include "pilas.h"
#include "pilas_auxiliar.h"
#include "validaciones.h"
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

static const int MAX = 100;

//2. Dada una pila cargada con valores al azar realizar los siguientes ejercicios: 
void cargarClavesRandom(Pila pila, int cantidadElementos){
    int numeroRandom;
    int esNegativo;
    while (cantidadElementos > 0){
        numeroRandom = (rand() % 50);
        esNegativo = (rand () % 2);
        if (esNegativo == 0){
            p_apilar(pila, te_crear(numeroRandom));
        } else {
            p_apilar(pila, te_crear(numeroRandom*-1));
        }
        cantidadElementos--;
    }
};

void cargarClavesManual(Pila pila, int cantidadElementos){
    int i = 1;
    char buffer[100];
    int clave;
    while (cantidadElementos > 0){
        printf("Ingrese una clave para el elemento %d: ", i);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < -99999999 || atoi(buffer) > 99999999){
            printf("Error. Ingrese una clave para el elemento %d: ", i);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int clave = atoi(buffer);
        p_apilar(pila, te_crear(clave));
        i++;
        cantidadElementos--;
    }
}

//  a. Buscar una clave y determinar si existe en la Pila (sin perder la pila). 
bool buscarClave(Pila pila, int clave){
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

//  b. Colocar  en  una  posición  ordinal  determinada,  recibida  por  parámetro,  un 
//     nuevo elemento (Insertar un elemento nuevo). 
Pila insertarElemento(Pila pila, TipoElemento elemento, int posicion){
    Pila PAux = p_crear();
    Pila POriginal = p_crear();
    TipoElemento elementoAux;
    int i = 1;

    if (p_es_vacia(pila)){
        p_apilar(PAux, elemento);
    } else {
        while (p_es_vacia(pila) == false) {
            elementoAux = p_desapilar(pila);
            p_apilar(POriginal, elementoAux);
            if (i == posicion) {
                p_apilar(PAux, elemento);
            }
            p_apilar(PAux, elementoAux);
            i++;
        }
        if (i == posicion) {
            p_apilar(PAux, elemento);
        }
    }
    p_intercambiar(pila, POriginal);
    p_intercambiar(POriginal, PAux);
    return POriginal;
}

//  c. Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la 
//     clave). 
Pila eliminarElemento(Pila pila, TipoElemento elemento){
    Pila PAux = p_crear();
    Pila POriginal = p_crear();
    TipoElemento elementoAux = te_crear(0);
    bool elementoEliminado = false;

    while (p_es_vacia(pila) == false){
        elementoAux = p_desapilar(pila);
        p_apilar(POriginal, elementoAux);
        if (elemento->clave == elementoAux-> clave && elementoEliminado == false){
            elementoEliminado = true;
        } else {
            p_apilar(PAux, elementoAux);
        }
    }

    if (elementoEliminado == false){
        printf("\nEl elemento ingresado no se encuentra en la pila. \n");
    } 

    p_intercambiar(pila, POriginal);
    p_intercambiar(POriginal, PAux);

    if (elementoEliminado){
        printf("\nEl elemento con clave %d ha sido eliminado. \n", elemento->clave);
    }
    return POriginal;
}

//  d. Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 
//     2da con la 4ta. 

Pila intercambiarElementos(Pila pila, int posicionA, int posicionB){
    TipoElemento elementoA;
    TipoElemento elementoB;
    TipoElemento elementoAux;
    Pila PAux = p_crear();
    Pila POriginal = p_crear();
    int i = 1;
    while (p_es_vacia(pila) == false){
        elementoAux = p_desapilar(pila);
        p_apilar(PAux, elementoAux);
        p_apilar(POriginal, elementoAux);
        if (i == posicionA){
            elementoA = elementoAux;
        }
        if (i == posicionB){
            elementoB = elementoAux;
        }
        i++;
    }
    p_intercambiar(pila, POriginal);
    p_intercambiar(POriginal, PAux);
    i = 1;
    while (p_es_vacia(POriginal) == false){
        elementoAux = p_desapilar(POriginal);
        if (i == posicionA){
            p_apilar(PAux, elementoB);
        } else if (i == posicionB){
            p_apilar(PAux, elementoA);
        } else p_apilar(PAux, elementoAux);
        i++;
    }
    p_intercambiar(POriginal, PAux);
    return POriginal;
}

//  e. Duplicar el contenido de una pila. 
Pila duplicarElementos(Pila pila){
    Pila POriginal = p_crear();
    Pila PAux = p_crear();
    TipoElemento elementoAux;
    TipoElemento elementoDuplicado;
    while (p_es_vacia(pila) == false){
        elementoAux = p_desapilar(pila);
        p_apilar(POriginal, elementoAux);
        elementoDuplicado = te_crear(elementoAux->clave);
        p_apilar(PAux, elementoDuplicado);
    }
    p_intercambiar(pila, POriginal);
    p_intercambiar(POriginal, PAux);
    return POriginal;
}

//  f. Contar los elementos de la pila.
int contarElementos(Pila pila){
    if (p_es_vacia(pila)){
        return 0;
    }
    Pila PAux = p_crear();
    TipoElemento elementoAux;
    int cantidadElementos = 0;
    while (p_es_vacia(pila) == false){
        elementoAux = p_desapilar(pila);
        p_apilar(PAux, elementoAux);
        cantidadElementos++;
    }
    p_intercambiar(pila, PAux);
    return cantidadElementos;
}

int main(){

    char buffer[100];

    // Seteo la semilla para rand()
    time_t tiempo;
    srand((unsigned) time(&tiempo));

    // Creo la pila
    Pila pila = p_crear();

    // Creo la pila para mostrar los resultados
    Pila pilaResultado = p_crear();

    // Pido si quiere que la carga de los elementos sea manual o random
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    printf("CARGA DE PILA: \n");
    printf("0 - Manual \n");
    printf("1 - Random \n");
    printf("Ingrese una opcion: ");
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > 1){
        printf("\nError. Ingreso invalido.\n");
        printf("\nCARGA DE PILA: \n");
        printf("0 - Manual \n");
        printf("1 - Random \n");
        printf("Ingrese una opcion: ");
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    int carga = atoi(buffer);

    // Pido la cantidad de elementos a generar
    printf("Ingrese la cantidad de elementos (0 - %d) que desea cargar en la pila: ", MAX);
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > MAX) {
        printf("\nError. Ingrese un numero entre 0 y %d: ", MAX);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }

    // Creo la pila y luego la muestro
    pila = p_crear();
    int cantidadElementos = atoi(buffer);

    if (carga == 0){
        cargarClavesManual(pila, cantidadElementos);
    } else if (carga == 1){
        cargarClavesRandom(pila, cantidadElementos);
    }

    if (p_es_vacia(pila)) {
        printf("\nPila vacia generada. \n");
    } else p_mostrar(pila);

    int longitud_pila = longitudPila(pila);

    if (p_es_vacia(pila)){
        printf("\nNo se puede buscar elementos ya que la pila es vacia.\n");
    } else {
        // Pido una clave para buscar en la pila
        printf("\nIngrese una clave (numero entero) a buscar en la pila: ");
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false) {
            printf("\nError. Ingrese una clave (numero entero) a buscar en la pila: ");
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int claveABuscar = atoi(buffer);

        // Muestro si es que la clave fue encontrada o no
        if (buscarClave(pila, claveABuscar)) {
            printf("\nLa clave %d fue encontrada en la pila. \n", claveABuscar);
        } else printf("\nLa clave %d NO fue encontrada en la pila. \n", claveABuscar);
    }

    if (p_es_llena(pila)){
        printf("\nNo se puede insertar elementos ya que la pila esta llena. \n");
    } else {
        // Pido una posicion para insertar un elemento en la pila
        printf("\nIngrese una posicion (1 - %d) para insertar un nuevo elemento en la pila: ", longitud_pila + 1);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) > longitud_pila + 1 || atoi(buffer) < 1) {
            printf("\nError. Ingrese una posicion (1 - %d) para insertar un nuevo elemento en la pila: ", longitud_pila + 1);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int posicion = atoi(buffer);

        // Pido la clave del elemento a insertar en la pila
        printf("\nIngrese una clave (numero entero) para el elemento insertar en la posicion %d: ", posicion);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < -99999999 || atoi(buffer) > 99999999) {
            printf("\nError. Ingrese una clave (numero entero) para el elemento a insertar en la posicion %d: ", posicion);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int clave = atoi(buffer);
   
        TipoElemento elementoAInsertar = te_crear(clave);

        pilaResultado = insertarElemento(pila, elementoAInsertar, posicion);  
        printf("\nPila con elemento con clave %d insertado: \n", elementoAInsertar->clave);
        p_mostrar(pilaResultado);         
    }

    if (p_es_vacia(pila)){
        printf("\nNo se puede eliminar elementos ya que la pila esta vacia. \n");
    } else {
        printf("\nPila original: \n");
        p_mostrar(pila);
        // Pido una clave a eliminar en la pila
        printf("\nIngrese una clave (numero entero) a eliminar en la pila: ");
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < -99999999 || atoi(buffer) > 99999999){
            printf("\nError. Ingrese una clave (numero entero) a eliminar en la pila: ");
            fgets(buffer,100,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        TipoElemento elementoAEliminar = te_crear(atoi(buffer));

        pilaResultado = eliminarElemento(pila, elementoAEliminar);

        p_mostrar(pilaResultado);
    }

    if (p_es_vacia(pila) || contarElementos(pila) == 1){
        printf("\nNo se puede intercambiar elementos ya que no hay suficientes elementos. \n");
    } else {
        printf("\nPila original: \n");
        p_mostrar(pila);
        longitud_pila = longitudPila(pila);
        // Pido las posiciones para intercambiar elementos
        printf("\nIngrese una posicion (%d - %d) para intercambiar un elemento en la pila: ", 1, longitud_pila);
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < 1 || atoi(buffer) > longitud_pila){
            printf("\nError. Ingrese una posicion para intercambiar un elemento en la pila: ");
            fgets(buffer,100,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int posicionA = atoi(buffer);

        printf("\nIngrese otra posicion: ");
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) < 1 || atoi(buffer) > longitud_pila || atoi(buffer) == posicionA){
            if (atoi(buffer) == posicionA){
                printf("\nLa posicion ingresada es la misma que la anterior ingresada (%d).", posicionA);
            }
            printf("\nError. Ingrese otra posicion: ");
            fgets(buffer,100,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int posicionB = atoi(buffer);

        // Muestro la comparacion entre la pila original y la pila con los elementos intercambiados
        printf("\nPila original:\n");
        p_mostrar(pila);
        pilaResultado = intercambiarElementos(pila, posicionA, posicionB);
        printf("\nPila con las posiciones %d y %d intercambiadas:\n", posicionA, posicionB);
        p_mostrar(pilaResultado);
    }

    // Duplico los valores de los elementos de la pila
    pilaResultado = duplicarElementos(pila);
    printf("\nPila con elementos duplicados:\n");
    p_mostrar(pilaResultado);
    printf("\nPila original:\n");
    p_mostrar(pila);

    // Muestro cuantos elementos tiene la pila
    printf("\nLa pila contiene %d elementos. \n", contarElementos(pila));
}

