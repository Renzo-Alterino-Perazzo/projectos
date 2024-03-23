#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>


bool validacion(char buffer[], int Max_valor, int n){
    // Valido la cantidad de digitos que puede ingresar
    if (n == 0){
        if ( (atoi(buffer) > Max_valor) || (atoi(buffer) <= 0)) {
        return false;
        }
    }
    else{
        if ( (atoi(buffer) >= Max_valor) || (atoi(buffer) <= -Max_valor)){
            return false;
        }
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
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    } else {
        // Si no hay "-" en el primer carácter, verifico que todos los caracteres sean digitos
        for (int i = 0; i < strlen(buffer); i++){
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    }
    return true;   
}



void recursividad_mostrar_subconjuntos(int j, int parcial[], int longitud_parcial, int numeros[]){
    if (j >= longitud_parcial){
        return;
    }
    else{
        printf("%d", numeros[parcial[j]]);
        if (j < longitud_parcial - 1) {
            printf(", ");
        }
        return recursividad_mostrar_subconjuntos((j + 1), parcial, longitud_parcial, numeros);      
    }
}


int recursividad_suma_Parcial(int suma_parcial,int longitud_parcial,int numeros[],int parcial[],int i){
    if (i >= longitud_parcial){
        return suma_parcial;
    }
    else{
        suma_parcial = suma_parcial + numeros[parcial[i]];
        return recursividad_suma_Parcial(suma_parcial, longitud_parcial, numeros, parcial, (i + 1));
    }
}

void recursividad_conjuntos(int numeros[], int objetivo, int parcial[], int longitud_parcial, int indice_actual, int longitud_numeros) {
    if (indice_actual == longitud_numeros) {
        if (longitud_parcial > 0) {
            int suma_parcial = 0;
            int i = 0;
            suma_parcial = recursividad_suma_Parcial(suma_parcial, longitud_parcial, numeros, parcial, i);
            if (suma_parcial == objetivo) {
                int j = 0;
                printf("{");
                recursividad_mostrar_subconjuntos((j), parcial, longitud_parcial, numeros);
                printf("}\n");
            }
        }
        return;
    }
    parcial[longitud_parcial] = indice_actual;
    recursividad_conjuntos(numeros, objetivo, parcial, longitud_parcial + 1, indice_actual + 1, longitud_numeros);
    recursividad_conjuntos(numeros, objetivo, parcial, longitud_parcial, indice_actual + 1, longitud_numeros);
}

