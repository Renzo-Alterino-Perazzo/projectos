
#include <stdio.h>
#include "assert.h"

int cant_universidades_sin_cargar(FILE* fp){ 
	// Programar la funcion aqui
}

void test_cant_universidades_sin_cargar(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_cant_universidades_sin_cargar... ");
    assert(cant_universidades_sin_cargar(fp)==6);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_cant_universidades_sin_cargar();
    return 0;
}