// Порядок виконання роботи
// 1. Написати програму, що реалізує методи сортування (табл.2).
// 2. Згенерувати масив розмірності 1000, 10000, 100000 елементів:
//      a. відсортований за зростанням;
//      b. з випадковими елементами (кількість генерувань = 1000);
//      c. відсортований за спаданням.
// 3. Відсортувати одержані масиви за зростанням, отримавши такі змінні:
//      a. кількість порівнянь;
//      b. кількість обмінів;
// 24 варіант: Методи сортування: шейкерний обмін, злиття, підрахунком
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/times.h> // for times
#include <unistd.h> // for sysconf

#define MAX 30 //10000
#define MIN 0
#define RAND() (MIN)+rand()%(MAX) // random from 0 to 9999
unsigned long long countOfSwap = 0;
unsigned long long countOfCmp = 0;
void arrayInit(int array[], int size);
void arrayPrint(int array[], int size);
void shakerSort(int array[], int size);
void merge(int array[], int lo, int mid, int hi);
void mergeSort(int array[], int lo, int hi); //lo - first index of element, hi - last index of element of array or part of array 
void mergeLoop(int array[], int lo, int mid, int hi);
void mergeSortLoop(int array[], int arrSize);
void countSort(int array[], int size, int arrResult[]);
void countSortSeq(int array[], int size, int arrResult[], int diapFirst, int diapStep);
int checkSorted(int array[], int size);
//
int main() {
    srand(time(NULL));
    union ticks{
        unsigned long long t64;
        struct s32 { long th, tl; } t32;
    } start, end;
    
    struct tms tms_start, tms_end;
    long clocks_per_sec = sysconf(_SC_CLK_TCK);
    int shakeSize = 100000;
    
    double cpu_Hz = 31001000000ULL;// Intel(R) Core(TM) i5-3450 CPU @ 3.10GHz; cpu MHz: 3101.000
    
    int sortArr1k[1000];
    int sortArr10k[10000];
    int sortArr100k[100000];
    int sortRevArr1k[1000];
    int sortRevArr10k[10000];
    int sortRevArr100k[100000];
    int arr1k[1000];
    int arr10k[10000];
    int arr100k[100000];
    
    for(int i=0; i < 100000; i++ ){
        if(i < 1000) {
            sortArr1k[i] = i;
            sortRevArr1k[i] = 999-i;
        }
        if(i < 10000) {
            sortArr10k[i] = i;
            sortRevArr10k[i] = 9999-i;
        }
        sortArr100k[i] = i;
        sortRevArr100k[i] = 99999-i;
    }
    
    arrayInit(arr1k, 1000);
    arrayInit(arr10k, 10000);
    arrayInit(arr100k, 100000);
    
    for(int i=0; i < 100000; i++ ){
        if(i < 1000) {
            sortArr1k[i] = i;
            sortRevArr1k[i] = 999-i;
        }
        if(i < 10000) {
            sortArr10k[i] = i;
            sortRevArr10k[i] = 9999-i;
        }
        sortArr100k[i] = i;
        sortRevArr100k[i] = 99999-i;
    }
    
    for (int method = 0; method < 4; method++ ) {
        switch (method)
        {
            case 0: {
                printf("\n--------------------------- Shaker sort ---------------------------\n");
                
                for (int size = 1000; size < 100001 ;size*=10) {
                    int array[size];
                    
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = arr1k[i];
                        if(size == 10000) array[i] = arr10k[i];
                        if(size == 100000) array[i] = arr100k[i];
                    }
                    
                    printf("\nSort of random array of %d elements\nStart sort... ", size);
                    
                    if (size < shakeSize)  asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    else                times(&tms_start);
                    countOfSwap = 0;
                    countOfCmp = 0;
                    shakerSort(array, size);
                    if (size < shakeSize) {
                        asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                        printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    } else {
                        times(&tms_end);
                        printf("End sort, Time taken: %lf sec.\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(tms_end.tms_utime - tms_start.tms_utime)/(double)(clocks_per_sec), countOfCmp, countOfSwap );
                    }
                    
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortArr1k[i];
                        if(size == 10000) array[i] = sortArr10k[i];
                        if(size == 100000) array[i] = sortArr100k[i];
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    shakerSort(array, size);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of revers-sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortRevArr1k[i];
                        if(size == 10000) array[i] = sortRevArr10k[i];
                        if(size == 100000) array[i] = sortRevArr100k[i];
                    }
                    if (size < 10000)  asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    else                times(&tms_start);
                    countOfSwap = 0;
                    countOfCmp = 0;
                    shakerSort(array, size);
                    if (size < 10000) {
                        asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                        printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    } else {
                        times(&tms_end);
                        printf("End sort, Time taken: %lf sec.\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(tms_end.tms_utime - tms_start.tms_utime)/(double)(clocks_per_sec), countOfCmp, countOfSwap );
                    }
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                }
                
                printf("\n-------------------------------------------------------------------\n");
            }
            break;
            case 1: {
                printf("\n--------------------------- Merge sort ---------------------------\n");
                
                for (int size = 1000; size < 100001 ;size*=10) {
                    int array[size];
                    
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = arr1k[i];
                        if(size == 10000) array[i] = arr10k[i];
                        if(size == 100000) array[i] = arr100k[i];
                    }
                    printf("\nSort of random array of %d elements\nStart sort... ", size);
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSort(array, 0, size-1);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortArr1k[i];
                        if(size == 10000) array[i] = sortArr10k[i];
                        if(size == 100000) array[i] = sortArr100k[i];
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSort(array, 0, size-1);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of revers-sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortRevArr1k[i];
                        if(size == 10000) array[i] = sortRevArr10k[i];
                        if(size == 100000) array[i] = sortRevArr100k[i];
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSort(array, 0, size-1);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                }
                
                printf("\n------------------------------------------------------------------\n");
            }
            break;
            case 2: {
                printf("\n------------------------- Merge sort loop -------------------------\n");
                
                for (int size = 1000; size < 100001 ;size*=10) {
                    int array[size];
                    
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = arr1k[i];
                        if(size == 10000) array[i] = arr10k[i];
                        if(size == 100000) array[i] = arr100k[i];
                    }
                    printf("\nSort of random array of %d elements\nStart sort... ", size);
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSortLoop(array, size);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortArr1k[i];
                        if(size == 10000) array[i] = sortArr10k[i];
                        if(size == 100000) array[i] = sortArr100k[i];
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSortLoop(array, size);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                    
                    printf("\nSort of revers-sorted array of %d elements\nStart sort... ", size);
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = sortRevArr1k[i];
                        if(size == 10000) array[i] = sortRevArr10k[i];
                        if(size == 100000) array[i] = sortRevArr100k[i];
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    mergeSortLoop(array, size);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("%s\n", checkSorted(array, size) ? "ok sort (each preview element <= current element)":"wrong sort (one or more preview elements > current element)" );
                }
                
                printf("-------------------------------------------------------------------\n");
            }
            break;
            case 3: {
                //int step = 1;
                int resSize = MAX; //(MAX-MIN)/step;
                int arrResult[resSize];
                memset(arrResult, 0, sizeof(arrResult));
                
                printf("\n--------------------------- Count sort ---------------------------\n");
                
                for (int size = 1000; size < 100001 ;size*=10) {
                    int array[size];
                    for(int i=0; i < size; i++ ) {
                        if(size == 1000) array[i] = arr1k[i];
                        if(size == 10000) array[i] = arr10k[i];
                        if(size == 100000) array[i] = arr100k[i];
                    }
                    printf("\nSort of random array of %d elements\nStart sort... ", size);
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    countSort(array, size, arrResult);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    //countSortSeq(array, size, arrResult, 0, 1);
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("[element:count]: ");
                    for(int i = 0; i < resSize; i++)
                        printf("[%2d:%4d]  ", i, arrResult[i]);
                    printf("\n");
                    //for(int i = 0; i < resSize; i++)
                        //printf("[%2d:%4d]", (i*step+MIN), arrResult[i]);
                    //printf("\n");
                    memset(arrResult, 0, sizeof(arrResult));
                    
                    printf("\nSort of sorted array of %d elements\nStart sort... ", size);
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    countSort(array, size, arrResult);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("[element:count]: ");
                    for(int i = 0; i < resSize; i++)
                        printf("[%2d:%4d]  ", i, arrResult[i]);
                    printf("\n");
                    memset(arrResult, 0, sizeof(arrResult));
                    
                    printf("\nSort of revers-sorted array of %d elements\nStart sort... ", size);
                    int halfSZ = size/2;
                    int sizeDecr = size-1;
                    for(int i=0; i < size/2; i++ ) {
                        int tmp = array[i];
                        array[i] = array[sizeDecr - i];
                        array[sizeDecr - i] = tmp;
                    }
                    asm("rdtsc\n":"=a"(start.t32.th),"=d"(start.t32.tl));
                    countOfSwap = 0;
                    countOfCmp = 0;
                    countSort(array, size, arrResult);
                    asm("rdtsc\n":"=a"(end.t32.th),"=d"(end.t32.tl));
                    printf("End sort, Time taken: %lf sec., CPU %llu tacts\nCount of compares=%llu, Count of Swaps=%llu\n", (double)(end.t64-start.t64)/cpu_Hz, end.t64-start.t64, countOfCmp, countOfSwap );
                    printf("[element:count]: ");
                    for(int i = 0; i < resSize; i++)
                        printf("[%2d:%4d]  ", i, arrResult[i]);
                    printf("\n");
                    memset(arrResult, 0, sizeof(arrResult));
                }
                
                printf("...End sort\n------------------------------------------------------------------\n");
            }
            break;
            default:
                printf("uncnown case\n");
        }
    }
    
    return 0;
}
//----------------------------------------------------------------------
void arrayInit(int array[], int size) {
    printf("Make array with %d elements... ", size);
    for ( int i=0; i<size; i++ ){ *(array+i)=RAND(); }
    printf("Done\n");
}
void arrayPrint(int array[], int size) {
    for ( int i=0; i<size; i++ ){
        printf("%4d", *(array+i));
    }
    printf("\n");
}
void shakerSort(int array[], int size) {
    int buff;
    int ctrl = size - 1;
    int left = 0;
    int right = ctrl;
    
    //printf("[left:right]= [%d:%d], ", left, right);
    
    while (left < right ) {
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1]) {
                buff = array[i];
                array[i] = array[i + 1];
                array[i + 1] = buff;
                ctrl=i;
                countOfSwap++;
            }
            countOfCmp++;
        }
        right=ctrl;
        for (int i = right; i > left; i--) {
            if (array[i] < array[i - 1]) {
                buff = array[i];
                array[i] = array[i - 1];
                array[i - 1] = buff;
                ctrl=i;
                countOfSwap++;
            }
            countOfCmp++;
        }
        left=ctrl;
        //printf("[%d:%d], ", left, right);
    }
    //printf("\n");
}
void mergeSort(int array[], int lo, int hi) {
    if ( lo < hi ) {
        int mid = (lo + hi - 1) / 2;
        mergeSort(array, lo, mid);
        mergeSort(array, mid+1, hi);
        merge(array, lo, mid, hi);
        //printf("%d ", 1);
    }
}
void mergeLoop(int array[], int lo, int mid, int hi) {
    int size = hi - lo;
    int buffer[size];
    
    for ( int i = 0, j = lo, k = mid; i < size; ) {
        if ( array[j] < array[k] && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        } else if ( k < hi ) {
            buffer[i] = array[k];
            i += 1;
            k += 1;
            countOfCmp++;
        }
        countOfCmp++;
        if ( k == hi && j < mid ) {
            buffer[i] = array[j];
            i += 1;
            j += 1;
        }
        countOfCmp++;
    }
    for ( int i = 0, j = lo; i < size; i++, j++ ) {
        array[j] = buffer[i];
        countOfSwap++;
    }
}
void mergeSortLoop(int array[], int len) {
    int tmp;
    int last = len - len % 2;
    
    if ( len > 1 ) {
        for ( int i = 1, j = 0; i < last; i += 2, j += 2 ) {
            if ( array[i] < array[j] ) {
                tmp = array[j];
                array[j] = array[i];
                array[i] = tmp;
                countOfSwap++;
            }
            countOfCmp++;
        }
        if ( len > last ) {
            mergeLoop(array, last-2, last, len);
        }
        
        for ( int step = 2; step < len; ) {
            int start = 0;
            int mid = start + step;
            int end;
            
            step *= 2;
            end = start + step;
            for ( ; end < len; start += step, mid += step, end += step ) {
                mergeLoop(array, start, mid, end);
            }
            if ( mid < len ) {
                mergeLoop(array, start, mid, len);
            }
        }
    }
}
void countSort(int array[], int size, int arrResult[]) {
    
    for ( int i = 0; i < size; i++ ) {
         arrResult[array[i]]++;
         countOfSwap++;
    }
}
void countSortSeq(int array[], int size, int arrResult[], int diapFirst, int diapStep) {
    
    for ( int i = 0; i < size; i++ ) {
         arrResult[(array[i] - diapFirst)/diapStep]++;
    }
}
int checkSorted(int array[], int size) {
    for (int i = 1; i < size; i++) {
        if (array[i-1] > array[i]) {
            printf("\nError: el[%d]:%d > el[%d]:%d \n", i-1, array[i-1], i, array[i]);
            return 0;
        }
    }
    
    return 1;
}
void merge(int array[], int lo, int mid, int hi)
{
    int lowCount = mid - lo + 1;
    int hiCount = hi - mid;
    int arrLow[lowCount], arrHigh[hiCount];  // Create temp arrays
    
    // Copy data to temp arrays arrLow[] and arrHigh[]
    for (int i = 0; i < lowCount; i++)
        arrLow[i] = array[lo + i];
    for (int j = 0; j < hiCount; j++)
        arrHigh[j] = array[mid + j + 1];
    // Merge the temp arrays back into array[lo..hi]
    int i = 0; // first subarray index
    int j = 0; // second subarray index
    int k = lo; // merged subarray index
    
    while (i < lowCount && j < hiCount) {
        if (arrLow[i] <= arrHigh[j]) {
            array[k] = arrLow[i];
            i++;
            countOfSwap++;
        }
        else {
            array[k] = arrHigh[j];
            j++;
            countOfSwap++;
        }
        countOfCmp++;
        k++;
    }
    // merge tail
    while (i < lowCount) {
        array[k] = arrLow[i];
        i++;
        k++;
        countOfSwap++;
    }
    while (j < hiCount) {
        array[k] = arrHigh[j];
        j++;
        k++;
        countOfSwap++;
    }
}
