
#include <stdio.h>
#include "assert.h"

int contador_dias_maximo_calor(FILE* fp, int mes){ 
	// Programar la funcion aqui
	int dia, el_mes, anio, cant_lluvia, temp_min, temp_max;
	int cant_dias_maximo_calor=0;
	int temp_maxima=0;
	fp=fopen("datos_lluvia_temp.tsv","r");
	rewind(fp);
	fscanf(fp,"%i %i %i %i %i %i", &dia, &el_mes, &anio, &cant_lluvia, &temp_min, &temp_max);

	while(!feof(fp)){
		if(el_mes==mes){
			if(temp_max>temp_maxima){
				temp_maxima=temp_max;
				cant_dias_maximo_calor=0;
			}
			if(temp_max==temp_maxima){
				cant_dias_maximo_calor++;
			}
		}
		fscanf(fp,"%i %i %i %i %i %i", &dia, &el_mes, &anio, &cant_lluvia, &temp_min, &temp_max);
	}
	fclose(fp);
	return cant_dias_maximo_calor;
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