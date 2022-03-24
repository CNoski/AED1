#include <stdio.h>
#include <stdlib.h>

int main(){

    int x = 10;
    float y = 5.5;
    char z = 'z';

    int *intx;
    float *floaty;
    char *charz;

    intx = &x;
    floaty = &y;
    charz = &z;

    x = 4;
    y = 4.4;
    z = 'y';

    printf("X = %i\n", *intx);
    printf("Y = %f\n", *floaty);
    printf("Z = %c\n", *charz);
    

    return 0;
}
