#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    //n é a variael que é igual o numero de caracteres da string


    char lista[15];
    char adicionar[15];
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

        scanf("%i", &controle);

        switch(controle){

            case 1:
            //adicionar um nome
            if(!testemem){
                printf("Erro!Falta memoria\n");
                return -1;
            }

            printf("Digite o nome que deseja adicionar: \n");
            scanf("%s", &adicionar);
            char *adicionar =(char*)realloc(sizeof(char)*strlen(adicionar)+1);

            if(ndenomes >= 1){
                strcat(lista, ",");
                strcat(lista, adicionar);
                ++ndenomes;          
            }
            else{
                printf("lista:%s", &lista);
                printf("adicionar:%s", &adicionar);
                strcpy(lista, adicionar);
                printf("lista:%s", &lista);
                ++ndenomes;
            }
            break;


            case 2:
            //remover um nome
            printf("Insira o nome que deseja remover a lista \n");
            scanf("%s \n", &remover);
            
            printf("2\n");
            
            break;

            case 3:
            //listar os nomes

            printf("%s \n", &lista);
            break;
        }
        
    }while(controle != 4);

    //sair do programa

    printf("aaaaaaaa\n");
}

