
#include <stdio.h>

void leer(char nom_arch[]) {
    FILE *arch = fopen(nom_arch, "r");
    int dia, mes, anio, lluvia, tmin, tmax;
    fscanf(arch, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax); //leo los datos
    while (feof(arch)==0) {
        printf("Dia: %d \nMes: %d \nAño: %d \nLluvia: %d \nTemperatura minima: %d \nTemperatura maxima: %d\n", dia, mes, anio, lluvia, tmin, tmax); //muestra lo leido
        fscanf(arch, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax); //leo los datos
    }
    fclose(arch); //cierro el archivo
}

int main() {
    char nombre[] = "datos_lluvia_temp.tsv";
    leer(nombre);
    return 0;
}