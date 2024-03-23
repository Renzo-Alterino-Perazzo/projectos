
#include <stdio.h>
#include "assert.h"

int maximos_inscriptos(FILE* fp){ 
	// Programar la funcion aqui
}

void test_maximos_inscriptos(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_maximos_inscriptos... ");
    assert(maximos_inscriptos(fp)==102);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_maximos_inscriptos();
    return 0;
}