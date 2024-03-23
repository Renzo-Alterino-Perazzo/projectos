
#include <stdio.h>
const int tamanio = 6;

int main()
{
    int A[] = {5, 7, 3, 9, 8, 3};
    int B[] = {9, 2, 1, 6, 11, 1};
    int C[tamanio];
    int resultado = 0;
    int contador = 0;
    while (contador < tamanio) {
        //printf("%d", i);
        //printf("%d", A[i]);
        //printf("%d", B[i]);
        C[contador] = A[contador] * B[contador];
        //printf("%d\n", C[contador]);
        contador += 1;
    }
    contador = 0;
    while (contador < tamanio) {
        resultado += C[contador];
        contador += 1;
    }
    printf("%d", resultado);
    return 0;
}
