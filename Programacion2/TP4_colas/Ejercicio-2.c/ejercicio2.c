#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "colas.h"
#include "validaciones.h"
#define MAX 100

void recolar(Cola cola,Cola auxiliar){
    TipoElemento elemento;
    while(c_es_vacia(auxiliar)==false){
        elemento = c_desencolar(auxiliar);
        c_encolar(cola,elemento);
    }
}

int c_longitud(Cola cola){
    int contador = 0;
    TipoElemento elemento;
    Cola auxiliar = c_crear();
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        c_encolar(auxiliar,elemento);
        contador++;
    }
    recolar(cola,auxiliar);
    return contador;
}

void cargarCola(Cola cola, int longitud){
    int i;
    int clave;
    char auxiliar[MAX];
    TipoElemento elemento;
    printf("Ingrese las claves: \n");
    for(i=1;i<=longitud;i++){
        printf("Ingrese clave %d: ",i);
        fflush(stdin);
        fgets(auxiliar,MAX,stdin);
        borrarEspacios(auxiliar);
        while(validacion(auxiliar) == false || atoi(auxiliar) > 9999999 || atoi(auxiliar) < -9999999){
            printf("Error. Reingrese la clave %d de la cola: \n",i);
            fflush(stdin);
            fgets(auxiliar,MAX,stdin);
            borrarEspacios(auxiliar);
        }
        clave = atoi(auxiliar);
        elemento = te_crear(clave);
        c_encolar(cola,elemento);
    }
}
//a. Informar si un elemento dado se encuentra en la cola.
bool encontarElemento(Cola cola, int clave){
    TipoElemento elemento;
    Cola colaAux = c_crear();
    bool encontrado = false;
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        c_encolar(colaAux,elemento);
        if(elemento->clave==clave){
            encontrado = true;
        }
    }
    recolar(cola,colaAux);
    return encontrado;
}
//b. Agregar un nuevo elemento en una posición dada (colarse).
Cola agregarElemento(Cola cola,TipoElemento elementoAgregar,int posicion){
    int contador = 1;
    TipoElemento elemento;
    Cola colaAux = c_crear();
    Cola colaAgregada = c_crear();
    while(c_es_vacia(cola)==false ){
        if (contador==posicion){
            c_encolar(colaAgregada,elementoAgregar);
        }
        else{
            elemento = c_desencolar(cola);
            c_encolar(colaAux,elemento);
            c_encolar(colaAgregada,elemento);
        }
        contador++;
    }
    if (posicion == contador){
        c_encolar(colaAgregada,elementoAgregar);
    }
    recolar(cola,colaAux);
    return colaAgregada;
}
//c. Dado un elemento sacarlo de la cola todas las veces que aparezca.
Cola eliminarElemento(Cola cola, TipoElemento elementoEliminar){
    TipoElemento elemento;
    Cola colaAux = c_crear();
    Cola colaEliminada = c_crear();
    bool existe = false;
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        if (elemento->clave!=elementoEliminar->clave){
            c_encolar(colaEliminada,elemento);
        }else{
            existe = true;
        }
        c_encolar(colaAux,elemento);
    }
    if (existe == false && c_es_vacia(colaEliminada) == false){
        printf("No se pudo eliminar El elemento por que no se encuentra en la cola\n\n");
    }
    recolar(cola,colaAux);
    return colaEliminada;
}

//d. Contar los elementos de la cola.
int contarElementos(Cola cola){
    int contador;
    if (c_es_vacia(cola) == true){
        contador = 0;
    }else{
        contador = 1;
        TipoElemento elemento = c_desencolar(cola);
        Cola auxiliar = c_crear();
        c_encolar(auxiliar,elemento);
        while(c_es_vacia(cola)==false){
            elemento = c_desencolar(cola);
            c_encolar(auxiliar,elemento);
            contador++;
        }
        recolar(cola,auxiliar);
    }  
    return contador;
    //no queda claro en la guia ej 2 D si es que quiere le mande la longitud o solo la cantidad de elementos en la cola
}
//e. Realizar una función que realice una copia de una cola.
Cola copiarCola(Cola cola){
    TipoElemento elemento;
    Cola auxilar = c_crear();
    Cola copia = c_crear();
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        c_encolar(auxilar,elemento);
        c_encolar(copia,elemento);
    }
    recolar(cola,auxilar);
    return copia;
}
//f. Invertir del contenido de una cola sin destruir la cola original
Cola invertirCola(Cola cola){
    TipoElemento elemento;
    int tamanio = c_longitud(cola);
    Cola colaInvertida = c_crear();
    Cola colaAux = c_crear();
    TipoElemento arreglo[tamanio];
    int i = 0;
    while(c_es_vacia(cola)==false){
        elemento = c_desencolar(cola);
        c_encolar(colaAux,elemento);
        arreglo[tamanio-1-i] = elemento;
        i++;
    }
    recolar(cola,colaAux);
    int j;
    for (j=0;j<tamanio;j++){
        c_encolar(colaInvertida,arreglo[j]);
    }
    return colaInvertida;
}

