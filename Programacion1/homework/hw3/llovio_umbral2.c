
#include <stdio.h>
#include "assert.h"

void llovio_umbral(FILE* fp, int x, int* lluvias_menor_x, int* lluvias_mayorigual_x){ 
    fp = fopen("datos_lluvia_temp.tsv", "r");
	rewind(fp);
    int lluvias_menor = 0;
    int lluvias_mayorigual = 0;
    int dia,es_mes,anio,cant_lluvia,temp_min,temp_max;
    fscanf(fp,"%i %i %i %i %i %i", &dia, &es_mes, &anio, &cant_lluvia, &temp_min, &temp_max);
    while (feof(fp) == 0){
        if (cant_lluvia >= x){
            lluvias_mayorigual++; 
            *lluvias_mayorigual_x = lluvias_mayorigual;
        }
        else{
            lluvias_menor ++;
            *lluvias_menor_x = lluvias_menor;
        }
        fscanf(fp,"%i %i %i %i %i %i", &dia, &es_mes, &anio,&cant_lluvia,&temp_min, &temp_max);
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