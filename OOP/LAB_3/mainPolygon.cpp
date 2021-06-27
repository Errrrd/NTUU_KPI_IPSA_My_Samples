#include <iostream>

#include "color.h"
#include "coordinates.h"
#include "circle.h"
#include "polygon.h"

using namespace std;

int main(int argsCount, char *argsValues[]) {
    double x,y,r=-1.0;
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
    
    cout<<"\nCircle 1:\n";
    Circle cr1(cntr1,r);
    cout<<cr1<<'\n';
    cr1.printCircleShort();
    cr1.printCircle();
    cr1.visCircle();

    cout<<"\n\nCreate Color 1\n";
    Color col1(0.1f,0.5f,0.5f);
    
    cout<<"\n\nCreate polygon in 1:\n";
    PolygonIn pli1;
    pli1.visPolygon();
    cout << "\nCreate polygon in 2:\n";
    PolygonIn pli2(x-2, y-1, r-1, 4);
    pli2.visPolygon();
    cout << "\nCreate polygon in 3:\n";
    PolygonIn pli3(cntr1, r, 5);
    pli3.visPolygon();
    cout << "\nCreate polygon in 4:\n";
    PolygonIn pli4(pli1);
    pli4.visPolygon();

    cout << "\n\nCreate polygon out 1:\n";
    PolygonOut plo1;
    plo1.visPolygon();
    cout << "\nCreate polygon out 2:\n";
    PolygonOut plo2(x-1,y+1, r+3, 6, col1);
    plo2.visPolygon();
    cout << "\nCreate polygon out 3:\n";
    PolygonOut plo3(cntr1, r, 7, col1);
    plo3.visPolygon();
    cout << "\nCreate polygon in 4:\n";
    PolygonOut plo4(plo1);
    plo4.visPolygon();
    
    return 0;
}
