#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //n é a variael que é igual o numero de caracteres da string


    char *lista= (char*)malloc(1);
    char *adicionar= (char*)malloc(1);
    char remover;
    int testemem;
    int ndenomes = 0;
    int ndechar;
    int controle =0;
    

    do{
        printf("Digite 1 para adicionar um nome \n");
        printf("Digite 2 para remover um nome \n");
        printf("Digite 3 para listar os nomes \n");
        printf("Digite 4 fechar o programa \n");

        scanf("%i", controle);

        switch(controle){

            case 1:
            
            printf("Digite o nome que deseja adicionar:\n");
            scanf("%d", adicionar);

            break;
        }
        return 0;
        }while(controle != 2);
        return 0;
}