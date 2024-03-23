#include "arbol-avl.h"
#include "arbol-binario-busqueda.h"
#include "nodo.h"
#include "tipo_elemento.h"
#include "validaciones.h"
#include <time.h>

// Dada una serie de números generados al azar, cargar la misma serie en un árbol
// binario de búsqueda y en un árbol binario balanceado “AVL”. Comparar la altura de
// ambos árboles. Repetir el proceso “n” veces. ¿Qué puede concluir al respecto?


void cargar_aleatorio(ArbolBinarioBusqueda arbol_bb, ArbolAVL arbol_avl,int cantidad,int rango_maximo){
    int clave_random;
    char auxiliar[100];
    TipoElemento elem;
    for (int i = 1; i <= cantidad;i++){
        clave_random = (rand() % rango_maximo) + 1;
        elem = te_crear(clave_random);
        avl_insertar(arbol_avl,elem);
        abb_insertar(arbol_bb,elem);
    }
}

void cargar_arboles(ArbolBinarioBusqueda arbol_bb, ArbolAVL arbol_avl,int cantidad){
    char auxiliar[100];
    int clave;
    TipoElemento elem;
    for (int i = 1; i <= cantidad; i++){
        printf("introdusca la clave del elemento %d del arbol: ",i);
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) >= 100){
            printf("Error. Reingrese la clave: ");
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        elem = te_crear(atoi(auxiliar));
        abb_insertar(arbol_bb,elem);
        avl_insertar(arbol_avl,elem);
    }
}

int calcular_altura_arbol(NodoArbol nodo){
    if (nodo == NULL) {
        return 0;
    } else {
        int alturaIzq = calcular_altura_arbol(n_hijoizquierdo(nodo));
        int alturaDer = calcular_altura_arbol(n_hijoderecho(nodo));
        
        // La altura del árbol es la máxima altura entre el subárbol izquierdo y derecho, más 1 por el nodo actual
        return (alturaIzq > alturaDer) ? alturaIzq + 1 : alturaDer + 1;
    }
}


void pre_orden(NodoArbol N){ // funcion para mostrar el arbol en pre_orden
    TipoElemento x;
    if (N == NULL) {
        printf(".");
    }
    else {
        x = n_recuperar(N);
        printf(" %d", x->clave);
        pre_orden(n_hijoizquierdo(N));
        pre_orden(n_hijoderecho(N));
    }
}

int main(){
    // seteo de semilla
    time_t tiempo;
    srand((unsigned) time(&tiempo));
    int cantidad,repeticiones,altura_bb,altura_avl,resul_altura_bb,resul_altura_avl, opcion, rango_maximo;
    int alt_min_bb = 1000;
    int alt_max_bb = 0;
    int alt_min_avl = 1000;
    int alt_max_avl = 0;
    int acumulador_bb = 0;
    int acumulador_avl = 0;
    float promedio_bb,promedio_avl;
    char auxiliar[100];
    printf("Eliga una opcion para el ingreso de claves: \n1 - aleatorio\n2 - Manual\n");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 1 || atoi(auxiliar) > 2){
        printf("Error. Ingrese 1 o 2: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    opcion = atoi(auxiliar);
    printf("\n(Cantidad de elementos limitadas a 100)\n");
    printf("(Cantidad de repeticiones limitadas a 200)\n(Valor maximo de las claves limitadas a 8 digitos)\n\n");
    printf("introdusca la cantidad de elementos que desea cargar en los arboles: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > 100){
        printf("Error. Reingrese la cantidad de elementos a cargar: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    cantidad = atoi(auxiliar);
    printf("Introdusca la cantidad de veces que desea realizar el proceso: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 1 || atoi(auxiliar) > 200){
        printf("Error. Reingrese la cantidad de elementos a cargar: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    repeticiones = atoi(auxiliar);
    if (opcion == 1){
        printf("\ningrese el valor maximo que pueden tomar las claves generadas: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) > 99999999){
            printf("Error. Reingrese el valor maximo : ");
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        rango_maximo = atoi(auxiliar);
    }
    for (int i = 1 ; i <= repeticiones ; i++){
        ArbolBinarioBusqueda arbol_bb = abb_crear();
        ArbolAVL arbol_avl = avl_crear();
        if (opcion == 1){
            cargar_aleatorio(arbol_bb,arbol_avl,cantidad,rango_maximo);
        }
        else {
            cargar_arboles(arbol_bb,arbol_avl,cantidad);
        }
        printf("\narbol abb: \n");
        pre_orden(abb_raiz(arbol_bb));
        printf("\narbol avl: \n");
        pre_orden(avl_raiz(arbol_avl));
        resul_altura_bb = calcular_altura_arbol(abb_raiz(arbol_bb));
        printf("\nla altura del arbol bb es: %d",resul_altura_bb);
        resul_altura_avl = calcular_altura_arbol(avl_raiz(arbol_avl));
        printf("\nla altura del arbol avl es: %d\n",resul_altura_avl);
        acumulador_bb = acumulador_bb + resul_altura_bb;
        acumulador_avl = acumulador_avl + resul_altura_avl;
        if (resul_altura_bb > alt_max_bb){
            alt_max_bb = resul_altura_bb;
        }
        if (resul_altura_bb < alt_min_bb){
            alt_min_bb = resul_altura_bb;
        }
        if (resul_altura_avl > alt_max_avl){
            alt_max_avl = resul_altura_avl;
        }
        if (resul_altura_avl < alt_min_avl){
            alt_min_avl = resul_altura_avl;
        }
    }
    promedio_bb = (acumulador_bb * 1.0) / (repeticiones * 1.0);
    promedio_avl = (acumulador_avl * 1.0) / (repeticiones * 1.0);
    printf("\nARBOLES BUSQUEDA BINARIO: \n");
    printf("\nLa Altura MINIMA de los arboles BB cargadados fue : %d",alt_min_bb);
    printf("\nLa Altura MAXIMA de los arboles BB cargadados fue : %d",alt_max_bb);
    printf("\nel promedio de alturas del arbol binario de busqueda es: %0.4f\n",promedio_bb);
    printf("\nARBOLES AVL: \n");
    printf("\nLa Altura MINIMA de los arboles AVL cargadados fue : %d",alt_min_avl);
    printf("\nLa Altura MAXIMA de los arboles AVL cargadados fue : %d",alt_max_avl);
    printf("\nel promedio de alturas del arbol binario avl es: %0.4f\n",promedio_avl);
    printf("\nEn conclusion, Los arboles binario de busqueda tienden a tener mayor altura que los avl al no estar balanceado\nTambien el avl facilita la busqueda de un elemento");
}
