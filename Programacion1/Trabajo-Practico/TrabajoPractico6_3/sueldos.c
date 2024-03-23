
#include <stdio.h>

void lectura(FILE* fp){
    rewind(fp);
    int sucursal, empleado;
    float sueldo;
    fscanf(fp, "%d,%d,%f", &sucursal, &empleado, &sueldo);
    while(feof(fp)==0){
        printf("Sucursal %d \nCodigo empleado: %d \nSueldo: %.2f\n", sucursal, empleado, sueldo);
        fscanf(fp, "%d,%d,%f", &sucursal, &empleado, &sueldo);
    }
    fclose(fp);
}

void reporte_sueldo(FILE* fp){
    rewind(fp);
    int sucursal, empleado, acumulador, sucursal_anterior;
    float sueldo;
    fscanf(fp, "%d,%d,%f", &sucursal, &empleado, &sueldo);
    printf("REPORTE DE SUELDO\n");
    while(feof(fp)==0){
        acumulador = 0;
        sucursal_anterior = sucursal;
        printf("Sucursal %d\n", sucursal);
        while(sucursal == sucursal_anterior && feof(fp)==0) {
            printf("Codigo empleado: %d \nSueldo: %.2f\n", empleado, sueldo);
            acumulador += sueldo;
            fscanf(fp, "%d,%d,%f", &sucursal, &empleado, &sueldo);
        }
        printf("Total sucursal: %d\n", acumulador);
    }
    fclose(fp);   
}

int main(){
    FILE* fp = fopen("sueldos.txt", "r");
    //lectura(fp);
    reporte_sueldo(fp);
    return 0;
}