
#include <stdio.h>
#include <assert.h>
#include "hw1.c"


int main() {
    // test_hw1.cpp
// IMPORTANTE: No modificar ni borrar ni renombrar este archivo

int m1[] = {1,3,2};
int m2[] = {2};
int m3[] = {6,4};
int m4[] = {1,1,2};
int r_m1[] = {2,3,1};
int r_m3[] = {4,6};

    assert(apariciones(m1,3,3) == 1);
    assert(apariciones(m1,3,8) == 0);    
    assert(apariciones(m2,1,2) == 1);    
    assert(apariciones(m4,3,1) == 2);   
    printf("Paso apariciones\n");

   assert(mayor(m1,3) == 3);
   assert(mayor(m2,1) == 2);
   assert(mayor(m3,2) == 6);
   printf("Paso mayor\n");



    assert(reverso(m1,r_m1,3) == 1);
    assert(reverso(m3,r_m3,2) == 1);
    assert(reverso(m2,m2,1) == 1);
    assert(reverso(m1,m4,3) == 0);
    printf("Paso reverso\n");


    assert(ordenado(m1,3)==0);
    assert(ordenado(m2,1)==1);    
    assert(ordenado(m3,2)==1);  
    assert(ordenado(m4,3)==1);
    printf("Paso ordenado\n");

}