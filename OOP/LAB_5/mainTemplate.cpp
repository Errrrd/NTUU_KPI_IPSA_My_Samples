#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "helper.h"
#include "color.h"
#include "coordinates.h"
#include "circle.h"
#include "polygon.h"
#include "image.h"

using namespace std;

template <typename Tp1, typename Tp2>
double getDistance(const Tp1 figA, const Tp2 figB)
{
    return figA.getCentre().getDistance(figB.getCentre());
}

template <typename Tp3>
int findElement(Tp3& el, vector<Tp3>& vEls ) {
    int idx = -1;
    if (!vEls.empty()) {
        int size = vEls.size();
        for (int i = 0; i < size; i++) {
            if (vEls[i] == el) {
                idx = i;
                break;
            }
        }
    }
    return idx;
}

template <typename Tp4>
Tp4* findElementMoreThan(Tp4& el, vector<Tp4>& vEls, bool (*isMore)(Tp4&, Tp4&) ) {
    Tp4* ptr = nullptr;
    if (!vEls.empty()) {
        int size = vEls.size();
        for (int i = 0; i < size; i++) {
            if (isMore (vEls[i], el) ) {
                ptr = &vEls[i];
                break;
            }
        }
    }

    return ptr;
}

template <typename Tp5>
bool isMoreThan(Tp5& one, Tp5& two) {
    return two < one;
}


int main(int argsCount, char *argsValues[]) {
    double x,y,r=-1.0;
    
    cout << "argsCount = " << argsCount <<endl;
    if (argsCount > 1) {
        string sDebug =string(argsValues[1]);
        bDebug = (sDebug.compare("Debug") == 0 || sDebug.compare("debug") == 0 || sDebug.compare("DEBUG") == 0 );
        for (int i = 0; i < argsCount; i++)
            cout << "argsValue[" << i << "]=\"" << argsValues[i] <<"\"\n";
        cout << "bDebug=" << bDebug <<'\n';
    }

    /*
    cout<<"\nPlease set coordinate X:";
    cin>>x;
    cout<<"\nPlease set coordinate Y:";
    cin>>y;
    
    for (;r < 0.0;) {
        cout<<"\nPlease set radius for circle R >= 0:";
        cin>>r;
        if (r < 0) {
            cout<< "\nradius < 0.0. Could you Please set right value\n";
        } 
    }
    */
    
    cout << "\n-------------------------------------------------------------------------\n";
    x = 5.6; y = -3.2; r = 12.7;
    cout<<"\nCoordinates 1:\n";
    Coordinates cntr1(x,y);
    cout<<cntr1<<'\n';
    cout << "\n-------------------------------------------------------------------------\n";
    cout<<"\nCircle 1:\n";
    Circle cr1(cntr1,r);
    cout<<cr1<<'\n';
    cr1.printShort();
    cr1.print();
    cr1.visCircle();
    cout << "\n-------------------------------------------------------------------------\n\n\nCircle 2:\n";
    Circle cr2(x+4, y-6, r-5);
    cout<<cr2<<'\n';
    cr1.printShort();
    cr1.print();
    cr1.visCircle();
    cout << "\n-------------------------------------------------------------------------\n\n\nCreate Color 1\n";
    Color col1(0.1f,0.5f,0.5f);
    cout << col1<<'\n';
    cout << "\n-------------------------------------------------------------------------\n\n\nCreate polygon in 1:\n";
    PolygonIn pli1(x-2, y-1, r-1, 4);
    pli1.visPolygon();
    pli1.printShort();
    cout << "\n-------------------------------------------------------------------------\n\n\nCreate polygon out 1:\n";
    PolygonOut plo1(x-1,y+1, r+3, 6, col1);
    plo1.visPolygon();
    plo1.printShort();
    cout << "\n-------------------------------------------------------------------------\n";
    
    cout << "\nDistance for figures: Circle 1 and Circle 2 is " << getDistance(cr1, pli1) <<'\n';
    cout << "\nDistance for figures: Circle 1 and Polygon In 1 is " << getDistance(cr1, pli1) <<'\n';
    cout << "\nDistance for figures: Circle 1 and Polygon Out1 is " << getDistance(cr1, plo1) <<'\n';
    cout << "\nDistance for figures: Polygon In 1 and Polygon Out1 is " << getDistance(pli1, plo1) <<'\n';

    vector<int> intVec = { 1,2,3,4,5,6,7,8,9,10 };
    vector<PolygonIn> polyInVec = { PolygonIn(x, y, r, 3), PolygonIn(x-1, y+11, r+6, 4),PolygonIn(x+4, y-1, r+7, 5),PolygonIn(x+33, y-5, r+4, 6),PolygonIn(x-7, y+1, r+2, 7),PolygonIn(x-3, y+2, r+66, 8),PolygonIn(0, 0, r+42, 9)};
    vector<PolygonOut> polyOutVec = { PolygonOut(x, y, r, 3), PolygonOut(x - 1, y + 11, r + 6, 4),PolygonOut(x + 4, y - 1, r + 7, 5),PolygonOut(x + 33, y - 5, r + 4, 6),PolygonOut(x - 7, y + 1, r + 2, 7),PolygonOut(x - 3, y + 2, r + 66, 8),PolygonOut(0, 0, r + 42, 9) };
    int int1 = 7;
    int int2 = 42;
    PolygonIn polyIn1(x + 33, y - 5, r + 4, 6);
    PolygonIn polyIn2(0, 0, r + 99, 20);
    PolygonOut polyOut1(x - 7, y + 1, r + 2, 5);
    PolygonOut polyOut2(0, 0, r + 99, 20);

    cout << "\nElement 1 type int :" << int1 << " of vector int is N(" << findElement(int1, intVec)<< ")\n";
    cout << "\nElement 2 type int :" << int2 << " of vector int is N(" << findElement(int2, intVec) << ")\n";
    cout << "\nElement 1 type PolygonIn :" << polyIn1 << " of vector PolygonIn is N(" << findElement(polyIn1, polyInVec) << ")\n";
    cout << "\nElement 2 type PolygonIn :" << polyIn2 << " of vector PolygonIn is N(" << findElement(polyIn2, polyInVec) << ")\n";
    PolygonOut* polyOut = findElementMoreThan(polyOut1, polyOutVec, isMoreThan);
    if (polyOut)
        cout << "\nElement more of element 1 type PolygonOut :" << polyOut1 << " of vector PolygonOut is (" << *polyOut << ")\n";
    else
        cout << "\nElement more of element 1 type PolygonOut :" << polyOut1 << " of vector PolygonOut is (" << "nullptr" << ")\n";
    polyOut = findElementMoreThan(polyOut2, polyOutVec, isMoreThan);
    if (polyOut)
        cout << "\nElement more of element 2 type PolygonOut :" << polyOut2 << " of vector PolygonOut is (" << *polyOut << ")\n";
    else
        cout << "\nElement more of element 2 type PolygonOut :" << polyOut2 << " of vector PolygonOut is (" << "nullptr" << ")\n";

    return 0;
}
