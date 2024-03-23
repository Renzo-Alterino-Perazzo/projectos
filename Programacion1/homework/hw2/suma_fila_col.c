
#include <stdio.h>
#include "assert.h"

void suma_filas_col(int m, int n, int arr[m][n], int v[m], int w[n]) {
    int acumulador_fila, acumulador_columna;
    for (int i = 0; i < m; i++) {
        acumulador_fila = 0;
        for (int j = 0; j < n; j++) {
            acumulador_fila += arr[i][j];
        }
        v[i] = acumulador_fila;
    }
    for (int k = 0; k < n; k++) {
        acumulador_columna = 0;
        for (int l = 0; l < m; l++) {
            acumulador_columna += arr[l][k];
        }
        w[k] = acumulador_columna;
    }
}

int compareArrays(int a[], int b[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}


void testeando_suma_filascol(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    // Defino 2 vectores para el ejercicio de sumar filas y columnas
    int v1[m1];
    int w1[n1];
    int v2[m2];
    int w2[n2];

    int r_v1[m1] ={4,2};
    int r_w1[n1] ={2,4,0};
    int r_v2[m2] ={2,3,2};
    int r_w2[n2] ={4,3};

    // Obtengo la longitud de los vectores
    int sv1 = sizeof(v1) / sizeof(v1[0]);
    int sw1 = sizeof(w1) / sizeof(w1[0]);

    suma_filas_col(m1, n1, mat1, v1, w1);
    suma_filas_col(m2, n2, mat2, v2, w2);
    assert(compareArrays(v1, r_v1, sv1));   
    assert(compareArrays(w1, r_w1, sw1)); 
    assert(compareArrays(v2, r_v2, sw1));  
    assert(compareArrays(w2, r_w2, sv1));  
}

int main() {
testeando_suma_filascol();
printf("paso");
}