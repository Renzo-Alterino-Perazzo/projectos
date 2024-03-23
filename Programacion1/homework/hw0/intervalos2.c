
#include <stdio.h>

int intervalo(int n1, int n2) {
    int resultado, n3;
    resultado = 0;
    n3 = n1;
    for (int numero = n1; numero < n2+1; numero++) {
        resultado = resultado + n3;
        n3 = n3 + 1;
    }
    return resultado;
}

int main() {
    int n1, n2, resultado;
    n1 = 1;
    n2 = 4;
    resultado = intervalo(n1, n2);
    printf("%d", resultado);
    return 0;
}
