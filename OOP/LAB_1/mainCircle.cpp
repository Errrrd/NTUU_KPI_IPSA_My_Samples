#include <iostream>

#include "coordinates.h"
#include "circle.h"

using namespace std;

int main(int argsCount, char *argsValues[]) {
    
    cout<<"\nCoordinates 1:\n";
    Coordinates cntr1;
    cout<<cntr1<<'\n';
    
    cout<<"\nCoordinates 2:\n";
    Coordinates cntr2(5);
    cout<<cntr2<<'\n';
    
    cout<<"\nCoordinates 3:\n";
    Coordinates cntr3(5,6);
    cout<<cntr3<<'\n';
    cntr3.printCoordShort();
    cntr3.printCoordinates();
    
    cout<<"\nCoordinates 4:\n";
    Coordinates cntr4(cntr2);
    cout<<cntr4<<'\n';
    
    cout<<"\n\nCircle 1:\n";
    Circle cr1;
    cout<<cr1<<'\n';
    
    cout<<"\nCircle 2:\n";
    Circle cr2(cntr2);
    cout<<cr2<<'\n';
    
    cout<<"\nCircle 3:\n";
    Circle cr3(cntr3,3);
    cout<<cr3<<'\n';
    cr3.visCircle();
    
    cout<<"\nCircle 4:\n";
    Circle cr4(7,8,4);
    cout<<cr4<<'\n';
    cr4.printCircleShort();
    cr4.printCircle();
    
    cout<<"\nCircle 5:\n";
    Circle cr5(cr2);
    cout<<cr5<<'\n';
    
    cout<<"\nCircle 6:\n";
    Circle cr6(3,5);
    cout<<cr6<<'\n';
    cr6.visCircle();

    
    double x,y,r=-1.0;
    cout<<"\nplease set coordinate X:";
    cin>>x;
    cout<<"\nplease set coordinate Y:";
    cin>>y;
    
    for (;r < 0.0;) {
        cout<<"\nplease set radius for circle R >= 0:";
        cin>>r;
        if (r < 0) {
            cout<< "\nradius < 0.0. Could you please set right value\n";
        } 
    }
    
    cout<<"\nCoordinates 5:\n";
    Coordinates cntr5(x,y);
    cout<<cntr5<<'\n';
    
    cout<<"\nCircle 7:\n";
    Circle cr7(cntr5,r);
    cout<<cr7<<'\n';
    cr7.printCircleShort();
    cr7.printCircle();
    cr7.visCircle();
    cout<<'\n';
    
    return 0;
}
