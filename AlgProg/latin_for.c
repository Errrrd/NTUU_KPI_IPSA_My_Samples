//2-6а. Надане число від 1 до 100 надрукувати латинськими цифрами, пам’ятаючи, що С-100, L -50, X – 10, V – 5, I -1, IV - 4, IX - 9, XL -40 XC = 90
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int num=1; num<101; num++){
        int tmpNum = num;
        char latinNum[9]; 
        int i = 0;
        
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
                tmpNum --;
            }
        }
        latinNum[i] = 0;
        printf("Latin number for %d == %s\n", num, latinNum);
    }
    return 0;
}
