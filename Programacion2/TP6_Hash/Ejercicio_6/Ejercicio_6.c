#include "tabla_hash.h"
#include "validaciones.h"
#include "arbol-avl.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

struct t_persona
{
    int dni;
    char apellido[20];
    char nombre[20];
};
typedef struct t_persona *Persona;

//                  ----------Prototipos----------
int ingresar_valor();
void in_orden(NodoArbol N);
void ingresar_personas(TablaHash tabla);
void Buscar_personas(TablaHash tabla);
int transformacion_clave(int clave);
//
//
//
int main()
{
    TablaHash tabla = th_crear(41, *transformacion_clave);
    printf("\t\t----Personas vacunadas en una determinada fecha----");
    printf("\n\n\t\t -Seleccione una opcion-\n1\t-Cargar personas\n2\t-Buscar Personas\n0\t-Salir\n");
    int respuesta;
    fflush(stdin);
    respuesta = ingresar_valor();

    while (respuesta != 0)
    {
        system("cls");
        if (respuesta == 1)
        {

            printf("Indique cuantas fechas distintas ingresara: ");
            int num;
            fflush(stdin);
            num = ingresar_valor();
            for (int i = 0; i < num; i++)
            {

                ingresar_personas(tabla);
            }
        }
        if (respuesta == 2)
        {
            Buscar_personas(tabla);
        }
        printf("\n\n\t\t -Seleccione una opcion-\n1\t-Cargar personas\n2\t-Buscar Personas\n0\t-Salir");
        fflush(stdin);
        respuesta = ingresar_valor();
    }
    return 0;
}

//                  ----------Funciones----------

int ingresar_valor()
{
    printf("\nIngrese el valor: ");
    char auxiliar[100];
    fflush(stdin);
    fgets(auxiliar, 100, stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < -99999999 || atoi(auxiliar) >= 99999999)
    {
        printf("Error. Reingrese la clave a buscar: ");
        fflush(stdin);
        fgets(auxiliar, 100, stdin);
        borrarEspacios(auxiliar);
    }
    return atoi(auxiliar);
}

void ingresar_personas(TablaHash tabla)
{

    printf("\nDebe ingresar una fecha en el formato DD/MM/AAAA:\n\t ");
    char dia[10], mes[10], anio[10];
    printf("Dia: ");
    fflush(stdin);
    fgets(dia, 100, stdin);
    borrarEspacios(dia);
    while (NumeroValidado(dia) > 31 || NumeroValidado(dia) < 1)
    {
        printf("error, dato invalido\n");
        printf("\n\tDia: ");
        fflush(stdin);
        fgets(dia, 100, stdin);
        borrarEspacios(dia);
    }

    printf("\n\tMes: ");
    fflush(stdin);
    fgets(mes, 100, stdin);
    borrarEspacios(mes);
    while (NumeroValidado(mes) > 12 || NumeroValidado(mes) < 1)
    {
        printf("error, dato invalido\n");
        printf("\n\tMes: ");
        fflush(stdin);
        fgets(mes, 100, stdin);
        borrarEspacios(mes);
    }
    printf("\n\tAnio: ");
    fflush(stdin);
    fgets(anio, 100, stdin);
    borrarEspacios(anio);
    while (NumeroValidado(anio) < 2021)
    {
        printf("error, dato invalido\n");
        printf("\n\tAnio: ");
        fflush(stdin);
        fgets(anio, 100, stdin);
        borrarEspacios(anio);
    }
    strcat(mes, anio);
    strcat(dia, mes);

    int clave_buscar = (atoi(dia));
    printf("\nCuantas personas se vacunaron en esta fecha: ");
    int contador;
    fflush(stdin);
    contador = ingresar_valor();
    TipoElemento ElementoEnTabla = th_recuperar(tabla, clave_buscar);

    for (int i = 0; i < contador; i++)
    {

        system("cls");
        printf("Insertar los datos de la persona N %i", i + 1);
        if (ElementoEnTabla == NULL)
        {

            ArbolAVL a = avl_crear();

            printf("\nInsertas el DNI de la persona: ");
            int dni = ingresar_valor();
            printf("\nInsertas el apellido de la persona: ");
            char apellido[20];
            fflush(stdin);
            scanf("%s", apellido);
            printf("\nInsertas el nombre de la persona: ");
            char nombre[20];
            fflush(stdin);
            scanf("%s", nombre);

            Persona persona = (Persona)malloc(sizeof(struct t_persona));

            persona->dni = dni;

            strcpy(persona->apellido, apellido);
            strcpy(persona->nombre, nombre);

            TipoElemento te_arbol = te_crear_con_valor(persona->dni, (Persona)persona);
            avl_insertar(a, te_arbol);
            TipoElemento te_tabla = te_crear_con_valor(clave_buscar, (ArbolAVL)a);
            th_insertar(tabla, te_tabla);
            ElementoEnTabla = te_tabla;
        }
        else
        {
            printf("\nInsertas el DNI de la persona: ");
            int dni;
            fflush(stdin);
            dni = ingresar_valor();
            printf("\nInsertas el apellido de la persona: ");
            fflush(stdin);
            char apellido[20];
            fflush(stdin);
            scanf("%s", apellido);
            printf("\nInsertas el nombre de la persona: ");
            char nombre[20];
            fflush(stdin);
            scanf("%s", nombre);
            Persona persona = (Persona)malloc(sizeof(struct t_persona));
            persona->dni = dni;
            strcpy(persona->apellido, apellido);
            strcpy(persona->nombre, nombre);

            TipoElemento te_arbol = te_crear_con_valor(persona->dni, (Persona)persona);
            avl_insertar(ElementoEnTabla->valor, te_arbol);
        }
    }
}

