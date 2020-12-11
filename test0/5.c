#include <stdio.h>
//#include <stdlib.h>

#define N 7

int main() {
    short int m[4]={1,2,3,4},x,*p;
    p=&m[0];
    x = *p; printf("x=%d p=%u\n", x, p);
    x = *p++; printf("x=%d p=%u\n", x, p);
    x = ++*p; printf("x=%d p=%u\n", x, p);
    x = *++p; printf("x=%d p=%u\n", x, p);
    x = (*p)++; printf("x=%d p=%u\n", x, p);
    x = ++(*p); printf("x=%d p=%u\n", x, p);
     printf("p=%hu\n", 65536);
     
    return 0;
}