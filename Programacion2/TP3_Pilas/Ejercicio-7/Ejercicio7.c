// Dada dos pilas realizar una función que permita determinar los elementos que tienen
// en común. Debe retornar una nueva pila con esos elementos (que están en ambas
// pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la
// solución. 


#include <stdlib.h>
#include <stdio.h>
#include "pilas.h"
#include "validaciones.h"
#include <stdbool.h>

#define TAMANIO_MAXIMO 100

void llenar_pilas(Pila p1, Pila p2){
    char auxiliar[100];
    int tamanio;
    printf("ingrese el tamanio de la primera pila: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > TAMANIO_MAXIMO){
        printf("Error. Elija un rango de numeros (0 - %d) para crear la lista 1: \n", (TAMANIO_MAXIMO));
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    tamanio = atoi(auxiliar);
    for (int i = 1;i <= tamanio;i++){
        int numero;
        printf("ingrese el numero %d a apilar: ",i);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999){
            printf("Error. Reingrese el numero %d que quiere apilar: ",i);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        numero = atoi(auxiliar);
        TipoElemento elemento = te_crear(numero);
        p_apilar(p1,elemento);
    }
    printf("\n\t\tPila 1: \n");
    p_mostrar(p1);
    printf("\ningrese el tamanio de la segunda pila: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > TAMANIO_MAXIMO){
        printf("Error. Elija un rango de numeros (0 - %d) para crear la lista 2: \n", (TAMANIO_MAXIMO));
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    tamanio = atoi(auxiliar);
    for (int j = 1;j <= tamanio;j++){
        int numero_2;
        printf("ingrese el numero %d a apilar: ",j);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999){
            printf("Error. Reingrese el numero %d que quiere apilar: ",j);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        numero_2 = atoi(auxiliar);
        TipoElemento elemento = te_crear(numero_2);
        p_apilar(p2,elemento);
    }
    printf("\n\t\tPila 2: \n");
    p_mostrar(p2);
}

Pila pilas_comun(Pila p1,Pila p2){
    Pila resultado = p_crear();
    Pila aux_resultado = p_crear();
    Pila aux_p1 = p_crear();
    Pila aux_p2 = p_crear();
    TipoElemento elemento_p1;
    TipoElemento elemento_p2;
    TipoElemento elemento_resultado;
    bool esta_dentro = false;
    while (p_es_vacia(p1) != true){
        elemento_p1 = p_desapilar(p1);
        p_apilar(aux_p1,elemento_p1);
        while (p_es_vacia(p2) != true){
            elemento_p2 = p_desapilar(p2);
            p_apilar(aux_p2,elemento_p2);
            if (elemento_p1->clave == elemento_p2->clave){
                while (p_es_vacia(resultado) != true){   //desapilo resultado para comprobar que no este dentro el numero
                    elemento_resultado = p_desapilar(resultado);
                    p_apilar(aux_resultado,elemento_resultado);
                    if (elemento_p2->clave == elemento_resultado->clave){   //controlo que no este dentro de la pila resultado
                        esta_dentro = true;
                    }
                }
                while (p_es_vacia(aux_resultado) != true){ //reapilo la pila resultados
                    elemento_resultado = p_desapilar(aux_resultado);
                    p_apilar(resultado,elemento_resultado);
                } 
                if (esta_dentro == false){  //si no esta adentro de resultados,lo apilo
                    p_apilar(resultado,elemento_p2);
                }
            }
            esta_dentro = false; //reinicio el bool por si estaba adentro
        }
        while (p_es_vacia(aux_p2) != true){ //reapilo p2
            elemento_p2 = p_desapilar(aux_p2);
            p_apilar(p2,elemento_p2);
        }
    }
    while (p_es_vacia(aux_p1) != true){ //reapilo p1
        elemento_p1 = p_desapilar(aux_p1);
        p_apilar(p1,elemento_p1);
    }
    return resultado;
}


int main(){
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    Pila p1 = p_crear();
    Pila p2 = p_crear();
    llenar_pilas(p1,p2);
    Pila resultado = pilas_comun(p1,p2);
    printf("\n\t\tresultado: \n");
    p_mostrar(resultado);
    printf("\nLa complejidad algoritmica es O(n^3)\n");
}
