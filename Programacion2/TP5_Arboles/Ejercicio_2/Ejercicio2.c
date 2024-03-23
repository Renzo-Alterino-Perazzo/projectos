#include "nodo.h"
#include "tipo_elemento.h"
#include "arbol-binario.h"
#include "validaciones.h"
#include "listas.h"
#include <stdbool.h>
#include <string.h>

// Dado un árbol binario no vacío determinar:
//  a. Retornar una lista con todos los nodos terminales u hojas.
//  b. Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
//  c. Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
//  d. Determinar la complejidad algorítmica de los puntos “a”, “b”, “c”. 


static const int TAMANIO_MAXIMO = 100;

Lista hojas_arbol(Lista L,NodoArbol N){ // funcion para recorrer el arbol y encontrar las hojas
    TipoElemento elem;
    if (N == NULL) {
    }
    else {
        // averigua si es un hoja
        if ((n_hijoizquierdo(N) == NULL) && (n_hijoderecho(N) == NULL)) {
            elem = n_recuperar(N);
            l_agregar(L,elem);
        }
        // Llamo para el recorrido
        hojas_arbol(L,n_hijoizquierdo(N));
        hojas_arbol(L,n_hijoderecho(N));
    }
    return L;
}

Lista hojas(ArbolBinario a){ // funcion que prepara las listas y llama a la funcion recursiva para encontrar las hojas
    Lista L = l_crear();
    Lista resul = l_crear();
    resul = hojas_arbol(L,a_raiz(a));
    return resul;
}

Lista nodos_interiores_arbol(Lista L,NodoArbol N,bool es_raiz){ // funcion para recorrer el arbol y encontrar los nodos interiores del arbol
    TipoElemento elem;
    if (N == NULL) {
    }
    else {
        // averigua si es un nodo interno
        if ( ( (n_hijoizquierdo(N) != NULL) || (n_hijoderecho(N) != NULL) ) && (es_raiz == false) ) {
            elem = n_recuperar(N);
            l_agregar(L,elem);
        }
        es_raiz = false;
        // Llamo para el recorrido
        nodos_interiores_arbol(L,n_hijoizquierdo(N),es_raiz);
        nodos_interiores_arbol(L,n_hijoderecho(N),es_raiz);
    }
    return L;
}

Lista nodos_interiores(ArbolBinario a){ // funcion que prepara las listas y llama a la funcion recursiva para encontrar los nodos interiores del arbol
    Lista L = l_crear();
    Lista resul = l_crear();
    bool es_raiz = true;
    resul = nodos_interiores_arbol(L,a_raiz(a),es_raiz);
    return resul;
}

Lista ocurrencias_arbol(Lista L,NodoArbol N,int clave){ //funcion para recorrer el arbol y encontrar los nodos con la clave dada
    TipoElemento elem;
    NodoArbol nodo;
    if (N == NULL) {
        return L;
    }
    else {
        // verifica si la clave es igual
        if ((N->datos->clave == clave)) {
            elem = te_crear_con_valor(0,N);
            l_agregar(L,elem);
        }
        // Llamo para el recorrido
        ocurrencias_arbol(L,n_hijoizquierdo(N),clave);
        ocurrencias_arbol(L,n_hijoderecho(N),clave);
    }
    return L;    
}

Lista ocurrencias (ArbolBinario a,int clave){ // funcion que prepara las listas y llama a la funcion recursiva para encontrar los nodos con la clave dada
    Lista L = l_crear();
    Lista resul = l_crear();
    resul = ocurrencias_arbol(L,a_raiz(a),clave);
    return resul;    
}

void mostrar_claves_nodos(Lista resul_3){ // funcion para verificar que los punteros de los nodos guardados contienen la clave expecificada
    TipoElemento elem;
    NodoArbol nodo;
    if (l_es_vacia(resul_3) == true){
        printf("No se encontro ninguna ocurrencia en el arbol\n");
    }else{
        for (int i = 1;i <= l_longitud(resul_3);i++){
            elem = l_recuperar(resul_3,i);
            nodo = (NodoArbol)elem->valor;
            printf("clave del nodo %d en la lista: %d\n",i,nodo->datos->clave);
        }
    }
}


void cargar_arbol(ArbolBinario A,NodoArbol N, int sa){ // funcion para cargar los nodos al arbol
    char auxiliar[100];
    TipoElemento elem;
    NodoArbol nodo;
    int clave;
    if (a_es_lleno(A) == false){
        printf("ingrese la clave o un . para NULL: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while (validacion_arboles(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999){
            printf("Error. Reingrese la clave del nodo a cargar: ");
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        if (auxiliar[0] == '.' && strlen(auxiliar) == 1){ // si es un . no hace nada
        }else{ // sino carga el nodo al hijo correspondiente o a la raiz
            clave = atoi(auxiliar);
            elem = te_crear(clave);
            if (sa == -1){
                nodo = a_conectar_hi(A,N,elem);
            }
            else if (sa == 1){
                nodo = a_conectar_hd(A,N,elem);
            } else {
                nodo = a_establecer_raiz(A,elem);
            }
            cargar_arbol(A,nodo,-1);
            cargar_arbol(A,nodo,1);
        }
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
    char auxiliar[100];
    int clave_buscar;
    ArbolBinario a = a_crear();
    NodoArbol N;
    cargar_arbol(a,N,0);
    printf("\nArbol mostrado en pre_orden : \n");
    pre_orden(a_raiz(a));
    Lista resul = l_crear();
    Lista resul_2 = l_crear();
    Lista resul_3 = l_crear();
    resul = hojas(a);
    printf("\nLista con las hojas del arbol: \n");
    l_mostrarLista(resul);
    resul_2 = nodos_interiores(a);
    printf("\nLista con los nodos interiores del arbol: \n");
    l_mostrarLista(resul_2);
    printf("\nElija la clave con la que desea buscar todas sus ocurrencias: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999){
        printf("Error. Reingrese la clave a buscar: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    clave_buscar = atoi(auxiliar);
    resul_3 = ocurrencias (a,clave_buscar);
    mostrar_claves_nodos(resul_3);
    printf("\n\n la complejidad algoritmica de los ejercicios es O(n), donde n es la cantidad de nodos del arbol");
}
