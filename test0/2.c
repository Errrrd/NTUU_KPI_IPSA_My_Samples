#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int len;
    char *s = "abcdef";
    
    len = strlen(s);
    while(*s) putchar(*s++);
    for (int i=0; i<len; i++) *s--;
    puts(s);
    while(*s) putchar(*s+1);
    
    return 0;
}