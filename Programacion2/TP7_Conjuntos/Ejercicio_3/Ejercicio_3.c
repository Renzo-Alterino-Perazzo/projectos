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

Conjunto operacion_union(Lista L){
    int longitud_lista = l_longitud(L);
    Conjunto respuesta = cto_crear();
    Conjunto conjunto_actual = cto_crear();
    TipoElemento elem = l_recuperar(L,1);
    respuesta = (Conjunto)(elem->valor);
    for (int i = 2; i <= longitud_lista;i++){
        elem = l_recuperar(L,i);
        conjunto_actual = (Conjunto)(elem->valor);
        respuesta = cto_union(respuesta,conjunto_actual);
    }
    return respuesta;
}

Conjunto operacion_interseccion(Lista L){
    int longitud_lista = l_longitud(L);
    Conjunto respuesta = cto_crear();
    Conjunto conjunto_actual = cto_crear();
    TipoElemento elem = l_recuperar(L,1);
    respuesta = (Conjunto)(elem->valor);
    for (int i = 2; i <= longitud_lista;i++){
        elem = l_recuperar(L,i);
        conjunto_actual = (Conjunto)(elem->valor);
        respuesta = cto_interseccion(respuesta,conjunto_actual);
    }
    return respuesta;
}

int main(){
    char auxiliar[100];
    int cant_conjuntos,cardinalidad;
    printf("Ingrese la cantidad de conjuntos que desea crear: ");
    fflush(stdin);
    fgets(auxiliar,100,stdin);
    borrarEspacios(auxiliar);
    while ( (validacion(auxiliar) == false) || ( atoi(auxiliar) < 0) || ( atoi(auxiliar) > 100)){
        printf("Error. Reingrese la Cardinalidad de los conjuntos : ");
        fflush(stdin);
        fgets(auxiliar,100,stdin);
        borrarEspacios(auxiliar);
    }
    cant_conjuntos = atoi(auxiliar);
    Lista L = l_crear();
    for (int i = 1; i <= cant_conjuntos ;i++){
        printf("Ingrese la Cardinalidad del conjunto %d: ",i);
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
        Conjunto A = cto_crear();
        printf("\t\t\tCONJUNTO %d\n",i);
        cargar_conjunto(A,cardinalidad);
        TipoElemento conjunto = te_crear_con_valor(i,A);
        l_agregar(L,conjunto);
    }
    Conjunto respuesta = cto_crear();
    respuesta = operacion_union(L);
    printf("CONJUNTO UNION\n");
    cto_mostrar(respuesta);
    respuesta = operacion_interseccion(L);
    printf("CONJUNTO INTERSECCION\n");
    cto_mostrar(respuesta);
}
