#include <stdio.h>

int main(){
    
    float x[10] = {1,2, 3, 4, 5, 6, 7, 8, 9, 10};
    int i, count = 10;
    int *ptr;

        for (size_t i = 0; i < count; i++){

            ptr = &x[i];
            printf("Endrereco de %d e = %d\n", i, ptr);

        }
        

    return 0;
}
