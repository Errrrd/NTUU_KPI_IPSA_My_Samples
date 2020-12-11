#include <stdio.h>

int main() {
    int x=10, y=20;
    int *p1, *p2=NULL;
    p1=&x;
    y=*p1;
    *p1-=10; //y=x=*p1=0
    if(p2==NULL) p2=p1;
    ++*p1;//y=x=*p1=*p2=1
    printf("x=%d y=%d *p2=%i\n", x,y,*p2);
    
    return 0;
}
