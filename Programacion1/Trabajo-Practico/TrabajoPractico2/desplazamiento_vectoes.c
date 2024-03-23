
#include <stdio.h>
#define TAMANIO 7

int main() {
    int vector[] = {1,2,3,4,5,6,7};
    int contador = 0;
    int auxiliar [TAMANIO];
    while (contador < TAMANIO) {
        if (contador != 0) {
            auxiliar[contador-1] = vector[contador];
        }
        else {
            auxiliar[TAMANIO-1] = vector[0];
        //    printf("%d", auxiliar[TAMANIO-1]);
        }
        contador += 1;
        }
    contador = 0;
    while (contador < TAMANIO) {
        printf("%d\n", vector[contador]);
        contador += 1;
    }
    contador = 0;
    while (contador < TAMANIO) {
        printf("%d\n", auxiliar[contador]);
        contador += 1;
    }
    

    return 0;
}