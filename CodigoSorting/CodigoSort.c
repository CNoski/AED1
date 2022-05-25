#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void InsertionSort(int *pvetor, int n);
void SelectionSort(int *pvetor, int n);
void MergeSort(int *pvetor, int n);
void Dividir(int VetorMerge, int esq, int dir);
void Conquistar(int VetorMerge[], int esq, int meio, int dir);
void QuickSortmain(int *pvetor, int esq, int n);
int Separar(int VetorQuick[], int esq, int dir);
int Separar_r(int VetorQuick[], int esq, int dir);
int QuickSort(int VetorQuick, int esq, int dir);


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
    MergeSort(vetor, n);
    QuickSortmain(vetor, 0, n);

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

    Dividir(VetorMerge, 0, n);

    printf("Vetor organizado\n\n");

    for ( i= 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorMerge[i]);

    
}
void Dividir(int VetorMerge, int esq, int dir)//parte que une os vetores
{
    if (esq < dir)
    {

        int meio = (esq + dir - 1) / 2;// dir - 1 pq começa no zero;

        //recursar para fazer com todos os membros.
        Dividir(VetorMerge, esq, meio);/*esse aqui divide pra metade da esquerda*/
        Dividir(VetorMerge, meio + 1, dir);/*esse aqui divide pra metade da direita*/

        //o codigo so chega aqui depois de dividir todos vetores
        Conquistar(VetorMerge, esq, meio, dir);
    }
}
void Conquistar(int VetorMerge[], int esq, int meio, int dir)
{

    int i, j, k;
    int n1 = meio - esq + 1;
    int n2 = dir - meio;

    int Esquerda[n1], Direta[n2];

    for (i=0;i < n1; i++)
        Esquerda[i] = VetorMerge[esq + i];
    for (j = 0; j < n2; j++)
        Direta[j] = VetorMerge[meio + 1 + j];

    i = 0;
    j = 0;
    k = esq;
    while ( i < n1 && j < n2){
        if (Esquerda[i] <= Direta[j]){
            VetorMerge[k] = Esquerda[i];
            i++;
        }
        else{
            VetorMerge[k] = Direta[j];
            j++;
        }
        k++;
    }
    while (i < n1){
        VetorMerge[k] = Esquerda[i];
        i++;
        k++;
    }
    while (j < n2){
        VetorMerge[k] = Direta[j];
        j++;
        k++;
    }
}
//================QUICKSORT=====================
void QuickSortmain(int *pvetor, int esq, int n)
{  
    printf("==========Quick Sort==========\n\n");
    int VetorQuick[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorQuick[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorQuick[i]);
    }
    QuickSort(VetorQuick, 0, n);

    printf("Vetor organizado\n\n");
    for ( i= 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorQuick[i]);


}
int Separar(int VetorQuick[], int esq, int dir)
{
    int pivo = VetorQuick[esq];
    int i = esq - 1, j = dir + 1;

    while (1){
        do
        {
            i++;
        }while(VetorQuick[i] < pivo);
        do
        {
            j--;
        } while (VetorQuick[j] > pivo);

        if (i >= j)
            return j;

        int temp = VetorQuick[i];
        VetorQuick[i] = VetorQuick[j];
        VetorQuick[j] = temp;
    }
}
int Separar_r(int VetorQuick[], int esq, int dir)
{
    srand(time(0));
    int aleatorio = esq + rand()%(dir - esq);

    int temp = VetorQuick[aleatorio];
    VetorQuick[aleatorio] = VetorQuick[esq];
    VetorQuick[esq] = temp;

    return Separar(VetorQuick, esq, dir);
}
int QuickSort(int VetorQuick, int esq, int dir)
{
    if (esq < dir)
    {   
        int meio = Separar_r(VetorQuick, esq, dir);
        
        QuickSort(VetorQuick, esq, meio);
        QuickSort(VetorQuick, meio + 1, dir);
    }
}