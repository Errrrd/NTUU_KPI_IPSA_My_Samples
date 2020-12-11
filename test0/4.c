#include <iostream>
#include <string.h>
using namespace std;

int f1(int *m);

int main() {
    int n = 7;
    cout << double(10)/double(3) << endl; //f1(&n) << " " << n << endl;
    
    return 0;
}

int f1 (int *m) {
    *m = *m+1;
    return *m;
}