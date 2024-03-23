
#include <stdio.h>

int posicion(int A[], int n, int x) {
    int coincidencia, contador, posicion, apariciones[n], primera_aparicion; coincidencia = 0; contador = 0; posicion = 0; primera_aparicion = -1;
    while (contador < n) {
        if (A[contador]==x) {
            coincidencia++;
            apariciones[posicion] = contador;
            posicion++;
        }
        contador++;
    }
    printf("Coincidencias: %d\n", coincidencia);
    if (coincidencia > 0) {
        primera_aparicion = apariciones[0];
    }
    printf("Primera aparicion: %d\n", primera_aparicion);
    for (int i = 0; i < coincidencia; i++) {
        printf("Posiciones donde aparece: %d\n", apariciones[i]);
    }
    return 0;
}

int main() {
    int A[] = {5,7,3,9,2,3,8}; int n = 7; int x = 3;
    posicion(A,n,x);
    return 0;
}