
#include <stdio.h>
#include <string.h>

int main() {
    char A [] = {"cajtpg"}; int contador, orden, n, ascendente, descendente; contador = 0; orden = 1; n = sizeof(A)/sizeof(A[0]); ascendente = 0; descendente = 0;
    for (int i = 0; i < n-1; i++) {
        if (A[i] < A[i+1]) {
            descendente += 1;
        }
        else if (A[i] > A[i+1]) {
            ascendente += 1;
        }
        else {
            descendente += 1; ascendente += 1;
        }
    }
    if (descendente < n-2 || ascendente < n-2) {
        orden = 0;
    }
    printf("%d", orden);
    return 0;
}