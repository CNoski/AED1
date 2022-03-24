#include <stdio.h>


int main(){

    float matriz[3][3];
    int i, j;
    int *ptr;
    int count = 3;

    for ( i = 0; i < count; i++){
        for ( j = 0; j < count; j++){
            ptr = &matriz[i][j];
            printf("O endereco de matriz[%d][%d] e = %d\n", i, j, ptr);
        }
    }
    



    return 0;
}
