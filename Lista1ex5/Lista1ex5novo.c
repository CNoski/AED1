#include <stdio.h>
#include <stdlib.h>



typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

int main(void){


    int sair = 1;
    int menu;
    int n = 0;//numero de pessoas
    int i;

    Pessoa *ptrpessoa;


    while(sair){
        
        printf("Digite 1 para inserir uma pessoa\n");
        printf("Digite 2 para sair do programa\n");
        scanf("%d", &menu);

        switch (menu){
        
        case 1:

            if(n == 0){
                
                ptrpessoa =(Pessoa*)malloc(sizeof(Pessoa));
                printf("Insira o nome:\n"); scanf("%s", (ptrpessoa)->nome);
                printf("Insira a idade:\n"); scanf("%d", &(ptrpessoa)->idade);
                printf("Insira a altura:\n"); scanf("%d", &(ptrpessoa)->altura);
                n++;
            }
            else{
            
                ptrpessoa = realloc(ptrpessoa, sizeof(Pessoa) * n);
                printf("Insira o nome:\n"); scanf("%s", (ptrpessoa+n)->nome);
                printf("Insira a idade:\n"); scanf("%d", &(ptrpessoa+n)->idade);
                printf("Insira a altura:\n"); scanf("%d", &(ptrpessoa+n)->altura);
                n++;
            }
            break;

        case 2:
            sair = 0;
            for ( i = 0; i < n; i++)
            {
                printf("Nome = %s\n", (ptrpessoa+i)->nome);
                printf("Idade = %d\n", (ptrpessoa+i)->idade);
                printf("Altura = %d\n", (ptrpessoa+i)->altura);
            }
            
            free(ptrpessoa);

            break;
        
        }
    }
    
    return 0;
}