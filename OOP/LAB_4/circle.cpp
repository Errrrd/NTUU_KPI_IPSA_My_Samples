#include <iostream>
#include <iomanip>
#include <cmath>

#include "helper.h"
#include "coordinates.h"
#include "circle.h"

int Circle::circleCount = 0;

Circle::Circle()
    : centre()
    , r(0.0)
{
    circleCount++;
    numOfCircle = circleCount;
    if(bDebug)
        std::cout <<  "Circle N" << numOfCircle <<": Create Default"<<'\n';
}

Circle::Circle(const Coordinates& newCentre, double newR)
    : centre(newCentre)
    , r(newR)
{
    circleCount++;
    numOfCircle = circleCount;
    if(bDebug)
        std::cout <<  "Circle N" << numOfCircle <<": Create by coord:" << newCentre <<" + R:"<< newR <<'\n';
}

Circle::Circle(double newX, double newY, double newR)
    : centre(Coordinates(newX,newY))
    , r(newR)
{
    circleCount++;
    numOfCircle = circleCount;
    if(bDebug)
        std::cout <<  "Circle N" << numOfCircle <<": Create by x=" << newX << " + y=" << newY << " + R=" << newR <<'\n';
}

Circle::Circle(const Circle& other)
    : centre(other.centre)
    , r(other.r)
{
    circleCount++;
    numOfCircle = circleCount;
    if(bDebug)
        std::cout <<  "Circle N" << numOfCircle <<": Create by copy from " << other <<'\n';
}

Circle& Circle::operator=(Circle& other) {
    if ( this != &other ) {
        this->r = other.r;
        this->centre = other.centre;
        circleCount++;
        numOfCircle = circleCount;
    }
    if(bDebug)
        std::cout << "Circle N" << numOfCircle <<": Create via operator \"=\""<<'\n';
    return *this;
}

bool Circle::operator==(const Circle& other) const {
    return (this == &other) || (this->centre == other.centre && this->r == other.r );
}

double Circle::getR() const { return this->r; }

const Coordinates& Circle::getCentre() const { return this->centre; }

Circle& Circle::setR(double newR) {
    this->r = newR;
    return *this;
}

Circle& Circle::setCentre(const Coordinates& centre) {
    this->centre = centre;
    return *this;
}

Circle& Circle::setCentreXY(double x, double y) {
    this->centre.setX(x);
    this->centre.setY(y);
    return *this;
}

// (y – cY)^2 = R^2 - (x – cX)^2
void Circle::visCircle() const {
    std::cout<<"----------------------------------------------------------------------\nVisualisation Circle, dependency [x, y]:\n";
    // double stepX = r / 10.0;
    // double startX = this->centre.getX() - r;
    // double endX = this->centre.getX() + r*1.00001;
    // for (double x = startX; x < endX; x=x+stepX) {
        // double powDiff = r*r - (x-this->centre.getX())*(x-this->centre.getX());
        // if (powDiff < 0.0) {powDiff = -powDiff;}
        
        // double shiftY = sqrt(powDiff);
        // std::cout   << '['  << x 
                    // << ", " << this->centre.getY() - shiftY 
                    // << '|'  << this->centre.getY() + shiftY 
                    // << "]; ";
    // }
    double stepAng = Trig::Pi / 10.0;
    double endAng = Trig::Pi * 2.0;
    int i=1;
    for (double radAng = 0.0; radAng < endAng; radAng+=stepAng, i++) {
        double coordX = this->centre.getX() + this->r * cos(radAng);
        double coordY = this->centre.getY() + this->r * sin(radAng);
        std::cout << '[' << std::setprecision(5) << coordX  << ", " << coordY << "],\t";
        if (i%5 == 0) {std::cout << '\n'; } 
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
}

void Circle::printShort() const {
    std::cout << this->centre.getX() << ' ' << this->centre.getY() << ' ' << this->r << '\n';
}

void Circle::print() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << "Circle:" << *this <<'\n';
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
out << '(' << circle.centre << ", R:" << circle.r << ')';
    return out;
}

Circle::~Circle() {
    --circleCount;
    if(bDebug) {
        std::cout << "Delete object Circle N"<< numOfCircle << '\n';
        if (circleCount == 0) { std::cout << "All objects of class Circle was deleted\n"; }
    }
}
