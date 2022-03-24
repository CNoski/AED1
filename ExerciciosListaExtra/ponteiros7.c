#include <stdio.h>

void soma(int *p,int *q);

int main(){

    int A, B; 
    int *p, *q; 
    p = &A; q = &B; 

    printf("Digite o valor de A\n");
    scanf("%d", &A);
    printf("Digite o valor de B\n");
    scanf("%d", &B);  

    soma( p, q);

    printf(" A =%d", A);
    printf(" B =%d", B);
    
    return 0;
}
void soma(int *p,int *q){

    int temp;

    temp = *p + *q;
    *p = temp;

}