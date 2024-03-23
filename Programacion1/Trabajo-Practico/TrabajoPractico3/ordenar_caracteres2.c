
#include <stdio.h>
#include <string.h>

int main() {
    char A[][1] = {"c","a","j","t","p","g"}; char temp; int n = (sizeof(A)/sizeof(A[0]));
    for (int i = 0; i < n-1; i++){
        if (A[i] > A[i+1]){
            temp = A[i][0]; A[i][0] = A[i+1][0]; A[i+1][0] = temp;
        }
    }
    printf("%c", temp);
    return 0;
}