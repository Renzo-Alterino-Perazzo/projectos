
#include <stdio.h>

int main() {
    int parcial1, parcial2;
    printf("Ingrese nota del primer parcial: ");
    scanf("%d", &parcial1);
    printf("Ingrese nota del segundo parcial: ");
    scanf("%d", &parcial2);
    float promedio = parcial1+ parcial2;
    promedio = promedio/2;
    if (parcial1 < 4 || parcial2 < 4) {
        printf("A quedado libre");
    }
    else {
        if (promedio < 7)
        {
            printf("A regularizado la materia");
        }
        else {
            printf("A promocionado la materia");
        }
    }
    return 0;
}
