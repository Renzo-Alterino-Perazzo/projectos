
#include <stdio.h>
#include "assert.h"

int minimo_elem_matriz(int m, int n, int arr[m][n]) {
    int minimo = arr[0][0];
    for (int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (arr[i][j] < minimo) {
                minimo = arr[i][j];
            }
        }
    }
    return minimo;
}

void testeando_minimo_elem_matriz(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    assert(minimo_elem_matriz(m1, n1, mat1)==0);   
    assert(minimo_elem_matriz(m2, n2, mat2)==1); 
}

int main() {
testeando_minimo_elem_matriz();
printf("minimo: pasado");
}