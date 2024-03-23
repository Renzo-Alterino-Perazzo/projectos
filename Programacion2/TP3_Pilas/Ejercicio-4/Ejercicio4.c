#include <stdlib.h>
#include <stdio.h>
#include "pilas.h"
#include "validaciones.h"
#include <stdbool.h>
#include <string.h>


char *convertir_decimal(int decimal,int base){
    Pila p1 = p_crear();
    TipoElemento elemento;
    int resto,i;
    bool negativo = false;
    char letra;
    char *respuesta = (char *) malloc(100 * sizeof(char));
    if (decimal == 0){
        respuesta[0] = '0';
        respuesta[1] = '\0';
        return respuesta;
    }
    if (decimal < 0){  // si el decimal es negativo, convierto a positivo y cambio el bool negativo por true para el final
        negativo = true;
        decimal = decimal * -1;
    }
    for (i = decimal;i != 0;i = i / base){    // hago el modulo del decimal por la base hasta que el decimal sea igual a 0
        resto = i % base;
        elemento = te_crear(resto);
        p_apilar(p1,elemento);
    }
    p_mostrar(p1);
    int j = 0;    // creo la varaible j para ir metiendo en orden las letras en el chat respuesta
    while (p_es_vacia(p1) == false){    //creo el char respuesta con los numeros en la pila, convirtiendo a letra los numeros iguales o mayores a 10
        elemento = p_desapilar(p1);
        if (elemento->clave == 10){
            letra = 'A';
            respuesta[j++] = letra;
        }
        else if (elemento->clave == 11){
            letra = 'B';
            respuesta[j++] = letra;
        }
        else if (elemento->clave == 12){
            letra = 'C';
            respuesta[j++] = letra;
        }
        else if (elemento->clave == 13){
            letra = 'D';
            respuesta[j++] = letra;
        }
        else if (elemento->clave == 14){
            letra = 'E';
            respuesta[j++] = letra;
        }
        else if (elemento->clave == 15){
            letra = 'F';
            respuesta[j++] = letra;;
        }else{
            letra = '0' + elemento->clave;
            respuesta[j++] = letra;
        }
    }
    respuesta[j] = '\0';
    if (negativo == true){   // si es negativa, creo una cadena,le agrego el guion y luego le agrego la respuesta
        char* respuesta_negativa = (char*)malloc(strlen(respuesta) + 2);
        char guion[] = "-";
        strcpy(respuesta_negativa, guion);
        strcat(respuesta_negativa,respuesta);
        return respuesta_negativa;
    }else{
        return respuesta;
    }
}


int main(){
    printf("(Los espacios seran borrados)\n(claves limitadas a 8 digitos)\n\n");
    char auxiliar[100];
    char respuesta[100];
    int decimal,base;
    bool negativo = false;
    printf("ingrese el decimal que desea convertir: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) > 99999999){
        printf("Error. Reingrese el decimal:");
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    decimal = atoi(auxiliar);
    printf("Elija una base (2,16) a la que desea convertir el decimal: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 2 || atoi(auxiliar) > 16){
        printf("Error. Reingrese la base a la que desea convertir(2,16): ");
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    base = atoi(auxiliar);
    strcpy(respuesta,convertir_decimal(decimal,base));
    printf ("Decimal convertido : %s",respuesta);
}
