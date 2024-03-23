
#include <stdio.h>
#include "assert.h"

typedef struct {
	int universidad;
	int carrera;
	int legajo;
	float promedio;
} t_carrera;

int promedio_umbral(FILE* fp, int c, float u){ 
	// Programar la funcion aqui
    t_carrera carrera;
    fseek(fp, sizeof(t_carrera), SEEK_SET);
    int acumulador = 0;
    fread(&carrera, sizeof(t_carrera), 1, fp);
    while(feof(fp)==0){
        fread(&carrera, sizeof(t_carrera), 1, fp);
        if (carrera.carrera == c && carrera.promedio >= u){
            acumulador++;
        }
    }
    //fclose(fp);
    return acumulador;
}

void test_promedio_umbral(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_promedio_umbral... ");
    assert(promedio_umbral(fp,101,9.0)==41);
    assert(promedio_umbral(fp,103,9.9)==6);
    printf("Paso!\n");
    fclose(fp);
}

int main(){
    test_promedio_umbral();
    return 0;
}