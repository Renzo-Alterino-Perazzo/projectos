
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
    int mayor = vector[0];
    contador = 0;
    while (contador < TAMANIO) {
        if (mayor < vector[contador]) {
            mayor = vector[contador];
        }
        contador += 1;  
    }
    printf("%d", mayor);
    return 0;
}