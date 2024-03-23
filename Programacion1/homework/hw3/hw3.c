/*
Nombre de archivo: hw3.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW3 es: github.com/unlu-edu-ar/prog1-2022-hw-3-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido: Renzo Alterino Perazzo
DNI: 42.302.260
*/
 
 /* 
 Se disponen de archivos de texto, donde se guardan los datos del clima. 
 Cada linea de un archivo de clima se corresponde a un dia del anio. 
 Los datos en cada linea estan separados por tabuladores (a los archivos de texto 
 que tienen los datos separados por tabuladores, se los acostumbra guardar con 
 la extension .tsv, que viene del ingles tab separated values).
 Los datos guardados en cada linea son numeros enteros, y estan en el siguiente orden:
 - dia
 - mes
 - anio 
 - cantidad de lluvia caida 
 - temperatura minima
 - temperatura maxima

 Nota: para evitar errores de incompatilidades, no hemos puesto tildes, ni caracteres
 propios del lenguaje castellano.
 */

#include <stdio.h>

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, 
y devuelva cuantos dias hubo sin lluvias en ese mes.
INPUT: fp (puntero a archivo), mes (int)
OUTPUT: sin_lluvias (int)
*/

int sin_lluvias(FILE* fp, int mes){ 
	// Programar la funcion aqui
	rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    int acumulador = 0;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while (feof(fp)==0) {
        if (mes_aux == mes && lluvia == 0) {
            acumulador++;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    return acumulador;
    fclose(fp);
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y devuelva cuantos dias 
llovio menos de x mm, y cuantos dias llovio x mm o mas que x mm, en el anio.
INPUT: fp (puntero a archivo), x (int), lluvias_menor_x (int*), lluvias_mayorigual_x (int*)  
OUTPUT: void
*/

void llovio_umbral(FILE* fp, int x, int* lluvias_menor_x, int* lluvias_mayorigual_x){ 
	// Programar la funcion aqui
    fp = fopen("datos_lluvia_temp.tsv", "r");
    rewind(fp);
    int lluvia_menor = 0, lluvia_mayor = 0;
    int dia, mes, anio, lluvia, tmin, tmax;
    fscanf(fp, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax);
    while(feof(fp)==0){
        if (lluvia >= x){
            lluvia_mayor++;
            *lluvias_mayorigual_x = lluvia_mayor;
        }
        else {
            lluvia_menor++;
            *lluvias_menor_x = lluvia_menor;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia, &mes, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva cuantos dias se registro la maxima temperatura del mes. 
INPUT: fp (puntero a archivo), mes (int)
OUTPUT: cant_dias_maximo_calor (int) 
*/

int contador_dias_maximo_calor(FILE* fp, int mes){ 
	// Programar la funcion aqui
    int dia, mes_aux, anio, lluvia, tmin, tmax;
    int dias_tmax = 0, temperatura_max = 0;
    fp=fopen("datos_lluvia_temp.tsv","r");
	rewind(fp);
    fscanf(fp,"%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while(feof(fp)==0){
        if (mes==mes_aux) {
            if(tmax > temperatura_max) {
                temperatura_max = tmax;
                dias_tmax = 0;
            }
            if (tmax==temperatura_max) {
                dias_tmax++;
            }
        }
        fscanf(fp,"%d %d %d %d %d %d", &dia, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
    return dias_tmax;
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva el dia donde se registro la minima temperatura del mes y cual fue dicha temperatura. 
En el caso de haber varios dias con temperatura minima, debe devolver el primer dia.
INPUT: fp (puntero a archivo), mes (int), dia (int*), temp_minima (int*)  
OUTPUT: void
*/

void dia_mas_frio_mes(FILE* fp, int mes, int* dia, int* temp_minima){ 
	// Programar la funcion aqui
    fp = fopen("datos_lluvia_temp.tsv","r");
    rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    *temp_minima = tmin;
    while(feof(fp)==0){
        if (mes_aux==mes && tmin < *temp_minima ){
            *temp_minima = tmin;
            *dia = dia_aux;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    fclose(fp);
}

/* 
Programe una funcion que recibe los datos de un archivo de clima, y un mes, y
devuelva el promedio de lluvias de dicho mes. 
INPUT: fp (puntero a archivo), mes (int) 
OUTPUT: promedio_lluvia (float) 
*/

float promedio_lluvias_mes(FILE* fp, int mes){ 
	// Programar la funcion aqui
    rewind(fp);
    int dia_aux, mes_aux, anio, lluvia, tmin, tmax;
    float promedio;
    int cant_lluvia = 0, cant_dia = 0;
    fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    while (feof(fp)==0) {
        if (mes_aux == mes) {
            cant_lluvia += lluvia;
            cant_dia++;
        }
        fscanf(fp, "%d %d %d %d %d %d", &dia_aux, &mes_aux, &anio, &lluvia, &tmin, &tmax);
    }
    promedio = cant_lluvia/cant_dia;
    return promedio;
}
