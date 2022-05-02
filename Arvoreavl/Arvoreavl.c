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

int main(){

    No *Raiz = NULL;

    srand(time(0));/* define a seed para o rand()*/

    return 0;
}

void caso1(){

    PonteiroNo ppRaiz;

    int ndenodos,aleatorio;
    printf("Insira o numero de nos que você deseja adicionar na arvores.\n");
    scanf("%d", &ndenodos);
    No novono;
    aleatorio = rand();
}

void caso2(){

}

int inserir(No **ppRaiz, int x){
    
    if(*ppRaiz == NULL){
        
        *ppRaiz =(PonteiroNo)malloc(sizeof(No));
        (*ppRaiz)->reg.Dado = x;
        (*ppRaiz)->pDireita = NULL;
        (*ppRaiz)->pEsquerda = NULL;
        return 1;
    }
    else if( (*ppRaiz)->reg.Dado > x){
        if(inserir(&(*ppRaiz)->pEsquerda,x) ){
            if(Balancear(ppRaiz)){
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if((*ppRaiz)->reg.Dado < x){
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