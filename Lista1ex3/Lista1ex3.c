#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NOMECONS 10
#define TELCONS 8

    int ndepessoas;
    char nome[NOMECONS];
    char telefone[TELCONS];
    int idade[3];
    void *ptr;
    int i, count;    

    void *adicionar(void *pBuffer);
    void *listar(void *pBuffer);
    void *remover(void *pBuffer);
    void *buscar(void *pBuffer);

    int main(void){


        int sair = 1, menu = 0;
        void *pBuffer = calloc(1, sizeof(int));
        *(int*)pBuffer = 0;

        while(sair){

            printf("Digite 1 para inserir uma pessoa a agenda. \n");
            printf("Digite 2 para apagar uma pessoa a agenda. \n");
            printf("Digite 3 para buscar uma pessoa na agenda. \n");
            printf("Digite 4 para listar. \n");
            printf("Digite 5 para sair. \n");

            scanf("%i", &menu);
            
            switch (menu){

            case 1:
                pBuffer = adicionar(pBuffer);

                break;
            case 2:
                pBuffer = remover(pBuffer); 

                break;
            case 3:
                pBuffer = buscar(pBuffer);

                break;
            case 4:
                pBuffer = listar(pBuffer);

                break;
            case 5:
            
                free(pBuffer);
                return 0;
                break;
            }
        }
    } 

    void *adicionar(void *pBuffer){

        ndepessoas = ndepessoas + 1;
        int contatos;
        ptr = pBuffer;

        printf("Digite o nome que voce deseja inserir\n");
        scanf("%s", nome);
        printf("Digite a idade que voce deseja inserir\n");
        scanf("%i", idade);
        printf("Digite o numero de telefone que voce deseja inserir(maximo de 8 digitos)\n");
        scanf("%s", telefone);
        ndepessoas = *(int*)pBuffer;
        pBuffer = realloc(pBuffer, contatos);
        pBuffer = pBuffer + sizeof(int);
        memmove((char*)pBuffer, nome, sizeof(nome));
        pBuffer = pBuffer + sizeof(nome);
        memmove((int*)pBuffer, idade, sizeof(idade));
        pBuffer = pBuffer + sizeof(idade);
        memmove((char*)pBuffer, telefone, sizeof(telefone));
        pBuffer = pBuffer + sizeof(telefone);
     
        return ptr;
    }
    void *remover(void *pBuffer){
        

    }

    void *listar(void *pBuffer){

        void *ptr;
        ptr = pBuffer;

        printf("Numero de contatos = %d \n", ndepessoas);
        for (int i = 1; i <= ndepessoas; i++){
            printf("Nome = %s\n", *(char*)pBuffer);
            pBuffer = pBuffer + NOMECONS;
            printf("Idade =%d\n", *(int*)pBuffer);
            pBuffer = pBuffer + sizeof(int);
            printf("Telefone = %S\n", *(char*)pBuffer);
            pBuffer = pBuffer + TELCONS;
            printf("\n");
        
        return ptr;
        }   
    }
    void *buscar(void *pBuffer){ 
        char nomebuscar;
        void *ptr;
        int contatos;

        ptr = pBuffer;
        printf("Digite o nome que deseja buscar/");
        scanf("%s", nomebuscar);
        for ( i = 0; i < contatos; i++)
        {
            if(strcmp((char*)pBuffer,nomebuscar) != NULL){
                printf("Esta presente na agenda");
                pBuffer++;
            }
        }
    return ptr;
    }