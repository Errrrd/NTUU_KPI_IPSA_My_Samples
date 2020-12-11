#include <iostream>
#include <string.h>
using namespace std;

int f1(int n);

int main() {
    int n,s;
    
    for (int i=1; i<=5; i++)
        s = f1(i);
    
    cout << "s=" << s << endl;
    
    return 0;
}

int f1 (int n) {
    static int s1 = 0;
    s1+=n;
    return s1;
}