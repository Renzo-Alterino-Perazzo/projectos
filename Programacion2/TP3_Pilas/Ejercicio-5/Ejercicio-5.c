#include <stdio.h>
#include <stdlib.h>
#include "pilas.h"
#include "pilas_auxiliar.h"
#include "tipo_elemento.h"
#include "validaciones.h"

static const int MAX = 100;

void llenarPila(Pila pila,int longitud){
    int i;
    int clave;
    char auxiliar[100];
    TipoElemento elemento;
    printf("Ingrese las claves:\n");
    for(i=1;i<longitud+1;i++){
        printf("Ingrese clave %d: ",i);
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) > 99999999 || atoi(auxiliar) < -99999999){
            printf("Error. Reingrese la clave numero %d de la lista: \n", i);
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        clave = atoi(auxiliar);
        elemento = te_crear(clave);
        p_apilar(pila,elemento);
    }
}

void reapilar(Pila original, Pila auxiliar){
    TipoElemento elemento;
    while(p_es_vacia(auxiliar)==false){
        elemento = p_desapilar(auxiliar);
        p_apilar(original,elemento);
    }
}

Pila invertirPila(Pila pila){
    Pila pilaAux = p_crear();
    Pila pila2 = p_crear();
    TipoElemento auxiliar;
    while (p_es_vacia(pila)==false){
        auxiliar = p_desapilar(pila);
        p_apilar(pilaAux,auxiliar);
        p_apilar(pila2,auxiliar);
    }
    reapilar(pila,pila2);
    return pilaAux;
}
//la complejidad algoritmica es O(n) o lineal
//n siendo el tamaño de la pila

int main(){
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    char auxiliar[100];
    printf("Invierte la pila dada\n");
    int longitud;
    printf("Ingrese la longitud de la pila (entre 0 y 100): ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > MAX){
        printf("Error. Elija un rango de numeros (0 - %d) para crear la lista: \n", (MAX));
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    longitud = atoi(auxiliar);
    Pila pila = p_crear();
    if (longitud != 0){
        llenarPila(pila,longitud);
    }
    Pila pilaInvertida = invertirPila(pila);
    printf("Pila ingresada\n");
    p_mostrar(pila);
    printf("\n\n");
    printf("Pila invertida\n");
    p_mostrar(pilaInvertida);
    printf("\n\n");
    printf("La complejidad algoritmica es O(n) o lineal\n");
    return 0;
}
