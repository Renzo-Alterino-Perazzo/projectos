
#include <stdio.h>

int main() {
    int opcion;
    printf("Introdusca tipo de bomba entre 0-4: ");
    scanf("%d", &opcion);
    switch (opcion) {
    case 0:
        printf("No hay establecido un valor definido para el tipo de bomba\n");
        break;
    case 1:
        printf("La bomba es una bomba de agua\n");
        break;
    case 2:
        printf("La bomba es una bomba de gasolina\n");
        break;
    case 3:
        printf("La bomba es una bomba de hormigón");
        break;
    case 4:
        printf("La bomba es una bomba de pasta alimenticia");
        break;
    default:
        printf("No existe un valor valido para tipo de bomba\n");
        break;
    }
    return 0;
}