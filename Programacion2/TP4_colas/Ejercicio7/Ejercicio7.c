#include "colas.h"
#include "tipo_elemento.h"
#include "validaciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static const int MAXIMO = 100;

int pedirElementos(int numeroCola){
    char buffer[10];
    printf("\nIngrese la cantidad de elementos a cargar en la cola %d (0-%d): ", numeroCola, MAXIMO);
    fgets(buffer,10,stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) < 0 || atoi(buffer) > MAXIMO){
        printf("\nError. El valor ingresado es invalido.\n");
        printf("\nIngrese la cantidad de elementos a cargar en la cola %d (0-%d): ", numeroCola, MAXIMO);
        fgets(buffer,10,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    return atoi(buffer);
}

void mostrarColas(Cola cola);

Cola cargarCola (int cantidadElementos){
    char buffer[20];
    Cola cola = c_crear();
    int i = 1;
    while (cantidadElementos > 0){
        printf("\nIngrese un numero N > 0 de 8 digitos para la posicion %d: ", i);
        fgets(buffer,20,stdin);
        fflush(stdin);
        borrarEspacios(buffer);
        while (validacion(buffer) == false || atoi(buffer) > 99999999 || atoi(buffer) < 1){
            printf("\nError. El valor ingresado es invalido.\n");
            printf("\nIngrese un numero N > 0 de 8 digitos para la posicion %d: ", i);
            fgets(buffer,20,stdin);
            fflush(stdin);
            borrarEspacios(buffer);
        }
        c_encolar(cola, te_crear(atoi(buffer)));
        cantidadElementos--;
        i++;
    }
    printf("\nCola ingresada: ");
    mostrarColas(cola);
    return cola;
}

void mostrarColas(Cola cola){
    Cola colaAuxiliar = c_crear();
    TipoElemento elemento;
    if (c_es_vacia(cola)){
        printf("()\n");
        return;
    }
    printf("(");
    while (c_es_vacia(cola) == false){
        elemento = c_desencolar(cola);
        if (c_es_vacia(cola) == false){
            printf("%d, ", elemento->clave);
        } else printf("%d)\n", elemento->clave);
        c_encolar(colaAuxiliar, elemento);
    }
    while (c_es_vacia(colaAuxiliar) == false){
        c_encolar(cola, c_desencolar(colaAuxiliar));
    }
}

Cola copiarCola(Cola cola){
    Cola colaCopia = c_crear();
    Cola colaAuxiliar = c_crear();
    TipoElemento elemento;
    while (c_es_vacia(cola) == false){
        elemento = c_desencolar(cola);
        c_encolar(colaCopia, elemento);
        c_encolar(colaAuxiliar, elemento);
    }
    while (c_es_vacia(colaAuxiliar) == false){
        c_encolar(cola, c_desencolar(colaAuxiliar));
    }
    return colaCopia;
}

void actualizarColas(Cola cola, TipoElemento cliente){
    Cola colaAuxiliar = c_crear();
    c_desencolar(cola);
    c_encolar(colaAuxiliar, cliente);
    while (c_es_vacia(cola) == false){
        c_encolar(colaAuxiliar, c_desencolar(cola));
    }
    while (c_es_vacia(colaAuxiliar) == false){
        c_encolar(cola, c_desencolar(colaAuxiliar));
    }
}

void atenderColas(int Q, Cola cola1, Cola cola2, Cola cola3){
    
    Cola cola1Copia = copiarCola(cola1);
    Cola cola2Copia = copiarCola(cola2);
    Cola cola3Copia = copiarCola(cola3);

    int QAuxiliar,Q_rest;
    int contadorCliente[3];
    for (int i = 0; i <= 2; i++){
        contadorCliente[i] = 1;
    }


    TipoElemento cliente;
    while (c_es_vacia(cola1) == false || c_es_vacia(cola2) == false || c_es_vacia(cola3) == false){
        if (c_es_vacia(cola1) == false){
            cliente = c_recuperar(cola1);
            Q_rest = Q - cliente->clave;
            while (Q_rest > 0 && c_es_vacia(cola1) == false){
                printf("\nCliente %d Cola 1", contadorCliente[0]++);
                c_desencolar(cola1);
                if (c_es_vacia(cola1) == false){
                    cliente = c_recuperar(cola1);
                    Q_rest = Q_rest - cliente->clave;
                }
            }
            if (Q_rest == 0 && c_es_vacia(cola1) == false){
                printf("\nCliente %d Cola 1", contadorCliente[0]++);
                if (c_es_vacia(cola1) == false){
                    c_desencolar(cola1);
                }
            }
            if (Q_rest < 0 && c_es_vacia(cola1) == false){
                cliente->clave = cliente->clave - Q;
                actualizarColas(cola1,cliente);
            }        
        }
        if (c_es_vacia(cola2) == false){
            cliente = c_recuperar(cola2);
            Q_rest = Q - cliente->clave;
            while (Q_rest > 0 && c_es_vacia(cola2) == false){
                printf("\nCliente %d Cola 2", contadorCliente[1]++);
                c_desencolar(cola2);
                if (c_es_vacia(cola2) == false){
                    cliente = c_recuperar(cola2);
                    Q_rest = Q_rest - cliente->clave;
                }
            }
            if (Q_rest == 0 && c_es_vacia(cola2) == false){
                printf("\nCliente %d Cola 2", contadorCliente[1]++);
                if (c_es_vacia(cola2) == false){
                    c_desencolar(cola2);
                }
            }
            if (Q_rest < 0 && c_es_vacia(cola2) == false){
                cliente->clave = cliente->clave - Q;
                actualizarColas(cola2,cliente);
            } 
        }
        if (c_es_vacia(cola3) == false){
            cliente = c_recuperar(cola3);
            Q_rest = Q - cliente->clave;
            while (Q_rest > 0 && c_es_vacia(cola3) == false){
                printf("\nCliente %d Cola 3", contadorCliente[2]++);
                c_desencolar(cola3);
                if (c_es_vacia(cola3) == false){
                    cliente = c_recuperar(cola3);
                    Q_rest = Q_rest - cliente->clave;
                }
            }
            if (Q_rest == 0 && c_es_vacia(cola3) == false){
                printf("\nCliente %d Cola 3", contadorCliente[2]++);
                if (c_es_vacia(cola3) == false){
                    c_desencolar(cola3);
                }
            }
            if (Q_rest < 0 && c_es_vacia(cola3) == false){
                cliente->clave = cliente->clave - Q;
                actualizarColas(cola3,cliente);
            }
        }    
    } 
    printf("\n\n-- FIN DE LA SIMULACION --\t\n");
    
    cola1 = copiarCola(cola1Copia);
    cola2 = copiarCola(cola2Copia);
    cola3 = copiarCola(cola3Copia);   
}


int main(){
    Cola cola1, cola2, cola3;
    
    // Pido los elementos para cargar las colas y las cargo

    cola1 = cargarCola(pedirElementos(1));
    cola2 = cargarCola(pedirElementos(2));
    cola3 = cargarCola(pedirElementos(3));

    char buffer[10];

    printf("\nIngrese un numero Q > 0 el cual será la cantidad de minutos a la que atenderá por cola: ");
    fgets(buffer, 10, stdin);
    fflush(stdin);
    borrarEspacios(buffer);
    while (validacion(buffer) == false || atoi(buffer) <= 0 || atoi(buffer) > 99999999){
        printf("\nError. El Q ingresado no es valido.\n");
        printf("\nIngrese un numero Q > 0 el cual será la cantidad de minutos a la que atenderá por cola: ");
        fgets(buffer, 10, stdin);
        fflush(stdin);
        borrarEspacios(buffer);
    }
    int Q = atoi(buffer);

    printf("\n\t-- SIMULACION --\t\n");
    printf("Q = %d\n", Q);
    printf("Cola 1 = ");
    mostrarColas(cola1);
    printf("Cola 2 = ");
    mostrarColas(cola2);
    printf("Cola 3 = ");
    mostrarColas(cola3);
    printf("RESULTADO:");
    atenderColas(Q, cola1, cola2, cola3);
}
