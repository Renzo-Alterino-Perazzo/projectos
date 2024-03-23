#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void borrarEspacios(char string[]){ // borra todos los espacios del string
    int contadorSinEspacio = 0;
    for (int i = 0; string[i]; i++){
        if (string[i] != ' ' && string[i] != '\n'){
            string[contadorSinEspacio++] = string[i];
        }
    }
    if (contadorSinEspacio != 0){
        string[contadorSinEspacio] = '\0';
    } else return;
}

bool validacion(char string[]){ // comprueba si el string es un número válido
    for (int i = 0; i < strlen(string); i++){
        if ((isdigit(string[i]) == 0)){
            if ((string[i] == '-' && i != 0) || (string[i] != '-')){
                return false;
            } 
        }
    }
    if (atoi(string) > 200000 || atoi(string) < -200000){
        printf("El número es demasiado grande. ");
        return false;
    } else return true;
}

int productoRecursivo(int m, int n, int resultado){
    if (m != 0 && n != 0){
        resultado = resultado + m;
        productoRecursivo(m,n-1,resultado);
    } else return resultado;
};
