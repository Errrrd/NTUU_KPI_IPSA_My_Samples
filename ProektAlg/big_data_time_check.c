#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50000001 
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN) // 10 + 0...49999990

int main()
{
    srand(time(NULL));
    union ticks{
        unsigned long long t64;
        struct s32 { long th, tl; } t32;
    } start, end;
    // Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz; cpu MHz: 3101.000
    double cpu_Hz = 31001000000ULL; 
    int n = RAND();
    int odd=0, even = 0;
    int * bigArray = malloc(sizeof(int)*n);
    
    for(int i = 0; i < n; i++)
    {
        *(bigArray+i) = RAND();
    }
    
    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
    for(int i = 0; i < n; i++)
    {
        if(*(bigArray+i)% 2 == 0) even++;
        else odd++;
    }
    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    
    printf("Big array has %d num: odd=%d, even=%d, diff=%d(%f\%)\n ", n, odd, even, (odd-even), (((odd-even) < 0) ? ((float)(even-odd)/n*100.0) : ((float)(odd-even)/n*100.0)));
    
    printf("Time taken: %lf sec.\n", (end.t64-start.t64)/cpu_Hz);
    free(bigArray);
    
    return 0;
}
