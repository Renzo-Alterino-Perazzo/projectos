/*
Nombre de archivo: hw0.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW0 es: github.com/unlu-edu-ar/prog1-2022-hw-0-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido: Renzo Alterino Perazzo
DNI: 42.302.260
*/

#include <stdio.h>

/* Programe una funcion que reciba dos numeros enteros
   como parametros, y returne la suma de dichos numeros.
 */
int sumar_dos_numeros(int a, int b){
   //Escribir aca el codigo de la funcion sumar_dos_numeros
    int resultado = a + b;
    return resultado;
}

/* Programe una funcion que reciba un numero entero como parametro. 
   La funcion debe retornar 1, si el numero es mayor a o igual a cero. 
   La funcion debe retornar cero, si el numero fuese menor a cero.
 */
int positividad(int b){
   //Escribir aca el codigo de la funcion positividad
    int positivo;
    if (b >= 0) {
        positivo = 1;
    }
    else {
        positivo = 0;
    }
    return positivo;
}

/* Programe una funcion que recibe dos numeros enteros positivos n1 y n2 
   como parametros, donde n1 < n2, y retorna el resultado de sumar 
   los numeros enteros contenidos en el intervalo [n1...n2]
*/
int sumar_intervalo(int n1, int n2){
   //Escribir aca el codigo de la funcion sumar_intervalo
    int resultado;
    resultado = 0;

    for (int numero = n1; numero < n2+1; numero++) {
        resultado = resultado + numero;
    }
    return resultado;
}
