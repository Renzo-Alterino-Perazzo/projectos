#include "colas.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

void divisores(Cola cola, float cant);

void cargarCola(){

    Cola cola=c_crear();
    TipoElemento elem=te_crear(0);
    TipoElemento elem2=te_crear(0);
    char cantElementos[MAX];
    char valorCadena[MAX];
    float cant;
    int i;
    int j;
    int k;
    int valor;
    int valido=0;

    printf("ingrese la cantidad de elementos de la cola (minimo 0 elemento, maximo 100):");
    while (valido==0){
        valido=1;
        fflush(stdin);
        fgets(cantElementos, MAX, stdin);
        if (cantElementos[strlen(cantElementos)-1]=='\n'){
            cantElementos[strlen(cantElementos)-1]='\0';
        }
        if (!esEntero(cantElementos)){
            valido=0;
        }
        cant=atof(cantElementos);

        if (cant<0 || cant>100){
            valido=0;
        }
        if (valido==0){
            printf("ERROR. ingrese la cantidad de elementos de la cola (minimo 0 elemento, maximo 100):");
        }
    }

    for (i=0; i<cant; i++){
        valido=0;
        printf("Ingrese el elemento %d (debe ser mayor a 1 y no encontrarse en la cola):", i+1);

        while (valido==0){
            valido=1;
            fflush(stdin);
            fgets(valorCadena, MAX, stdin);
            if (valorCadena[strlen(valorCadena)-1]=='\n'){
                valorCadena[strlen(valorCadena)-1]='\0';
            }
            if (!esEntero(valorCadena)){
                valido=0;
            }
            valor=atoi(valorCadena);
            if (valor<2){
                valido=0;
            }
            if (valor<-99999999 || valor>99999999){
                valido=0;
            }
            if (i!=0){
                for (j=0; j<i; j++){
                    elem2=c_desencolar(cola);
                    if (valor==elem2->clave){
                        valido=0;
                    }
                    c_encolar(cola, elem2);
                }
            }
            if (valido==0){
                printf("ERROR. Ingrese el elemento %d (debe ser mayor a 1 y no encontrarse en la cola):", i+1);
            }
            
        }

        elem=te_crear(valor);
        c_encolar(cola, elem);    
    }

    system("cls");
    c_mostrar(cola);
    printf("\n\n");
    divisores(cola, cant);

}

void divisores(Cola cola, float cant){
    int i, j;
    int contador=1;
    TipoElemento elem=te_crear(0);
    TipoElemento elem2=te_crear(0);
    for (i=0; i<cant; i++){
        elem=c_desencolar(cola);
        for (j=0; j<cant-1; j++){
            elem2=c_desencolar(cola);
            if (elem2->clave%elem->clave==0){
                contador++;
            }
            c_encolar(cola, elem2);
        }
        if (contador==cant){
            printf("%d es divisor total.\n", elem->clave);
        }
        else if (contador>=cant/2 && contador<cant){
            printf("%d es divisor parcial.\n", elem->clave);
        }
        c_encolar(cola, elem);
        contador=1;
    }
}

void main(){
    system("cls");
    cargarCola();
    printf("\nLa complejidad algoritmica de la solucion es de orden cuadratico O(n^2)");
}
