#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void allocar(char *string, int ndechars);

int main(){

    int ndechars;
    char *string;
    

    printf("Insira o numero de chars da string\n");
    scanf("%d", &ndechars);


    allocar(string, ndechars);

    printf("Insira a sua string desejada (Maximo de %d chars)\n", ndechars);
    scanf("%s", &string);

    printf("Sua frase é '%s'", string);


 
    return 0;
}
void allocar(char *string, int ndechars){
    string = (char *)malloc(sizeof(char) * ndechars+1);
}