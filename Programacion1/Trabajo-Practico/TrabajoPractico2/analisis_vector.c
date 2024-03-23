
#include <stdio.h>
#define TAMANIO 50

int main() {
    int vector[TAMANIO];
    int contador = 0;
    int numero = -20;
    while (contador < TAMANIO) {
        vector[contador] = numero;
        //printf("%d\n", vector[contador]);
        contador += 1;
        numero += 1;
    }
    contador = 0;
    int negativo, positivo, cero;
    negativo = 0;
    positivo = 0;
    cero = 0;
    while (contador < TAMANIO) {
        if (vector[contador] > 0) {
            positivo += 1;
        }
        else if (vector[contador] < 0) {
            negativo += 1;
        }
        else {
            cero += 1;
        }
        
        contador += 1;
    }
    printf("Positivos: " "%d\n", positivo);
    printf("Negativos: " "%d\n", negativo);
    printf("Ceros: " "%d\n", cero);
    return 0;
}