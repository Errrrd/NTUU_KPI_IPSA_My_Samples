// 3. Створити програму для введення рядка і можливості вилучення із заданої позиції певної кількості символів рядка. Значення кількості символів для вилучення й номера позиції ввести з клавіатури


#include <stdio.h>
#include <stdlib.h>

#define N 1087

int main() {
    int count, pos, i=0;
    char sentence[N] = "There is a need for standardized texts to assess reading performance, for multiple equivalent texts for repeated measurements, and for texts equated across languages for multi-language studies.";
    sentence[1086] = 0;
    printf("Sentence:\n%s\n", sentence);
    printf("count of symb. in sentence (int >= 0):");
    
    if( scanf("%d", &count) != 1 || count < 0)
    {
         printf("\nwrong input (int >= 0)\n");
         exit(1);
    }
    
    printf("\npos of symb. in sentence (int >= 0):");
    
    if( scanf("%d", &pos) != 1 || pos < 0)
    {
         printf("\nwrong input (int >= 0)\n");
         exit(1);
    }
    int last = N-count;
    for( i=pos; i<last; i++)
        *(sentence+i) = *(sentence+i+count);
    
    printf("\n%s\n", sentence);
    return 0;
}