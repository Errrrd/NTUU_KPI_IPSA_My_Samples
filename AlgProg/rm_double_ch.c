//6–24. У введеному з клавіатури тексті видалити усі подвоєні букви – окрім заданих у деякому рядковому літералі, подвоєні розділові знаки і подвоєні пропуски.
//----------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//----------------------------------------------------------------------------
#define MAX 10240
#define ABC 26
//----------------------------------------------------------------------------
int requestText(char text[], int maxSize);
int checkTextForDouble(char text[], int textLen, char lit[], int litLen);
void customStrCpy(char * src, char * dest);
//----------------------------------------------------------------------------
int main()
{
    int textLen = MAX;
    int litLen = ABC;
    char text[MAX];
    char lit[ABC];
    
    
    printf("Text: ");
    textLen = requestText(text, textLen);
    printf("\nLiteral (please set different letters): ");
    litLen = requestText(lit, litLen);
    
    if (textLen > -1){
        printf("\nYour text (size=%d):\n%s\n", textLen, text);
    }
    litLen = checkTextForDouble(lit, litLen, NULL, 0);
    if (litLen > -1){
        printf("\nYour literal after check for double (size=%d):\n%s\n", litLen, lit);
    }
    textLen = checkTextForDouble(text, textLen, lit, litLen);
    
    printf("\nYour text after update (size=%d):\n%s\n", textLen, text);
    
    return 0;
}
//----------------------------------------------------------------------------
int requestText(char text[], int maxSize)
{
    int chLeftInBuff = 0;
    int sLen = -1;
    printf("set please a text (%d bytes max): ", maxSize);
    
    if (fgets(text, maxSize+1, stdin) == NULL){
        printf("Data is not read\n");
        exit(1);
    } else {
        sLen = (int)(strlen(text));
        if (text[sLen - 1] == '\n'){ //2 last symbols if sLen < MAX is '\n'+'\0'
            text[sLen - 1] = '\0';
            sLen--;//(sLen - 1) is '\0' so len = len -1
        }
    }
    return sLen;
}

int checkTextForDouble(char text[], int textLen, char lit[], int litLen)
{
    int newSize = textLen;
    //printf("\n%s\n", text);
    for(int i=1; text[i] != 0; ) {
        char tmpCh0 = text[i-1];
        char tmpCh1 = text[i];

        if(tmpCh0 > 64 && tmpCh0 < 91) tmpCh0 +=32;
        if(tmpCh1 > 64 && tmpCh1 < 91) tmpCh1 +=32;
        
        char bToRm = (tmpCh0 == tmpCh1);
        
        for(int j=0; j < litLen; j++){
            char tmpLit = lit[j];
            if(tmpLit > 64 && tmpLit < 91) tmpLit +=32;
            if(tmpLit > 96 && tmpLit < 123 && tmpLit == tmpCh0){
                bToRm = 0;
                break;
            }
        }
        
        if( bToRm ){
            //strcpy ((text+i), (text+i+1)); //worked with errors
            customStrCpy((text+i), (text+i+1));
            newSize--;
            //printf("\n%d:%c:%s\n", i, tmpCh0, text);
        } else {
            i++;
        }
    }
    
    return newSize;
}

void customStrCpy(char * src, char * dest){
    int i=0;
    while( *src != 0 && *dest != 0 )
    {
        *src = *dest;
        src++;
        dest++;
    }
    *src=0;
}
