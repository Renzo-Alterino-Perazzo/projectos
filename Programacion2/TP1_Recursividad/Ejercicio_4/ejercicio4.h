#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <math.h>


bool validacion(char buffer[],int Max_valor,int n){
    // Verifico que la entrada no tenga una cantidad de digitos a lo permitido
    if ( (atoi(buffer) >= Max_valor) || (atoi(buffer) <= (Max_valor * -1)) ) {
        return false;
    }
    // Verifico si el ultimo caracter es un caracter de nueva línea
    if (strlen(buffer) == 1 && buffer[0] == '\n') {
        return false;
    }
    if (buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0'; // Elimino el caracter de nueva línea
    }
    if (buffer[0] == '-' && strlen(buffer) > 1) {
        // Si el primer caracter es "-" y hay más de un caracter en el buffer verifico que los demás caracteres sean dígitos
        for (int i = 1; i < strlen(buffer); i++){
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    } else {
        // Si no hay "-" en el primer caracter, verifico que todos los caracteres sean digitos
        for (int i = 0; i < strlen(buffer); i++){
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    }
    // si invalido el divisor, no puede ser 0;
    if (n == 2){
        if (atoi(buffer) == 0){
            return false;
        }
    }
    // si todo sale bien, devuelvo true
    return true;   
}



int negativo(int* m,int* n,int ref_negativo){
    int aux_m,aux_n;
    aux_m = *m;
    aux_n = *n;
    if (aux_m < 0 && aux_n < 0){
        aux_m = aux_m * -1;  
        aux_n = aux_n * -1;
        ref_negativo = 3;      
    }   // si ambos son negativos guardo en re_negativo el 3
    if (aux_m < 0 ){
        aux_m = aux_m * -1;
        ref_negativo = 1;
    }   // si solo el dividendo es negativo guardo en re_negativo el 1
    if (aux_n < 0){
        aux_n = aux_n * -1;
        ref_negativo = 2;
    }   // si solo el divisor es negativo guardo en re_negativo el 2
    *m = aux_m;   
    *n = aux_n;     //guardo en el puntero de m y n el valor ingresado en positivo
    return ref_negativo;
}


float mini_recursividad(int *m,int n,float i){
    if (n > *m){
        return i;
    }
    else{
        *m = *m - n;
        return mini_recursividad( m , n , i+1);
    }
}


float division_recursiva(int m, int n, float resul, float limite_decimal){
    if (m <= n){
        m = m * 10;
        float i = 0.0;
        i = mini_recursividad(&m,n,i);
        limite_decimal++;
        resul = resul + (i *  pow(10,-limite_decimal));
        if (limite_decimal < 4){
            division_recursiva(m,n,resul,limite_decimal);
        }
        else {
            return (resul);
        }
    }
    else {
        resul++;
        return division_recursiva((m - n), n , resul, limite_decimal);
    }
}


void mostrar_resultado(int m,int n,float resul,int ref_negativo){
    if (ref_negativo == 1){
        m = m * -1;
        resul = resul * -1.0;
    }
    if (ref_negativo == 2){
        n = n * -1;
        resul = resul * -1.0;        
    }
    if (ref_negativo == 3){
        m = m * -1;        
        n = n * -1;        
    }
    printf( "El resultado de dividir %d por %d es : %0.4f",m,n,resul);
}

