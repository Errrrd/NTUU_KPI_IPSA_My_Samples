//3-24 Обчислити з точністю до Eps ( 0 <Eps < 1 ) кожну внутрішню суму, визначити кількість доданків, вивести проміжні результати: Sum(x1..5)Sum(k1...infinity) X!/(k*(X^k))
#include <stdio.h>
#include <stdlib.h>

#define EPS 0.0001

int main()
{
    double xSum = 0.0;
    int fctX = 1;
    
    printf("Summ for k:\n\
--------------------------------------------------------------------------\n\
|   last k   |   Summ(k)  |  X!   |     x^k    |    currEps   |     Eps  |\n\
|------------|------------|-------|------------|--------------|----------|\n");
    for(int x = 1; x < 6; x++){
        int k=1;
        int expX = x;
        double kSum0 = 0;
        double kSum = 0;
        double tmpEps = 0.0;
        
        //first Sum:
        fctX *=x;
        kSum = (double)fctX/(double)(k++*expX);
        tmpEps = kSum - kSum0;
        //other sum
        while( EPS < tmpEps && k > 0 ){ //int k > 2^31 is < 0
            expX *= x;
            kSum0 = kSum;
            kSum += (double)fctX/(double)(k++*expX);
            tmpEps = kSum - kSum0;
            //printf("eps:[%g-%g]=%e\n", kSum, kSum0, tmpEps );
        }
        xSum += kSum;
        printf("| %10d | %10g | %5d | %10d | %12g | %8g |\n", k, kSum, fctX, expX, tmpEps, EPS );
    }
    printf("--------------------------------------------------------------------------\n");
    printf("\nSumm for x = 1...5 xS=%g\n", xSum);
    
    return 0;
}
