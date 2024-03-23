/* test_hw4.c 
   IMPORTANTE: No modificar ni borrar ni renombrar este archivo 
   Tests del HW4 - Programacion 1, Universidad Nacional de Lujan */

/* 1 includes */
#include "hw4.c"
#include "assert.h"
#include <stdio.h>
/* 2 defines */
// Testings sin cargar (s), umbral (u), maximos inscriptos (m)
#define OPTSTR "s:m:u"
/* 3 external declarations */
/* 4 typedefs */
/* 5 global variable declarations */
/* 6 function prototypes */
void test_cant_universidades_sin_cargar();
void test_maximos_inscriptos();
void test_promedio_umbral();
void test_all();

int main(int argc, char *argv[]) {
// /* 7 command-line parsing */
    if(argc==1)
        test_all();

    if(argc>=2)
    {
        int opt = *(argv[1]);
        switch (opt)
        {
        case 's':
            test_cant_universidades_sin_cargar();
            break;

        case 'm':
            test_maximos_inscriptos();
            break;

        case 'u':
            test_promedio_umbral();
            break;

        default:
            printf("Ese parametro de linea no existe!\n");
            return 1;
        }
    }
    return 0;
}

/* 8 function declarations */

// Funciones de tests de archivos

void test_cant_universidades_sin_cargar(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_cant_universidades_sin_cargar... ");
    assert(cant_universidades_sin_cargar(fp)==6);
    printf("Paso!\n");
    fclose(fp);
}

void test_maximos_inscriptos(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_maximos_inscriptos... ");
    assert(maximos_inscriptos(fp)==102);
    printf("Paso!\n");
    fclose(fp);
}

void test_promedio_umbral(){
    FILE* fp;

    fp = fopen("promedio_carreras.dat", "rb");
    printf("Corriendo test_promedio_umbral... ");
    assert(promedio_umbral(fp,101,9.0)==41);
    assert(promedio_umbral(fp,103,9.9)==6);
    printf("Paso!\n");
    fclose(fp);
}

void test_all(){
    printf("Testear todo...\n");
    test_cant_universidades_sin_cargar();
    test_maximos_inscriptos();
    test_promedio_umbral();
    printf("Pasaste todos los tests. Felicitaciones!!\n");
}