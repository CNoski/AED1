#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Registro {
    int dado;
} Registro;

typedef struct No {
    Registro Reg;
    struct No *pEsq, *pDir;
} No;


int FB (No* pRaiz);
int Altura(No* pRaiz);
void RSE(No** ppRaiz);
void RSD(No** ppRaiz);
int BalancaEsquerda(No** ppRaiz);
int BalancaDireita(No** ppRaiz);
int Balancear(No** ppRaiz);
int TesteArvoreArvl(No* pRaiz);
int Inserir(No** ppRaiz,int x);
void Listar(No *pRaiz);
void Limpar(No *pRaiz);
void Registrar(Registro *reg);
int Remover(No** ppRaiz, int x);
No* procuraMenor (No* pAtual);
void Caso1(No *pRaiz);
void Caso2();

int main(){
    No *pRaiz = NULL;

    int op;

    do{
        printf("Caso 1 digite 1\n");
        printf("Caso 2 digite 2\n");
        printf("Digite 3 para sair\n");
        scanf("%d", &op);

        switch(op){
            case 1:
                Caso1(pRaiz);
                break;
            case 2:
                Caso2();
                break;
            case 3:
                exit(1);
                break;
            default:
                printf("Opcao invalida\n");
                break;
        }
    }while(op!=3);

}

void Caso1(No *pRaiz){
    int numeroNos, random, i;
    srand(time(0));

    printf("Numero de nos que deseja ter na arvore? ");
    scanf("%d", &numeroNos);
    getchar();

    for(i=0;i<numeroNos;i++){
        random = rand()%1000;
        Inserir(&pRaiz, random);
    }

    Listar(pRaiz);
    printf("\n");

    if(TesteArvoreArvl(pRaiz)) {
        printf("\nA arvore e AVL\n");
    }
    else {
        printf("\nNao e AVL\n");
    }

    Limpar(pRaiz);
}

No* procuraMenor (No* pAtual) { 
    No *no1 = pAtual;
    No *no2 = pAtual->pEsq;
    while (no2 != NULL) {
        no1 = no2;
        no2 = no2->pEsq;
    }
    return no1;
}

int Remover(No** ppRaiz, int x){
    if(*ppRaiz == NULL){
        printf("O valor n existe\n");
        return 0;
    }
    int res; 
    if(x < (*ppRaiz)->Reg.dado){
        if((res=Remover(&(*ppRaiz)->pEsq, x)) == 1){
            Balancear(ppRaiz);
        }
    }

    if(x > (*ppRaiz)->Reg.dado){
        if((res=Remover(&(*ppRaiz)->pDir, x)) == 1){
            Balancear(ppRaiz);
        }
    }

    if((*ppRaiz)->Reg.dado == x){
        if((*ppRaiz)->pEsq == NULL || (*ppRaiz)->pDir == NULL){
            No *removido = (*ppRaiz);
            if((*ppRaiz)->pEsq != NULL){
                (*ppRaiz) = (*ppRaiz)->pEsq;
            }
            else
                (*ppRaiz) = (*ppRaiz)->pDir;
            free(removido);
        }
        //tem dois filhos
        else{
            No *temporario = procuraMenor((*ppRaiz)->pDir);
            (*ppRaiz)->Reg.dado = temporario->Reg.dado;
            Remover(&(*ppRaiz)->pDir, (*ppRaiz)->Reg.dado);
            Balancear(ppRaiz);
        }
        return 1;
    }
    return res;
}

void Limpar(No *pRaiz){
    if (pRaiz == NULL) {
        return;
    }

    Limpar(pRaiz->pEsq);
    Limpar(pRaiz->pDir);

    free(pRaiz);
}


int Altura(No* pRaiz){
    int iEsq,iDir;
    if (pRaiz == NULL)
        return 0;

    iEsq = Altura(pRaiz->pEsq);
    iDir = Altura(pRaiz->pDir);

    if( iEsq > iDir )
        return iEsq + 1;

    else
        return iDir + 1;
}

int FB (No* pRaiz){
    if (pRaiz == NULL){
        return 0;
    }

    return Altura(pRaiz->pEsq) - Altura(pRaiz->pDir);
}

void RSE(No** ppRaiz){
    No *pAux;
    pAux = (*ppRaiz)->pDir;
    (*ppRaiz)->pDir = pAux->pEsq;
    pAux->pEsq = (*ppRaiz);
    (*ppRaiz) = pAux;
}

void RSD(No** ppRaiz){
    No *pAux;
    pAux = (*ppRaiz)->pEsq;
    (*ppRaiz)->pEsq = pAux->pDir;
    pAux->pDir = (*ppRaiz);
    (*ppRaiz) = pAux;
}

int BalancaEsquerda(No** ppRaiz){
    int fbe = FB ( (*ppRaiz)->pEsq );

    if( fbe >= 0 ){
        RSD(ppRaiz);
        return 1;
    }

    else if (fbe < 0 ){ 
        RSE( &((*ppRaiz)->pEsq) );
        RSD( ppRaiz ); 
        return 1;
    }

    return 0;
}

int BalancaDireita(No** ppRaiz){
    int fbd = FB( (*ppRaiz)->pDir);

    if( fbd <= 0 ){
        RSE (ppRaiz);
        return 1;
    }

    else if (fbd > 0 ){ 

        RSD( &((*ppRaiz)->pDir) );
        RSE( ppRaiz );
        return 1;
    }
    return 0;
}

