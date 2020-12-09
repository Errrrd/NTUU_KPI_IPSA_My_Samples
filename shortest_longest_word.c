//24. У наданому реченні знайти найкоротше та найдовше слово.
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>
#define MAX 1024*1024

int requestMaxSize();
int requestFileName(char fileName[]);
int readSentenceFromFile(char * fileName, char array[], int maxSize);

//---------------------------------------------------------------------------------
int main()
{
    //define name of file (char array) for source of sentence
    //set last char as '\0' for cstring compatiblity/printing
    char fileName[256]; fileName[255] = 0; 
    int sentenceSize, minWordSz, maxWordSz, idxMin, idxMax, maxSize; //define used integer variables
    sentenceSize=minWordSz=maxWordSz=idxMin=idxMax=0; //
    maxSize = requestMaxSize();
    //define sentence with  of file (char array) for source of sentence
    //set last char as '\0' for cstring compatiblity/printing
    char sentence[maxSize+1]; sentence[maxSize] = 0;
    
    if (requestFileName(fileName) < 1) //request filename. If wrong => exit from program with error 1.
    {
        printf("File Name is not set\n");
        exit(2);
    }
    //get sentence from file.
    sentenceSize = minWordSz = readSentenceFromFile(fileName, sentence, maxSize);
    if( sentenceSize > 0)
    {
        printf( "Current sentens: \"%s\"\nSize = %d\n", sentence, sentenceSize);
    } else if (sentenceSize == 0){
        printf("file \"%s\" is empty\n", fileName);
        exit(3);
    } else {
        printf("ERROR: file \"%s\" is not available or unknown issue\n", fileName);
        exit(4);
    }
    
    //code for task
    for( int i=0, tmpWordSz=0, tmpIdx = 0, bIdxStarted = 0; i < sentenceSize; i++)
    {
        
        if( ( sentence[i] > 47 && sentence[i] < 58 ) || //0-9
            ( sentence[i] > 64 && sentence[i] < 91 ) || //A-Z
            ( sentence[i] > 95 && sentence[i] < 123) || //a-z,'`' == 96
              sentence[i]== 39//"'" 
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
                if(tmpWordSz > maxWordSz)
                {
                    maxWordSz = tmpWordSz;
                    idxMax = tmpIdx;
                    //printf("\n[Max[%d:%d]\n", idxMax, maxWordSz);
                }
                if(tmpWordSz < minWordSz)
                {
                    minWordSz = tmpWordSz;
                    idxMin = tmpIdx;
                    //printf("\n[Min[%d:%d]\n", idxMin, minWordSz);
                }
                 //printf("\n");
            }
            bIdxStarted = 0;
            tmpWordSz = 0;
            tmpIdx = 0;
        }
    }
    
    //printf("\n[Min[%d:%d], Max[%d:%d]\n", idxMin, minWordSz, idxMax, maxWordSz);
    
    if(maxWordSz == 0)
    {
        minWordSz = 0;
        printf("Sentens: \"%s\" has not any \"word\"\n", sentence);
    } else {
        int endOfStr = idxMin + minWordSz;
        char minWord[minWordSz+1]; minWord[minWordSz] = 0;
        char maxWord[maxWordSz+1]; maxWord[maxWordSz] = 0;
        
        /*
        strncpy(minWord, sentence+idxMin, minWordSz);
        strncpy(maxWord, sentence+idxMax, maxWordSz);
        */
        for(int i=idxMin, j=0; i < endOfStr; i++, j++ )
        {
            minWord[j] = sentence[i];
        }
        endOfStr = idxMax + maxWordSz;
        for(int i=idxMax, j=0; i < endOfStr; i++, j++ )
        {
            maxWord[j] = sentence[i];
        }
        printf("Longest of words is \"%s\", size:%d; shortest of words is \"%s\", size:%d.\n", maxWord, maxWordSz, minWord, minWordSz);
        
    }
    
    return 0;
}

//---------------------------------------------------------------------------------
int requestMaxSize()
{
    int maxSize = 0;
    printf("Please set max size of your Sentence in your file (<= 1Mb == 1048576 bytes)\n");
    for( ; maxSize <= 0 || maxSize > MAX; ) //check input for max size of sentence
    {
        if( scanf("%d",&maxSize) != 1) //request maxSize sentence in symbols. If wrong => exit from program with error 2.
        {
            printf("Incorrect data (not INT 32 type)\n");
            exit(1);
        }
        while(getchar()!='\n'); //remove last bytes of buffer if user write extra-symbols
        
        if(maxSize > MAX || maxSize <= 0) //attention if data is incorrect
        {
            printf("Incorrect data (maxSize [INT:%d] out of range). Please repeat again.\n", maxSize);
        }
    }
    
    return maxSize;
}
//---------------------------------------------------------------------------------
int readSentenceFromFile(char * fileName, char sentence[], int limit)
{
    int size = 0;
    char bEndOfSentence = 0;
    FILE *in = fopen(fileName, "r");
    
    if (in == NULL) { return -1; }; //check for error of opening file. If file wasn't open - not necessary to close it
    
    for ( ; !bEndOfSentence && size < limit && fscanf(in, "%c", &sentence[size]) == 1; size++ )
    {
        if(sentence[size]=='.') //check point if it filename
        {
            char ch = 0;
            fscanf(in, "%c", &ch);
            if( (ch > 47 &&  ch < 58) ||
                (ch > 64 &&  ch < 91) ||
                (ch > 96 &&  ch < 123) )
            {
                sentence[++size] = ch;
            } else {
                bEndOfSentence = 1;
            }
        }
        
        bEndOfSentence = bEndOfSentence      ||
                         sentence[size]=='!' ||
                         sentence[size]=='?' ||
                         sentence[size]== 10 || //== '\n' == LF - new line
                         sentence[size]== 13    //== '\r' == CR Carriage Return
                         ;
    }
    sentence[size] = '\0';
    fclose(in);
    
    return size;
}
//---------------------------------------------------------------------------------
int requestFileName(char fileName[])
{
    int chLeftInBuff = 0;
    int scanfResult = 0;
    printf("Set please the name of file with a sentence or a text.\n\
File should be in same path as program or relative/full path to file \
(<=255 symbols): ");
    
    scanfResult = scanf("%255s", fileName);
    while(getchar()!='\n') {++chLeftInBuff;}
    if(chLeftInBuff > 0) { printf("!!!User input contains more than 255 symbols (%d is extra)!!!\n"
                                , chLeftInBuff); }
    //fflush(stdin); //don't work on linux (Ubuntu)

    return scanfResult;
}
//---------------------------------------------------------------------------------
/*
    //part of code from requestFileName
    //check if buffer is empty. Is not empty -> "endOfBuf" will obtain fullSizeOfBuff-255 left symbols
    char endOfBuf[255];
    scanf("%255s", endOfBuf);
    printf("endOfBuf %s, size %d\n", endOfBuf, (int)strlen(endOfBuf));
    */
    
    /*
    //second path for reading string
    //int sLen = 0;
    if (fgets(fileName, 255, stdin) == NULL)
    {
        printf("Data is not read");
        exit(1);
    } else {
        sLen = (int)(strlen(fileName));
        if (fileName[sLen - 1] == '\n') { fileName[sLen - 1] = '\0'; }
    }
    return sLen;
*/
//---------------------------------------------------------------------------------
