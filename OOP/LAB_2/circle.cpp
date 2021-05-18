#include <iostream>
#include <cmath>
//#include <typeinfo>

#include "coordinates.h"
#include "circle.h"

int Circle::circleCount = 0;

Circle::Circle()
    : centre()
    , r(0.0)
{
    circleCount++;
    numOfCircle = circleCount;
    std::cout <<  "Circle N" << numOfCircle <<": Create Default"<<'\n';
}

Circle::Circle(const Coordinates& newCentre, double newR)
    : centre(newCentre)
    , r(newR)
{
    circleCount++;
    numOfCircle = circleCount;
    std::cout <<  "Circle N" << numOfCircle <<": Create by coord:" << newCentre <<" + R:"<< newR <<'\n';
}

Circle::Circle(double newX, double newY, double newR)
    : centre(Coordinates(newX,newY))
    , r(newR)
{
    circleCount++;
    numOfCircle = circleCount;
    std::cout <<  "Circle N" << numOfCircle <<": Create by x=" << newX << " + y=" << newY << " + R=" << newR <<'\n';
}

Circle::Circle(const Circle& other)
    : centre(other.centre)
    , r(other.r)
{
    circleCount++;
    numOfCircle = circleCount;
    std::cout <<  "Circle N" << numOfCircle <<": Create by copy from " << other <<'\n';
}

Circle& Circle::operator=(Circle& other) {
    if ( this != &other ) {
        this->r = other.r;
        this->centre = other.centre;
        circleCount++;
        numOfCircle = circleCount;
    }
    std::cout << "Circle N" << numOfCircle <<": Create via operator \"=\""<<'\n';
    return *this;
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
    std::cout<<"----------------------------------------------------------------------\nVisualisation Circle, dependency [x, y1|y2]:\n";
    double stepX = r / 10.0;
    double startX = this->centre.getX() - r;
    double endX = this->centre.getX() + r*1.00001;
    for (double x = startX; x < endX; x=x+stepX) {
        double powDiff = r*r - (x-this->centre.getX())*(x-this->centre.getX());
        if (powDiff < 0.0) {powDiff = -powDiff;}
        
        double shiftY = sqrt(powDiff);
        std::cout   << '['  << x 
                    << ", " << this->centre.getY() - shiftY 
                    << '|'  << this->centre.getY() + shiftY 
                    << "]; ";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
}

void Circle::printCircleShort() const {
    std::cout << this->centre.getX() << ' ' << this->centre.getY() << ' ' << this->r << '\n';
}

void Circle::printCircle() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << "Circle:" << *this <<'\n';
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
out << '(' << circle.centre << ", R:" << circle.r << ')';
    return out;
}

Circle::~Circle() {
    std::cout << "Delete N"<< numOfCircle << " Circle. Counter:"<< --circleCount <<'\n';
}
