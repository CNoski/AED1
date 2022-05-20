#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *pvetor, int n);
void SelectionSort(int *pvetor, int n);

int main()
{   
    srand(time(NULL));
    int n, i;
    printf("Insira o numero de inteiros do vetor.\n");
    scanf("%d", &n);
    int vetor[n];

    for ( i = 0; i < n; i++)
        vetor[i] = rand()%1000;

    InsertionSort(vetor, n);
    SelectionSort(vetor, n);

    return 0;
}

void InsertionSort(int *pvetor, int n)
{
    printf("==========Insertion Sort==========\n\n");
    int VetorInsert[n], i, chave, j;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorInsert[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorInsert[i]);
    }

    /*começo da contagem*/
    for ( i = 1; i < n; i++)
    {
        chave = VetorInsert[i];
        j = i - 1;

        while( j >= 0 && VetorInsert[j] > chave)
        {
            VetorInsert[j + 1] = VetorInsert[j];
            j = j - 1;
        }
        VetorInsert[j + 1] = chave;
    }
    /*fim da contagem*/
    printf("Vetor Organizado\n\n");
    for ( i = 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorInsert[i]);
  
}

void SelectionSort(int *pvetor, int n)
{
    printf("==========Selection Sort==========\n\n");
    int VetorSelection[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorSelection[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorSelection[i]);
    }

    int VAux, VMenor, VTemp, VTroca;
    for ( VAux = 0; VAux < n-1; VAux++)//ele vai até o n-1 porque o ultimo numero sempre sera o maior
    {
        VMenor = VAux;
        for ( VTemp = VAux + 1; VTemp < n; VTemp++)// checka os proximos até achar um numero menor que o menor anterior
        {
            if(VetorSelection[VTemp] < VetorSelection[VMenor])
                VMenor = VTemp;
        }
        if(VMenor != VAux)
        {
        VTroca = VetorSelection[VAux];
        VetorSelection[VAux] = VetorSelection[VMenor];
        VetorSelection[VMenor] = VTroca;
        } 
    }
    printf("Vetor Organizado\n\n");
    for ( i = 0; i < n; i++)
    printf("<Vetor[%d] = %d>\n", i, VetorSelection[i]);
    
}
//================MERGESORT====================
void MergeSort(int *pvetor, int n){
    printf("==========Merge Sort==========\n\n");

    int VetorMerge[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorMerge[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorMerge[i]);
    }
    
}
void Dividir(int VetorMerge, int esq, int dir)//parte que une os vetores
{
    if (esq < dir)
    {
        int meio = esq + (dir-1)/ 2;// dir - 1 pq começa no zero;

        //recursar para fazer com todos os membros.
        Dividir(VetorMerge, esq, meio);/*esse aqui divide pra metade da esquerda*/
        Dividir(VetorMerge, meio + 1, dir);/*esse aqui divide pra metade da direita*/

        //o codigo so chega aqui depois de dividir todos vetores

    }
}

//================QUICKSORT=====================