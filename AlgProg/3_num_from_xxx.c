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
        for( int num1 = 9; num1 > 0; num1-- )
        {
            int tmpNum = num - num1;
            for( int num2 = 0; tmpNum - num2 >= 0 && num2 < 10; num2++){
                if( tmpNum - num2 <= 9) printf("%d%d%d ", num1, num2, tmpNum-num2);
                
            }
        }
    }
    printf("\n");
    return 0;
}
