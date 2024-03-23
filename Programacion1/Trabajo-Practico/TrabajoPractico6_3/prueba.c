
#include <stdio.h>

void corte_control(FILE* fp){
    rewind(fp);
    int campo1, campo2, campo3, campo4;
    fscanf(fp, "%d,%d,%d,%d", &campo1, &campo2, &campo3, &campo4);
    while(feof(fp)==0){
        //printf("Campo 1: %d \nCampo 2: %d \nCampo 3: %d \nCampo 4: %d", campo1, campo2, campo3, campo4);
        printf("%d\n", campo1);
        fscanf(fp, "%d,%d,%d,%d", &campo1, &campo2, &campo3, &campo4);
    }
}

int main(){
    FILE* fp = fopen("corte_control_prueba.txt", "r");
    corte_control(fp);
    return 0;
}