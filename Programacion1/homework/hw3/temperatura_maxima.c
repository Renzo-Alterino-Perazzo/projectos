
#include <stdio.h>
#include "assert.h"

int contador_dias_maximo_calor(FILE* fp, int mes){ 
	// Programar la funcion aqui
    rewind(fp);
    int dia, mes_aux, anio, lluvia, tmin, tmax, tmax_aux, acumulador = 0;
    fscanf(fp, "%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, tmax);
    tmax_aux = tmax;
    while (feof(fp)==0) {
        if (tmax == tmax_aux) {
            acumulador++;
        }
        if (tmax > tmax_aux) {
            tmax_aux = tmax;
            acumulador = 1;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, tmax);
    }
    return acumulador;
    fclose(fp);
}

void test_contador_dias_maximo_calor(){
    FILE* fp;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_contador_dias_maximo_calor... ");
    assert(contador_dias_maximo_calor(fp, 1)==2);
    assert(contador_dias_maximo_calor(fp, 2)==2);
    assert(contador_dias_maximo_calor(fp, 3)==5);
    assert(contador_dias_maximo_calor(fp, 4)==4);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_contador_dias_maximo_calor();
    return 0;
}