/*
Nombre de archivo: hw1.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW1 es: github.com/unlu-edu-ar/prog1-2022-hw-1-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido:
DNI:
*/

/* Programe una funcion que recibe como parametros un vector v 
de numeros enteros, su cantidad de elementos n, y un entero k, 
y devuelve la cantidad de apariciones de k en v.
*/
int apariciones(int v[], int n, int k){
   //Escribir aca el codigo de la funcion apariciones
   int contador = 0;
   int acumulador = 0;
   while (contador < n) {
      if (v[contador] == k) {
         acumulador += 1;
      }
      contador += 1;
   }
   return acumulador;
}

/* Programe una funcion que reciba como parametro un vector v 
de numeros enteros mayores o iguales a cero, y su cantidad de 
elementos n, y retorne el mayor elemento del vector.
 */
int mayor(int v[], int n){
   //Escribir aca el codigo de la funcion mayor
   int mayor = v[0];
   int acumulador = 0;
   while (acumulador < n) {
      if (mayor < v[acumulador]) {
         mayor = v[acumulador];
      }
      acumulador += 1;
   }
   return mayor;
}

/* Programe una funcion que reciba como parametros dos vectores de 
numeros enteros v1 y v2, y su longitud n (los vectores tienen igual
longitud), y devuelva 1 si v2 es el orden reverso de v1, y 0 si no. 
Ejemplo: 
Si v1 = {3,4,1} su reverso es v2 = {1,4,3}, y la funcion retorna 1.
 */
int reverso(int v1[], int v2[], int n){
   //Escribir aca el codigo de la funcion reverso
   int acumulador = 0, contador = 0;
   int reverso = 0;
   while (contador < n) {
      if (v1[contador] == v2[n-1-contador]) {
         acumulador += 1;
      }
      contador += 1;
   }
   if (acumulador == n) {
      reverso = 1;
   }
   return reverso;
}

/* Programe una funcion que recibe un vector v de numeros enteros, 
y su longitud n, y devuelve 1 si esta ordenado (ya sea creciente o 
decrecientemente), y 0 si no.
Ejemplo:
{1,1,2} esta ordenado en forma ascendente y retorna 1.
{6,4} esta ordenado en forma descendente y retorna 1.
{1,3,2} esta desordenado y retorna 0.
*/
int ordenado(int v[], int n){
   //Escribir aca el codigo de la funcion ordenado
   int ascendente, descendente, orden , contador; ascendente = 0; descendente = 0; orden = 1; contador = 0;
   while (contador < n-1) {
      if (v[contador] < v[contador+1]) {
         ascendente += 1;
      }
      else {
         if (v[contador] > v[contador+1]) {
            descendente += 1;
         }
         else {
            ascendente += 1;
            descendente += 1;
         }
      }
      contador += 1;
   }
   if (ascendente < n-1 && descendente < n-1) {
      orden = 0; 
   }
   return orden;
}

