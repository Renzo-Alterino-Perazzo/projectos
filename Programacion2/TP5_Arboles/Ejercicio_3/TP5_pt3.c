#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#include "arbol-binario.h"

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

void mostrarNivel(NodoArbol n1, int nivel, int contador);

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
        else if (!esEntero(claveC)){
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
        else if (!esEntero(claveC)){
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

void buscarClave(ArbolBinario ar, NodoArbol n1, int y, int n, int nivel, NodoArbol padre, int *encontrado){

    TipoElemento x=n_recuperar(n1);
    NodoArbol n2=NULL;
    NodoArbol n3=NULL;

    if (x->clave==y){
        *encontrado=1;
        int alt=0;
        nivel=n;

        printf("\n");

        if (x->clave==n_recuperar(a_raiz(ar))->clave){
            printf("Padre: nulo\n");
        }
        else {
            printf("Padre: %d\n", n_recuperar(padre)->clave);
        }
        
        n2=n_hijoizquierdo(n1);
        if (n2!=NULL){
            printf("Hijo izquierdo: %d\n", n_recuperar(n2)->clave);
        }
        else {
            printf("Hijo izquierdo: nulo\n");
        }

        n2=n_hijoderecho(n1);
        if (n2!=NULL){
            printf("Hijo derecho: %d\n", n_recuperar(n2)->clave);
        }
        else {
            printf("Hijo derecho: nulo\n");
        }

        n2=n_hijoizquierdo(padre);
        n3=n_hijoderecho(padre);

        if (n2==n1 && n3!=NULL){
            printf("hermano: %d\n", n_recuperar(n3)->clave);
        }
        else if(n3==n1 && n2!=NULL){
            printf("hermano: %d\n", n_recuperar(n2)->clave);
        }
        else {
            printf("hermano: nulo\n");
        }

        printf("Nivel: %d\n", nivel);
        altura(n1, &alt, 0);

        printf("Altura del subarbol: %d\n", alt);

        n1=a_raiz(ar);
        printf("Nodos del nivel %d: ", nivel);
        mostrarNivel(n1, nivel, 0);
    }

    else {

        if (n1->hi!=NULL){
            n2=n_hijoizquierdo(n1);
            n=n+1;
            padre=n1;
            buscarClave(ar, n2, y, n, nivel, padre, encontrado);
            n--;
        }

        if (n1->hd!=NULL){
            n2=n_hijoderecho(n1);
            n=n+1;
            padre=n1;
            buscarClave(ar, n2, y, n, nivel, padre, encontrado);
            n--;
        }
    }

}

void mostrarNivel(NodoArbol n1, int nivel, int contador){

    TipoElemento x=n_recuperar(n1);

    if (contador==nivel){
        printf("%d ", x->clave);
    }

    if (n1->hi!=NULL && contador<nivel){
        contador++;
        mostrarNivel(n_hijoizquierdo(n1), nivel, contador);
        contador--;
    }

    if (n1->hd!=NULL && contador<nivel){
        contador++;
        mostrarNivel(n_hijoderecho(n1), nivel, contador);
        contador--;
    }
}

void main(){

    system("cls");

    int valores[MAX];    
    char clave[MAX];
    int y;
    int encontrado=0;
    ArbolBinario ar=a_crear();
    NodoArbol padre;

    int valido=0;

    printf("Carga Pre-orden\n");
    printf("Introduzca la raiz (debe ser un numero entero):");

    while (valido==0){

        valido=1;
        
        fflush(stdin);
        fgets(clave, MAX, stdin);
        if (clave[strlen(clave)-1]=='\n'){
            clave[strlen(clave)-1]='\0';
        }
        
        if (!esEntero(clave)){
            valido=0;
        }
        
        if (valido==0){
            printf("Error. Introduzca la raiz (debe ser un numero entero):");
        }
    }

    TipoElemento t1=te_crear(atoi(clave)); 
    NodoArbol n1=a_establecer_raiz(ar, t1);
    valores[0]=atoi(clave); 

    cargaArbolPreOrden(ar, n1, valores, 1);

    printf("\nArbol: ");
    mostrarArbol(n1);
    printf("\n");

    valido=0;

    printf("\nIntroduzca el nodo a buscar: ");

    while (valido==0){
        valido=1;
        fflush(stdin);
        fgets(clave, MAX, stdin);
        if (clave[strlen(clave)-1]=='\n'){
            clave[strlen(clave)-1]='\0';
        }
        if (!esEntero(clave)){
            valido=0;
        }
        if (valido==0){
            printf("Error. Introduzca el nodo a buscar:");
        }
    }

    y=atoi(clave);

    buscarClave(ar, n1, y, 0, 0, padre, &encontrado);

    if (encontrado==0){
        printf("\nNodo no encontrado\n");
    }
}
