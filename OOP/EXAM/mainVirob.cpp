#include <iostream>
#include <string>

#include "tvirob.h"
#include "tpvirob.h"
#include "helper.h"

using namespace std;

int main(int argsCount, char *argsValues[]) {

    cout << "argsCount = " << argsCount <<endl;
    if (argsCount > 1) {
        string sDebug =string(argsValues[1]);
        bDebug = (sDebug.compare("Debug") == 0 || sDebug.compare("debug") == 0 || sDebug.compare("DEBUG") == 0 );
        for (int i = 0; i < argsCount; i++)
            cout << "argsValue[" << i << "]=\"" << argsValues[i] <<"\"\n";
        cout << "bDebug=" << bDebug <<'\n';
    }

    
    cout << "\n-------------------------------------------------------------------------\n";
    Tvirob v0("Vyrob0",  80, 75 );
    TPvirob v1("Vyrob1", 100, 95);
    Tvirob * v2 = new Tvirob("Vyrob2", 200, 195);
    TPvirob* v3 = new TPvirob("Vyrob3", 300, 290);
    Tvirob * v4 = new TPvirob("Vyrob4", 400, 385);

    v0.print();
    v1.print();
    v2->print();
    v3->print();
    v4->print();

    delete v2;
    delete v3;
    delete v4;

    
    return 0;
}
