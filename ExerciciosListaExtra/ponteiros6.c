#include <stdio.h>

void somadobro(int *p, int *q,int A,int B, int produto);

int main(){

    int produto = 0;
    int A, B;
    int *p, *q;
    p = &A; q = &B;

    printf("Digite o valor de A\n");
    scanf("%d", &A);
    printf("Digite o valor de B\n");
    scanf("%d", &B);

    somadobro(p, q, A, B, produto);
    
    printf("A = %d\n", A);
    printf("B = %d\n", B);

    produto = A + B;
    printf("Produto das somas e %d\n", produto);

    return 0;
}
void somadobro(int *p, int*q,int A,int B, int produto){

    int a, b;
    b = *q;
    a = *p;
    a = a * 2;
    b = b * 2;
    *p = a;
    *q = b;
}