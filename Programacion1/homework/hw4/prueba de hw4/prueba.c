#include <stdio.h>

typedef struct {
	int universidad;
	int carrera;
	int legajo;
	float promedio;
} t_carrera;

int maximos_inscriptos(FILE* fp){ 
	// Programar la funcion aqui
    t_carrera carrera;
    int acumulador [8];
    int inscriptos_mayor = 0, carrera_mayor;
    for (int i = 0; i < 8; i++){
        acumulador[i] = 0;
    }
    fread(&carrera, sizeof(t_carrera), 1, fp);
    while(feof(fp)==0){
        acumulador[carrera.carrera-101] = acumulador[carrera.carrera-101] + 1;
        fread(&carrera, sizeof(t_carrera), 1, fp);
    }
    for (int j = 0; j < 8; j++){
        if (inscriptos_mayor < acumulador[j]){
            inscriptos_mayor = acumulador[j];
            carrera_mayor = j + 101;
        }
    }
    fclose(fp);
    
    return carrera_mayor;
}

int main(){
    FILE* fp;
    fp = fopen("promedio_carreras.dat", "rb");
    maximos_inscriptos(fp);
    return 0;
}