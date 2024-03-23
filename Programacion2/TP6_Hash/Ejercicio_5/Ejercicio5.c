#include "tabla_hash.h"
#include "arbol-avl.h"
#include "listas.h"
#include "validaciones.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <math.h>
#include <time.h>

static const int MAXSIZE = 2000;
static const int NRO_PRIMO = 1999;

/*Realizar una comparación de los tiempos de accesos a las claves entre un árbol AVL y
una Tabla Hash. El operador debe poder indicarle cuantas claves se deben generar
(entre 1 y 2000), cuantas repeticiones se realizaran y cuál es el rango de las claves a
generar. Luego se tomarán claves al azar dentro del mismo rango y se buscaran en
ambas estructuras. El proceso se repetirá “n” veces (repeticiones a ingresar por el
operador). Documentar la conclusión final respecto a los tiempos de accesos de
ambas estructuras.*/

void calcularTiempos(int rangoDesde, int rangoHasta, TablaHash tablaHash, ArbolAVL arbolAVL, int repeticiones){
    int clave;
    long segundos, microsegundos;
    double tiempoTotalHash, tiempoTotalAVL;
    struct timeval comienzo;
    struct timeval fin;

    for (int j = 1; j < repeticiones + 1; j++){
        printf("\nRepeticion %d. Calculo de tiempos con claves: ", j);
        for (int i = 1; i < 6; i++){
            clave = (rand() % (rangoHasta - rangoDesde + 1)) + rangoDesde;
        
            if (i == 5){
                printf("%d.", clave);
            } else {
                printf("%d, ", clave);
            }

            gettimeofday(&comienzo, 0);
            th_recuperar(tablaHash, clave);
            gettimeofday(&fin, 0);
            segundos = fin.tv_sec - comienzo.tv_sec;
            microsegundos = fin.tv_usec - comienzo.tv_usec;
            tiempoTotalHash += segundos + microsegundos*1e-6;

            gettimeofday(&comienzo, 0);
            avl_buscar(arbolAVL, clave);
            gettimeofday(&fin, 0);
            segundos = fin.tv_sec - comienzo.tv_sec;
            microsegundos = fin.tv_usec - comienzo.tv_usec;
            tiempoTotalAVL += segundos + microsegundos*1e-6;
        }
    }

    printf("\nTiempo de busqueda total en hash: %.5f segundos.", tiempoTotalHash);
    printf("\nTiempo de busqueda total en AVL: %.5f segundos.\n", tiempoTotalAVL);
}

bool esPrimo(int numero){
    if (numero == 1){
        return true;
    }
    double raiz = sqrt(numero);
    for (int i = 2; i <= raiz; i++){
        if (numero % i == 0){
            return false;
        }
    }
    return true;
}

int tamanoHash(int cantidadClaves){
    int tamano = cantidadClaves;
    while(esPrimo(tamano) == false){
        tamano--;
    }
    return tamano;
}

int funcionHashModulo(int clave){
    return (clave % NRO_PRIMO);
}

int main(){
    char buffer[20];

    printf("Ingrese la cantidad (1 - 2000) de claves a generar: ");
    fflush(stdin);
    fgets(buffer, 20, stdin);
    borrarEspacios(buffer);
    while(validacion(buffer) == false || atoi(buffer) < 1 || atoi(buffer) > 2000){
        if (atoi(buffer) < 1 || atoi(buffer) > 2000){
            printf("\nError. La cantidad ingresada no se encuentra en el rango pedido.");
        } else {
            printf("\nError. Ingreso invalido.");
        }
        printf("\nIngrese la cantidad (1 - 2000) de claves a generar:  ");
        fflush(stdin);
        fgets(buffer, 20, stdin);
        borrarEspacios(buffer);
    }

    int cantidadClaves = atoi(buffer);

    printf("\nIngrese el rango desde el cual se generaran claves (hasta 8 digitos): ");
    fflush(stdin);
    fgets(buffer, 20, stdin);
    borrarEspacios(buffer);
    while(validacion(buffer) == false || atoi(buffer) < -99999999){
        if (atoi(buffer) < -99999999){
            printf("\nError. El dato ingresado tiene mas de 8 digitos.");
        } else {
            printf("\nError. Ingreso invalido.");
        }
        printf("\nIngrese el rango desde el cual se generaran claves (hasta 8 digitos): ");
        fflush(stdin);
        fgets(buffer, 20, stdin);
        borrarEspacios(buffer);
    }

    int rangoDesde = atoi(buffer);

    printf("\nIngrese el rango hasta el cual se generaran claves (hasta 8 digitos y debe ser mayor o igual que %d): ", rangoDesde);
    fflush(stdin);
    fgets(buffer, 20, stdin);
    borrarEspacios(buffer);
    while(validacion(buffer) == false || atoi(buffer) > 99999999 || atoi(buffer) < rangoDesde){
        if (atoi(buffer) < -99999999){
            printf("\nError. El dato ingresado tiene mas de 8 digitos.");
        } else if (atoi(buffer) < rangoDesde){
            printf("\nError. El dato ingresado es menor que %d", rangoDesde);
        } else {
            printf("\nError. Ingreso invalido.");
        }
        printf("\nIngrese el rango hasta el cual se generaran claves (hasta 8 digitos y debe ser mayor o igual que %d): ", rangoDesde);
        fflush(stdin);
        fgets(buffer, 20, stdin);
        borrarEspacios(buffer);
    }
    
    int rangoHasta = atoi(buffer);

    printf("\nIngrese la cantidad de repeticiones que se realizaran (hasta 100): ");
    fflush(stdin);
    fgets(buffer, 20, stdin);
    borrarEspacios(buffer);
    while(validacion(buffer) == false || atoi(buffer) < 1 || atoi(buffer) > 100){
        if (atoi(buffer) < 1 || atoi(buffer) > 100){
            printf("\nError. La cantidad ingresada no se encuentra en el rango pedido.");
        } else {
            printf("\nError. Ingreso invalido.");
        }
        printf("\nIngrese la cantidad de repeticiones que se realizaran (hasta 100): ");
        fflush(stdin);
        fgets(buffer, 20, stdin);
        borrarEspacios(buffer);
    }

    int repeticiones = atoi(buffer);

    int tamano = tamanoHash(cantidadClaves);
    TablaHash tablaHash = th_crear(tamano, *funcionHashModulo);

    ArbolAVL arbolAVL = avl_crear();

    time_t tiempo;
    srand((unsigned) time(&tiempo));

    // Genero las claves
    printf("\nClaves generadas: ");
    TipoElemento elemento;
    for (int i = 1; i < cantidadClaves+1; i++){
        elemento = te_crear((rand() % (rangoHasta - rangoDesde + 1)) + rangoDesde);
        th_insertar(tablaHash, elemento);
        avl_insertar(arbolAVL, elemento);
        if (i == cantidadClaves){
            printf("%d.\n", elemento->clave);
        } else {
            printf("%d, ", elemento->clave);
        }
    }
    calcularTiempos(rangoDesde, rangoHasta, tablaHash, arbolAVL, repeticiones);
    
    printf("\nConclusion: para poca cantidad de claves, los arboles AVL son mas rapidos, mientras que para cantidades muy grandes de claves, las tablas hash son mas rapidas.\n");
}
