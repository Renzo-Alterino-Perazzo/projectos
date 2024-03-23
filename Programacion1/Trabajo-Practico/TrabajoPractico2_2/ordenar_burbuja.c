
#include <stdio.h>

char elegir_orden() {
    char opcion;
    printf("Ingrese si desea ordenar de manera ascendente (A) o descendente (D): ");
    scanf("%c", &opcion);
    printf("%c", opcion);
    return opcion;
}

int bubblesort_ascendente(int arreglo[], int n) {
    int auxiliar;
    for (int i = 0; i < n; i++) {   // loop n times - 1 per element
        for (int j = 0; j < n - i - 1; j++) { // last i elements are sorted already
            if (arreglo[j] > arreglo[j + 1]) {  // swop if order is broken
                auxiliar = arreglo[j];
                arreglo[j] = arreglo[j + 1];
                arreglo[j + 1] = auxiliar;
            }
        }
    }
    for (int k = 0; k < n; k++){
        printf("%d\n", arreglo[k]);
    }
    return 0;
}


int main() {
    int arreglo[] = {5,7,3,9,2,3,4,14,12};
    int n = sizeof(arreglo)/sizeof(arreglo[0]);
    char orden = elegir_orden;
    //bubblesort_ascendente(arreglo,n);
    return 0;
}