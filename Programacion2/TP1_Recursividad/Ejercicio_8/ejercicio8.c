#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include "Ejercicio8.h"


int main() {
    char buffer[100];
    int Max_valor = 99999999;
    printf("Ingrese la CANTIDAD de elementos del conjunto a analizar (el valor maximo es 100): ");
    fgets(buffer,100,stdin);
    while (validacion(buffer, 100,0) == false){
        printf("El dato ingresado es invalido, reingrese el numero: ");
        fflush(stdin);
        fgets(buffer,100,stdin);
    }
    int longitud_numeros = atoi(buffer);
    fflush(stdin);
    int numeros[longitud_numeros];
    printf("Ingrese un numero OBJETIVO de 8 digitos o menos al cual debe de llegar la suma de los subconjuntos: ");
    fgets(buffer,100,stdin);
    while (validacion(buffer, Max_valor,1) == false){
        printf("El dato ingresado es invalido, reingrese el numero: ");
        fflush(stdin);
        fgets(buffer,100,stdin);
    }
    int objetivo = atoi(buffer);
    fflush(stdin);
    for (int i = 0;i < longitud_numeros;i++){
        printf ("Ingrese el numero de 8 digitos o menos de la posicion %d : ",i+1);
        fgets(buffer,100,stdin);
        while (validacion(buffer, Max_valor,1) == false){
            printf("El dato ingresado es invalido, reingrese el numero: ");
            fflush(stdin);
            fgets(buffer,100,stdin);
        }
        numeros[i] = atoi(buffer);
        fflush(stdin);
    }
    int parcial[longitud_numeros+1];
    printf("\nLos Subconjuntos cuya suma es igual a %d son:\n",objetivo);
    recursividad_conjuntos(numeros, objetivo, parcial, 0, 0, longitud_numeros);
    printf("Fin del programa");
    return 0;
}

