#include <stdio.h>
#include <stdlib.h>

void adicionar(p, numpessoa);

typedef struct{
    char nome[30];
    int idade;
    int altura;
}Pessoa;

int main(void){


    int sair = 1;
    int menu;
    int numpessoa = 0;

    Pessoa *p;




    while(sair){
        
        printf("Digite 1 para inserir uma pessoa");
        printf("Digite 3 para inserir uma pessoa");
        scanf("%d", menu);

        switch (menu){
        
        case 1:

            numpessoa = numpessoa + 1;
            adicionar(p, numpessoa);
            
            break;
        case 2:
            /* code */
            break;
        case 3:
            
            free(p);
            break;
        
        }

    }
    
    return 0;
}
void adicionar( p, numpessoa){

    if (numpessoa = 0){

        p =(Pessoa*)malloc(sizeof(Pessoa) * numpessoa);
        
        printf("Insira o nome");scanf("%s",&p->nome);
        printf("Insira a idade");scanf("%d",&p->idade);
        printf("Insira a altura");scanf("%d",&p->altura);
    }
    

}