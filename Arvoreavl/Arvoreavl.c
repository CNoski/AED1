#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


typedef struct Registro{
    int Dado;
}Registro;

typedef struct No* PonteiroNo;

typedef struct No{
    Registro reg;
    PonteiroNo pEsquerda, pDireita;
}No;

int Altura(No* pRaiz);
int FB(No *pRaiz);
void RotSimEsq(No **ppRaiz);
void RotSimDir(No **ppRaiz);
int BalancaDireita(No** ppRaiz);
int BalancaDireita(No** ppRaiz);
int Balancear(No** ppRaiz);
void Limpar(No *pRaiz);
int TesteArvoreAVL(No* pRaiz);

int main(){

    No *Raiz = NULL;

    int menu;

    do
    {
        printf("Digite 1 para o primeiro caso.\n");
        printf("Digite 2 para o segundo caso.\n");
        printf("Digite 3 para o sair.\n");

        switch(menu){
            case 1:
                caso1(Raiz);
                break;
            case 2:
                caso2(Raiz);
                break;
            case 3:
                exit(1);
                break;
            default:
                print("Opção invalida.");
                break;
        }
    } while (menu != 3);
    

    return 0;
}

void caso1(No *pRaiz){


    int ndenos, aleatorio, i;

    srand(time(0));/* define a seed para o rand()*/

    printf("Insira o numero de nos que você deseja adicionar na arvores.\n");
    scanf("%d", &ndenos);

    for(i=0;i<ndenos;i++){
        aleatorio = rand()%2001-1000;
        inserir(&pRaiz,aleatorio);
    }
    /*Imprimir arvore*/


    if(TesteArvoreAVL(pRaiz)){
        printf("\nA arvore e AVL");
    }
    else{
        printf("\nNao e AVL");
    }

    Limpar(pRaiz);
}

void caso2(){

}

int inserir(No **ppRaiz, int x){
    
    if(*ppRaiz == NULL){/*Caso a arvore esteja vazia*/
        
        *ppRaiz =(PonteiroNo)malloc(sizeof(No));
        (*ppRaiz)->reg.Dado = x;
        (*ppRaiz)->pDireita = NULL;
        (*ppRaiz)->pEsquerda = NULL;
        return 1;
    }
    else if( (*ppRaiz)->reg.Dado > x){/*Caso o novo número seja menor que o nó anterior[insere na esquerda]*/
        if(inserir(&(*ppRaiz)->pEsquerda,x) ){
            if(Balancear(ppRaiz)){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if((*ppRaiz)->reg.Dado < x){/*Caso o novo número seja maior que o nó anterior[insere na direita]*/
        if(inserir(&(*ppRaiz)->reg.Dado, x)){
            if(Balancear(ppRaiz)){
                return 0;
            }
            else{
                return 1;              
            }
        }
        else{
            return 0;
        }
    }
    else{
        return 0;
    }
}



int Altura(No* pRaiz){
    int AlturaEsquerda, AlturaDireita;
    if(pRaiz == NULL){
        return 0;
    }
    AlturaEsquerda = Altura(pRaiz->pEsquerda);
    AlturaDireita = Altura(pRaiz->pDireita);

    if(AlturaEsquerda > AlturaDireita){
        return AlturaEsquerda + 1;
    }
    else{
        return AlturaDireita + 1;
    }

}

int FB(No *pRaiz){
    if(pRaiz == NULL){
        return 0;
    }
    return Altura(pRaiz->pEsquerda) - Altura(pRaiz->pDireita);
}

int BalancaEsquerda(No** ppRaiz){

    int fbEsq = FB((*ppRaiz)->pEsquerda);

    if(fbEsq > 0){
        /*rotação simples direita*/
        RotSimDir(ppRaiz);
        return 1;
    }
    else if(fbEsq < 0){
        /*rotação dupla direita*/
        RotSimEsq(&((*ppRaiz)->pEsquerda));
        RotSimDir(ppRaiz);
        return 1;
    }
    return 0;
}
int BalancaDireita(No** ppRaiz){

    int fbDir = FB((*ppRaiz)->pDireita);

    if(fbDir > 0){
        /*rotação simples direita*/
        RotSimEsq(ppRaiz);
        return 1;
    }
    else if(fbDir < 0){
        /*rotação dupla direita*/
        RotSimDir(&((*ppRaiz)->pDireita));
        RotSimEsq(ppRaiz);
        return 1;
    }
    return 0;
}
void RotSimEsq(No **ppRaiz){
    No *pAux;
    pAux = (*ppRaiz)->pDireita;
    (*ppRaiz)->pDireita = pAux->pEsquerda;
    pAux->pEsquerda = (*ppRaiz);
    (*ppRaiz) = pAux;
}
void RotSimDir(No **ppRaiz){
    No *pAux;
    pAux = (*ppRaiz)->pEsquerda;
    (*ppRaiz)->pEsquerda = pAux->pDireita;
    pAux->pEsquerda = (*ppRaiz);
    (*ppRaiz) = pAux;
}
int Balancear(No** ppRaiz){
    
    int fb = FB(*ppRaiz);
    if(fb > 1){
        return BalancaEsquerda(ppRaiz);
    }
    else if(fb < -1){
        return BalancaDireita(ppRaiz);
    }
    else{
        return 0;
    }
}
int TesteArvoreAVL(No* pRaiz){
    int fb;

    if(pRaiz == NULL){
        return 1;
    }
    if(!TesteArvoreAVL(pRaiz->pEsquerda)){/*bate na folha e vai testando na volta*/
        return 0;
    }
    if(!TesteArvoreAVL(pRaiz->pDireita)){/*bate na folha e vai testando na volta*/
        return 0;
    }
    fb = FB(pRaiz);
    if((fb > 1) || fb < -1){
        return 0;/*retorna falha*/
    }
    else{
        return 1;/*retorna sucesso*/
    }
}
void Limpar(No *pRaiz){
    if(pRaiz == NULL){
        return;
    }

    Limpar(pRaiz->pEsquerda);
    Limpar(pRaiz->pDireita);

    free(pRaiz);
}
