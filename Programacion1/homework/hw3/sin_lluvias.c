
#include "assert.h"
#include <stdio.h>

int sin_lluvias(FILE* fp, int mes){ 
	// Programar la funcion aqui
	rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    int acumulador = 0;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while (feof(fp)==0) {
        if (mes_aux == mes && lluvia == 0) {
            acumulador++;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    return acumulador;
    fclose(fp);
}

void test_sin_lluvias(){
    FILE* fp;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_sin_lluvias...");
    assert(sin_lluvias(fp, 1)==2);
    assert(sin_lluvias(fp, 2)==4);
    assert(sin_lluvias(fp, 3)==8);
    assert(sin_lluvias(fp, 4)==0);
    printf("Paso!\n");
    fclose(fp);
}

int main() {
    test_sin_lluvias();
    return 0;
}