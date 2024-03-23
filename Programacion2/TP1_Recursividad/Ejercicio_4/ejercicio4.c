#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <string.h>
#include "ejercicio4.h"


char buffer[100];
int ref_negativo = 0;
float limite_decimal = 0.0;
int m,n;
float resul = 0;
int Max_valor = 43325;

int main(){
    printf("Ingrese un DIVIDENDO en el intervalo de (-43325,43325) sin incluir: ");
    fgets(buffer,100,stdin);
    while (validacion(buffer,Max_valor,1) == false){
        printf("El dato ingresado es invalido, reingrese el DIVIDENDO: ");
        fgets(buffer,100,stdin);
    }
    m = atoi(buffer);
    printf("Ingrese un DIVISOR en el intervalo de (-43325,43325) sin incluir: ");
    fflush(stdin);
    fgets(buffer,100,stdin);
    while (validacion(buffer,Max_valor,2) == false){
        printf("El dato ingresado es invalido, reingrese el DIVISOR: ");
        fgets(buffer,100,stdin);
    }
    n = atoi(buffer);
    if (n == 1 ){
        printf("El resultado de dividir %d por %d es : %d.0000",m,n,m);
    }
    else if (n == -1){
        printf("El resultado de dividir %d por %d es : %d.0000",m,n,-m);
    }
    else{
        ref_negativo = negativo(&m,&n,ref_negativo);  // transformo los negativos en positivos y guardo cuales eran negativos en ref_negativo
        resul = division_recursiva(m,n,resul,limite_decimal);    // divido recursivamente
        mostrar_resultado(m,n,resul,ref_negativo);   //muestro el valor de m y n con el resultado de su division              
    }
    return 0;
}
