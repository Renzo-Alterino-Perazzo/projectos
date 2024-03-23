
#include <stdio.h>

int ordenado(int v[], int n) {
    int ascendente, descendente, orden , contador; ascendente = 0; descendente = 0; orden = 1; contador = 0;
    while (contador < n-1) {
        if (v[contador] < v[contador+1]) {
            ascendente += 1;
        }
        else {
            if (v[contador] > v[contador+1]) {
                descendente += 1;
            }
            else {
                ascendente += 1;
                descendente += 1;
            }
        }    
        printf("ascendente: %d\n", ascendente);
        printf("descendente: %d\n", descendente);
        contador += 1;
    }
    if (ascendente < n-1 && descendente < n-1) {
        orden = 0; 
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