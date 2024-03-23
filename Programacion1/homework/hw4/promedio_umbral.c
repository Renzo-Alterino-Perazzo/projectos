
#include <stdio.h>
#include "assert.h"

int promedio_umbral(FILE* fp, int c, float u){ 
	// Programar la funcion aqui
}

void test_promedio_umbral(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_promedio_umbral... ");
    assert(promedio_umbral(fp,101,9.0)==41);
    assert(promedio_umbral(fp,103,9.9)==6);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_promedio_umbral();
    return 0;
}