#include <stdio.h>
char lname[20], fname[15];
int n, year;


int main() {
    int arr[10] = {2,5,7};
    
    printf("*a+5=%d\n", *(arr+5));
    char ptr[30];
    char *p=ptr;
    for(char i=97; i<123; i++)
        *p++=i;
    *p = 0;
    puts(ptr);
    int x = 10;
    while(x++ < 13)
    {
        int x=50;
        x++;
        printf("x=%d ", x);
    }
    int a=2, b=3,c;
    c=(a & 0X0002)<<2| (b | 0x000f);
    printf("\nsss=%d ", c);
    return 0;
}
void test1() {}