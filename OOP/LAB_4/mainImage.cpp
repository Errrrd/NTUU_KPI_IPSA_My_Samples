#include <iostream>
#include <string>

#include "helper.h"
#include "color.h"
#include "coordinates.h"
#include "circle.h"
#include "polygon.h"
#include "image.h"

using namespace std;

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
    
    cout<<"\nCircle 1:\n";
    Circle cr1(cntr1,r);
    cout<<cr1<<'\n';
    cr1.printShort();
    cr1.print();
    cr1.visCircle();

    cout<<"\n\nCreate Color 1\n";
    Color col1(0.1f,0.5f,0.5f);
    cout << "\n-------------------------------------------------------------------------\n";
    cout<<"\n\nCreate polygon in 1:\n";
    PolygonIn pli1;
    pli1.visPolygon();
    pli1.printShort();
    cout << "\nCreate polygon in 2:\n";
    PolygonIn pli2(x-2, y-1, r-1, 4);
    pli2.visPolygon();
    pli2.printShort();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\nCreate polygon out 3 from polygon in 2 via \"=\" :\n";
    PolygonOut plo3 = pli2;
    plo3.visPolygon();
    plo3.printShort();
    cout << "\nCreate polygon out 3 from polygon in 2 via \"Copy\" constructor :\n";
    PolygonOut plo4(pli2);
    plo4.visPolygon();
    plo4.printShort();

    cout << "\n\nCreate polygon out 1:\n";
    PolygonOut plo1;
    plo1.visPolygon();
    plo1.printShort();
    cout << "\nCreate polygon out 2:\n";
    PolygonOut plo2(x-1,y+1, r+3, 6, col1);
    plo2.visPolygon();
    plo2.printShort();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\nCreate polygon in 3 from polygon out 2 via \"=\" :\n";
    PolygonOut pli3 = plo2;
    pli3.visPolygon();
    pli3.printShort();
    cout << "\nCreate polygon in 3 from polygon out 2 via \"Copy\" constructor :\n";
    PolygonOut pli4(plo2);
    pli4.visPolygon();
    pli4.printShort();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\nCreate Image 1:\n";
    Image img1;
    cout << img1 <<endl;
    cout << "\nadd circle and polygons to image1\n";
    img1.addCircle(cr1);
    img1.addCircle(pli2);
    img1.addCircle(plo2);
    img1.addCircle(cr1);
    cout << img1 <<endl;
    cout << "print method img1:\n";
    img1.print();
    cout << "\n-------------------------------------------------------------------------\n";
    cout << "\nCreate Image 2:\n";
    Image img2(cr1);
    cout << img2 <<endl;
    cout << "\nadd circle and polygons to image1\n";
    img2.addCircle(pli1);
    img2.addCircle(plo1);
    img2.addCircle(pli2);
    img2.addCircle(plo2);
    cout << "\n\"cout\" print method img2:\n";
    cout << img2 <<endl;
    cout << "\nShort print method img2:\n";
    img2.printShort();
    cout << "\nprint method img2:\n";
    img2.print();
    cout << "\nprint idx 3 of img2:\n";
    img2[3].print();

    return 0;
}
