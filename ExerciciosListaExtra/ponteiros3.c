#include <stdio.h>

int main(){
    
    int x;
    int y;
    int *px;
    int *py;

    px = &x;
    py = &y;
    
    printf("Endereço de x = %d\n", px);
    printf("Endereço de y = %d\n", py);   

    printf("Digite o valor de x\n");
    scanf("%d", &x);
    printf("Digite o valor de y\n");
    scanf("%d", &y);    

    if( py > px){

        py = y;
        printf("O maior = %i", py);
    }
    else{
        px = x;
        printf("O maior = %i", px);
    }
    return 0;
}
