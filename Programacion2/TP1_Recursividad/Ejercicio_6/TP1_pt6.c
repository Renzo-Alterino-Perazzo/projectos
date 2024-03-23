#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>
#include<ctype.h>
#include<math.h>

void vistaReunion(int nivel, int n);
void cargarNivel();

void vistaReunion(int nivel, int n){

    if (nivel==1 && n==1){
        printf("(-.-)");
    }
    else {
        if (nivel>1){
            printf("(-.");
            vistaReunion(nivel-1, n);
        }
        else if (nivel==1 && n>1){
            printf("(-.-)");
            vistaReunion(nivel-1, n);
        }
        else if (nivel<1 && n>1){
            printf(".-)");
            vistaReunion(nivel, n-1);
        }
    }
}

void cargarNivel(){

    char num[1000];
    int nivel;
    int n;
    int valido=1;
    while (valido==1){

        valido=0;
        
        printf("Ingrese un numero entero mayor a 0 y menor a 20:");
        fflush(stdin);
        fgets(num, 1000, stdin);
        if (num[strlen(num)-1]=='\n'){
            num[strlen(num)-1]='\0';
        }

        int longitud=strlen(num);
        int i;
        int puntos=0;
        int indicePuntos=0;

        if (valido==0){
            for (i=0; i<longitud; i++){
                if ((num[i]>57 || num[i]<48) && num[i]!=46){
                    printf("Valor no valido.\n");
                    valido=1;
                    break;
                }
            }
        }

        if (valido==0){
            for (i=0; i<longitud; i++){
                if (num[i]==46){
                    puntos++;
                    indicePuntos=i;
                }   
            }
            if (puntos>1){
                printf("Valor no valido.\n");
                valido=1;
            }
            else if (puntos==1){
                indicePuntos++;
                if (num[indicePuntos]=='\0'){
                    printf("Valor no valido.\n");
                    valido=1;
                }
                else {
                    for (indicePuntos; indicePuntos<longitud; indicePuntos++){
                        if (num[indicePuntos]!=48 && num[indicePuntos]!='\n'){
                            printf("Debe ingresar valores enteros.\n");
                            valido=1;
                            break;
                        }
                    }
                }
            }
        }

        if (valido==0){
            nivel=atoi(num);
            if (nivel>19 || nivel<1){
                printf("Valor no valido.\n");
                valido=1;
            }
        }
    }

    n=nivel;
    vistaReunion(nivel, n);

}

void main(){
    system("cls");
    cargarNivel();
}
