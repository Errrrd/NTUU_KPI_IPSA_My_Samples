#include <stdio.h>

void(f1)(void)
{
    static int counter = 0;
    counter++;
    printf("Call %d ", counter);
}
int main() {
    auto counter = 3;
    f1();
    f1();
    
    char one, two 
     
    return 0;
}