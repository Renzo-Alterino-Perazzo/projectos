
#include <stdio.h>
#define TAMANIO 15

int main() {
    char nombre[TAMANIO];
    int acumulador = 0;
    scanf("%s", &nombre);
    while (acumulador < TAMANIO) {
        printf("%c\n", nombre[acumulador]);
        acumulador += 1;
    }
    return 0;
}
