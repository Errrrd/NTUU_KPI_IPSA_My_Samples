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
    long long unsigned int start_sh = 0;
    long long unsigned int end_sh = 0;
    long long unsigned int start_st = 0;
    long long unsigned int end_st = 0;
    long long unsigned int start_all = 0;
    long long unsigned int end_all = 0;
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
    
    char * words[textSize/2];
    int arrSize=updateArrayWords(text, words);;
    int preLast = arrSize - 1;
    char word[256];
    
    //line search
    printf("\nInput please word for search (len <= 255 chars):");
    scanf("%255s", word);
    while(getchar()!='\n'){}
    //start time for all
    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
    start_all = start.t64;
    
    for( int i=0; i < preLast; i++){
         printf("\"%s\", ", words[i]);
    }
    if (preLast > 0) {printf("\"%s\"\n", words[preLast]);}
    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
    start_sh = start.t64;
    int idx = -1;
    for( int i=0; i < arrSize; i++){
        char * tmpWord = words[i];
        if(strcmp(word, tmpWord) == 0) {
            idx = i;
            break;
        }
    }
    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    end_sh = end.t64;
    if (idx > -1){
        printf ("\nword \"%s\" has index %d in word array (from 0)\n", word, idx);
    } else {
        printf ("\nword \"%s\" not found\n", word);
    }
    //printf("Pres Enter to continue...\n");
    //getchar();
    //line search end
    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
    start_st = start.t64;
    quickSort( words, 0, arrSize-1);
    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    end_st = end.t64;
    for( int i=0; i < preLast; i++){
         printf("\"%s\", ", words[i]);
    }
    if (preLast > 0) {printf("\"%s\"\n", words[preLast]);}
    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
    end_all = end.t64;
    
    printf("\nTime of line search: %g sec. (%lld - %lld)\n", (end_sh-start_sh)/cpu_Hz, end_sh, start_sh);
    printf("\nTime Quick sort: %g sec. (%lld - %lld)\n", (end_st-start_st)/cpu_Hz, end_st, start_st);
    printf("\nTime all with print: %g sec. (%lld - %lld)\n", (end_all-start_all)/cpu_Hz, end_all, start_all);
    
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
