#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int menu;
    int ndepessoas;
    char nome[10];
    char telefone[9];
    int idade[3];
    int *ptr;
    int i, count;

    

    int main(void){
        ndepessoas = 0;

        void *pBuffer = (unsigned char*)malloc(sizeof(nome)+sizeof(telefone)+sizeof(idade)+2);

        do{
            menu == 0;
            printf("Digite 1 para inserir uma pessoa a agenda. \n");
            printf("Digite 2 para apagar uma pessoa a agenda. \n");
            printf("Digite 3 para buscar uma pessoa na agenda. \n");
            printf("Digite 4 para listar. \n");
            printf("Digite 5 para sair. \n");

            scanf("%i", &menu);
            
            switch (menu){

            case 1:
                ndepessoas = ndepessoas + 1;
                pBuffer = &ndepessoas;
                printf("Digite o nome que voce deseja inserir\n");
                scanf("%s", nome);
                printf("Digite a idade que voce deseja inserir(maximo de 3 digitos))\n");
                scanf("%d", idade);
                printf("Digite o numero de telefone que voce deseja inserir(maximo de 9 digitos)\n");
                scanf("%d", telefone);

                pBuffer = realloc(pBuffer,sizeof(nome)+sizeof(telefone)+sizeof(idade)+2);
                
                pBuffer =  &nome;


                printf("%i\n", *((int*)pBuffer));
                menu = 0;               
                break;
            case 2:
                ndepessoas = ndepessoas - 1;

                break;
            case 3:

                printf("menu = %i \n", menu);
                menu = 0;
                printf("menu = %i \n", menu);
                break;
            case 4:
                count = sizeof(pBuffer);
                printf("=========================AGENDA============================ \n");
                for ( i = sizeof(pBuffer); i < count; i++)
                {
                
                }
                

                printf("======================FIM DA AGENDA============================\n", menu);
                menu = 0;
                break;
            case 5:
            
                printf("menu = %i \n", menu);
                free(pBuffer);
                break;
            }
         
        } while (menu < 5);
        
        if(menu > 5){
            printf("NUMERO INVALIDO");
        }
        return(0);
    } 