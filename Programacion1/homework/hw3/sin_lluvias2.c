
#include <stdio.h>
#include "assert.h"

int sin_lluvias(FILE* fp, int mes){ 
    //fp = fopen("datos_lluvia_temp.tsv", "r");
    rewind(fp);
    int dia,es_mes,anio,cant_lluvia,temp_min,temp_max;
    int contador=0;
    fscanf(fp,"%i %i %i %i %i %i", &dia, &es_mes, &anio, &cant_lluvia,&temp_min,&temp_max);
    while (feof(fp) == 0){
   
        if (es_mes == mes && cant_lluvia == 0){
            contador ++;
        }
        fscanf(fp,"%i %i %i %i %i %i", &dia, &es_mes, &anio, &cant_lluvia,&temp_min,&temp_max);
        }
    return contador;
    fclose(fp);
}

void test_sin_lluvias(){
    FILE* fp;

    fp = fopen("datos_lluvia_temp.tsv", "r");
    printf("Corriendo test_sin_lluvias...");
    assert(sin_lluvias(fp, 1)==2);
    assert(sin_lluvias(fp, 2)==4);
    assert(sin_lluvias(fp, 3)==8);
    assert(sin_lluvias(fp, 4)==0);
    printf("Paso!\n");
    fclose(fp);
}

int main() {
    test_sin_lluvias();
    return 0;
}