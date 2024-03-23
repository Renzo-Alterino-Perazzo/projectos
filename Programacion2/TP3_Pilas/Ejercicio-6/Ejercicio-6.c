#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "pilas.h"
#include "pilas_auxiliar.h"
#include "tipo_elemento.h"
#include "validaciones.h"

static const int MAX = 100;


void llenarPila_manualmente(Pila pila, int cantidadElementos){
    char clave[100];
    int clave_elemento;
    int contador = 1;
    while(cantidadElementos > 0){
        printf("Ingrese la clave %d: ", contador);
        fgets(clave,100,stdin);
        fflush(stdin);
        borrarEspacios(clave);
        while(validacion(clave)==false || atoi(clave) > 99999999 || atoi(clave) < -99999999){
            printf("Valor invalido, ingrese clave %d: ", contador);
            fgets(clave,100,stdin);
            fflush(stdin);
            borrarEspacios(clave);
        }
        clave_elemento = atoi(clave);
        p_apilar(pila,te_crear(clave_elemento));
        cantidadElementos--;
        contador++;
    }
}

void llenarPila(Pila pila, int cantidadElementos){
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
}

void reapilar(Pila original, Pila auxiliar){
    TipoElemento elemento;
    while(p_es_vacia(auxiliar) == false){
        elemento = p_desapilar(auxiliar);
        p_apilar(original,elemento);
    }
}

int eliminarIter(Pila P,Pila pilaAux,Pila pilaEliminado,int eliminar,int lo_contiene){
    TipoElemento elemento;
    int i,j;
    while(p_es_vacia(P)==false){
        elemento = p_desapilar(P);
        p_apilar(pilaAux,elemento);
        if (elemento->clave!=eliminar){
            p_apilar(pilaEliminado,elemento);
        }else {
            lo_contiene = 1;
        }
    }
    reapilar(P,pilaAux);
    return lo_contiene;
}


int eliminarRec(Pila P,Pila pilaAux,Pila pilaEliminado,int eliminar,int lo_contiene){
    TipoElemento elemento;
    if (p_es_vacia(P)){
        reapilar(P,pilaAux);
        return lo_contiene;
    }
    else{
        elemento = p_desapilar(P);
        p_apilar(pilaAux,elemento);
        if (elemento->clave != eliminar){
            p_apilar(pilaEliminado,elemento);
        }else {
            lo_contiene = 1;
        }
        return eliminarRec(P,pilaAux,pilaEliminado,eliminar,lo_contiene);
    }
}

//la complejidad algoritmica es O(n) o lineal
//n siendo la longitud de la pila

int main(){
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    char auxiliar[100];
    // Seteo la semilla para rand()
    time_t tiempo;
    srand((unsigned) time(&tiempo));
    printf("Elimina elementos de pila que posean la clave ingresada\n");
    int longitud;
    printf("Ingrese la longitud de la pila (entre 0 y 100): ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > MAX){
        printf("Error. Elija un rango de numeros (0 - %d) para crear la lista 1: \n", (MAX));
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    longitud = atoi(auxiliar);
    Pila pila = p_crear();
    Pila pilaAux = p_crear();
    Pila pilaAux2 = p_crear();
    int claveEliminar;
    printf("Ingrese 1 para ingresar las claves manualmente o 2 si quiere llenarla aleatoriamente: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || ( atoi(auxiliar) != 1 && atoi(auxiliar) != 2 )){
        printf("Error. reingrese la opcion 1 o 2: \n");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    int opcion_ingreso = atoi(auxiliar);
    if (opcion_ingreso == 2){
        llenarPila(pila,longitud);
    }else{
        llenarPila_manualmente(pila,longitud);
    }
    p_mostrar(pila);
    printf("Ingrese el numero de la clave que quiere eliminar: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) > 99999999){
        printf("Error. reingrese el numero a eliminar: \n", (MAX));
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    claveEliminar = atoi(auxiliar);
    int opcion;
    printf("Elija 1 para version iterativa o 2 para version recursiva: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || (atoi(auxiliar) != 1 && atoi(auxiliar) != 2) ){
        printf("Error. Elija la opcion 1 o 2: ", (MAX));
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    opcion = atoi(auxiliar);
    int lo_contiene = 0;
    if(opcion==1){
        lo_contiene = eliminarIter(pila,pilaAux,pilaAux2,claveEliminar,lo_contiene);
    }
    else{
        lo_contiene = eliminarRec(pila,pilaAux,pilaAux2,claveEliminar,lo_contiene);
    }
    Pila respuesta = p_crear();
    reapilar(respuesta,pilaAux2);
    if (lo_contiene == 1){
        printf("\nPila ingresada\n");
        p_mostrar(pila);
        printf("\n\n");
        printf("Pila con clave eliminada\n");
        p_mostrar(respuesta);
        printf("\n\n");
        printf("La complejidad algoritmica es O(n) o lineal\n");
        return 0;
    }else{
        printf("\nEl elemento no se encontro en la Pila\n");
        printf("\nLa complejidad algoritmica es O(n) o lineal en ambas soluciones,donde n es la longitud de la pila\n");
        return 0;
    }
}
