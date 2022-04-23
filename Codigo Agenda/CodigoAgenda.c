#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NODO_TAM sizeof(void*)*2+sizeof(int)*2+sizeof(char)*30


int main(){

    
    
    void *pBuffer = (void*)malloc(sizeof(char)*100);
    if(pBuffer == NULL){
    printf("Erro! Memoria nao alocada.");
    return EXIT_FAILURE;
    }


    /*
    pbuffer[0] é um inteiro que define o while da linha 32
    pbuffer[3] é um inteiro que defino o valor do menu
    pbuffer[7] = Ancora (começo da lista) 46 bytes


    */

    void *Ancora = NULL ;

    void **proximo;
    void *nodo;
    void **nodoleitor;

    
    while (((int*)pBuffer)[0]){

        printf("Digite 1 para adicionar um nome \n");
        printf("Digite 2 para remover um nome \n");
        printf("Digite 3 para buscar o programa \n");
        printf("Digite 4 para listar os nomes \n");
        printf("Digite 5 fechar o programa \n");
        scanf("%i", &((int*)pBuffer)[4]);

        switch(((int*)pBuffer)[4]){

            case 1:
            
                nodoleitor = &((void*)pBuffer)[7];
                proximo = *nodoleitor + sizeof(char)*42;
                while ((*nodoleitor) && (strncmp(*nodoleitor + sizeof(void*),*proximo + sizeof(void*),sizeof(char)*30)) < 1){
                    
                
                }
                nodo = (void*)malloc(sizeof(NODO_TAM));


            break;

            case 2:

                printf("\n2");

            break;

            case 3:

            printf("\n3");

            break;

            case 4:

            printf("\n4");

            break;

            case 5:

            printf("Saindo do Aplicativo.");
            free(pBuffer);
            return EXIT_SUCCESS;

            break;           


        }
    }
}
