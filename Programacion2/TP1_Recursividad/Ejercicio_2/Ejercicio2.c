#include <stdio.h>
#include "Ejercicio2.h"

char auxiliar[100];

int main(){
    int m,n;
    printf("Ingrese un número: (los espacios serán ignorados)\n");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false){
        printf("No es un número válido.\n");
        printf("Ingrese un número: (los espacios serán ignorados)\n");
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    m = atoi(auxiliar);
    printf("m = %d \n", m);

    printf("Ingrese otro número: (los espacios serán ignorados)\n");
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false){
        printf("No es un número válido.\n");
        printf("Ingrese otro número: (los espacios serán ignorados)\n");
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    n = atoi(auxiliar);
    printf("n = %d \n", n);

    int resultado = 0;
    if ( m < 0 && n < 0){ // si los dos son negativos
        m = -m;
        n = -n;
        printf("El producto entre %d y %d es %d.\n",-m,-n,productoRecursivo(m,n,resultado));
    } else if (n < 0){ // si solo n es negativo
        printf("El producto entre %d y %d es %d.\n",m,n,productoRecursivo(n,m,resultado));
    } else printf("El producto entre %d y %d es %d.\n",m,n,productoRecursivo(m,n,resultado));
};
