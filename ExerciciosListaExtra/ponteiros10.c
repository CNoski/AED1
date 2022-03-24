#include <stdio.h>


int main(){

    int array[5];
    int *ptr;
    ptr = &array[0];
    int i, count = 5;
    int ptrorg;
    ptrorg = ptr;
    for ( i = 0; i < count; i++){
        printf("Digite o valor de array[%d]\n", i);
        scanf("%d", ptr);

        ptr++;
    }
    ptr = ptrorg;
    for ( i = 0; i < count; i++){
        *ptr = *ptr * 2;
        printf("Valor de array[%d]= %d\n", i, array[i]);
        ptr++;
    }
    


    return 0;
}
