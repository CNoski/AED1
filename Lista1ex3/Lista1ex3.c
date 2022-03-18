#include <stdio.h>
#include <stdlib.h>
#include <string.h>

    int menu;
    int ndepessoas;
    char nome[10];
    char telefone[14];
    int idade[3];

    void *pBuffer = (unsigned char*)malloc(sizeof(nome)+sizeof(telefone)+sizeof(idade)+2);

    int main(void){
        ndepessoas = 0;

        do
        {
            menu = 0;
            printf("Digite 1 para inserir uma pessoa a agenda.");
            printf("Digite 2 para apagar uma pessoa a agenda.");
            printf("Digite 3 para buscar uma pessoa na agenda.");
            printf("Digite 4 para listar.");
            printf("Digite 5 para sair.");

            scanf("%i", menu);

            if (menu == 1){
                /*inserir*/ 
            }
            if (menu == 2){
                /*apagar*/
            }
            if (menu == 3)
            {
                /*buscar*/
            }
            if (menu == 4)
            {
                /*listar*/
            }
            if (menu < 5)
            {
                printf("Numero inserido é invalido.");
            }
            
            
        } while (menu != 5);
    return(0);
    }