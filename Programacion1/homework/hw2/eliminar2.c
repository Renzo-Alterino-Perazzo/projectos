
#include <stdio.h>
#include "assert.h"

int eliminar(int v[], int n, int* util, int pos){ 
	// Programar la funcion aqui
    int s;
    if (pos < *util) {
        v[pos] = v[pos+1];
        *util = *util - 1; s = 0;
    }
    else {
        s = 1;
    }
   return s;
}

int compareArrays(int a[], int b[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        if (a[i] != b[i]) return 0;
    }
    return 1;
}

void testeando_eliminar(){
    // Defino algunos vectores para probar 
    int arr3[] = {1,2,4};
    int arr4[] = {1,4,4};
    int arr5[] = {4,4,4};
    int arr6[] = {1,2,4,9};
    int arr7[] = {1,4,4,9};
    int util_arr3 = 3;
    int util_arr6 = 3;
    int ok; 
    int pos0 = 0;
    int pos1 = 1;
    int s3 = sizeof(arr3) / sizeof(arr3[0]);
    int s6 = sizeof(arr6) / sizeof(arr6[0]);   

    ok = eliminar(arr3, s3, &util_arr3, pos1);
    assert(compareArrays(arr3, arr4, s3));
    assert(util_arr3==2);
    assert(ok==0);
    ok = eliminar(arr3, s3, &util_arr3, pos0);
    assert(compareArrays(arr3, arr5, s3));
    assert(util_arr3==1);
    assert(ok==0);
    ok = eliminar(arr3, s3, &util_arr3, pos1);
    assert(compareArrays(arr3, arr5, s3));
    assert(util_arr3==1);
    assert(ok==1); 
    ok = eliminar(arr6, s6, &util_arr6, pos1);
    assert(compareArrays(arr6, arr7, s6));
    assert(util_arr6==2);
    assert(ok==0);
}

int main() {
    testeando_eliminar();
    printf("paso");
}