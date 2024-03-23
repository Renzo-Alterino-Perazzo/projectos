
#include <stdio.h>
#include <string.h>

typedef struct {
    char nombre[20];
    char apellido[20];
    char condicion[20];
    int parcial1, parcial2, parcial3;
    int legajo;
    float promedio;
} t_alumno;

void prueba(t_alumno tabla_alumno[]){
    int j;
    for (j=0; j < 4; j++) {
        printf("Numero de legajo: %d\n", tabla_alumno[j].legajo);
        printf("Nombre y apellido: %s ", tabla_alumno[j].nombre);
        printf("%s \n", tabla_alumno[j].apellido);
        printf("Promedio: %.2f \n", tabla_alumno[j].promedio);
        printf("Condicion: %s \n", tabla_alumno[j].condicion);
    }
}

int main(){
    t_alumno tabla_alumno[4];
    int i, nota, legajo;
    float promedio;
    char condicion [20];
    for (i = 0; i < 4; i++) {
        printf("Ingrese datos del alumno\n");
        printf("Ingrese numero de legajo: ");
        scanf("%d", &legajo);
        tabla_alumno[i].legajo = legajo;
        printf("Ingrese nombre del alumno: ");
        scanf("%s", tabla_alumno[i].nombre);
        printf("Ingrese apellido del alumno: ");
        scanf("%s", tabla_alumno[i].apellido);
        printf("Ingrese nota del primer parcial: ");
        scanf("%d", &nota);
        tabla_alumno[i].parcial1 = nota;
        printf("Ingrese nota del segundo parcial: ");
        scanf("%d", &nota);
        tabla_alumno[i].parcial2 = nota;
        printf("Ingrese nota del tercer parcial: ");
        scanf("%d", &nota);
        tabla_alumno[i].parcial3 = nota;
        promedio = tabla_alumno[i].parcial1 + tabla_alumno[i].parcial2 + tabla_alumno[i].parcial3;
        promedio = promedio/3;
        tabla_alumno[i].promedio = promedio;
        if (tabla_alumno[i].promedio >= 4){
            if(tabla_alumno[i].promedio >= 7){
                strcpy(tabla_alumno[i].condicion, "Promovido");
            }
            else{
                strcpy(tabla_alumno[i].condicion, "Regular");
            }
        }
        else{
            strcpy(tabla_alumno[i].condicion, "Libre");
        }
    }
	prueba(tabla_alumno);
    return 0;
}
