
#include "assert.h"
#include <stdio.h>

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

void test_promedio_lluvias_mes(){
    FILE* fp;
    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_promedio_lluvias_mes... ");
    assert((int)promedio_lluvias_mes(fp, 1)==25);
    assert((int)promedio_lluvias_mes(fp, 2)==20);
    assert((int)promedio_lluvias_mes(fp, 3)==17);
    assert((int)promedio_lluvias_mes(fp, 4)==22);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_promedio_lluvias_mes();
    return 0;
}