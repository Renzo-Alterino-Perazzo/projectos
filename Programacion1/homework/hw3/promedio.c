
#include <stdio.h>
#include "assert.h"

float promedio_lluvias_mes(FILE* fp, int mes){ 
	// Programar la funcion aqui
    rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    float promedio;
    int cant_lluvia = 0, cant_dia = 0;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while (feof(fp)==0) {
        if (mes_aux == mes) {
            cant_lluvia += lluvia;
            cant_dia++;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    promedio = cant_lluvia/cant_dia;
    return promedio;
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