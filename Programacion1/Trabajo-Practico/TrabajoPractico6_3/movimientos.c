
#include <stdio.h>

void reporte_movimiento(FILE* fp){
    rewind(fp);
    int n_cuenta, movimiento, n_cuenta_anterior;
    float importe, saldo;
    fscanf(fp, "%d,%d,%f", &n_cuenta, &movimiento, &importe);
    while(feof(fp)==0){
        saldo = 0;
        n_cuenta_anterior = n_cuenta;
        while(n_cuenta == n_cuenta_anterior && feof(fp)==0){
            if (movimiento==1){
                saldo += importe;
            }
            else{
                saldo = saldo - importe;
            }
            fscanf(fp, "%d,%d,%f", &n_cuenta, &movimiento, &importe);
        }
        printf("Numero de cuenta: %d\n", n_cuenta_anterior);
        printf("Saldo: %.2f\n", saldo);
    }
    fclose(fp);
}

int main(){
    FILE* fp = fopen("movimientos.txt", "r");
    reporte_movimiento(fp);
    return 0;
}