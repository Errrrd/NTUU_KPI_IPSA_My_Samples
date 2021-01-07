//5 – 24. Впорядкувати за спаданням методом вибору всі елементи матриці m*n , по рядках так, ніби кожний наступний рядок є продовженням попереднього.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100
#define MIN 10
#define RAND() MIN+rand()%(MAX-MIN)

#define M 10
#define N 10
#define SIZE N*M

void selectSortRevers(int * firstElement, int size) {
    int max;
    int tmp;
    
    for ( int i = 0; i < size; i++ ) {
        max = i;
        for ( int j = i + 1; j < size; j++ ) {
            if ( *(firstElement+j) >= *(firstElement+max) ) {
                max = j;
            }
        }
        tmp = *(firstElement+i);
        *(firstElement+i) = *(firstElement+max);
        *(firstElement+max) = tmp;
    }
}

void matrixInit(int * firstElement, int size) {
    for ( int i=0; i<size; i++ ){ *(firstElement+i)=RAND(); }
}

void matrixPrint(int * firstElement, int rows, int cols) {
    for ( int i=0; i<rows; i++ ){
        for ( int j=0; j<cols; j++ ){
            printf("%4d", *(firstElement+(i*cols)+j));
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int array[N][M];
    
    srand(time(NULL));
    
    matrixInit(&array[0][0], SIZE);
    matrixPrint(&array[0][0], N, M);
    selectSortRevers(&array[0][0], SIZE);
    matrixPrint(&array[0][0], N, M);
    
    return 0;
}
