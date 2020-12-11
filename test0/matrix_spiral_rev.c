#include <stdio.h>
//#include <stdlib.h>

#define N 7

int main() {
    int matrix[N][N];
    int startCol=0, endCol=N-1, startRow=0, endRow=N-1;
    int maxNum = N*N;
    
    for ( int i=startRow, j = startRow, num=0, bRow=0, bFwd = 0; num < maxNum; )
    {
        if(bRow)
        {
            if(bFwd){//row stay col forward
                matrix[startRow][j] = num++;
                if( j < endCol){
                    j++;
                }else{
                    bFwd = 0;
                    bRow = 0;
                    i = ++startRow;
                }
            } else { //row stay col backward
                matrix[endRow][j] = num++;
                if( j > startCol){
                    j--;
                }else{
                    bFwd = 1;
                    bRow = 0;
                    i = --endRow;
                }
            }
        } else {
            if(bFwd){ //col stay row down 
                matrix[i][startCol] = num++;
                if( i > startRow){
                    i--;
                }else{
                    bFwd = 1;
                    bRow = 1;
                    j = ++startCol;
                }
            } else {//col stay row down
                matrix[i][endCol] = num++;
                if( i < endRow){
                    i++;
                }else{
                    bFwd = 0;
                    bRow = 1;
                    j = --endCol;
                }
            }
        }
    }
    for ( int i=0; i < N; i++ ){
        for ( int j=0; j < N; j++ ) { printf("%5d", matrix[i][j]); }
        printf("\n\n");
    }    
    
    return 0;
}