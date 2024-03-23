
#include <stdio.h>

void menu () {
    printf("********* MI PROGRAMA *********\n");
    printf("1. Saludar.\n");
    printf("2. Informar temperatura.\n");
    printf("3. Mostrar nombre de materia.\n");
    printf("4. Salir.\n");
    printf("Seleccione una opción [1-4]: ");
}

int main() {
    menu();
    int opcion;
    scanf("%d", &opcion);
        if (opcion == 1)
        {
            printf("�Hola, bienvenido a mi programa interactivo!");
        }
        else if (opcion == 2) {
            printf("Hay una sensacion térmica de 20 grados Celsius");
        }
        else if (opcion == 3) {
            printf("Estas en la materia Programacion I!");
        }
        else if (opcion == 4) {
            printf("�Hasta la proxima!");
        }
        else {
            printf("Opcion invalida.");
        }
    return 0;
}
