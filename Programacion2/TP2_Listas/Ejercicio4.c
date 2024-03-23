#include "validaciones.h"
#include "tipo_elemento.h"
#include "listas.h"
#include <stdlib.h>
#include <stdio.h>

void llenar_listas(Lista L1,Lista L2,int cant_elementos){
    int clave;
    char auxiliar[100];
    printf("(Los espacios seran borrados)\n(Claves acotadas a 8 digitos)\n");
    for (int i = 1;i <= cant_elementos;i++){
        printf("ingrese la clave de la posicion %d de la Lista 1: ",i);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while ((validacion(auxiliar) == false) || (atoi(auxiliar) > 99999999) || (atoi(auxiliar) < -99999999)){
            printf("Error. Reingrese la clave de la posicion %d de la lista 1: ",i);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        clave = atoi(auxiliar);
        l_agregar(L1,te_crear(clave));
    }
    printf("Lista 1 llena. Ahora ingrese los datos de la Lista 2\n");
    for (int i = 1;i <= cant_elementos;i++){
        printf("ingrese la clave de la posicion %d de la Lista 2: ",i);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while ((validacion(auxiliar) == false) || (atoi(auxiliar) > 99999999) || (atoi(auxiliar) < -99999999)){
            printf("Error. Reingrese la clave de la posicion %d de la lista 2: ",i);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        clave = atoi(auxiliar);
        l_agregar(L2,te_crear(clave));
    }
}


void Comparar_Listas(Lista L1, Lista L2){
    int mayores_L1 = 0;
    int mayores_L2 = 0;
    int longitud;
    TipoElemento elemento_L1;
    TipoElemento elemento_L2;
    longitud = l_longitud(L1);
    for (int i=1; i <= l_longitud(L1);i++){
        elemento_L1 = l_recuperar(L1, i);
        elemento_L2 = l_recuperar(L2, i);
        if (elemento_L1->clave > elemento_L2->clave){
            mayores_L1++;
        }
        else if (elemento_L1->clave < elemento_L2->clave){
            mayores_L2++;
        }
    }
    if (mayores_L1 > mayores_L2){
        printf("La lista 1 es mayor a la lista 2");
    }
    else if (mayores_L1 < mayores_L2){
        printf("La lista 1 es menor a la lista 2");
    }
    else{
        printf("La lista 1 es igual a la lista 2");
    }
}



int main(){
    int TAMANIO_MAXIMO = 100;
    char auxiliar[100];
    Lista L1 = l_crear();
    Lista L2 = l_crear();
    printf("(los espacios seran borrados)\nIngrese la cantidad de elementos de ambas Listas: ");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) >= TAMANIO_MAXIMO){
        printf("Error. Elija un rango de numeros (0 - %d) para crear las listas: \n", TAMANIO_MAXIMO-1);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    int cant_elementos = atoi(auxiliar);
    if (cant_elementos == 0){
        printf("la listas estan vacias por lo tanto:\n");
        printf("La lista 1 es igual a la lista 2");
    }else{
    llenar_listas(L1, L2, cant_elementos);
    l_mostrarLista(L1);
    l_mostrarLista(L2);
    Comparar_Listas(L1, L2);
    }
    printf("\nLa complejidad algortimica de la solucion es lineal O(n) donde n es el tamanio de la listas");
}
