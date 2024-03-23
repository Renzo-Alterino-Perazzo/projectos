#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "arbol-binario.h"
#include "arbol-avl.h"

#define MAX 100

bool esEntero(char * cadena){

    int longitud=strlen(cadena);
    int puntos=0;
    int i=0;

    if (cadena[0]=='\0'){
        return false;
    }

    if (cadena[0]=='-'){
        i=1;
    }

    for (i; i<longitud; i++){
        if (puntos==0){
            if ((cadena[i]>57 || cadena[i]<48) && cadena[i]!=46){
                return false;
            }
            else if (cadena[i]==46){
                if (cadena[i+1]=='\0'){
                    return false;
                }
                else {
                    puntos=1;
                }    
            }
        }
        else if (puntos==1){
            if (cadena[i]!=48){
                return false;
            }
        }
    }

    return true;
}

int altura(NodoArbol n1, int *a, int c){
    if (n1==NULL){
        if (c>*a){
            *a=c;            
        }
    }
    else {
        altura(n_hijoizquierdo(n1), a, c+1);
        altura(n_hijoderecho(n1), a, c+1);
    }
}

void cargaArbolPreOrden(ArbolBinario ar, NodoArbol n1, int valores[], int contador){

    int valido=0;
    int i;
    char claveC[MAX];

    TipoElemento x=n_recuperar(n1);
    TipoElemento t=te_crear(0);
    NodoArbol n2=n_crear(0);

    printf("ingrese el hijo izquierdo de %d ( . para nulo):", x->clave);

    while (valido==0){

        valido=1;

        fflush(stdin);
        fgets(claveC, MAX, stdin);
        if (claveC[strlen(claveC)-1]=='\n'){
            claveC[strlen(claveC)-1]='\0';
        }

        if (claveC[0]=='.'){
            if (claveC[1]!='\0'){
                valido=0;
            }    
        }
        else if (!esEntero(claveC) || atoi(claveC) > 99999999 || atoi(claveC) < -99999999){
                valido=0;
        }

        for (i=0; i<contador; i++){
            if (atoi(claveC)==valores[i]){
                valido=0;
            }
        }

        if (valido==0){
            printf("Error. ingrese el hijo izquierdo de %d ( . para nulo):", x->clave);
        }
    }

    if (claveC[0]!='.'){
        t=te_crear(atoi(claveC));
        n2=a_conectar_hi(ar, n1, t);
        valores[contador]=atoi(claveC);
        contador++;
        cargaArbolPreOrden(ar, n2, valores, contador);
    }

    valido=0;

    printf("ingrese el hijo derecho de %d ( . para nulo):", x->clave);

    while (valido==0){

        valido=1;

        fflush(stdin);
        fgets(claveC, MAX, stdin);
        if (claveC[strlen(claveC)-1]=='\n'){
            claveC[strlen(claveC)-1]='\0';
        }

        if (claveC[0]=='.'){
            if (claveC[1]!='\0'){
                valido=0;
            }    
        }
        else if (!esEntero(claveC) || atoi(claveC) > 99999999 || atoi(claveC) < -99999999){
                valido=0;
        }

        for (i=0; i<contador; i++){
            if (atoi(claveC)==valores[i]){
                valido=0;
            }
        }

        if (valido==0){
            printf("Error. ingrese el hijo derecho de %d ( . para nulo):", x->clave);
        }
    }

    if (claveC[0]!='.'){
        t=te_crear(atoi(claveC));
        n2=a_conectar_hd(ar, n1, t);
        valores[contador]=atoi(claveC);
        contador++;
        cargaArbolPreOrden(ar, n2, valores, contador);
    }
}

void mostrarArbol(NodoArbol na){
    TipoElemento x=te_crear(0);
    if (na==NULL){
        printf(".");
    }
    else {
        x=n_recuperar(na);
        printf(" %d ", x->clave);
        mostrarArbol(n_hijoizquierdo(na));
        mostrarArbol(n_hijoderecho(na));
    }
}

void crearAvl(ArbolBinario ar, NodoArbol n1, ArbolAVL arA, int flag){   

    TipoElemento x=n_recuperar(n1);

    if (flag==0){
        flag=1;
        if (n1->hi!=NULL){
            crearAvl(ar, n_hijoizquierdo(n1), arA, flag);
        }
        if (n1->hd!=NULL){
            crearAvl(ar, n_hijoderecho(n1), arA, flag);
        }
    }

    else{
        avl_insertar(arA, x);
        if (n1->hi!=NULL){
            crearAvl(ar, n_hijoizquierdo(n1), arA, flag);
        }
        if (n1->hd!=NULL){
            crearAvl(ar, n_hijoderecho(n1), arA, flag);
        }
    }
}

void main(){

    system("cls");

    int valores[MAX];    
    char clave[MAX];
    int alt=0;
    int altA=0;

    ArbolBinario ar=a_crear();
    NodoArbol padre;

    int valido=0;

    printf("Introduzca la raiz (debe ser un numero entero):");

    while (valido==0){

        valido=1;

        fflush(stdin);
        fgets(clave, MAX, stdin);
        if (clave[strlen(clave)-1]=='\n'){
            clave[strlen(clave)-1]='\0';
        }

        if (!esEntero(clave)|| atoi(clave) > 99999999 || atoi(clave) < -99999999){
            valido=0;
        }

        if (valido==0){
            printf("Error. Introduzca la raiz (debe ser un numero entero):");
        }
    }

    TipoElemento t1=te_crear(atoi(clave)); 
    NodoArbol n1=a_establecer_raiz(ar, t1);
    NodoArbol n2=n_crear(t1);
    ArbolAVL arA=avl_crear();
    arA->raiz=n2;
    valores[0]=atoi(clave); 

    cargaArbolPreOrden(ar, n1, valores, 1);

    altura(a_raiz(ar), &alt, 0);
    printf("\n\nArbol binario:");
    mostrarArbol(n1);
    printf("\nAltura: %d", alt);

    crearAvl(ar, n1, arA, 0);

    altura(avl_raiz(arA), &altA, 0);
    printf("\n\nArbol AVL:");
    mostrarArbol(avl_raiz(arA));
    printf("\nAltura: %d", altA);

    printf("\n\nLa complejidad algoritmica de la solucion es de orden linel O(n)");

}
