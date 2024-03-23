#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "conjuntos.h"

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

void cargarConjunto(Conjunto A, int lon){

    int clave;
    char claveC[MAX];
    int i;
    int val=0;

    for (i=0; i<lon; i++){
        printf("Ingrese el elemento %d: ", i+1);

        while (val==0){
            val=1;

            fflush(stdin);
            fgets(claveC, MAX, stdin); 
            if (claveC[strlen(claveC)-1]=='\n'){
                (claveC[strlen(claveC)-1]='\0');
            }    

            if (!esEntero(claveC)){
                val=0;
            }   

            clave=atoi(claveC);

            if (val==0){
                system("cls");
                printf("ERROR. Ingrese el elemento %d: ", i+1);
            }
        }
        val=0;

        TipoElemento X=te_crear(clave);
        cto_agregar(A, X);
    }
}

bool pertenencia(Conjunto A, int num){

    int i;
    bool resu=false;
    TipoElemento X;

    for (i=0; i<cto_cantidad_elementos(A); i++){
        X=cto_recuperar(A, i+1);
        if (X->clave==num){
            resu=true;
            break;
        }
    }

    return resu;
}

Conjunto unionConjuntos(Conjunto A, Conjunto B){

    Conjunto resu=cto_crear();
    TipoElemento X;
    int i;

    for (i=0; i<cto_cantidad_elementos(A); i++){
        X=cto_recuperar(A, i+1);
        cto_agregar(resu, X);
    }

    for (i=0; i<cto_cantidad_elementos(B); i++){
        X=cto_recuperar(B, i+1);
        cto_agregar(resu, X);
    }    

    printf("\nResultado\n");
    if (cto_cantidad_elementos(resu)==0){
        printf("Conjunto vacio\n");
    }
    else{
        cto_mostrar(resu);
        return resu;        
    }

}

Conjunto interseccion(Conjunto A, Conjunto B){

    Conjunto resu=cto_crear();
    TipoElemento X;
    TipoElemento Y;
    int i;

    for (i=0; i<cto_cantidad_elementos(A); i++){
        X=cto_recuperar(A, i+1);
        if (pertenencia(B, X->clave)==true){
            cto_agregar(resu, X);
        }
    }

    printf("\nResultado\n");
    if (cto_cantidad_elementos(resu)==0){
        printf("Conjunto vacio\n");
    }
    else{
        cto_mostrar(resu);
        return resu;        
    }
}

Conjunto diferencia(Conjunto A, Conjunto B){

    Conjunto resu=cto_crear();
    TipoElemento X;
    TipoElemento Y;
    int i;

    for (i=0; i<cto_cantidad_elementos(A); i++){
        X=cto_recuperar(A, i+1);
        if (pertenencia(B, X->clave)==false){
            cto_agregar(resu, X);
        }
    }  

    printf("\nResultado\n");
    if (cto_cantidad_elementos(resu)==0){
        printf("Conjunto vacio\n");
    }
    else{
        cto_mostrar(resu);
        return resu;        
    }
}

