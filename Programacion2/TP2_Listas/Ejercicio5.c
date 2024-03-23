#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "validaciones.h"
#include "tipo_elemento.h"
#include "listas.h"


void l_mostrar_respuesta(Lista lista){
    int longitud_lista = l_longitud(lista);
    float aux;
    for (int i = 1; i <= longitud_lista; i++) {
        TipoElemento elemento = l_recuperar(lista,i);
        aux = *((float*)elemento->valor);
        printf("%0.4f ", aux);
    }
    printf("\n");
}

void llenar_lista_coeficiente(Lista lista_coeficiente,int grado_polinomio){
    char auxiliar[100];
    printf("Coeficientes acotados a 8 digitos)\n");
    for (int i = 0; i <= grado_polinomio; i++){
        float* coeficiente = malloc(sizeof(float));  // asignar memoria para un nuevo valor de tipo float
        if (i == 0){
            printf("Ingrese el Termino independiente: ");
        }
        else{
            printf("Ingrese el coeficiente de grado %d: ", i);            
        }
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while ((validacion_enteros_decimales(auxiliar) == false) || (atof(auxiliar) > 99999999) || (atof(auxiliar) < -99999999)){
            if (i == 0){
                printf("Error. Reingrese el termino independiente: ");
            }else{
                printf("Error. ReIngrese el coeficiente de grado %d: ", i);
            }
            fflush(stdin);
            fgets(auxiliar,100,stdin);
            borrarEspacios(auxiliar);
        }
        *coeficiente = atof(auxiliar); // transformo a float
        printf("%0.4f\n", *coeficiente);
        TipoElemento elemento = te_crear_con_valor(i, coeficiente); // creo un TE con el valor del coeficiente
        l_agregar(lista_coeficiente, elemento); // lo agrego a la lista de coeficiente, donde la posicion 1 de la lista sera el termino independiente
    }
}

float Retornar_valor(Lista lista_coeficiente,float x){
    TipoElemento coeficiente;
    int longitud_lista = l_longitud(lista_coeficiente);
    float resul = 0.0;
    for (int i = 2; i <= longitud_lista; i++){ // hago la suma de todos los coeficientes menos el termino independiente
        coeficiente = l_recuperar(lista_coeficiente,i); 
        resul = resul + ((*(float*)coeficiente->valor) * pow(x,(i-1)) );
    }
    coeficiente = l_recuperar(lista_coeficiente,1); // recupero el termino independiente
    resul = resul + (*(float*)coeficiente->valor);  // lo sumo al resultado total
    return resul;
}


Lista Retornar_valores_de_Y(Lista lista_coeficiente,float x_inicio,float x_final,float l){
    float valor_Y;
    float valor_x;
    int posicion = 1;
    Lista resultados = l_crear();  // creo una lista para los resultados
    bool ultima_iteracion = false;
    if (l == 0){
        float* valor_Y = malloc(sizeof(float));
        *valor_Y = Retornar_valor(lista_coeficiente,x_inicio);
        TipoElemento elemento = te_crear_con_valor(posicion, valor_Y);
        l_agregar(resultados,elemento);
        return resultados;
    }else{
        for (float i = x_inicio; i <= x_final || fabs(i - x_final) < 1e-6; i += l) {
            if (i >= x_final) {
                i = x_final;
                ultima_iteracion = true;
            }
            valor_x = i;
            float* valor_Y = malloc(sizeof(float));
            *valor_Y = Retornar_valor(lista_coeficiente,i); // guardo el valor de F(x)
            TipoElemento elemento = te_crear_con_valor(posicion, valor_Y); // creo un TE con el valor de Y en el campo "valor", en la clave guardo la posicion pero no la uso
            l_agregar(resultados,elemento);
            posicion++;
        }
        return resultados;
    }
}


int main(){
    int grado_polinomio;
    float termino_independiente;
    float x_final,x_inicio;
    float l;
    char auxiliar[100];
    Lista lista_coeficiente = l_crear();
    printf("(los espacios seran borrados)\n(Grado maximo acotado a 10)\ningrese el grado del polinomio: ");
    fgets(auxiliar,100,stdin);
    fflush(stdin);
    borrarEspacios(auxiliar);
    while (validacion(auxiliar) == false || atoi(auxiliar) < 0 || atoi(auxiliar) > 10){
        printf("Error. Reingrese el grado del polinomio: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    grado_polinomio = atoi(auxiliar);
    llenar_lista_coeficiente(lista_coeficiente,grado_polinomio);
    printf("Coeficientes del polinomio:\n");
    l_mostrar_respuesta(lista_coeficiente); // Muestro los coeficientes por pantalla
    printf("(Los valores estan acotados a 4 digitos)\ningrese el rango de inicio de los valores de X: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while ((validacion_enteros_decimales(auxiliar) == false) || (atof(auxiliar) > 9999) || (atof(auxiliar) < -9999) ){
        printf("Error. Reingrese el rango de inicio: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    x_inicio = atof(auxiliar);
    printf("ingrese el rango final de los valores de X: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while ((validacion_enteros_decimales(auxiliar) == false) || (atof(auxiliar) < x_inicio)|| (atof(auxiliar) > 9999) || (atof(auxiliar) < -9999)){
        printf("Error. Reingrese el rango final: ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    x_final = atof(auxiliar);
    printf("ingrese el valor del intervalo de cada valor que desea retornar: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while ((validacion_enteros_decimales(auxiliar) == false) || (atof(auxiliar) > ((x_final - x_inicio) + 0.00001)) || (atof(auxiliar) < 0) || (atof(auxiliar) > 9999) ||( (atof(auxiliar) == 0.0) && (x_final - x_inicio) != 0.0 )){
        printf("Error. Reingrese el intervalo: ");   // en ((x_final - x_inicio) + 0.00001) el 0.00001 es una toleracia
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    l = atof(auxiliar);
    Lista resultados = l_crear();
    resultados = Retornar_valores_de_Y(lista_coeficiente,x_inicio,x_final,l);
    printf("Los valores de F(x) son:\n");
    l_mostrar_respuesta(resultados);
}

