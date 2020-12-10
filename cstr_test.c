#include <stdio.h>
#include <stdlib.h>

int main()
{
    if(1)
    {
        char ch[1000];
        for(int i=0; i <1000; i++ )
        {
            ch[i] = 48 + i%22;
        }
    }
    char chArray1[11] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '\0'}; 
    char * chStr = "0123456789";
    char chArray2[] = "0123456789";
    chArray1[5] = 'Y';
    //chStr[7] = 'X'; //Segmentation fault
    char * p = &chArray2[7]; //segmentation fault+
    *p = 'X';
    printf("chArray1[10]:\"%s\", chArray2:\"%s\", p:%c; chStr(const value):\"%s\", chStr[10]:%d.\n", chArray1, chArray2, *p, chStr, chStr[10]);
        

    return 0;
}