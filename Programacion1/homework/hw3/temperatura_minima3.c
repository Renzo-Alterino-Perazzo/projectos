
#include <stdio.h>
#include "assert.h"

void dia_mas_frio_mes(FILE* fp, int mes, int* dia, int* temp_minima){
    fp = fopen("datos_lluvia_temp.tsv","r");
    rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    *temp_minima = tmin;
    while(feof(fp)==0){
        if (mes_aux==mes && tmin < *temp_minima ){
            *temp_minima = tmin;
            *dia = dia_aux;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
}

void test_dia_mas_frio_mes(){
    FILE* fp;
    int dia, temp_minima;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_dia_mas_frio_mes... ");
    dia_mas_frio_mes(fp, 1, &dia, &temp_minima);
    assert(dia ==2);
    assert(temp_minima==5);
    dia_mas_frio_mes(fp, 2, &dia, &temp_minima);
    assert(dia ==4);
    assert(temp_minima==6);
    dia_mas_frio_mes(fp, 3, &dia, &temp_minima);
    assert(dia ==21);
    assert(temp_minima==5);
    dia_mas_frio_mes(fp, 4, &dia, &temp_minima);
    assert(dia ==25);
    assert(temp_minima==5);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_dia_mas_frio_mes();
    return 0;
}