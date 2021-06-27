#include <stdio.h>
//#include <stdlib.h>

#define N 7
#define M 8

int main() {
    int matrix[N][M];

    
    for ( int i=0; i <= N-1; i++ ) {
        for ( int j=0; j <= M-1; j++ ) {
            if ( (i%2)==0 ) printf("%d,%d ",i,j);
            else            printf("%d,%d ",i, M-1-j);
        }
        printf("\n");
    }
    
    return 0;
}