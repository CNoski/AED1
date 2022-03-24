#include <stdio.h>

int main(){

    int x = 5;
    int y = 4;
    int *px;
    int *py;

    px = &x;
    py = &y;

    if( py > px){
        printf("O maior = %i", py);
    }
    else{
        printf("O maior = %i", px);
    }
    return 0;
}