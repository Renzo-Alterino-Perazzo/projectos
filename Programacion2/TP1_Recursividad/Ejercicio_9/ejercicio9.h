#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>


bool validacion(char buffer[], int Max_valor){
    int puntos = 0;
    // Valido la cantidad de digitos que puede ingresar
    if ( (atoi(buffer) >= Max_valor) || (atoi(buffer) <= -Max_valor)) {
        return false;
    }
    // Verificar si el último carácter es un carácter de nueva línea
    if (strlen(buffer) == 1 && buffer[0] == '\n') {
        return false;
    }
    if (buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0'; // Eliminar el carácter de nueva línea
    }
    if (buffer[0] == '-' && strlen(buffer) > 1) {
        // Si el primer carácter es "-" y hay más de un carácter en el buffer verifico que los demás caracteres sean dígitos
        for (int i = 1; i < strlen(buffer); i++){
            if (!isdigit(buffer[i]) && buffer[i] != '.'){
                return false;
            }
        }
        if (atoi(buffer) != atof(buffer)){
            return false;
        }
    } else {
        // Si no hay "-" en el primer carácter, verifico que todos los caracteres sean digitos
        for (int i = 0; i < strlen(buffer); i++){
            if (!isdigit(buffer[i]) && buffer[i] != '.'){
                return false;
            }
            if (buffer[i] == '.'){
                if (puntos == 1){
                    return false;
                }
                else{
                    puntos++;
                }
            }
        }
        if (atoi(buffer) != atof(buffer)){
            return false;
        }
    }
    return true;   
}


int negatividad(int numero,int* negativo){
    int aux;
    aux = *negativo;
    if (numero < 0){
        numero = numero * -1;
        aux = 1;
    }
    else{
        aux = 0;
    }
    *negativo = aux;
    return numero;
}


bool recursividad_multiplo7(int numero, int cifra_separada){
    if (numero < 70){
        if (numero == 0 || numero % 7 == 0){
            return true;
        }
        else {
            return false;
        }
    }
    else{
        cifra_separada = numero % 10;
        cifra_separada = cifra_separada * 2;
        numero = numero / 10;
        numero = numero - cifra_separada;
        return recursividad_multiplo7(numero,cifra_separada);
    }
}


