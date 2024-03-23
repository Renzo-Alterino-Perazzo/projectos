#include <stdio.h>
#include "listas.h"
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

bool esEntero(char * cadena){

    int longitud=strlen(cadena);
    int puntos=0;
    int i=0;

    if (cadena[0]=='\0'){
        return false;
    }

    if (cadena[0]=='-'){
        i=1;
    }

    for (i; i<longitud; i++){
        if (puntos==0){
            if ((cadena[i]>57 || cadena[i]<48) && cadena[i]!=46){
                return false;
            }
            else if (cadena[i]==46){
                if (cadena[i+1]=='\0'){
                    return false;
                }
                else {
                    puntos=1;
                }    
            }
        }
        else if (puntos==1){
            if (cadena[i]!=48){
                return false;
            }
        }
    }

    return true;
}

void sonMultiplos(Lista l1, Lista l2, int lon){

    system("cls");

    if (lon==0){
        printf("No se pueden calcular listas vacias.");
        return;
    }

    TipoElemento te1;
    TipoElemento te2;

    int i;
    int escalar=0;
    int multiplos=0;
    int valorEscalar;

    for (i=1; i<lon+1; i++){
        te1=l_recuperar(l1, i);
        te2=l_recuperar(l2, i);
        if (te2->clave%te1->clave!=0){
            multiplos=1;
        }
        if (i==1){
            valorEscalar=te2->clave/te1->clave;
        }
        else {
            if (valorEscalar!=te2->clave/te1->clave){
                escalar=1;
            }
        }
    }

    if (multiplos==1){
        printf("No son multiplos");
    }
    else if (multiplos==0 && escalar==0){
        printf("Son multiplos con valor escalar %d", valorEscalar);
    }
    else {
        printf("Son multiplos sin valor escalar");
    }
}

void cargar(){

    Lista l1=l_crear();
    Lista l2=l_crear();

    int valido=1;
    char cantElementoCadena[MAX];
    int cantElementos;
    char valorCadena[MAX];
    int valor;
    int i;

    printf("Ingrese la cantidad de elementos de las listas (maximo 20): ");
    fflush(stdin);
    fgets(cantElementoCadena, MAX, stdin);
    if (cantElementoCadena[strlen(cantElementoCadena)-1]=='\n'){
        cantElementoCadena[strlen(cantElementoCadena)-1]='\0';
    }

    while (valido==1){
        valido=0;
        if (esEntero(cantElementoCadena)==false){
            valido=1;
            printf("Valor invalido.\n");
            printf("Ingrese la cantidad de elementos de las listas (maximo 20): ");
            fflush(stdin);
            fgets(cantElementoCadena, MAX, stdin);
            if (cantElementoCadena[strlen(cantElementoCadena)-1]=='\n'){
                cantElementoCadena[strlen(cantElementoCadena)-1]='\0';
            }            
        }
        else if ((cantElementos=atoi(cantElementoCadena))>20 || (cantElementos=atoi(cantElementoCadena))<0){
            valido=1;
            printf("Valor invalido.\n");
            printf("Ingrese la cantidad de elementos de las listas (maximo 20): ");
            fflush(stdin);
            fgets(cantElementoCadena, MAX, stdin);
            if (cantElementoCadena[strlen(cantElementoCadena)-1]=='\n'){
                cantElementoCadena[strlen(cantElementoCadena)-1]='\0';
            }
        }
    }

    system("cls");
    printf("LISTA 1:\n");

    cantElementos=atoi(cantElementoCadena);

    for (i=0; i<cantElementos; i++){
        printf("Ingrese un numero entero distinto de 0 para la posicion %d: ", i+1);
        fflush(stdin);
        fgets(valorCadena, MAX, stdin);
        if (valorCadena[strlen(valorCadena)-1]=='\n'){
            valorCadena[strlen(valorCadena)-1]='\0';
        }
        while (esEntero(valorCadena)==false || atoi(valorCadena)==0){
            printf("valor invalido.\n");
            printf("Ingrese un numero entero distinto de 0 para la posicion %d: ", i+1);
            fflush(stdin);
            fgets(valorCadena, MAX, stdin);
            if (valorCadena[strlen(valorCadena)-1]=='\n'){
                valorCadena[strlen(valorCadena)-1]='\0';
            }            
        }
        valor=atoi(valorCadena);
        l_agregar(l1, te_crear(valor));
    }

    system("cls");
    printf("LISTA 2:\n");

    for (i=0; i<cantElementos; i++){
        printf("Ingrese un numero entero para la posicion %d: ", i+1);
        fflush(stdin);
        fgets(valorCadena, MAX, stdin);
        if (valorCadena[strlen(valorCadena)-1]=='\n'){
            valorCadena[strlen(valorCadena)-1]='\0';
        }
        while (esEntero(valorCadena)==false){
            printf("valor invalido.\n");
            printf("Ingrese un numero entero para la posicion %d: ", i+1);
            fflush(stdin);
            fgets(valorCadena, MAX, stdin);
            if (valorCadena[strlen(valorCadena)-1]=='\n'){
                valorCadena[strlen(valorCadena)-1]='\0';
            }            
        }
        valor=atoi(valorCadena);
        l_agregar(l2, te_crear(valor));
    }    

    sonMultiplos(l1, l2, cantElementos);

}

void main(){
    system("cls");
    cargar();
}