void Buscar_personas(TablaHash tabla)
{
    printf("Indique la fecha que se desea conocer la gente que se vacuno: ");
    printf("\nDebe ingresar una fecha en el formato DD/MM/AAAA:\n\t ");
    char dia[100], mes[100], anio[100];
    printf("Dia: ");
    fflush(stdin);
    fgets(dia, 100, stdin);
    borrarEspacios(dia);
    while (NumeroValidado(dia) > 31 || NumeroValidado(dia) < 1)
    {
        printf("error, dato invalido\n");
        printf("\n\tDia: ");
        fflush(stdin);
        fgets(dia, 100, stdin);
        borrarEspacios(dia);
    }

    printf("\n\tMes: ");
    fflush(stdin);
    fgets(mes, 100, stdin);
    borrarEspacios(mes);
    while (NumeroValidado(mes) > 12 || NumeroValidado(mes) < 1)
    {
        printf("error, dato invalido\n");
        printf("\n\tMes: ");
        fflush(stdin);
        fgets(mes, 100, stdin);
        borrarEspacios(mes);
    }
    printf("\n\tAnio: ");
    fflush(stdin);
    fgets(anio, 100, stdin);
    borrarEspacios(anio);
    while (NumeroValidado(anio) < 2021)
    {
        printf("error, dato invalido\n");
        printf("\n\tAnio: ");
        fflush(stdin);
        fgets(anio, 100, stdin);
        borrarEspacios(anio);
    }
    int clave_buscar = (atoi(strcat(dia, strcat(mes, anio))));
    TipoElemento te = th_recuperar(tabla, clave_buscar);
    if (te == NULL)
    {
        printf("\n\nNo hay vacunados ese dia");
        return;
    }
    else
    {
        printf("\n Las personas vacunadas en esta fecha fueron: \n\n");
        in_orden(avl_raiz(te->valor));
    }
}
void in_orden(NodoArbol N)
{
    TipoElemento x;

    x = n_recuperar(N);
    if (n_hijoizquierdo(N) != NULL)
    {
        in_orden(n_hijoizquierdo(N));
    }

    printf("%i", x->clave);
    Persona pe = x->valor;
    printf(" %s", pe->apellido);
    printf(" %s", pe->nombre);
    printf("\n\t");
    if (n_hijoderecho(N) != NULL)
    {

        in_orden(n_hijoderecho(N));
    }
}
int transformacion_clave(int clave)
{
    return clave % 41;
}
