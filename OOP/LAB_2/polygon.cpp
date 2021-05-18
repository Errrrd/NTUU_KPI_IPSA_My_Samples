#include <iostream>
//#include <cmath>

#include "coordinates.h"
#include "circle.h"
#include "color.h"
#include "polygon.h"

//-------------------------------------------------------------------------------------------------
int PolygonIn::polygonCount = 0;

PolygonIn::PolygonIn()
    : Circle()
    , sideCount(0)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonIn N" << numOfPolygon <<": Create Default - Centre:" << this->getCentre() << " + R:" << this->getR() << " + Sides:" << this->sideCount << '\n';
}

PolygonIn::PolygonIn(const Coordinates& newCentre, double newR, int sides)
    : Circle(newCentre, newR)
    , sideCount(sides)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by coord:" << newCentre <<" + R:"<< newR << " + Sides:" << sides <<'\n';
}

PolygonIn::PolygonIn(double newX, double newY, double newR, int sides)
    : Circle(newX, newY, newR)
    , sideCount(sides)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by x=" << newX << " + y=" << newY << " + R=" << newR << " + Sides:" << sides <<'\n';
}

PolygonIn::PolygonIn(const PolygonIn& other) 
    : Circle(other)
    , sideCount(other.sideCount)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by copy from " << other <<'\n';
}

PolygonIn& PolygonIn::operator=(PolygonIn& other) {
    if ( this != &other ) {
        Circle::operator=(other);
        this->sideCount = other.sideCount;
        polygonCount++;
        numOfPolygon = polygonCount;
    }
    std::cout << "PolygonIn N" << numOfPolygon <<": Create via operator \"=\""<<'\n';
    return *this;
}

PolygonIn& PolygonIn::setSideCount(int sides) {
    this->polygonCount = sides;
    return *this;
}

int PolygonIn::getSideCount() const { return this->polygonCount; }

// (y – cY)^2 = R^2 - (x – cX)^2
// void PolygonIn::visPolygonIn() const {
    // std::cout<<"----------------------------------------------------------------------\nVisualisation PolygonIn, dependency [x, y1|y2]:\n";
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
    // std::cout<<"\n----------------------------------------------------------------------\n";
// }

void PolygonIn::printPolygonInShort() const {
    std::cout << this->getCentre() << ' ' << this->getR() << ' ' << this->sideCount << ' ' << '\n';
}

void PolygonIn::printPolygonIn() const {
    std::cout << "PolygonOut:" << *this << '\n';
}

std::ostream& operator<<(std::ostream& out, const PolygonIn& polygon) {
    out << '(' << polygon.getCentre() << ", R:" << polygon.getR() << polygon.sideCount << ')';
     return out;
}

PolygonIn::~PolygonIn() {
    std::cout << "Delete N"<< numOfPolygon << " PolygonIn. Counter:"<< --polygonCount <<'\n';
}
//-------------------------------------------------------------------------------------------------

//-------------------------------------------------------------------------------------------------
int PolygonOut::polygonCount = 0;

PolygonOut::PolygonOut() 
    : Circle()
    , sideCount(0)
    , polygonColor({0.0f,0.0f,0.0f})
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonOut N" << numOfPolygon <<": Create Default - Centre:" << this->getCentre() << " + R:" << this->getR() << " + Sides:" << this->sideCount << " + Color:" << this->polygonColor << '\n';
}
PolygonOut::PolygonOut(const Coordinates& newCentre, double newR, int sides, const Color& color)
    : Circle(newCentre, newR)
    , sideCount(sides)
    , polygonColor(color)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by coord:" << newCentre <<" + R:"<< newR << " + Sides:" << sides << " + Color:" << color << '\n';
}
PolygonOut::PolygonOut(double newX, double newY, double newR, int sides, const Color& color)
    : Circle(newX, newY, newR)
    , sideCount(sides)
    , polygonColor(color)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by x=" << newX << " + y=" << newY << " + R=" << newR << " + Sides:" << sides << " + Color:" << color <<'\n';
}
PolygonOut::PolygonOut(const PolygonOut& other) 
    : Circle(other)
    , sideCount(other.sideCount)
    , polygonColor(other.polygonColor)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by copy from " << other <<'\n';
}

PolygonOut& PolygonOut::operator=(PolygonOut& other) {
    if ( this != &other ) {
        Circle::operator=(other);
        this->sideCount = other.sideCount;
        this->polygonColor = other.polygonColor;
        polygonCount++;
        numOfPolygon = polygonCount;
    }
    std::cout << "PolygonOut N" << numOfPolygon <<": Create via operator \"=\""<<'\n';
    return *this;
}

PolygonOut& PolygonOut::setSideCount(int sides) {
    this->polygonCount = sides;
    return *this;
}

int PolygonOut::getSideCount() const { return this->polygonCount; }

const Color& PolygonOut::getColor() const { return this->polygonColor; }

PolygonOut& PolygonOut::setColor(const Color& newColor) {
    this->polygonColor = newColor;
    return *this;
}
// (y – cY)^2 = R^2 - (x – cX)^2
// void PolygonOut::visPolygonOut() const {
    // std::cout<<"----------------------------------------------------------------------\nVisualisation PolygonOut, dependency [x, y1|y2]:\n";
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
    // std::cout<<"\n----------------------------------------------------------------------\n";
// }

void PolygonOut::printPolygonOutShort() const {
    std::cout << this->getCentre() << ' ' << this->getR() << ' ' << this->sideCount << ' ' << this->polygonColor << '\n';
}

void PolygonOut::printPolygonOut() const {
    std::cout << "PolygonOut:" << *this <<'\n';
}

std::ostream& operator<<(std::ostream& out, const PolygonOut& polygon) {
    out << '(' << polygon.getCentre() << ", R:" << polygon.getR() << polygon.sideCount << ", Color:" << polygon.getColor() << ')';
    return out;
}

PolygonOut::~PolygonOut() {
    std::cout << "Delete N"<< numOfPolygon << " PolygonOut. Counter:"<< --polygonCount <<'\n';
}
//-------------------------------------------------------------------------------------------------
