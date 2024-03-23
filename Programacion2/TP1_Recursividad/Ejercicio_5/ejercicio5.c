
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define MAX 100

void negatividad(char* numero){
    int aux = atoi(numero);
    aux = aux * -1;
    sprintf(numero,"%d",aux);
}

void invertirCadena(char cadena[])
{
    int longitud = strlen(cadena);
    int i;
    for (i = 0; i < strlen(cadena) / 2; i++)
    {
        char temporal = cadena[i];
        cadena[i] = cadena[longitud - i - 1];
        cadena[longitud - i - 1] = temporal;
    }
}

void ponerPunto(char* numero, char* numeroPunto, int puntero, int puntos){
    int longitud = strnlen(numero,MAX);
    char c[]={0,0};
    if (puntero < longitud){
        if (puntos%3==0 && puntero != longitud && puntos != 0){
            c[0]='.';
            strcat(numeroPunto,c);
            ponerPunto(numero,numeroPunto,puntero,0);
        } else {
            c[0]=numero[puntero];
            strcat(numeroPunto,c);
            ponerPunto(numero,numeroPunto,puntero+1,puntos+1);
        }
    }
}

bool validacion(char buffer[], int Max_valor){
    // Valido la cantidad de digitos que puede ingresar
    if ( (atoi(buffer) >= Max_valor) || (atoi(buffer) <= -Max_valor)) {
        return false;
    }
    // Verificar si solo se ingreso un enter
    if (strlen(buffer) == 1 && buffer[0] == '\n') {
        return false;
    }
    if (buffer[strlen(buffer)-1] == '\n') {
        buffer[strlen(buffer)-1] = '\0'; // Eliminar el carácter de nueva línea que deja el fgets
    }
    if (buffer[0] == '-' && strlen(buffer) > 1) {
        // Si el primer carácter es "-" y hay más de un carácter en el buffer verifico que los demás caracteres sean dígitos
        for (int i = 1; i < strlen(buffer); i++){
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    } else {
        // Si no hay "-" en el primer carácter, verifico que todos los caracteres sean difitos
        for (int i = 0; i < strlen(buffer); i++){
            if (!isdigit(buffer[i])){
                return false;
            }
        }
    }
    return true;   
}


int main(){
    char numero[MAX];
    int Max_valor = 99999999;
    int aux;
    bool negativo = false;
    printf("Ingrese un numero entero de 8 digitos para colocar los puntos de los miles: ");
    fgets(numero,MAX,stdin);
    while (validacion(numero, Max_valor) == false){
        printf("El dato ingresado es invalido, reingrese el numero: ");
        fgets(numero,MAX,stdin);
    }
    char numeroPunto[MAX];
    memset(numeroPunto,0,MAX);
    aux = atoi(numero);
    sprintf(numero,"%d",aux);
    if (atoi(numero) < 1000 && atoi(numero) > 0){
        printf("%s", numero);
    } else {
        if (atoi(numero) < 0){
            negatividad(numero);
            negativo = true;
        }
        invertirCadena(numero);
        ponerPunto(numero,numeroPunto,0,0);
        invertirCadena(numeroPunto);
        if(negativo==false){
            printf("%s", numeroPunto);
        }
        else{
            printf("-%s", numeroPunto);
        }
    }
    return 0;
}
