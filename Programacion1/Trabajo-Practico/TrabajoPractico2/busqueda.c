
#include <stdio.h>

int main() {
    int arreglo[] = {5,7,3,9,2,3,8};
    int numero;
    int contador = 0;
    int coincidencias = 0;
    int posicion = 0;
    int primera_posicion_coincidencia = -1;
    int posiciones_coincidentes[7];
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    while (contador < 7) {
        if (arreglo[contador] == numero){
            coincidencias += 1;
            posiciones_coincidentes[posicion] = contador;
            posicion += 1;
        }
        contador += 1;
    }
    if (coincidencias > 0) {
        primera_posicion_coincidencia = posiciones_coincidentes[0];
    }
    printf("Hay un total de %d coincidencias\n", coincidencias);
    printf("La posicion de la primera coincidencia es %d\n", primera_posicion_coincidencia);
    printf("Posiciones de coincidencia son: ");
    contador = 0;
    while(contador < posicion) {
        printf("%d, ",posiciones_coincidentes[contador]);
        contador += 1;
    }
    return 0;
}
