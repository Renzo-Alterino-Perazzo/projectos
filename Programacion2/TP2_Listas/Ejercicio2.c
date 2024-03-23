#include "validaciones.h"
#include "tipo_elemento.h"
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void cargarClavesRandom(Lista lista, int tamanioLista){
    int numeroRandom;
    int esNegativo;
    for (int i = 0; i < tamanioLista; i++){
        numeroRandom = (rand() % 50);
        esNegativo = (rand () % 2);
        if (esNegativo == 0){
            l_agregar(lista, te_crear(numeroRandom));
        } else {
            l_agregar(lista, te_crear(numeroRandom*-1));
        }
    }
}

TipoElemento menorPosicionOrdinal(Lista lista){
    TipoElemento menor = te_crear_con_valor((l_recuperar(lista, 1))->clave,1);
    TipoElemento elementoAComparar;
    int longitudLista = l_longitud(lista);
    for (int i = 1; i < longitudLista+1; i++){
        elementoAComparar = l_recuperar(lista, i);
        if (elementoAComparar->clave < menor->clave){
            menor = elementoAComparar;
            menor->valor = i;
        }
    }
    return menor;
}

TipoElemento maximoRepetido(Lista lista){
    TipoElemento mayor = te_crear(-1);
    TipoElemento elementoAComparar;
    int longitudLista = l_longitud(lista);
    for (int i = 1; i < longitudLista+1; i++){
        elementoAComparar = l_recuperar(lista, i);
        elementoAComparar->valor = 0;
        if (elementoAComparar->clave > mayor->clave){
            mayor = elementoAComparar;
        } else if (elementoAComparar->clave == mayor->clave){
            mayor->valor++;
        }
    }
    return mayor;
}

float promedioRecursivo(Lista lista, int posicion, float sumatoria){
    if (posicion < l_longitud(lista)+1){
        promedioRecursivo(lista, posicion+1, sumatoria += l_recuperar(lista, posicion)->clave);
    } else {
        return (sumatoria/l_longitud(lista));
    }
}

Lista multiploLista(Lista lista, int numero){
    int longitudLista = l_longitud(lista);
    Lista listaMultiplo = l_crear();
    TipoElemento elementoLista;
    for (int i = 1; i < longitudLista+1; i++ ){
        elementoLista = te_crear(((l_recuperar(lista, i))->clave));
        if (elementoLista->clave % numero == 0){
            l_agregar(listaMultiplo, elementoLista);
        }
    }
    return listaMultiplo;
}


int main(){

    int TAMANIO_MAXIMO = 100;

    // Seteo la semilla para rand()
    time_t tiempo;
    srand((unsigned) time(&tiempo));

    char auxiliar[100];

    // Pido la cantidad de elementos para la lista
    printf("Elija la cantidad de elementos (1 - %d) de la lista a crear: \n", TAMANIO_MAXIMO-1);
    fgets(auxiliar,100,stdin);
    fflush(stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 1 || atoi(auxiliar) >= TAMANIO_MAXIMO){
        printf("Error. Elija la cantidad de elementos (1 - %d) de la lista a crear: \n", TAMANIO_MAXIMO-1);
        fgets(auxiliar,100,stdin);
        fflush(stdin);
        borrarEspacios(auxiliar);
    }

    // Creo la lista, la cargo con elementos random y luego la muestro
    Lista lista = l_crear();
    int tamanioLista = atoi(auxiliar);
    cargarClavesRandom(lista, tamanioLista);
    l_mostrarLista(lista);

    TipoElemento menor = menorPosicionOrdinal(lista);
    printf("El menor elemento de la lista es %d cuya posicion ordinal es %d. \n", menor->clave, menor->valor);

    TipoElemento mayor = maximoRepetido(lista);
    printf("El mayor elemento de la lista es %d, y se repite %d veces. \n", mayor->clave, mayor->valor);

    printf("El promedio de los elementos de la lista es %f \n", promedioRecursivo(lista, 1, 0));

    printf("Elija un numero entero de hasta 8 cifras para buscar sus multiplos: \n");
    fgets(auxiliar,100,stdin);
    fflush(stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) > 99999999 || atoi(auxiliar) == 0){
        if (atoi(auxiliar) == 0){
            printf("El numero 0 no tiene multiplos. Por favor ingrese  numero entero de hasta 8 cifras. \n");
        } else {
            printf("El dato ingresado es incorrecto. Por favor ingrese un numero entero de hasta 8 cifras. \n");
        }
        fgets(auxiliar,100,stdin);
        fflush(stdin);
        borrarEspacios(auxiliar);
    }

    int numero = atoi(auxiliar);
    Lista listaMultiplo = multiploLista(lista, numero);
    if (l_es_vacia(listaMultiplo)){
        printf("La lista no contiene ningun multiplo de %d. \n", numero);
    } else {
        printf("Elementos de la lista que son multiplos de %d: \n", numero);
        l_mostrarLista(listaMultiplo);
    }
}
