//2-24. Скласти програму виведення всіх тризначних десяткових чисел, сума цифр яких дорівнює наданому цілому числу..
#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned int num = 0;
    
    printf("please write int number form 1 to 27:");
    if(scanf("%u", &num) != 1){
        printf("\nWrong input. Please input an integer variable next time\n");
        exit(1);
    } else if ( num < 1 || num > 27 ) {
        printf("\nNothing for print\n");
    } else {
        for( int i = 9; i > 0; i-- )
        {
            int num1 = i;
            int tmpNum = num -i;
            for( int j = 0; tmpNum - j >= 0 && j < 10; j++){
                if( tmpNum - j <= 9)
                    printf("%d%d%d ", num1, j, tmpNum-j);
                
            }
        }
    }
    printf("\n");
    return 0;
}
