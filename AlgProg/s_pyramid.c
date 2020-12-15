//24. Обчислити площу поверхні піраміди, гранню якої є рівносторонній трикутник із стороною А.
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SQRT3 sqrt(3.0)

int main()
{
    float A;
    double Sp = 0;
    
    printf("please write float number (side of triangle):");
    if(scanf("%f", &A) != 1){
        printf("\nWrong input. Please input a float variable next time\n");
        exit(1);
    }
    
    Sp = A*A*SQRT3;
    
    printf("\nSurface of Pyramid with side A=%f is %lf\n", A, Sp);
    
    return 0;
}