void main(){

    system("cls");

    Conjunto A=cto_crear();
    Conjunto B=cto_crear();
    int lon;
    char lonC[MAX];
    int num;
    char numC[MAX];
    int op;
    char opC[MAX];
    int val=0;

    printf("Ingrese longitud del primer conjunto (0 a 100):");

    while (val==0){
        val=1;

        fflush(stdin);
        fgets(lonC, MAX, stdin); 
        if (lonC[strlen(lonC)-1]=='\n'){
            (lonC[strlen(lonC)-1]='\0');
        }    

        if (!esEntero(lonC)){
            val=0;
        }   

        lon=atoi(lonC);

        if (lon<0 || lon>100){
            val=0;
        }

        if (val==0){
            system("cls");
            printf("ERROR. Ingrese longitud del primer conjunto (0 a 100):");
        }
    }

    if (lon==0){
        printf("Conjunto A vacio\n");
    }
    
    else{
        printf("\nCarga conjunto A\n");
        cargarConjunto(A, lon);
    }

    printf("\nIngrese longitud del segundo conjunto (0 a 100):");

    val=0;
    while (val==0){
        val=1;

        fflush(stdin);
        fgets(lonC, MAX, stdin); 
        if (lonC[strlen(lonC)-1]=='\n'){
            (lonC[strlen(lonC)-1]='\0');
        }    

        if (!esEntero(lonC)){
            val=0;
        }   

        lon=atoi(lonC);

        if (lon<0 || lon>100){
            val=0;
        }

        if (val==0){
            system("cls");
            printf("ERROR. Ingrese longitud del segundo conjunto (0 a 100):");
        }
    }

    if (lon==0){
        printf("Conjunto B vacio\n");
    }
    
    else{
        printf("\nCarga conjunto B\n");
        cargarConjunto(B, lon);
        system("cls");
    }

    printf("Ingrese opcion\n\n");
    printf("1- mostrar conjuntos\n");
    printf("2- verificar pertenencia\n");
    printf("3- union\n");
    printf("4- interseccion\n");
    printf("5- diferencia\n");
    printf("0- terminar\n");
    printf("Opcion:");
    
    val=0;
    while (val==0){
        val=1;

        fflush(stdin);
        fgets(opC, MAX, stdin); 
        if (opC[strlen(opC)-1]=='\n'){
            (opC[strlen(opC)-1]='\0');
        }    

        if (!esEntero(opC)){
            val=0;
        }   

        op=atoi(opC);

        if (op<0 || op>5){
            val=0;
        }

        if (val==0){
            system("cls");
            printf("ERROR. Ingrese opcion\n\n");
            printf("1- mostrar conjuntos\n");
            printf("2- verificar pertenencia\n");
            printf("3- union\n");
            printf("4- interseccion\n");
            printf("5- diferencia\n");
            printf("0- terminar\n");
            printf("Opcion:");
        }
    }

    while (op!=0){
        system("cls");
        switch(op){
            case 1: system("cls");
                    printf("Conjunto A\n");
                    if (cto_cantidad_elementos(A)==0){
                        printf("Conjunto vacio\n");
                    }
                    else{
                        cto_mostrar(A);       
                    }
                    printf("\nConjunto B\n");
                    if (cto_cantidad_elementos(B)==0){
                        printf("Conjunto vacio\n");
                    }
                    else{
                        cto_mostrar(B);       
                    }
                    break;
            case 2: printf("Ingrese valor a verificar:");

                    val=0;
                    while (val==0){
                        val=1;

                        fflush(stdin);
                        fgets(numC, MAX, stdin); 
                        if (numC[strlen(numC)-1]=='\n'){
                            (numC[strlen(numC)-1]='\0');
                        }    

                        if (!esEntero(numC)){
                            val=0;
                        }   

                        if (val==0){
                            system("cls");
                            printf("ERROR. Ingrese valor a verificar:");
                        }

                        num=atoi(numC);
                    }                    

                    if (pertenencia(A, num)){
                        printf("\nEl valor pertenece al conjunto A\n");
                    }
                    else {printf("\nEl valor no pertenece al conjunto A\n");}
                    if (pertenencia(B, num)){
                        printf("\nEl valor pertenece al conjunto B\n");
                    }
                    else {printf("\nEl valor no pertenece al conjunto B\n");}                    
                    break;
            case 3: unionConjuntos(A, B);
                    break;
            case 4: interseccion(A, B);
                    break;
            case 5: printf("\nDiferencia entre A y B"); diferencia(A, B);
                    printf("\nDiferencia entre B y A"); diferencia(B, A);
                    break;
        }

        printf("\nIngrese opcion\n\n");
        printf("1- mostrar conjuntos\n");
        printf("2- verificar pertenencia\n");
        printf("3- union\n");
        printf("4- interseccion\n");
        printf("5- diferencia\n");
        printf("0- terminar\n");
        printf("Opcion:");
        
        val=0;
        while (val==0){
            val=1;

            fflush(stdin);
            fgets(opC, MAX, stdin); 
            if (opC[strlen(opC)-1]=='\n'){
                (opC[strlen(opC)-1]='\0');
            }    

            if (!esEntero(opC)){
                val=0;
            }   

            op=atoi(opC);

            if (op<0 || op>5){
                val=0;
            }

            if (val==0){
                system("cls");
                printf("ERROR. Ingrese opcion\n\n");
                printf("1- mostrar conjuntos\n");
                printf("2- verificar pertenencia\n");
                printf("3- union\n");
                printf("4- interseccion\n");
                printf("5- diferencia\n");
                printf("0- terminar\n");
                printf("Opcion:");
            }
        }
    }

    printf("\n\nFIN");
}

