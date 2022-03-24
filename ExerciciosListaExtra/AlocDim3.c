#include <stdio.h>
#include <stdlib.h>

int main(){
    
    int *array;
    int n; //numero de componentes do vetor
    int i, count;
    int par = 0;int impar = 0;

    printf("Insira o numero de componentes do vetor\n");
    scanf("%d", &n);

    count = n;

    array = (int*)malloc(n * sizeof(int));

    for ( i = 0; i < count; i++){

        printf("Digite o número para inserir em array[%d]\n", i);
        scanf("%d", &array[i]);
        if(array[i] % 2 == 0 ){
            par = par + 1;
        }
        else{
            impar = impar + 1;
        }
        
    }
    for ( i = 0; i < count; i++){

        printf("O valor de array[%d] = %d\n", i, array[i]);
    }
    printf("Numero de valores impares = %d\n", impar);
    printf("Numero de valores impares = %d\n", par);
    
    free(array);
}
