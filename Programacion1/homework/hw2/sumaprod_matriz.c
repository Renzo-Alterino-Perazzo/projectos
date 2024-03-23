
#include <stdio.h>
#include "assert.h"

int sumaprod_matriz(int m, int n, int arr[m][n]){ 
	// Programar la funcion aqui
   int s, i, j;
   if (m >= n) {
      s = 0;
      for (i = 0; i < m; i++){
         for (j = 0; j < n; j++) {
            s = s + arr[i][j];
         }
      }
   }
   else {
      s = 1;
      for (i = 0; i < m; i++) {
         for (j = 0; j < n; j++)  {
            s = s * arr[i][j];
         }
      }
   }
   return s;
}

void testeando_sumaprod_matriz(){
    // Defino dos matrices para los casos de test de matrices
    #define m1 2
    #define n1 3
    int mat1[m1][n1] = {{1,3,0},{1,1,0}};
    #define m2 3
    #define n2 2
    int mat2[m2][n2] = {{1,1},{2,1},{1,1}};

    assert(sumaprod_matriz(m1, n1, mat1)==0);   
    assert(sumaprod_matriz(m2, n2, mat2)==7); 
}

int main() {
testeando_sumaprod_matriz();
printf("Paso");
}