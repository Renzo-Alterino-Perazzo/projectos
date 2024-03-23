#include <stdio.h>
#include <string.h>
#include "Ejercicio7.h"

char string[100];
char resultado[100];

int main(){
    printf("Ingrese un string que contenga solamente H y L: (los espacios serán ignorados) \n");
    fgets(string,100,stdin);
    borrarEspacios(string);
    while (validacion(string) == false){
        printf("Error. El dato ingresado es inválido.\n");
        printf("Ingrese un string que contenga solamente H y L: (los espacios serán ignorados) \n");
        fgets(string,100,stdin);
        borrarEspacios(string);
    }
    int posicionString = 0;
    ondaDigital(string, posicionString, resultado);
    printf("Onda digital: %s\n", resultado);
}
