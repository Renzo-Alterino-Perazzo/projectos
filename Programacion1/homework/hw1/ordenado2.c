
#include <stdio.h>

int ordenado(int v[], int n) {
    int ascendente = 0, descendente = 0, orden = 0, contador = 0;
    while (contador < n+1) {
        if (v[contador] <= v[contador+1]) {
            ascendente += 1;
        }
        if (v[contador] >= v[contador+1]) {
            descendente += 1;
        }
        //printf("%d\n", descendente);
        //printf("%d\n", ascendente);
        contador += 1;
    }
    if (ascendente == n) {
        orden = 1; 
    }
    if (descendente == n) {
        orden = 1;
    }
    return orden;
}

int main() {
    int v[] = {2};
    int n = 1;
    int orden = ordenado(v,n);
    printf("%d", orden);
    return 0;
}