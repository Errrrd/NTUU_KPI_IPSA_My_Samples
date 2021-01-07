//2-6а. Надане число від 1 до 100 надрукувати латинськими цифрами, пам’ятаючи, що С-100, L -50, X – 10, V – 5, I -1, IV - 4, IX - 9, XL -40 XC = 90
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int num = 0;
    
    printf("please write int number form 1 to 100:");
    if(scanf("%u", &num) != 1){
        printf("\nWrong input. Please input an integer variable next time\n");
        exit(1);
    } else if ( num < 1 || num > 100 ) {
        printf("\nNothing for print (out of range).\n");
    } else {
        char latinNum[9]; 
        int i = 0;
        int tmpNum = num;
        
        if(tmpNum/100 > 0)
        {
            latinNum[i++]='C';
        }else {
            if( tmpNum/90 > 0 ){
                latinNum[i++]='X';
                latinNum[i++]='C';
                tmpNum -= 90;
            }
            if( tmpNum/50 > 0 )
            {
                latinNum[i++]='L';
                tmpNum -= 50;
            }
            if( tmpNum/40 > 0 )
            {
                latinNum[i++]='X';
                latinNum[i++]='L';
                tmpNum -= 40;
            }
            while( tmpNum/10 > 0 )
            {
                latinNum[i++]='X';
                tmpNum -= 10;
            }
            if( tmpNum/9 > 0 )
            {
                latinNum[i++]='I';
                latinNum[i++]='X';
                tmpNum -= 9;
            }
            if( tmpNum/5 > 0 )
            {
                latinNum[i++]='V';
                tmpNum -= 5;
            }
            if( tmpNum/4 > 0 )
            {
                latinNum[i++]='I';
                latinNum[i++]='V';
                tmpNum -= 4;
            }
            while( tmpNum > 0 )
            {
                latinNum[i++]='I';;
                tmpNum--;
            }
        }
        latinNum[i] = 0; //='\0'
        printf("Latin number for %d == %s\n", num, latinNum);
    }
    return 0;
}
