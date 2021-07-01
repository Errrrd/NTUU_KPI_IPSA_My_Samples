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
    cout<<"\nCoordinates 1 ++:\n";
    cntr1++;
    cout<<cntr1<<'\n';
    
    cout<<"\nCoordinates 2:\n";
    Coordinates cntr2(x-2,y+8);
    cout<<cntr2<<'\n';
    Coordinates cntr3 = cntr1 + cntr2;
    cout<<"\nCoordinates 1 + 2 = 3:\n" << cntr1 << " + " << cntr2 << " = " << cntr3;
    
    cout<<"\nCircle 1:\n";
    Circle cr1(cntr1,r);
    cout<<cr1<<'\n';
    cr1.printShort();
    cr1.print();
    cr1.visCircle();

    cout<<"\n\nCreate Color 1\n";
    Color col1(0.1f,0.5f,0.5f);
    
    cout<<"\n\nCreate polygon in 1:\n";
    PolygonIn pli1(0.0,0.0);
    pli1.visPolygon();
    cout << "\nCreate polygon in 2:\n";
    PolygonIn pli2(x-2, y-1, r-1, 4);
    pli2.visPolygon();
    cout << "\nCreate polygon in 3:\n";
    PolygonIn pli3(cntr1, r, 5);
    pli3.visPolygon();
    cout << "\nCreate polygon in 4 (Copy constructor from 1):\n";
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
    cout << "\nCreate polygon in 4 (Copy constructor from 2) :\n";
    PolygonOut plo4(plo2);
    plo4.visPolygon();
    
    cout << "\nPolygonOut 2 " << plo2 << " < PoligonOut 3 " << plo3 <<":\n" << ((plo2 < plo3) ? "It is true" : "It is false") << '\n';
    cout << "\nPolygonOut 3 " << plo3 << " < PoligonOut 2 " << plo2 <<":\n"  << ((plo3 < plo2) ? "It is true" : "It is false") << '\n';
    cout << "\nPolygonIn 2 " << pli2 << " == PoligonIn 3 " << pli3 <<":\n"  << ((pli2 == pli3) ? "It is true" : "It is false") << '\n';
    cout << "\nPolygonIn 1 " << pli1 << " == PoligonIn 4 " << pli4 <<":\n" << ((pli1 == pli4) ? "It is true" : "It is false") << '\n';
    
    cout<<"\nCoordinates 4 via \"cin >>\" please insert x y (space separator):\n";
    Coordinates cntr4;
    cin >> cntr4;
    cout<<cntr4<<'\n';
    
    cout<<"\nCircle 2 via \"cin >>\" please insert x y r (space separator):\n";
    Circle cr2;
    cin >> cr2;
    cout<<cr2<<'\n';
    cr2.printShort();
    cr2.print();
    cr2.visCircle();
    
    return 0;
}
