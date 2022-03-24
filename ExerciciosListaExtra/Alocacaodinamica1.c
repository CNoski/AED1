#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array;
    int i, count = 5;

    array = (int*)malloc(5 * sizeof(int));

    for ( i = 0; i < count; i++){

        printf("Digite o número para inserir em arrray[%d]\n", i);
        scanf("%d", &array[i]);
    }
    for ( i = 0; i < count; i++){

        printf("O valor de array[%d] = %d\n", i, array[i]);
    }
    free(array);
    
    
    
    return 0;
}
