
#include <stdio.h>
#include <string.h>

int main() {
    char A[] = {"cajtpg"}; char temp; int n = (sizeof(A)/sizeof(A[0]));
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-1; j++)    
            if (A[j] > A[j+1]) {
                temp = A[0];
                A[j] = A[j+1];
                A[j+1] = temp;
                //printf("%c", temp[0]);
            }
    }
    //printf("%c", A[0][0]);
    for (int k = 0;k < n; k++) {
        printf("%c", A[k]);
    }
    return 0;
}