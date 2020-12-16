// 1. Розробити програму для введення матриці цілих чисел розмірністю 6 х 3 і обчислення елементів вектора середніх арифметичних непарних елементів парних рядків.
// 0/2/4


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 99
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN)
#define N 6
#define M 3

int main() {
    srand(time(NULL));
    int matrix[N][M];
    double Sa=0;
    
    
    for (int i=0; i<N; i++){
        double tmpS = 0;
        for (int j=0; j<M; j++){
            matrix[i][j] = RAND();
            printf("%4d", matrix[i][j]);
            tmpS += matrix[i][j];
        }
        if(i%2 == 0)
            printf("\nSerednye Aryfm = %g", tmpS /(double)(M) );
        printf("\n");
    }
    
    return 0;
}