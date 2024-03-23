
#include <stdio.h>
#include "assert.h"

void llovio_umbral(FILE* fp, int x, int* lluvias_menor_x, int* lluvias_mayorigual_x){
    fp = fopen("datos_lluvia_temp.tsv", "r");
    rewind(fp);
    int lluvia_menor = 0, lluvia_mayor = 0;
    int dia, mes, anio, lluvia, tmin, tmax;
    fscanf(fp, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax);
    while(feof(fp)==0){
        if (lluvia >= x){
            lluvia_mayor++;
            *lluvias_mayorigual_x = lluvia_mayor;
        }
        else {
            lluvia_menor++;
            *lluvias_menor_x = lluvia_menor;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
}

void test_llovio_umbral(){
    FILE* fp;
    int lluvias_menor_x, lluvias_mayorigual_x;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_llovio_umbral... ");
    llovio_umbral(fp, 10, &lluvias_menor_x, &lluvias_mayorigual_x);
    assert(lluvias_menor_x==34);
    assert(lluvias_mayorigual_x==86);
    llovio_umbral(fp, 20, &lluvias_menor_x, &lluvias_mayorigual_x);
    assert(lluvias_menor_x==56);
    assert(lluvias_mayorigual_x==64);
    printf("Paso!\n");
    fclose(fp);
}

int main () {
    test_llovio_umbral();
    return 0;
}