
#include <stdio.h>

int apariciones(int v[], int n, int k) {
    int contador = 0;
    int acumulador = 0;
    while (contador < n) {
        if (v[contador] == k) {
            acumulador += 1;
        }
        contador += 1;
    }
    return acumulador;
}

int main() {
    int v[] = {1,1,2};
    int n = 3;
    int k = 1 ;
    int acumulador = apariciones(v,n,k);
    printf("%d", acumulador);
    return 0;
}