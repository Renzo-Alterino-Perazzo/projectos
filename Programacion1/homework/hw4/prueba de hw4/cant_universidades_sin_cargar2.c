
#include <stdio.h>
#include "assert.h"

typedef struct{
    int universidad;
    int carrera;
    int legajo;
    float promedio;
}tpromedios_de_carrreas;

int cant_universidades_sin_cargar(FILE* fp){
	tpromedios_de_carrreas promedios_de_carrreas;
	fp = fopen("promedio_carreras", "rb");
	int universidades_sin_cargar=0;
	while(!feof(fp)){
		fread(&promedios_de_carrreas.universidad,sizeof(tpromedios_de_carrreas),1,fp);
		if (&promedios_de_carrreas.universidad==NULL){
			universidades_sin_cargar ++;
		}
	}
	return universidades_sin_cargar;	
}

void test_cant_universidades_sin_cargar(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_cant_universidades_sin_cargar... ");
    assert(cant_universidades_sin_cargar(fp)==6);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_cant_universidades_sin_cargar();
    return 0;
}