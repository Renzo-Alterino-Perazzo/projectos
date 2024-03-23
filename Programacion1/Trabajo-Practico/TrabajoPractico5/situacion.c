
#include <stdio.h>

typedef struct {
    int legajo, parcial1, parcial2, parcial3;
    char nombre [20], apellido [20], situacion [20];
    float promedio;
} t_alumno;

void alumno_situacion(t_alumno alumnos[], int tamanio) {
    for (int i = 0; i < tamanio; i++){
        printf("Ingrese numero de legajo: ");
        scanf("%d", alumnos[i].legajo);
        printf("Ingrese nombre del alumno: ");
        scanf("%s", alumnos[i].nombre);
        printf("Ingrese apellido del alumno: ");
        scanf("%s", alumnos[i].apellido);
        printf("Ingrese nota del primer parcial: ");
        scanf("%d", alumnos[i].parcial1);
        printf("Ingrese nota del segundo parcial: ");
    }
}

int main(){
    t_alumno alumnos[4];
    int tamanio = sizeof(alumnos)/sizeof(alumnos[0]);
    alumno_situacion(alumnos, tamanio);
    return 0;
}