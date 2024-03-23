
#include <stdio.h>
#include "assert.h"

int contador_dias_maximo_calor(FILE* fp, int mes){
    int dia, mes_aux, anio, lluvia, tmin, tmax;
    int dias_tmax = 0, temperatura_max = 0;
    //fp=fopen("datos_lluvia_temp.tsv","r");
	rewind(fp);
    fscanf(fp,"%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while(feof(fp)==0){
        if (mes==mes_aux) {
            if(tmax > temperatura_max) {
                temperatura_max = tmax;
                dias_tmax = 0;
            }
            if (tmax==temperatura_max) {
                dias_tmax++;
            }
        }
        fscanf(fp,"%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
    return dias_tmax;
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