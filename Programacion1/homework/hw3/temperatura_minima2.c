
#include <stdio.h>
#include "assert.h"

void dia_mas_frio_mes(FILE* fp, int mes, int* dia, int* temp_minima){
fp = fopen("datos_lluvia_temp.tsv","r");  //fp el puntero al archivo= abro(nombre del arch, modo lectura(read)
		int lluviasino, mesarch, day, anio, temp1, temp2;
		int v = 1;
		int menor = 99;
		fscanf(fp,"%d%d%d%d%d%d",&day, &mesarch, &anio, &lluviasino, &temp1, &temp2);
		while (!feof(fp) && v == 1){ //mientras que no sea  el final del archivo/
			if (mesarch == mes){
				while (!feof(fp) && mesarch == mes && v == 1){
					if (temp1 < menor){
						menor = temp1;
						*temp_minima = temp1;
						*dia = day;
					}
					fscanf(fp,"%d%d%d%d%d%d",&day, &mesarch, &anio, &lluviasino, &temp1, &temp2);
				}
				v = 0;
			}
			if (v==1){
				fscanf(fp,"%d%d%d%d%d%d",&day, &mesarch, &anio, &lluviasino, &temp1, &temp2);
			}		
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
