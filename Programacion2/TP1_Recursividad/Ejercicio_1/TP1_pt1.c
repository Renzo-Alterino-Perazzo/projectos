#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool esPalindromo(char * cadena, int contador);
void ingresarCadena();

bool esPalindromo(char * cadena, int contador){
    int longitud=strlen(cadena);
    int i=longitud-contador;
    if (cadena[i]==cadena[contador-1]){
        if (i>=contador){
            return true;
        }
        else {
            esPalindromo(cadena, contador-1);
        }
    }
    else return false;
}

void ingresarCadena(){
    char cadena[1002]; 
    int valido=1;  
    *cadena=""; 
    char cadenaVal[1002];
    *cadenaVal="";
   
    int tamanio;
    int i;
    int j;

    while (valido==1){

        valido=0;

        fflush(stdin);
        printf("Ingrese una cadena de hasta 1000 caracteres (los espacios seran eliminados): ");
        fgets(cadena, 1002, stdin);  
        if (cadena[strlen(cadena)-1]=='\n'){
            cadena[strlen(cadena)-1]='\0';
        } 

        tamanio=strlen(cadena);

        if (tamanio==0){
            printf("La cadena no puede estar vacia.\n");
            valido=1;
        }
        else if (tamanio==1001){
            printf("La cadena supera los limites.\n");
            valido=1;
        }
        else {
            j=0;
            for (i=0; i<tamanio; i++){
                if (cadena[i]!=32 && cadena[i]!=9){
                    if (cadena[i]>=65 && cadena[i]<=90){
                        cadenaVal[j]=cadena[i]+32;
                        j++;
                    }
                    else {
                        cadenaVal[j]=cadena[i];
                        j++;
                    }    
                }
            }
            if (j==0){
            printf("La cadena no puede contener solo espacios.\n");
            valido=1;
            }
        }
        
    }
    cadenaVal[j]='\0';

    int contador=strlen(cadenaVal);

    if (esPalindromo(cadenaVal, contador)){
        printf("Es palindromo");
    }
    else printf("No es palindromo");
}


int main(){
    system("cls");
    ingresarCadena();
}
