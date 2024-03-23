#include "colas.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TAMANIO_MAXIMO 100

void llenar_cola(Cola c1,int longitud){
    int clave;
    char auxiliar[100];
    for (int i = 1; i <= longitud;i++){
        printf("ingrese la clave del elemento %d de la cola: ", i);
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999){
            printf("Error. Reingrese la clave del elemento %d que quiere encolar: ",i);
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        clave = atoi(auxiliar);
        c_encolar(c1,te_crear(clave));
    }
}

void comparar_colas(Cola c1,Cola c2,int longitud){
    Cola c_aux = c_crear();
    TipoElemento elemento_c1;
    TipoElemento elemento_c2;
    bool iguales = true;
    if (longitud <= 50 ){ // si la longitud es menor o igual a 50, se puede hacer de una pasada
        while (c_es_vacia(c1) == false){
            elemento_c1 = c_desencolar(c1);
            elemento_c2 = c_desencolar(c2);
            if (elemento_c1->clave != elemento_c2->clave){
                iguales = false;
            }
        c_encolar(c_aux,elemento_c1);
        c_encolar(c_aux,elemento_c2);
        }
        while (c_es_vacia(c_aux) == false){
            c_encolar(c1,c_desencolar(c_aux));
            c_encolar(c2,c_desencolar(c_aux));
        }
        if (iguales == true){
            printf("\nAmbas colas son iguales");
        }else{
            printf("\nAmbas colas son distintas");
        }
        return;
    }else{ // si la longitud es mayor a 50, se tiene que hacer una pasada con los primeros 50 y luego otra pasada con los restantes
        int resto_de_elementos = longitud - 50;
        for (int i = 1;i <= 50;i++){
            elemento_c1 = c_desencolar(c1);
            elemento_c2 = c_desencolar(c2);
            if (elemento_c1->clave != elemento_c2->clave){
                iguales = false;
            }
        c_encolar(c_aux,elemento_c1);
        c_encolar(c_aux,elemento_c2);
        }
        while (c_es_vacia(c_aux) == false){
            c_encolar(c1,c_desencolar(c_aux));
            c_encolar(c2,c_desencolar(c_aux));
        }
        for (int i = 1;i <= resto_de_elementos;i++){
            elemento_c1 = c_desencolar(c1);
            elemento_c2 = c_desencolar(c2);
            if (elemento_c1->clave != elemento_c2->clave){
                iguales = false;
            }
        c_encolar(c_aux,elemento_c1);
        c_encolar(c_aux,elemento_c2);
        }
        while (c_es_vacia(c_aux) == false){
            c_encolar(c1,c_desencolar(c_aux));
            c_encolar(c2,c_desencolar(c_aux));
        }
        if (iguales == true){
            printf("\nAmbas colas son iguales");
        }else{
            printf("\nAmbas colas son distintas");
        }
        return;
    }
}


int main(){
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    char auxiliar[100];
    Cola c1 = c_crear();
    Cola c2 = c_crear();
    int longitud;
    printf("ingrese la cantidad de elementos de las colas: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > TAMANIO_MAXIMO){
        printf("Error. Reingrese la cantidad de elementos de las colas : ", (TAMANIO_MAXIMO));
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    longitud = atoi(auxiliar);
    printf("\t  ----Cola 1----\n");
    llenar_cola(c1,longitud);
    printf("\t  ----Cola 2----\n");
    llenar_cola(c2,longitud);
    comparar_colas(c1,c2,longitud);
    printf("\n\nCola 1\n");
    c_mostrar(c1);
    printf("\nCola 2\n");
    c_mostrar(c2);
    printf("\n\nLa complejidad algoritmica del problema es O(n), donde n es el tamanio de las colas\n");
}
