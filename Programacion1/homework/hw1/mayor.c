
#include <stdio.h>

int mayor(int v[], int n) {
    int mayor = v[0];
    int acumulador = 0;
    while (acumulador < n) {
        if (mayor < v[acumulador]) {
            mayor = v[acumulador];
        }
        acumulador += 1;
    }
    return mayor;
}

int main() {
    int v[]= {6,4};
    int n = 2;
    int grande = mayor(v,n);
    printf("%d", grande);
    return 0;
}