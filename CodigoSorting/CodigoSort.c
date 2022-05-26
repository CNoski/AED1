#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

float InsertionSort(int *pvetor, int n);
float SelectionSort(int *pvetor, int n);
float MergeSort(int *pvetor, int n);
void Dividir(int VetorMerge, int esq, int dir);
void Conquistar(int VetorMerge[], int esq, int meio, int dir);
float QuickSortmain(int *pvetor, int esq, int n);
int Separar(int VetorQuick[], int esq, int dir);
int Separar_r(int VetorQuick[], int esq, int dir);
int QuickSort(int VetorQuick, int esq, int dir);
float tempodif(struct timeval *start, struct timeval *end);


int main()
{   
    srand(time(NULL));
    int n, i;
    printf("Insira o numero de inteiros do vetor.\n");
    scanf("%d", &n);
    int vetor[n];

    for ( i = 0; i < n; i++)
        vetor[i] = rand()%1000;


    float tempoinsertion = InsertionSort(vetor, n);
    float temposelection = SelectionSort(vetor, n);
    float tempomerge = MergeSort(vetor, n);
    float tempoquick = QuickSortmain(vetor, 0, n);

    printf("Tempo Insertion = %.8f.\n", tempoinsertion);
    printf("Tempo Selection = %.8f.\n", temposelection);
    printf("Tempo Merge = %.8f.\n", tempomerge);
    printf("Tempo Quick = %.8f.\n", tempoquick);
    return 0;
}
//================INSERTIONSORT====================
float InsertionSort(int *pvetor, int n)
{
    printf("==========Insertion Sort==========\n\n");
    int VetorInsert[n], i, chave, j;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorInsert[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorInsert[i]);
    }

    struct timeval comeco, fim;
    
    gettimeofday(&comeco, NULL);/*começo da contagem*/
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
    gettimeofday(&fim, NULL);/*fim da contagem*/

    printf("Vetor Organizado\n\n");
    for ( i = 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorInsert[i]);

    return tempodif(&comeco, &fim);
}
//================SELECTIONSORT====================
float SelectionSort(int *pvetor, int n)
{
    printf("==========Selection Sort==========\n\n");
    int VetorSelection[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorSelection[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorSelection[i]);
    }

    struct timeval comeco, fim;

    int VAux, VMenor, VTemp, VTroca;

    gettimeofday(&comeco, NULL);/*começo da contagem*/

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

    gettimeofday(&fim, NULL);/*fim da contagem*/

    printf("Vetor Organizado\n\n");
    for ( i = 0; i < n; i++)
    printf("<Vetor[%d] = %d>\n", i, VetorSelection[i]);
    
    return tempodif(&comeco, &fim);
}
//================MERGESORT====================
float MergeSort(int *pvetor, int n){
    printf("==========Merge Sort==========\n\n");

    int VetorMerge[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorMerge[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorMerge[i]);
    }

    struct timeval comeco, fim;
    gettimeofday(&comeco, NULL);/*começo da contagem*/
    Dividir(VetorMerge, 0, n);
    gettimeofday(&fim, NULL);/*fim da contagem*/

    printf("Vetor organizado\n\n");

    for ( i= 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorMerge[i]);

    return tempodif(&comeco, &fim);
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
float QuickSortmain(int *pvetor, int esq, int n)
{  
    printf("==========Quick Sort==========\n\n");
    int VetorQuick[n], i;
    printf("Vetor desorganizado\n\n");
    for ( i= 0; i < n; i++)
    {
        VetorQuick[i] = pvetor[i];
        printf("<Vetor[%d] = %d>\n", i, VetorQuick[i]);
    }
    struct timeval comeco, fim;
    gettimeofday(&comeco, NULL);/*começo da contagem*/
    QuickSort(VetorQuick, 0, n);
    gettimeofday(&fim, NULL);/*fim da contagem*/


    printf("Vetor organizado\n\n");
    for ( i= 0; i < n; i++)
        printf("<Vetor[%d] = %d>\n", i, VetorQuick[i]);

    return tempodif(&comeco, &fim);
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
float tempodif(struct timeval *comeco, struct timeval *fim)
{
    return (fim->tv_sec - comeco->tv_sec) + 1e-6*(fim->tv_usec - comeco->tv_usec);
}