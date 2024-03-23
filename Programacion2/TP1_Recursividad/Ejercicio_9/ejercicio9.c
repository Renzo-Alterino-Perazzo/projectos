#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "ejercicio9.h"

char buffer[100];
int Max_valor = 99999999;

int main(){
    int numero,cifra_separada;
    int negativo = 1;
    printf("Ingrese un numero de 8 digitos o menos que desee verificar si es multiplo de 7: ");
    fgets(buffer,100,stdin);
    while (validacion(buffer, Max_valor) == false){
        printf("El dato ingresado es invalido, reingrese el numero: ");
        fgets(buffer,100,stdin);
    }
    numero = atoi(buffer);
    numero = negatividad(numero,&negativo);
    if (recursividad_multiplo7(numero,cifra_separada) == true){
        if (negativo == 1){
            numero = numero * -1;
        }
        printf ("el numero %d es divisible por 7",numero);
    }
    else{
        if (negativo == 1){
            numero = numero * -1;
        }
        printf("el numero %d no es divisible por 7",numero);
    }
}