int Balancear(No** ppRaiz){
    int fb = FB(*ppRaiz);
    if( fb > 1)
        return BalancaEsquerda(ppRaiz);

    else if(fb < -1 )
        return BalancaDireita(ppRaiz);

    else
        return 0;
}

int Inserir(No** ppRaiz,int x){
    if (*ppRaiz == NULL){
        *ppRaiz = (No*)malloc(sizeof(No));
        (*ppRaiz)->Reg.dado = x;
        (*ppRaiz)->pEsq = NULL;
        (*ppRaiz)->pDir = NULL;
        return 1;
    }

    else if ( (*ppRaiz)->Reg.dado > x){
        if ( Inserir(&(*ppRaiz)->pEsq,x) ){
            if (Balancear(ppRaiz))
                return 0;
            else
                return 1;
        }
    }

    else if ( (*ppRaiz)->Reg.dado < x ){
        if ( Inserir(&(*ppRaiz)->pDir,x) ){
            if (Balancear(ppRaiz))
                return 0;
            else
                return 1;
        }
        else
            return 0;
    }

    else{
        return 0; /* valor já presente */
    }
    return 0;
}

int TesteArvoreArvl(No* pRaiz){
    int fb;
    if (pRaiz == NULL)
        return 1;

    if (!TesteArvoreArvl(pRaiz->pEsq))
        return 0;

    if (!TesteArvoreArvl(pRaiz->pDir))
        return 0;

    fb = FB (pRaiz);
    if ( ( fb > 1 ) || ( fb < -1) )
        return 0;

    else
        return 1;
}

void Listar (No *pRaiz){

    if (pRaiz != NULL) {
        printf("%d(", pRaiz->Reg.dado);
        Listar(pRaiz->pEsq);
        Listar(pRaiz->pDir);
        printf(")");
    }

}

void Caso2(){
    No *pRaiz = NULL;

    printf("Caso 1a: Inserir 15\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    printf("Arvore antes do 15\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 15);
    printf("Arvore depois do 15\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 2a: Inserir 15\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 26);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 3);
    printf("Arvore antes do 15\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 15);
    printf("Arvore depois do 15\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 3a: Inserir 15\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 26);
    Inserir(&pRaiz, 3);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 21);
    Inserir(&pRaiz, 30);
    Inserir(&pRaiz, 2);
    Inserir(&pRaiz, 7);
    Inserir(&pRaiz, 11);
    printf("Arvore antes do 15\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 15);
    printf("Arvore depois do 15\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 1b: Inserir 8\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    printf("Arvore antes do 8\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 8);
    printf("Arvore depois do 8\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 2b: Inserir 8\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 26);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 3);
    printf("Arvore antes do 8\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 8);
    printf("Arvore depois do 8\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 3b: Inserir 8\n");
    Inserir(&pRaiz, 20);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 26);
    Inserir(&pRaiz, 3);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 21);
    Inserir(&pRaiz, 30);
    Inserir(&pRaiz, 2);
    Inserir(&pRaiz, 7);
    Inserir(&pRaiz, 11);
    printf("Arvore antes do 8\n");
    Listar(pRaiz);
    printf("\n");
    Inserir(&pRaiz, 8);
    printf("Arvore depois do 8\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Caso 1: Deletar\n");
    Inserir(&pRaiz, 2);
    Inserir(&pRaiz, 1);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 3);
    Inserir(&pRaiz, 5);
    printf("Arvore antes de deletar o 1\n");
    Listar(pRaiz);
    printf("\n");
    //Removendo o 1
    Remover(&pRaiz, 1);
    printf("Arvore depois de deletar o 1\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    printf("Case 2: Delete\n");
    Inserir(&pRaiz, 6);
    Inserir(&pRaiz, 2);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 1);
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 8);
    Inserir(&pRaiz, 66);
    Inserir(&pRaiz, 3);
    Inserir(&pRaiz, 5);
    Inserir(&pRaiz, 7);
    Inserir(&pRaiz, 65);
    Inserir(&pRaiz, 67);
    Inserir(&pRaiz, 68);
    printf("Arvore antes de deletar o 1\n");
    Listar(pRaiz);
    printf("\n");
    //Removendo o 1
    Remover(&pRaiz, 1);
    printf("Arvore depois de deletar o 1\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;

    
    printf("Case 3: Delete\n");
    Inserir(&pRaiz, 5);
    Inserir(&pRaiz, 2);
    Inserir(&pRaiz, 8);
    Inserir(&pRaiz, 1);
    Inserir(&pRaiz, 3);
    Inserir(&pRaiz, 7);
    Inserir(&pRaiz, 65); //A
    Inserir(&pRaiz, 4);
    Inserir(&pRaiz, 6);
    Inserir(&pRaiz, 9);
    Inserir(&pRaiz, 66);//B
    Inserir(&pRaiz, 67);//C
    printf("Arvore antes de deletar o 1\n");
    Listar(pRaiz);
    printf("\n");
    //Removendo o 1
    Remover(&pRaiz, 1);
    printf("Arvore depois de deletar o 1\n");
    Listar(pRaiz);
    printf("\n\n");
    Limpar(pRaiz);
    pRaiz = NULL;
}
