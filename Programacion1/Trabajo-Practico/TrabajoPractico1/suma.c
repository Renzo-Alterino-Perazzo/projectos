
#include <stdio.h>

int main() {
    int numero1, numero2, resultado;
    printf("Ingrese un numero entre 10 y 99: \n");
    scanf("%d", &numero1);
    scanf("%d", &numero2);
    resultado = (numero1 + numero2);
    printf("El resultado de la suma es: " "%d",resultado);
    return 0;
}
