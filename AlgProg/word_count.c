//7 – 24 Реалізувати функцію, у яку передається символьний рядок і яка підраховує кількість слів цього рядка, які задовольняють певній умові. Цю умову передавати як вказівник на функцію. Передбачити дві функції – визначення чи утворюють букви даного слова паліндром, і визначення чи починається дане слово з великої букви. Продумати тестовий приклад для демонстрації роботи програми.
//слово паліндром - однаково читається справа наліво і зліва направо.


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------
#define MAX 1024*256
//----------------------------------------------------------------------------
int arrayScan(char * fileName, char array[], int len);
int checkMirror(char * text, int textLen);
char * checkUpperCase(char * text);
void checkTextForMirrorWords(char * text, int (*checkWrd)(char * text, int textLen), char * (*checkUC)(char * text));
int requestFileName(char fileName[]);
int readTextFromFile(char * fileName, char text[], int limit);
void customStrCpy(char * dest, int sizeDest, char * src);

//----------------------------------------------------------------------------
int main()
{
    char text[MAX+1];
    char fileName[256]; fileName[255] = 0;
    int textSize = MAX;
    int (*checkWrd)(char * text, int textLen) = checkMirror;
    char * (*checkUC)(char * text) = checkUpperCase;
    
    if (requestFileName(fileName) < 1) //request filename. If wrong => exit from program with error 1.
    {
        printf("File Name is not set\n");
        exit(1);
    }
    printf("\nScan file \"%s\" (size <= %d kBytes)...\n", fileName, MAX/1024);
    textSize=arrayScan(fileName, text, MAX);
    printf("Text (size=%d): \"%s\"\n", textSize, text);
    
    checkTextForMirrorWords(text, checkWrd, checkUC);
    
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

void checkTextForMirrorWords(char * text, int (*checkWrd)(char * text, int textLen), char * (*checkUC)(char * text))
{
    int len = strlen(text);
    for( int i=0, tmpWordSz=0, tmpIdx = 0, bIdxStarted = 0; i <= len; i++)
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
            //printf("tmp[idx:%d,i:%d,sz:%d]\t", tmpIdx, i, tmpWordSz);
        } else {
            if(tmpWordSz > 0)
            {
                // char word[tmpWordSz+1];
                // customStrCpy( word, tmpWordSz, &text[tmpIdx]);
                // printf("word(sz=%d:\"%s\"\n",tmpWordSz,word);
                if(checkWrd(&text[tmpIdx], tmpWordSz )) {
                    char word[tmpWordSz+1];
                    customStrCpy( word, tmpWordSz, &text[tmpIdx]);
                    printf("word:\"%s\", capital letter:%s; \n", word, checkUC(word) );
                }
            }
            bIdxStarted = 0;
            tmpWordSz = 0;
            tmpIdx = 0;
        }
    }
}

int checkMirror(char * text, int textLen)
{
    int centr = textLen/2;
    //printf("\n%s\n", text);
    for(int i=0; i<centr; i++ ) {
        char tmpCh1 = *(text + textLen-i-1);
        char tmpCh0 = *(text+i);

        if(tmpCh0 > 64 && tmpCh0 < 91) tmpCh0 +=32;
        if(tmpCh1 > 64 && tmpCh1 < 91) tmpCh1 +=32;
        
        if( tmpCh0!=tmpCh1 ) return 0;
        
    }
    
    return 1;
}

char * checkUpperCase(char * text) {
    if(text[0] > 64 && text[0] < 91) return "Yes"; else return "No";
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
//---------------------------------------------------------------------------------