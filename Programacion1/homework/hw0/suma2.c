
#include <stdio.h>

int suma(int a, int b){
    int resultado = a + b;
    return resultado;
}

int main (){
    int a, b, resultado;
    a = 1;
    b = 2;
    resultado = suma(a, b);
    printf("%d", resultado);
    return 0;
}
