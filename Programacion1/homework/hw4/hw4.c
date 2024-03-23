/*
Nombre de archivo: hw4.c (No cambiar el nombre de este archivo)
El repositorio donde esta tu HW4 es: github.com/unlu-edu-ar/prog1-2022-hw-4-TuNombreDeUsuarioGithub
Importante: No cambiar el nombre del archivo

Completa con tu nombre, apellido y DNI
Nombre y Apellido:
DNI:
*/
 
 /* 
 Se dispone de archivos binarios de informacion academica a nivel pais, donde se 
 guardan los promedios de los alumnos que estan estudiando en las distintas 
 universidades nacionales. 
 El archivo binario de informacion academica tiene guardada la informacion en 
 el siguiente orden:
 - codigo de la universidad (int). Es un numero entero entre 1 y 39.
 - codigo de la carrera (int). Es un numero entero entre 101 y 108.
 - legajo del alumno (int)
 - promedio del alumno en la carrera (float). Es un numero real entre 0 y 10.0

 Nota: para evitar errores de incompatilidades, no hemos puesto tildes, ni caracteres
 propios del lenguaje castellano.
 */

#include <stdio.h>

/* 
Programe una funcion que recibe los datos de un archivo binario de informacion
academica, y retorne la cantidad de universidades que no tienen inscriptos cargados
en el archivo binario.
INPUT: fp (puntero a archivo binario)
OUTPUT: universidades_sin_cargar (int)
*/

typedef struct {
	int universidad;
	int carrera;
	int legajo;
	float promedio;
} t_carrera;

int cant_universidades_sin_cargar(FILE* fp){ 
	// Programar la funcion aqui
	//fp = fopen("promedio_carreras.dat", "rb");

	t_carrera carrera;
	fread(&carrera, sizeof(t_carrera), 1, fp);
	int universidad_aux = carrera.universidad;
    int universidad_max = carrera.universidad;
    int universidad_cant = 1;
	while(feof(fp)==0){
		if (universidad_aux != carrera.universidad){
            universidad_cant++;
            universidad_aux = carrera.universidad;
        }
        if (universidad_max < carrera.universidad){
            universidad_max = carrera.universidad;
        }
		fread(&carrera, sizeof(t_carrera), 1, fp);
	}
	int universidad_no_cargadas = universidad_max - universidad_cant;
	return universidad_no_cargadas;
	fclose(fp);
}

/* 
Programe una funcion que recibe los datos de un archivo binario de informacion
academica, retorne el codigo de la carrera con mayor cantidad de inscriptos.
En el caso de que hubiese mas de una carrera con mayor cantidad de inscriptos,
debera retornar la de menor codigo.
INPUT: fp (puntero a archivo binario)
OUTPUT: carrera_max_inscriptos (int)
*/

int maximos_inscriptos(FILE* fp){ 
	// Programar la funcion aqui
    t_carrera carrera;
    int acumulador [8];
    int inscriptos_mayor = 0, carrera_mayor;
    for (int i = 0; i < 8; i++){
        acumulador[i] = 0;
    }
    fread(&carrera, sizeof(t_carrera), 1, fp);
    while(feof(fp)==0){
        acumulador[carrera.carrera-101] = acumulador[carrera.carrera-101] + 1;
        fread(&carrera, sizeof(t_carrera), 1, fp);
    }
    for (int j = 0; j < 8; j++){
        if (inscriptos_mayor < acumulador[j]){
            inscriptos_mayor = acumulador[j];
            carrera_mayor = j + 101;
        }
    }
    fclose(fp);
    return carrera_mayor;
}

/* 
Programe una funcion que recibe los datos de un archivo binario de informacion
academica, una carrera c, y un umbral u, y devuelva cuantos alumnos tienen un 
promedio mayor o igual al umbral, 
INPUT: fp (puntero a archivo binario), c (int), u (float)
OUTPUT: cant_alumnos (int)
*/

int promedio_umbral(FILE* fp, int c, float u){ 
	// Programar la funcion aqui
    t_carrera carrera;
    fp = fopen("promedio_carreras.dat", "rb");
    int acumulador = 0;
    fread(&carrera, sizeof(t_carrera), 1, fp);
    while(feof(fp)==0){
        fread(&carrera, sizeof(t_carrera), 1, fp);
        if (carrera.carrera == c && carrera.promedio >= u){
            acumulador++;
        }
    }
    fclose(fp);
    return acumulador;
}
