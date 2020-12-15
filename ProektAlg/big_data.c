#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000001
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN)

int main()
{
    srand(time(NULL));
    int n = RAND();
    int odd=0, even = 0;
    int * bigArray = malloc(sizeof(int)*n);
    
    for(int i = 0; i < n; i++)
    {
        *(bigArray+i) = RAND();
        if(*(bigArray+i)% 2 == 0) even++;
        else odd++;
    }
    
    printf("Big array has %d num: odd=%d, even=%d, diff=%d(%f\%)\n ", n, odd, even, (odd-even), (((odd-even) < 0) ? ((float)(even-odd)/n*100.0) : ((float)(odd-even)/n*100.0)));

    free(bigArray);
    
    return 0;
}
