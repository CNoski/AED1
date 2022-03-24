#include <stdio.h>
#include <stdlib.h>

int main(){

    int *array;
    int n; //numero de componentes do vetor
    int i, count;

    printf("Insira o numero de componentes do vetor\n");
    scanf("%d", &n);

    count = n;

    array = (int*)malloc(5 * sizeof(int));

    for ( i = 0; i < count; i++){

        printf("Digite o número para inserir em array[%d]\n", i);
        scanf("%d", &array[i]);
    }
    for ( i = 0; i < count; i++){

        printf("O valor de array[%d] = %d\n", i, array[i]);
    }
    free(array);
}
