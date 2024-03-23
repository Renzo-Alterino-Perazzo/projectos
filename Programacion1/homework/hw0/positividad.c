
#include <stdio.h>

int positividad (int b) {
    int positivo;
    if (b >= 0) {
        positivo = 1;
    }
    else {
        positivo = 0;
    }
    return positivo;
}

int main(){
    int b, positivo;
    b = 1;
    positivo = positividad(b);
    printf("%d", positivo);
    return 0;
}
