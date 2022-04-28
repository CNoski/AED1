#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NODO_TAM sizeof(void*)*2+sizeof(int)*2+sizeof(char)*30
#define NOME sizeof(void*)
#define IDADE sizeof(void*)+sizeof(char)*30
#define TELEFONE sizeof(void)+sizeof(char)*30+sizeof(int)
#define PROXIMO sizeof(void)+sizeof(char)*30+sizeof(int)*2


void *Criarnodo();
void *Push(void *pBuffer ,void *primeironodo, void* novonodo);
void *Listar(void *pBuffer, void *comecolista);


    /*
    pbuffer[0] é um inteiro que define o while da linha 36
    pbuffer[4] é um inteiro que defino o valor do menu
    pBuffer[8] é um inteiro que define o numero de nodos
    pBuffer[12] é um inteiro que controla o (i) do for loop
    */

   
int main(){

    
    
    void *pBuffer = (void*)malloc(sizeof(char)*100);
    if(pBuffer == NULL){
    printf("Erro! Memoria nao alocada.");
    return EXIT_FAILURE;
    }

   void *primeironodo = NULL;

    while (((int*)pBuffer)[0]){

        printf("Digite 1 para adicionar um nome \n");
        printf("Digite 2 para remover um nome \n");
        printf("Digite 3 para buscar o programa \n");
        printf("Digite 4 para listar os nomes \n");
        printf("Digite 5 fechar o programa \n");
        scanf("%i", &((int*)pBuffer)[4]);

        switch(((int*)pBuffer)[4]){

            case 1:

                primeironodo = Push(pBuffer,primeironodo,Criarnodo());
                
                
            break;

            case 2:

                printf("\n2");

            break;

            case 3:

            printf("\n3");

            break;

            case 4:

            printf("\n4");
            Listar(pBuffer,primeironodo);

            break;

            case 5:

            printf("Saindo do Aplicativo.");
            free(pBuffer);
            return EXIT_SUCCESS;

            break;           


        }
    }
}
void *Criarnodo(){

    void *nodo = malloc(NODO_TAM);
    *(void**)nodo = NULL;
    printf("Insira Nome:");scanf("%s", (char*)nodo+NOME);
    printf("Insira Idade:");scanf("%d", &*(int*)nodo+IDADE);
    printf("Insira Telefone:");scanf("%d", &*(int*)nodo+TELEFONE);
    *(void**)(nodo+PROXIMO) = NULL;


    return nodo;

}
void *Push(void *pBuffer , void *primeironodo, void *novonodo){


    //primeiro push da lista
    if(primeironodo == NULL){

        primeironodo = novonodo;
    
        return primeironodo;
    }

    if(strncmp(((char*)primeironodo+NOME) , ((char*)novonodo+NOME) , sizeof(char)*30) <= 0 ){
            
        *(void**)(novonodo+PROXIMO) = primeironodo;
        *(void**)primeironodo = novonodo;
        *(void**)(primeironodo + PROXIMO) = NULL;
        primeironodo = novonodo;

        return primeironodo;
    }

    void *leitor = primeironodo;
    void *leitoraux = primeironodo;

    while (leitor != NULL && strncmp((char*)primeironodo,(char*)novonodo,sizeof(char)*30) <= 0){
        leitoraux = leitor;
        leitor = *(void**)(leitor+PROXIMO);
    }
    *(void**)(leitoraux+PROXIMO) = novonodo;
    *(void**)(novonodo) = leitoraux;
    *(void**)(novonodo+PROXIMO) = leitor;
    *(void**)(leitor)= novonodo;
    *(void**)(leitor+PROXIMO)= NULL;
}
void *Listar(void *pBuffer, void *comecolista){

    if(comecolista == NULL ){
        printf("\nOpa, parece que sua lista esta vazia.");
        return 1;
    }

    void *leitor = comecolista;

    while (leitor != NULL){

        printf("\n----Nodo %d----\n", ((int*)pBuffer)[12]);
        printf("\nNome: %s\n", (char*)leitor+NOME);
        printf("\nIdade: %d\n", *(int*)leitor+IDADE);
        printf("\nTelefone: %d\n", *(int*)leitor+TELEFONE);

        leitor = *(void**)(leitor+PROXIMO);
    }
}