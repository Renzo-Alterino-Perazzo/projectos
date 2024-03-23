// test_hw1.cpp
// IMPORTANTE: No modificar ni borrar ni renombrar este archivo

#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "hw1.c"

int m1[] = {1,3,2};
int m2[] = {2};
int m3[] = {6,4};
int m4[] = {1,1,2};
int r_m1[] = {2,3,1};
int r_m3[] = {4,6};

TEST_CASE( "apariciones", "[multi-file:2]" ) {
    REQUIRE(apariciones(m1,3,3) == 1);
    REQUIRE(apariciones(m1,3,8) == 0);    
    REQUIRE(apariciones(m2,1,2) == 1);    
    REQUIRE(apariciones(m4,3,1) == 2);    
}

TEST_CASE( "mayor", "[multi-file:2]" ) {
   REQUIRE(mayor(m1,3) == 3);
   REQUIRE(mayor(m2,1) == 2);
   REQUIRE(mayor(m3,2) == 6);
}

TEST_CASE( "reverso", "[multi-file:2]" ) {
    REQUIRE(reverso(m1,r_m1,3) == 1);
    REQUIRE(reverso(m3,r_m3,2) == 1);
    REQUIRE(reverso(m2,m2,1) == 1);
    REQUIRE(reverso(m1,m4,3) == 0);
}

TEST_CASE( "ordenado", "[multi-file:2]" ) {
    REQUIRE(ordenado(m1,3)==0);
    REQUIRE(ordenado(m2,1)==1);    
    REQUIRE(ordenado(m3,2)==1);  
    REQUIRE(ordenado(m4,3)==1);  
}

