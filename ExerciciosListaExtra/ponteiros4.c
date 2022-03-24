#include <stdio.h>

int main(){
    
    int i, j;
    int *p, *q;
    p = &i; q = &j;

    printf("Digite o valor de i\n");
    scanf("%d", &i);
    printf("Digite o valor de j\n");
    scanf("%d", &j);
   

    troca(p,q);

    printf("valor de i = %i\n", i);
    printf("valor de j = %i\n", j);

    return 0;
}
void troca (int *p, int *q){
    int temp;
    temp = *p; *p = *q; *q = temp;
}