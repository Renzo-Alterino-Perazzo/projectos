
#include "assert.h"
#include <stdio.h>

int agregar(int v[], int n, int* util, int elem){ 
	// Programar la funcion aqui
	int s = 0;
	if (n > *util) {
    	v[*util] = elem;
        *util = *util + 1;
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

void testeando_agregar(){
    // Defino algunos vectores para probar 
    int arr1[] = {1,3,0};
    int arr2[] = {1,2,0};
    int arr3[] = {1,2,4};
    int util_arr1 = 1;
    int ok; 
    int elem1 = 2;
    int elem2 = 4;
    // s1 is the size of array 1
    int s1 = sizeof(arr1) / sizeof(arr1[0]);

    ok = agregar(arr1, s1, &util_arr1, elem1);
    assert(compareArrays(arr1, arr2, s1));
    assert(util_arr1==2);
    assert(ok==0);
    ok = agregar(arr1, s1, &util_arr1, elem2);
    assert(compareArrays(arr1, arr3, s1));
    assert(util_arr1==3);
    assert(ok==0);
    ok = agregar(arr1, s1, &util_arr1, elem2);
    assert(compareArrays(arr1, arr3, s1));
    assert(util_arr1==3);
    assert(ok==1);
}

int main() {
    testeando_agregar();
    printf("Pasado: agregar");
}