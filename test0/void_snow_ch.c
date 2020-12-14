#include <stdio.h>
#include <stdlib.h>

void f1();
void* f2();
void* f3();

int main()
{
	printf("some\n");
	
	f1();
    f2();
    
    char * str = f3();
    
    printf("some end: %s\n", str);
    
	return 0;
}

void f1(){
    printf("f1\n");
}

void *f2(){
    printf("f2\n");
}

void *f3(){
    char *i = "1223";
    printf("f3\n");
    
    return (void *)i;
}