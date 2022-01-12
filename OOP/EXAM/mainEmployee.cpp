#include <iostream>
#include <string>

#include "employee.h"


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
    Employee emp1("Ivanov", "Ivan", "Ivanovich", WorkType::SIMPLE, 299.0);
    Employee emp2("Petrov", "Ivan", "Ivanovich", WorkType::SIMPLE, 310.0);
    Employee emp3("Sidorov", "Ivan", "Ivanovich", WorkType::PART_TIME, 299.0);
    Employee emp4("Rabinovich", "Ivan", "Ivanovich", WorkType::PART_TIME, 299999.0);

    emp1.print();
    emp2.print();
    emp3.print();
    emp4.print();
    
    return 0;
}
