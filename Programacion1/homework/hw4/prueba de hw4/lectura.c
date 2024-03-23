
#include <stdio.h>

int main(){
    typedef struct {
		int universidad;
		int carrera;
		int legajo;
		float promedio;
	} t_carrera;
	t_carrera carrera;
    FILE* fp;
    fp = fopen("promedio_carreras.dat", "rb");
    fread(&carrera, sizeof(t_carrera), 1, fp);
    int universidad_aux = carrera.universidad;
    int universidad_max = carrera.universidad;
    int universidad_cant = 1;
	while(feof(fp)==0){
        printf("\nCodigo Universidad: %d \nCodigo Carrera: %d \nLegajo Alumno: %d \nPromedio: %.2f\n", carrera.universidad, carrera.carrera, carrera.legajo, carrera.promedio);
        if (universidad_aux != carrera.universidad){
            universidad_cant++;
            universidad_aux = carrera.universidad;
        }
        if (universidad_max < carrera.universidad){
            universidad_max = carrera.universidad;
        }
		fread(&carrera, sizeof(t_carrera), 1, fp);
	}
    //int universidad_no_cargadas = universidad_max - universidad_cant;
    //printf("Universidades sin cargar: %d\n", universidad_no_cargadas);
    fclose(fp);
    return 0;
}

