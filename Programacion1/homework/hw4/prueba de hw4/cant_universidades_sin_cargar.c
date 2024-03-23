
#include <stdio.h>
#include "assert.h"

typedef struct {
	int universidad;
	int carrera;
	int legajo;
	float promedio;
} t_carrera;

int cant_universidades_sin_cargar(FILE* fp){ 
	// Programar la funcion aqui
	//fp = fopen("promedio_carreras.dat", "rb");
	t_carrera carrera;
	fread(&carrera, sizeof(t_carrera), 1, fp);
	int universidad_aux = carrera.universidad;
    int universidad_max = carrera.universidad;
    int universidad_cant = 1;
	while(feof(fp)==0){
		if (universidad_aux != carrera.universidad){
            universidad_cant++;
            universidad_aux = carrera.universidad;
        }
        if (universidad_max < carrera.universidad){
            universidad_max = carrera.universidad;
        }
		fread(&carrera, sizeof(t_carrera), 1, fp);
	}
	int universidad_no_cargadas = universidad_max - universidad_cant;
	return universidad_no_cargadas;
	fclose(fp);
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