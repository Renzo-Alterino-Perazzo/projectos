#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"tabla_hash.h"
#include<stdbool.h>

#define MAX 100

typedef struct{
    int legajo;
    char apellido[MAX];
    char nombres[MAX];
    char domiciolio[MAX];
    char telefono[MAX];
    int estado;
} t_alumno;

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

int conversor(int clave){
    return (clave%113);
}

void crearArchivo(FILE* f, TablaHash tabla, int* max){
    f=fopen("alumnosHash.dat", "wb");

    int val=0;
    int i=1;
    int pos;
    int legajo=1;
    char legajoC[MAX];
    t_alumno alu;
    t_alumno aux;
    TipoElemento x=te_crear(0);

    while (legajo!=0){
        system("cls"); printf("Ingrese legajo (0 para terminar):");

        while(val==0){
            val=1;
            fflush(stdin);
            fgets(legajoC, MAX, stdin);
            if (legajoC[strlen(legajoC)-1]=='\n'){
                legajoC[strlen(legajoC)-1]='\0';}
            
            if (!esEntero(legajoC)){
                val=0;
                system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");
            }

            legajo=atoi(legajoC);

            if (legajo>999999 || legajo<0){
                val=0;
                system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");           
            }
        }

        alu.legajo=legajo;
        
        if (legajo!=0){
            printf("Ingrese apellido:");
            fflush(stdin);
            fgets(alu.apellido, MAX, stdin);
            if (alu.apellido[strlen(alu.apellido)-1]=='\n'){
                alu.apellido[strlen(alu.apellido)-1]='\0';}
            
            printf("Ingrese nombres:");
            fflush(stdin);
            fgets(alu.nombres, MAX, stdin);
            if (alu.nombres[strlen(alu.nombres)-1]=='\n'){
                alu.nombres[strlen(alu.nombres)-1]='\0';}

            printf("ingrese domicilio:");
            fflush(stdin);
            fgets(alu.domiciolio, MAX, stdin);
            if (alu.domiciolio[strlen(alu.domiciolio)-1]=='\n'){
                alu.domiciolio[strlen(alu.domiciolio)-1]='\0';}

            printf("ingrese telefono:");
            fflush(stdin);
            fgets(alu.telefono, MAX, stdin);
            if (alu.telefono[strlen(alu.telefono)-1]=='\n'){
                alu.telefono[strlen(alu.telefono)-1]='\0';}

            alu.estado=1;

            x=te_crear_con_valor(legajo, (int*) i);
            th_insertar(tabla, x);
            *max=i;

            fseek(f, sizeof(t_alumno)*i, SEEK_SET);
            fwrite(&alu, sizeof(t_alumno), 1, f);
            i++;
        }
    }
    fclose(f);
}

void buscarPos(TablaHash tabla, FILE* f){

    int val=0;
    char legajoC[MAX];
    int legajo;
    t_alumno alu;
    TipoElemento x=te_crear(0);
    system("cls"); printf("Ingrese legajo:");

    while(val==0){
        val=1;
        fflush(stdin);
        fgets(legajoC, MAX, stdin);
        if (legajoC[strlen(legajoC)-1]=='\n'){
            legajoC[strlen(legajoC)-1]='\0';}
            
        if (!esEntero(legajoC)){
            val=0;
            system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");
        }

        legajo=atoi(legajoC);

        if (legajo>999999 || legajo<0){
            val=0;
            system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");           
        }
    }

    x=th_recuperar(tabla, legajo);

    if (x==NULL){
        printf("Legajo no encontrado\n\n");
        return;
    }

    printf("Posicion: %d\n\n", x->valor);
    return;
}

