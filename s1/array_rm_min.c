#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define MAX 99
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN)

int main() {
    int array[N];
    int N1 = N-1;
    int idxMinNum = 0;
    
    srand(time(NULL));
    for (int minNum = MAX, i = 0; i < N; i++)
    {
        array[i] = RAND();
        printf("%4d", array[i]);
        if (minNum > array[i])
        {
            idxMinNum = i;
            minNum = array[i];
        };
    }
    printf("\n");
    for (int i=0, j=1; i < N1; i++, j++)
    {
        if( i >= idxMinNum)
        {
            array[i] = array[j];
        }
        printf("%4d", array[i]);
    }
    printf("\n");
    
    return 0;
}