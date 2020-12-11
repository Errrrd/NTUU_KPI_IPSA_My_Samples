#include <iostream>
using namespace std;

int main() {
    int n, *p, *q;
    int &c = n;
    p = &n;
    c = 50;
    (*p) /=10;
    q=&c;
    n++;
    cout<<n <<" " << c <<" " << *p <<" "<< *q;

    return 0;
}