int main(){
    char buffer[MAX];
    Cola cola = c_crear();
    Cola colaResultado = c_crear();
    printf("Ingrese la cantidad de elementos (0 - %d) que desea cargar en la cola: ", MAX);
    fgets(buffer, 100, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > MAX) {
        printf("\nError. Ingrese un numero entre 0 y %d: ", MAX);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    int cantidadElementos = atoi(buffer);
    cargarCola(cola,cantidadElementos);
    if(c_es_vacia(cola)){
        printf("\nCola vacia generada. \n");
    }
    else{
        c_mostrar(cola);
        printf("\n\n");
    }
    if (c_es_vacia(cola)==false){
        printf("\nIngrese una clave (numero entero) a buscar en la cola: ");
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false) {
            printf("\nError. Ingrese una clave (numero entero) a buscar en la cola: ");
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int elementoBuscar = atoi(buffer);
        if(encontarElemento(cola,elementoBuscar)){
            printf("El elemento con clave %d se encuentra en la cola\n", elementoBuscar);
        }
        else{
            printf("El elemento con clave %d no se encuentra en la cola\n", elementoBuscar);
        }
    }
    else{
        printf("\nNo se puede buscar el elemento porque la cola esta vacia\n");
    }
    if (c_es_llena(cola)){
        printf("\nNo se puede agregar un elemento a la cola porque se encuentra llena\n");
    }
    else {
        int longitud = c_longitud(cola);
        printf("\nIngrese una posicion (1 - %d) para insertar un nuevo elemento en la cola: ", longitud+1);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) > longitud + 1 || atoi(buffer) < 1) {
            printf("\nError. Ingrese una posicion (1 - %d) para insertar un nuevo elemento en la cola: ", longitud + 1);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int posicion = atoi(buffer);
        printf("\nIngrese una clave (numero entero) para el elemento insertar en la posicion %d: ", posicion);
        fgets(buffer, 100, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false) {
            printf("\nError. Ingrese una clave (numero entero) para el elemento a insertar en la posicion %d: ", posicion);
            fgets(buffer, 100, stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        int clave = atoi(buffer);
        TipoElemento elementoInsertar = te_crear(clave);
        Cola colaResultado = agregarElemento(cola,elementoInsertar,posicion);
        printf("\nCola con elemento con clave %d insertado: \n", elementoInsertar->clave);
        c_mostrar(colaResultado);
        printf("\n\n");        
    }
    if (c_es_vacia(cola)){
        printf("\nNo se puede eliminar elementos ya que la cola esta vacia. \n");
    } 
    else {
        printf("\nCola original: \n");
        c_mostrar(cola);
        printf("\n\n");
        printf("\nIngrese una clave (numero entero) a eliminar en la cola: ");
        fgets(buffer,100,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false){
            printf("\nError. Ingrese una clave (numero entero) a eliminar en la cola: ");
            fgets(buffer,100,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        TipoElemento elementoEliminar = te_crear(atoi(buffer));
        colaResultado = eliminarElemento(cola, elementoEliminar);
        c_mostrar(colaResultado);
        printf("\n\n");
    }
    int cantElemento = contarElementos(cola);
    printf("\nLa cola tiene %d elementos\n", cantElemento);
    printf("\nCola original:\n");
    c_mostrar(cola);
    printf("\n\n");
    colaResultado = copiarCola(cola);
    printf("\nCopia de la cola:\n");
    c_mostrar(colaResultado);
    printf("\n\n");
    colaResultado = invertirCola(cola);
    printf("\nCola invertida:\n");
    c_mostrar(colaResultado);
    return 0;
}
