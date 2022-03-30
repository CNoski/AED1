#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int *ptri;
typedef void *ptrvoid;
typedef struct{
    
    char *nome[10];
    int *idade;
    int *telefone;    
}Pessoa;


int main(){


    int n;
    Pessoa pessoas[10];
    n = 0;
    int i, j;

    void *pBuffer;
    char *nomeexcluir[10];
    char *nomebuscar[10];
    ptri sair;
    ptri menu;
    pBuffer = (void*)malloc(sizeof(char) * 20 + sizeof(int) * 2);
    nomeexcluir[0] = &pBuffer;
    nomebuscar[0] = &pBuffer+10;
    sair = &pBuffer+20;
    menu = &pBuffer+24;



    sair = 1;
        while(sair){
            
            menu = 0;

            printf("Digite 1 para inserir uma pessoa a agenda. \n");
            printf("Digite 2 para apagar uma pessoa a agenda. \n");
            printf("Digite 3 para buscar uma pessoa na agenda. \n");
            printf("Digite 4 para listar. \n");
            printf("Digite 5 para sair. \n");

            scanf("%i", &menu);
            
            if(menu == 1){

                if(n == 0){
                
                    printf("Insira o nome:\n"); scanf("%s", (pessoas)->nome);
                    printf("Insira a idade:\n"); scanf("%d", &(pessoas)->idade);
                    printf("Insira a telefone:\n"); scanf("%d", &(pessoas)->telefone);
                    n++;
                 }
                else{
                    
                    if(n < 10){
                    printf("Insira o nome:\n"); scanf("%s", (pessoas+n)->nome);
                    printf("Insira a idade:\n"); scanf("%d", &(pessoas+n)->idade);
                    printf("Insira a telefone:\n"); scanf("%d", &(pessoas+n)->telefone);
                    n++;
                    }
                    if(n >= 10){
                        printf("Impossivel inserir mais.\n");
                    }
                }
                   
            }   
            if(menu == 2){
                
                printf("Insira o nome do contato que deseja remover:\n");
                scanf("%s", nomeexcluir);
                for( i = 0; i < n; i++){
                    if(strcmp(nomeexcluir, pessoas[i].nome) == 0){
                        for( i = i ; i < n -1; i++){
                        
                            pessoas[i]  = pessoas[i+1];                       
                        }
                    }
                }
                n--;

            }
            if(menu == 3){

                printf("Insira o nome do contato que deseja buscar:\n");
                scanf("%s", nomebuscar);
                for ( i = 0; i < n; i++){

                    if(strcmp(nomebuscar, (pessoas+i)->nome) == 0){
                        
                        printf("Nome encontrado.\n");
                        printf("Nome = %s\n", (pessoas+i)->nome);
                        printf("Idade = %d\n", (pessoas+i)->idade);
                        printf("Telefone = %d\n", (pessoas+i)->telefone);
                        break;
                    }


                }
                
            }
            if(menu == 4){

              for ( i = 0; i < n; i++){
                printf("Nome = %s\n", (pessoas+i)->nome);
                printf("Idade = %d\n", (pessoas+i)->idade);
                printf("Telefone = %d\n", (pessoas+i)->telefone);
            }

            }
            if(menu == 5){
                free(pBuffer);
                return 0;
            }

                  
        }
}
