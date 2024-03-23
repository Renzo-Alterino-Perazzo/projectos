#include <stdio.h>
const int tamanio = 6;

int main()
{
    int A[] = {5, 7, 3, 9, 8, 3};
    int B[] = {9, 2, 1, 6, 11, 1};
    int C[tamanio];
    int resultado = 0;
    for (int i = 0; i < tamanio; i++) {
        //printf("%d", i);
        //printf("%d", A[i]);
        //printf("%d", B[i]);
        C[i] = A[i] * B[i];
        //printf("%d\n", C[i]);
    }
    for (int i = 0; i < tamanio; i++) {
        resultado += C[i];
    }
    printf("%d", resultado);
    return 0;
}
