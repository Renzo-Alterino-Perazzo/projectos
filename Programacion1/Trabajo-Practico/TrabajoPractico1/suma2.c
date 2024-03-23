
#include <stdio.h>

int main() {
    int numero1, numero2, suma, resta, producto;
    printf("Ingrese un numero entre 10 y 99: \n");
    scanf("%d", &numero1);
    printf("Ingrese otro numero: \n");
    scanf("%d", &numero2);
    suma = (numero1 + numero2);
    printf("El resultado de la suma es: " "%d\n", suma);
    resta = (numero1 - numero2);
    printf("El resultado de la resta es: " "%d\n", resta);
    producto = (numero1 * numero2);
    printf("El producto es: " "%d\n", producto);
    return 0;
}
