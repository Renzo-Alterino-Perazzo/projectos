
#include <stdio.h>

int reverso(int v1[], int v2[], int n) {
    int acumulador = 0, contador = 0;
    int reverso;
    while (contador < n) {
        if (v1[contador] == v2[n-1-contador]) {
            acumulador += 1;
        }
        contador += 1;
    }
    if (acumulador == n) {
        reverso = 1;
    }
    else {
        reverso = 0;
    }
    return reverso;
}

int main() {
    int v1[] = {1,3,2};
    int v2[] = {1,1,2};
    int n = 3;
    int al_revez = reverso(v1,v2,n);
    printf("%d", al_revez);
    return 0;
}