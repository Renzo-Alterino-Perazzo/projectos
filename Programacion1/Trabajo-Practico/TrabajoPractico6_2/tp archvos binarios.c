#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


// En un archivo Binario (o archivo de registros), denominado "gestion.dat", se almacena 
//la información correspondiente a las personas 
// que tienen acceso al sistema de gestión académica. Los datos almacenados son:  
//  Legajo…... integer (a partir de 1) 
//  Apellido... char [20] 
//  Nombre.... char [20] 
//  Cargo…... char [20] 
//  Permiso...  integer (toma valores del 1 al 5)
//  Activo …...integer (1: activo, 0:inactivo)
// Se deberá realizar un programa que permita: 
// Crear el archivo con 10 registros.

// Mostrar un listado de todos los usuarios ACTIVOS, informando los siguientes datos:
//  Legajo    Apellido Nombre              Cargo 
// Visualizar todos los datos de un empleado, ingresando por teclado su número de legajo. 
// Si el legajo ingresado no pertenece a un empleado de la organización, debe informarse dicha situación por pantalla. 

//  Implementar ABM de dicho archivo.
// NOTAS:  
// El número de legajo debe ser incremental. En este caso, además, coincide con la clave 
// (el primer legajo es el 1 y se encuentra en la posición 1 del archivo). 
// Para realizar una baja, se deberá ingresar el número de legajo por teclado y registrarse 
// el valor 0 en el campo “Activo”.  


typedef struct
{
    int legajo;
    char nombre[100];
    char apellido[100];
    char cargo[100];
    int activo;
} t_usuario;


void sacafl(char *nombre){
    if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n')){
        nombre[strlen(nombre) - 1] = '\0';
    }
}

void pausa(void){
	getc(stdin);
	printf(" \n\n\n \t\t\t\t Presione enter para continuar");
	getc(stdin);
}

void crear_archivo (char nombre[], char modo[]){
    FILE *archi = fopen(nombre, modo);
}

void cargar_datos(char nombre[], char modo[], int n){
    FILE *archi = fopen(nombre, modo);
    t_usuario usuario;
    char nada[200];
    usuario.legajo = n;
    printf("\ningrese el nombre del usuario: ");
    fgets(usuario.nombre, 100, stdin);
    strtok(usuario.nombre, "\n");
    printf("Ingrese el apellido del usuario: ");
    fgets(usuario.apellido, 100, stdin);
    strtok(usuario.apellido, "\n");
    printf("Ingrese el cargo del usuario: ");
    fgets(usuario.cargo, 100, stdin);
    strtok(usuario.cargo, "\n");
    usuario.activo = 1;
    fseek(archi, sizeof(t_usuario)*n,SEEK_SET);
    fwrite(&usuario, sizeof(t_usuario), 1, archi);
    fclose(archi);
}

void mostrar_archivo(char nombre[], char modo[], int n){
    FILE *arch = fopen(nombre, modo);
    t_usuario usuario;
    fread(&usuario, sizeof(t_usuario), 1, arch);
    while (feof(arch) == 0){
        if (usuario.activo == 1){
            printf("legajo: %i             nom: %s            ape: %s             cargo: %s\n",usuario.legajo, usuario.nombre,usuario.apellido,usuario.cargo);

        }
        fread(&usuario, sizeof(t_usuario), 1, arch);
    }
    pausa();
    fclose(arch);
}


void mostrar_usuario(char nombre[], char modo[]){
    FILE *arch = fopen(nombre,modo);
    t_usuario usuario;
    int legajo;
    printf("\nIngrese el legajo del usuario a buscar: ");
    scanf("%i", &legajo);
    while (legajo > 3 || legajo < 1){
        printf("\nEl legajo ingresado no existe, vuelva a intentarlo: ");
        scanf("%i", &legajo);
    }
    fseek(arch,sizeof(t_usuario)*legajo,SEEK_SET);
    fread(&usuario, sizeof(t_usuario), 1, arch);
    printf("\nlegajo: %i             nom: %s            ape: %s             cargo: %s\n",usuario.legajo, usuario.nombre,usuario.apellido,usuario.cargo);
    pausa();
    fclose(arch);
}

