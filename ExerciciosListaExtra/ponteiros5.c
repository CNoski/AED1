#include <stdio.h>

void ordenar(int *p, int *q);

int main(){

    int a, b;
    int *p, *q;
    p = &a; q = &b;

    printf("digite a primeira variavel\n");
    scanf("%d", &a);
    printf("digite a segunda variavel\n");
    scanf("%d", &b);   

    printf("q = %d\n", *p);
    printf("p = %d\n", *q);

    if(*q > *p){
    ordenar(p,q);
    }

    printf("Primeira variavel = %d\n", a);
    printf("Segunda variavel = %d\n", b);
    return 0;
}
void ordenar(int *p, int *q){
    
    int temp;
    temp = *p; *p = *q; *q = temp;
}
