#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){

    void *Ancora ;
    
    void *pBuffer;
    char *Nometemp[30];
    int *Telefonetemp;
    int *Idadetemp;

    int *loop_menu = 1;
    int *valor_menu = 0;
    
    while (loop_menu){

        printf("Digite 1 para adicionar um nome \n");
        printf("Digite 2 para remover um nome \n");
        printf("Digite 3 para buscar o programa \n");
        printf("Digite 4 para listar os nomes \n");
        printf("Digite 5 fechar o programa \n");
        scanf("%d", valor_menu);


        if (*valor_menu = 1){
            
            criar(*Nometemp, *Telefonetemp, *Idadetemp);
            push(&Ancora, criar);

        
        }
        else if (*valor_menu = 2){


        }
        else if (*valor_menu = 3){
            

        }
        else if (*valor_menu = 4){
            

        }
        else if (*valor_menu = 5){
            

        }
    }
    
    
    
    return 0;
}



void criar(char *Nometemp[30] , int *Telefonetemp, int *Idadetemp){

    void *nodo = (void *)malloc( sizeof(char) * 30 + sizeof(int) * 2 + sizeof(void*) );/* Aloca um espaço para 4 int e 30 char*/
    void *comeconodo;//sizeof(int)
    comeconodo = &nodo;/* cria um ponteiro pro começo do nodo */

    nodo = nodo + sizeof(void*);/*pula o espaço pro nodo anterior*/

    printf("Insira o Nome do contato.\n");
    scanf("%s", &Nometemp);/* recebe o nome*/
    memcpy(nodo, Nometemp, 30);/* copia o telefone pra dentro do nodo*/

    nodo = nodo + sizeof(char) * 30;/* pula o espaço pro que está a informação do nome */

    printf("Insira o Numero do contato.\n");
    scanf("%d",&Telefonetemp);/* recebe o telefone*/
    memcpy(nodo, Telefonetemp, sizeof(int));/* copia o telefone pra dentro do nodo*/

    nodo = nodo + sizeof(int);/* pula o espaço que armazena o telefone*/

    printf("Insira a Idade do contato.");
    scanf("%d",&Idadetemp);/* recebe a idade*/
    memcpy(nodo, Idadetemp, sizeof(int));/* Copia a idade pra dentro do nodo*/

    nodo = comeconodo; 

    return nodo;

}

void push(void **start, void **proximo){

    void **indice = start;
    void **indice_proximo = proximo;

    while ((*indice) && strncmp((*indice) + 4 , (*proximo) + 4, 30)< 1)
    {
        /* code */
    }
    

}

