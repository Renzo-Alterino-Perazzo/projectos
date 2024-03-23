
#include <stdio.h>

void informe_sueldo(FILE* fp){
    rewind(fp);
    int sucursal, departamento, empleado, sucursal_anterior, departamento_anterior;
    float acumulador_departamento, acumulador_sucursal;
    float sueldo;
    fscanf(fp, "%d,%d,%d,%f", &sucursal, &departamento, &empleado, &sueldo);
    printf("REPORTE DE SUELDO\n");
    while(feof(fp)==0){
        acumulador_sucursal = 0;
        sucursal_anterior = sucursal;
        printf("Sucursal %d\n", sucursal);
        while(sucursal == sucursal_anterior && feof(fp)==0){
            acumulador_departamento = 0;
            departamento_anterior = departamento;
            printf("Departamento: %d\n", departamento);
            while(departamento == departamento_anterior && feof(fp)==0){
                acumulador_departamento += sueldo;
                printf("Codigo empleado: %d \nSueldo: %.2f\n", empleado, sueldo);
                fscanf(fp, "%d,%d,%d,%f", &sucursal, &departamento, &empleado, &sueldo);
            }
            printf("Total departamento: %.2f\n", acumulador_departamento);
            acumulador_sucursal += acumulador_departamento;
        }
        printf("Total sucursal: %.2f\n", acumulador_sucursal);
    }
    fclose(fp);
}

int main(){
    FILE* fp = fopen("sueldos2.txt", "r");
    informe_sueldo(fp);
    return 0;
}