
#include <stdio.h>

int main() {
    int n = 4; int legajo[] = {5645,154582,6852,12366}; int calificacion[] = {4, 5,10,9};
    printf("LEGAJO     CALIFICACION\n");
    for (int i = 0; i < n; i++) {
        printf("%d       %d\n", legajo[i], calificacion[i]);
    }
    return 0;
}