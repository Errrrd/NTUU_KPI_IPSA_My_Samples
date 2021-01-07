// 8. Розробити алгоритм і програму швидкого лінійного пошуку. В якості вхідних даних слід використовувати рядок тексту, з якого необхідно виділити слова. Потім слова впорядкувати за алфавітом. Аргумент пошуку – слово.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------
#define MAX 1024*256
//----------------------------------------------------------------------------
int arrayScan(char * fileName, char array[], int len);
int requestFileName(char fileName[]);
int readTextFromFile(char * fileName, char text[], int limit);
void customStrCpy(char * dest, int sizeDest, char * src);
int updateArrayWords(char * text, char * words[]);
int partition(char * array[], int start, int end);
void quickSort(char * array[], int lo, int hi);

//----------------------------------------------------------------------------
int main()
{
    union ticks{
        unsigned long long t64;
        struct s32 { long th, tl; } t32;
    } start, end;
    // Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz; cpu MHz: 3101.000
    double cpu_Hz = 31001000000ULL; 
    
    char text[MAX+1];
    char fileName[256]; fileName[255] = 0;
    int textSize = MAX;
    
    if (requestFileName(fileName) < 1) //request filename. If wrong => exit from program with error 1.
    {
        printf("File Name is not set\n");
        exit(1);
    }
    printf("\nScan file \"%s\" (size <= %d kBytes)...\n", fileName, MAX/1024);
    textSize=arrayScan(fileName, text, MAX);
    printf("Text (size=%d): \"%s\"\n", textSize, text);
    
    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
    char * words[textSize/2];
    int arrSize=updateArrayWords(text, words);;
    
    
    for( int i=0; i < arrSize; i++){
         printf("\"%s\", ", words[i] );
    }
    printf ("\n");
    
    quickSort( words, 0, arrSize-1);
    
    for( int i=0; i < arrSize; i++){
         printf("\"%s\", ", words[i]);
    }
    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    
    printf("\nTime taken: %g sec. %lld - %lld\n", (end.t64-start.t64)/cpu_Hz, end.t64, start.t64);
    return 0;
}
//----------------------------------------------------------------------------
int arrayScan(char * fileName, char array[], int len) {
    FILE *in = fopen(fileName, "r");
    if (in == NULL) { return -1; };
    
    int size = 0;
    
    for ( ; size < len && fscanf(in, "%c", &array[size]) == 1; size++ );
    array[size]=0;
    
    fclose(in);
    
    return size;
}

int requestFileName(char * fileName)
{
    int chLeftInBuff = 0;
    int scanfResult = 0;
    printf("Set please the name of file with a text.\n\
File should be in same path as program or relative/full path to file \
(<=255 symbols): ");
    
    scanfResult = scanf("%255s", fileName);
    while(getchar()!='\n') {++chLeftInBuff;}
    if(chLeftInBuff > 0) { printf("!!!User input contains more than 255 symbols (%d is extra)!!!\n"
                                , chLeftInBuff); }
    //fflush(stdin); //don't work on linux (Ubuntu)

    return scanfResult;
}

void customStrCpy(char * dest, int sizeDest, char * src){
    for( int i=0; *src != 0 && i < sizeDest; i++ )
    {
        *dest = *src;
        src++;
        dest++;
    }
    *dest=0;
}

int updateArrayWords(char * text, char * words[]) {
    int arrSize=0;
    int len = strlen(text);
    printf ("len =%d\n", len);
    for( int i=0,tmpWordSz=0, tmpIdx = 0, bIdxStarted = 0; i <= len ; i++) //text[i] != 0
    {
        
        if( ( text[i] > 47 && text[i] < 58 ) || //0-9
            ( text[i] > 64 && text[i] < 91 ) || //A-Z
            ( text[i] > 96 && text[i] < 123) //a-z
        ){
            if(!bIdxStarted)
            {
                bIdxStarted = 1;
                tmpIdx = i;
            }
            tmpWordSz++;
        } else {
            if(tmpWordSz > 0)
            {
                char word[tmpWordSz+1];
                customStrCpy( word, tmpWordSz, &text[tmpIdx]);
                words[arrSize++]=&text[tmpIdx];
                text[tmpIdx+tmpWordSz]=0;
            }
            bIdxStarted = 0;
            tmpWordSz = 0;
            tmpIdx = 0;
        }
    }
    
    return arrSize;
}
//---------------------------------------------------------------------------------
// Quick Sort
//---------------------------------------------------------------------------------
int partition(char * array[], int start, int end) {
    int pivot = (start + end) / 2;
    char * tmp;
    int hi = end - 1;
    int lo = start;
    
    tmp = array[end];
    array[end] = array[pivot];
    array[pivot] = tmp;
    for ( ; lo <= hi; ) {
        if ( strcmp(array[end], array[lo]) < 0 ) {
            if ( strcmp(array[end], array[hi]) >= 0 ) {
                tmp = array[hi];
                array[hi] = array[lo];
                array[lo] = tmp;
                lo += 1;
                hi -= 1;
            } else {
                hi -= 1;
            }
        } else {
            lo += 1;
        }
    }
    tmp = array[lo];
    array[lo] = array[end];
    array[end] = tmp;
    return lo;
}

void quickSort(char * array[], int lo, int hi) {
    int pivot = partition(array, lo, hi);
    
    if( lo < pivot - 1 ) {
        quickSort(array, lo, pivot-1);
    }
    if( pivot + 1 < hi ) {
        quickSort(array, pivot+1, hi);
    }
}

//---------------------------------------------------------------------------------