void modificar(FILE* f, int max){

    int val=0;
    int pos;
    char posC[MAX];
    int op;
    char opC[MAX];
    t_alumno alu;

    system("cls"); printf("Ingrese posicion a partir de 1:");

    while(val==0){
        val=1;
        fflush(stdin);
        fgets(posC, MAX, stdin);
        if (posC[strlen(posC)-1]=='\n'){
            posC[strlen(posC)-1]='\0';}
            
        if (!esEntero(posC)){
            val=0;
            system("cls"); printf("ERROR. Ingrese posicion a partir de 1:");
        }

        pos=atoi(posC);
    }

    if (pos>max){
        printf("Legajo no encontrado\n\n");
        return;
    }

    f=fopen("alumnosHash.dat", "r+b");

    fseek(f, sizeof(t_alumno)*pos, SEEK_SET);
    fread(&alu, sizeof(t_alumno), 1, f);


    if(alu.estado==0){
        printf("Legajo dado de baja\n\n");
        return;
    }

    system("cls"); printf("--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);

    printf("\nIngrese campo a modificar:");
    printf("\n1 apellido");
    printf("\n2 nombres");
    printf("\n3 domicilio");
    printf("\n4 telefono");
    printf("\n5 dar de baja");
    printf("\n0 salir\nOpcion:");

    val=0;
    while(val==0){
        val=1;
        fflush(stdin);
        fgets(opC, MAX, stdin);
        if (opC[strlen(opC)-1]=='\n'){
            opC[strlen(opC)-1]='\0';}
        
        if (!esEntero(opC)){
            val=0;
            system("cls"); printf("--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);

            printf("\nERROR. Ingrese campo a modificar:");
            printf("\n1 apellido");
            printf("\n2 nombres");
            printf("\n3 domicilio");
            printf("\n4 telefono");
            printf("\n5 dar de baja");
            printf("\n0 salir\nOpcion:");
        }

        op=atoi(opC);

        if (op>5 || op<0){
            val=0;
            system("cls"); printf("--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);

            printf("\nERROR. Ingrese campo a modificar:");
            printf("\n1 apellido");
            printf("\n2 nombres");
            printf("\n3 domicilio");
            printf("\n4 telefono");
            printf("\n5 dar de baja");
            printf("\n0 salir\nOpcion:");          
        }
    }

    while(op!=0){
        switch(op){
            case 1:system("cls"); printf("Ingrese nuevo apellido:");
                    fflush(stdin);
                    fgets(alu.apellido, MAX, stdin);
                    if (alu.apellido[strlen(alu.apellido)-1]=='\n'){
                        alu.apellido[strlen(alu.apellido)-1]='\0';} break;
            case 2:system("cls"); printf("Ingrese nuevos nombres:");
                    fflush(stdin);
                    fgets(alu.nombres, MAX, stdin);
                    if (alu.nombres[strlen(alu.nombres)-1]=='\n'){
                        alu.nombres[strlen(alu.nombres)-1]='\0';} break;
            case 3:system("cls"); printf("Ingrese nuevo domicilio:");
                    fflush(stdin);
                    fgets(alu.domiciolio, MAX, stdin);
                    if (alu.domiciolio[strlen(alu.domiciolio)-1]=='\n'){
                        alu.domiciolio[strlen(alu.domiciolio)-1]='\0';} break;
            case 4:system("cls"); printf("Ingrese nuevo telefono:");
                    fflush(stdin);
                    fgets(alu.telefono, MAX, stdin);
                    if (alu.telefono[strlen(alu.telefono)-1]=='\n'){
                        alu.telefono[strlen(alu.telefono)-1]='\0';} break;
            case 5:system("cls"); printf("\nLegajo %d dado de baja\n\n", alu.legajo);
                    alu.estado=0; break;   
        }

        if (alu.estado!=0){
            printf("\n--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);
        }

        fseek(f, sizeof(t_alumno)*pos, SEEK_SET);
        fwrite(&alu, sizeof(t_alumno), 1, f);
        fseek(f, sizeof(t_alumno)*pos, SEEK_SET);
        fread(&alu, sizeof(t_alumno), 1, f);
        if (alu.estado==0){
            return;
        }

        printf("\nIngrese campo a modificar:");
        printf("\n1 apellido");
        printf("\n2 nombres");
        printf("\n3 domicilio");
        printf("\n4 telefono");
        printf("\n5 dar de baja");
        printf("\n0 salir\nOpcion:");

        val=0;
        while(val==0){
            val=1;
            fflush(stdin);
            fgets(opC, MAX, stdin);
            if (opC[strlen(opC)-1]=='\n'){
                opC[strlen(opC)-1]='\0';}
            
            if (!esEntero(opC)){
                val=0;
                system("cls"); printf("--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);

                printf("\nERROR. Ingrese campo a modificar:");
                printf("\n1 apellido");
                printf("\n2 nombres");
                printf("\n3 domicilio");
                printf("\n4 telefono");
                printf("\n5 dar de baja");
                printf("\n0 salir\nOpcion:");
            }

            op=atoi(opC);

            if (op>5 || op<0){
                val=0;
                system("cls"); printf("--Legajo %d, nombre: %s %s, domicilio: %s, telefono: %s--\n", alu.legajo, alu.apellido, alu.nombres, alu.domiciolio, alu.telefono);

                printf("\nERROR. Ingrese campo a modificar:");
                printf("\n1 apellido");
                printf("\n2 nombres");
                printf("\n3 domicilio");
                printf("\n4 telefono");
                printf("\n5 dar de baja");
                printf("\n0 salir\nOpcion:");          
            }
        }  
    }
    system("cls");
}

void aniadir(FILE* f, TablaHash tabla, int* max){

    int val=0;
    int i=1;
    int legajo;
    char legajoC[MAX];
    TipoElemento x=te_crear(0);
    t_alumno alu;
    t_alumno aluAux;

    system("cls"); printf("Ingrese el legajo a aniadir:");


    while(val==0){
        val=1;
        fflush(stdin);
        fgets(legajoC, MAX, stdin);
        if (legajoC[strlen(legajoC)-1]=='\n'){
            legajoC[strlen(legajoC)-1]='\0';}
            
        if (!esEntero(legajoC)){
            val=0;
            system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");
        }

        legajo=atoi(legajoC);

        if (legajo>999999 || legajo<0){
            val=0;
            system("cls"); printf("ERROR. Ingrese legajo (0 para terminar):");           
        }
    }

    alu.legajo=legajo;

    printf("Ingrese apellido:");
    fflush(stdin);
    fgets(alu.apellido, MAX, stdin);
    if (alu.apellido[strlen(alu.apellido)-1]=='\n'){
        alu.apellido[strlen(alu.apellido)-1]='\0';}
            
    printf("Ingrese nombres:");
    fflush(stdin);
    fgets(alu.nombres, MAX, stdin);
    if (alu.nombres[strlen(alu.nombres)-1]=='\n'){
        alu.nombres[strlen(alu.nombres)-1]='\0';}

    printf("ingrese domicilio:");
    fflush(stdin);
    fgets(alu.domiciolio, MAX, stdin);
    if (alu.domiciolio[strlen(alu.domiciolio)-1]=='\n'){
        alu.domiciolio[strlen(alu.domiciolio)-1]='\0';}

    printf("ingrese telefono:");
    fflush(stdin);
    fgets(alu.telefono, MAX, stdin);
    if (alu.telefono[strlen(alu.telefono)-1]=='\n'){
        alu.telefono[strlen(alu.telefono)-1]='\0';}
    
    alu.estado=1;

    f=fopen("alumnosHash.dat", "r+b");
    while(!feof(f)){
        fseek(f, sizeof(t_alumno)*i, SEEK_SET);
        fread(&aluAux, sizeof(t_alumno), 1, f);
        i++;
    }
    i--;

    x=te_crear_con_valor(alu.legajo, (int*) i);
    th_insertar(tabla, x);
    *max=i;

    fseek(f, sizeof(t_alumno)*i, SEEK_SET);
    fwrite(&alu, sizeof(t_alumno), 1, f);
    i=1;
    while(!feof(f)){
        fseek(f, sizeof(t_alumno)*i, SEEK_SET);
        fread(&aluAux, sizeof(t_alumno), 1, f);
        i++;
    }

    system("cls");
}

void main(){

    int val=0;
    int max;
    FILE *f;
    int op;
    char opC[MAX];
    TablaHash tabla=th_crear(113, *conversor);
    TipoElemento x=te_crear(0);
    t_alumno alu;
    int i=1;

    f=fopen("alumnosHash.dat", "r+b");

    if(f!=NULL){
        fseek(f, sizeof(t_alumno)*i, SEEK_SET);
        fread(&alu, sizeof(t_alumno), 1, f);
        x=te_crear_con_valor(alu.legajo, (int*) i);
        th_insertar(tabla, x);
        i++;
        while(!feof(f)){
            fseek(f, sizeof(t_alumno)*i, SEEK_SET);
            fread(&alu, sizeof(t_alumno), 1, f);
            x=te_crear_con_valor(alu.legajo, (int*) i);
            th_insertar(tabla, x);
            i++;
        }
    }

    fclose(f);

    system("cls"); printf("Ingresar modalidad:");
    printf("\n 1 para crear archivo");
    printf("\n 2 para buscar posicion por legajo");
    printf("\n 3 para consultar y modificar");
    printf("\n 4 para aniadir nuevo legajo");
    printf("\n 0 para salir\nopcion:");
    
    while(val==0){
        val=1;
        fflush(stdin);
        fgets(opC, MAX, stdin);
        if (opC[strlen(opC)-1]=='\n'){
            opC[strlen(opC)-1]='\0';}
        
        if (!esEntero(opC)){
            val=0;
            system("cls"); printf("ERROR. Ingresar modalidad:");
            printf("\n 1 para crear archivo");
            printf("\n 2 para buscar posicion por legajo");
            printf("\n 3 para consultar y modificar");
            printf("\n 4 para aniadir nuevo legajo");
            printf("\n 0 para salir\nopcion:");
        }

        op=atoi(opC);

        if (op>4 || op<0){
            val=0;
            system("cls"); printf("ERROR. Ingresar modalidad:");
            printf("\n 1 para crear archivo");
            printf("\n 2 para buscar posicion por legajo");
            printf("\n 3 para consultar y modificar");
            printf("\n 4 para aniadir nuevo legajo");
            printf("\n 0 para salir\nopcion:");            
        }
    }

    while (op!=0){
        switch(op){
        case 1: crearArchivo(f, tabla, &max); break;
        case 2: buscarPos(tabla, f); break;
        case 3: modificar(f, max); break;
        case 4: aniadir(f, tabla, &max); break;
        //case 5: consultar(f); break;
        }
        printf("Ingresar modalidad:");
        printf("\n 1 para crear archivo");
        printf("\n 2 para buscar posicion por legajo");
        printf("\n 3 para consultar y modificar");
        printf("\n 4 para aniadir nuevo legajo");
        printf("\n 0 para salir\nOpcion:");

        val=0;
        while(val==0){
            val=1;
            fflush(stdin);
            fgets(opC, MAX, stdin);
            if (opC[strlen(opC)-1]=='\n'){
                opC[strlen(opC)-1]='\0';}
            
            if (!esEntero(opC)){
                val=0;
                system("cls"); printf("ERROR. Ingresar modalidad:");
                printf("\n 1 para crear archivo");
                printf("\n 2 para buscar posicion por legajo");
                printf("\n 3 para consultar y modificar");
                printf("\n 4 para aniadir nuevo legajo");
                printf("\n 0 para salir\nopcion:");
            }

            op=atoi(opC);

            if (op>4 || op<0){
                val=0;
                system("cls"); printf("ERROR. Ingresar modalidad:");
                printf("\n 1 para crear archivo");
                printf("\n 2 para buscar posicion por legajo");
                printf("\n 3 para consultar y modificar");
                printf("\n 4 para aniadir nuevo legajo");
                printf("\n 0 para salir\nopcion:");            
            }
        }
    }
    printf("\n\nFIN");
}