void baja(char nombre[], char modo[]){
    FILE *arch = fopen(nombre,modo);
    t_usuario usuario;
    int legajo;
    printf("Ingrese el legajo a dar de baja: ");
    scanf("%i", &legajo);
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_SET);
    fread(&usuario, sizeof(t_usuario), 1, arch);
    usuario.activo = 0;
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_CUR-1);
    fwrite(&usuario, sizeof(t_usuario), 1, arch);
    printf("se ha dado de baja correctamente!\n");
    fclose(arch);
}

void alta(char nombre[], char modo[]){
    FILE *arch = fopen(nombre,modo);
    t_usuario usuario;
    int legajo;
    printf("Ingrese el legajo a dar de alta: ");
    scanf("%i", &legajo);
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_SET);
    fread(&usuario, sizeof(t_usuario), 1, arch);
    usuario.activo = 1;
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_CUR-1);
    fwrite(&usuario, sizeof(t_usuario), 1, arch);
    fclose(arch);
}

void modificacion(char nombre[], char modo[]){
    FILE *arch = fopen(nombre,modo);
    t_usuario usuario;
    char nada[200];
    int legajo;
    char n[100];
    char a[100];
    char c[100]; 
    printf("\nIngrese el legajo a modificar: ");
    scanf("%i", &legajo);
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_SET);
    fread(&usuario, sizeof(t_usuario), 1, arch);
    if (usuario.activo == 1){
        printf("ingrese un nuevo nombre (- no modifica): ");
        fgets(nada,200,stdin);
        fgets(n, 100, stdin);
        sacafl(n);
        if (n[0] != '-'){
            strcpy(usuario.nombre, n);
        }
    
        printf("ingrese un nuevo apellido (- no modifica): ");
        fgets(a, 100, stdin);
        if (a[0] != '-'){
            strcpy(usuario.apellido, a);
        }
    
        printf("ingrese un nuevo cargo (- no modifica): ");
        fgets(c, 100, stdin);
        if (c[0]!= '-'){
            strcpy(usuario.cargo, c);
        }
    }
    if (usuario.activo == 0){
        printf("\nEl usuario esta dado de baja");
    }
    fseek(arch, sizeof(t_usuario)*legajo, SEEK_CUR-1);
    fwrite(&usuario, sizeof(t_usuario), 1, arch);
    fclose(arch);
}



int main(){
    int n = 1;
    int i;
    int a = 100;
    char campo[100];
    char nada[200];
    crear_archivo("gestion.dat", "wb");
    for (i = 0 ; i < 3 ; i++){
        cargar_datos("gestion.dat", "r+b", n);
        n++;
    }
    while (a != 0){
        printf("\n\nSi desea ver los datos de todos los activos, ingrese 1.\n");
        printf("si desea ver los datos de un usuario en especifico, ingrese 2.\n");
        printf("si desea dar de baja un usuario en especifico, ingrese 3.\n");
        printf("si desea dar de alta un usuario dado de baja, ingrese 4:\n");
        printf("si desea modificar algun usuario, ingrese 5.\n");
        printf("si desea salir del programa, ingrese 0\n");
        scanf("%i", &a);
        fgets(nada, 100, stdin);

        if (a == 1){
            mostrar_archivo("gestion.dat", "r+b", n);
        }
        else if(a == 2){
            mostrar_usuario("gestion.dat", "r+b");
        }
        else if(a == 3){
            baja("gestion.dat", "r+b");
        }
        else if(a == 4){
            alta("gestion.dat", "r+b");
        }
        else if(a == 5){
            modificacion("gestion.dat", "r+b");
        }
    }
    printf("Hasta luego!");
}