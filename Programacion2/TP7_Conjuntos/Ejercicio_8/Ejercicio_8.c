#include "conjuntos.h"
#include "listas.h"
#include "validaciones.h"

void cargar_conjunto(Conjunto conjunto, int cardinalidad){
    char auxiliar[100];
    int clave;
    for (int i = 1;i <= cardinalidad;i++){
        printf("Ingrese el elemento n %d del conjunto: ", i);
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
        while ( (validacion(auxiliar) == false) || (cto_pertenece(conjunto,atoi(auxiliar)) == true) || ( atoi(auxiliar) < 1 ) || ( atoi(auxiliar) > 99999999 ) ){
            if (validacion(auxiliar) == false || ( atoi(auxiliar) < 1 ) || ( atoi(auxiliar) > 99999999 )){
                printf("Error. Reingrese la clave del conjunto : ");
                fflush(stdin);
                fgets(auxiliar,100,stdin);
                borrarEspacios(auxiliar);
            } else {
                printf("Error. La clave ingresada ya pertenece al conjunto, Reingrese la clave : ");
                fflush(stdin);
                fgets(auxiliar,100,stdin);
                borrarEspacios(auxiliar);
            }
        }
        clave = atoi(auxiliar);
        TipoElemento elem = te_crear(clave);
        cto_agregar(conjunto,elem);
    }
}

void comprobar_igualdad(Conjunto A,Conjunto B){
    bool iguales = true;
    TipoElemento elem_A;
    int longitud = cto_cantidad_elementos(A);
    for (int i = 1;i <= longitud; i++){
        elem_A = cto_recuperar(A,i);
        if (cto_pertenece(B,elem_A->clave) == false){
            iguales = false;
        }
    }
    if (iguales == true){
        printf("\nLos conjuntos son iguales\n");
    } else {
        printf("\nLos conjuntos NO son iguales\n");
    }
}



int main(){
    char auxiliar[100];
    int cardinalidad;
    Conjunto A = cto_crear();
    Conjunto B = cto_crear();
    printf("Ingrese la Cardinalidad de los conjuntos: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while ( (validacion(auxiliar) == false) || ( atoi(auxiliar) < 0) || ( atoi(auxiliar) > 100)){
        printf("Error. Reingrese la Cardinalidad de los conjuntos : ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    cardinalidad = atoi(auxiliar);
    printf("\t\t\tCONJUNTO A\n");
    cargar_conjunto(A,cardinalidad);
    cto_mostrar(A);
    printf("\t\t\tCONJUNTO B\n");
    cargar_conjunto(B,cardinalidad);
    cto_mostrar(B);
    comprobar_igualdad(A,B);
    printf("\n\nLa complejidad algoritmica es O(n^2) si contamos la funcion cto_pertenece del TAD en la implementacion Listas, En la implementacion avl la complejidad seria O(n.log), si no contamos la implementacion seria O(n). En donde N es la cantidad de elementos de ambos conjuntos");
}
