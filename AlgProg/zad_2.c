// 2. Розробити схему алгоритму та програмний проект для: 
// -  обчислення  елементів  матриці  розмірністю  N х N  за  формулою  А ij  = sin(i) + ln(j2 ), де  i = ; j= 
// -  обчислення  елементів  вектора  добутків  елементів  головної  діагоналі матриці на елементи другого рядка; 
// -  переставляння елементів побічної діагоналі й останнього стовпчика матриці


#include <stdio.h>
#include <stdlib.h>
//#include <math.h>
#include <tgmath.h>

#define MAX 99
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN)
#define N 6

int main() {
    double matrix[N][N];
    double dob[N];
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            matrix[i][j] = sin((double)(i)) + log((double)((j+1)*(j+1)));
            if (i == j ) dob[i] = matrix[i][j];
            printf("%10g", matrix[i][j]);
        }
        printf("\n");
    }
    
    for (int i=0, j=N-1; i<N; i++, j--){
        double tmp = matrix[i][j];
        matrix[i][j] = matrix[i][N-1];
        matrix[i][N-1] = tmp;
        dob[i] = matrix[1][i]*dob[i];
        printf("dobutok[%d]=%10g\n", i, dob[i]);
    }
    
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            printf("%10g", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}