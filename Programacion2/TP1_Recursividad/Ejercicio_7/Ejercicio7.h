#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validacion(char string[]){ // comprueba si el string es una onda digital
    int i = 0;
    while (i < strlen(string)){
        if (string[i] == 'h'){
            string[i] = 'H';
        } else if (string[i] == 'l'){
            string[i] = 'L';
        } else if (string[i] != 'H' && string[i] != 'L'){
            return false;
        }
        i++;
    }
    return true;
};

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

void ondaDigital(char string[], int posicionString, char resultado[]){
    char barra_alta[2];
    barra_alta[0] = 238;
    barra_alta[1] = '\0';
    if (posicionString == strlen(string)){
        return;
    } else {
        if (string[posicionString] == 'H' && posicionString > 0 && string[posicionString-1] != string[posicionString]){
            strcat(resultado,("|"));
            strcat(resultado,barra_alta);
            return ondaDigital(string, posicionString+1, resultado);
        } else if (string[posicionString] == 'H'){
            strcat(resultado,barra_alta);
            return ondaDigital(string, posicionString+1, resultado);
        } else if (string[posicionString] == 'L' && posicionString > 0 && string[posicionString-1] != string[posicionString]){
            strcat(resultado,("|"));
            strcat(resultado,("_"));
            return ondaDigital(string, posicionString+1, resultado);
        } else {
            strcat(resultado,"_");
            return ondaDigital(string, posicionString+1, resultado);
        }
    }
};
