#include <iostream>
//#include <iomanip>
#include <cmath>

#include "helper.h"
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
    if(bDebug)
        std::cout <<  "PolygonIn N" << numOfPolygon <<": Create Default - Centre:" << this->getCentre() << " + R:" << this->getR() << " + Sides:" << this->sideCount << '\n';
    //createCoordinates();
}

PolygonIn::PolygonIn(const Coordinates& newCentre, double newR, int sides)
    : Circle(newCentre, newR)
    , sideCount(sides)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by params - Centre:" << newCentre <<" + R:"<< newR << " + Sides:" << sides <<'\n';
    createCoordinates();
}

PolygonIn::PolygonIn(double newX, double newY, double newR, int sides)
    : Circle(newX, newY, newR)
    , sideCount(sides)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by x:" << newX << " + y:" << newY << " + R:" << newR << " + Sides:" << sides <<'\n';
    createCoordinates();
}

PolygonIn::PolygonIn(const PolygonIn& other) 
    : Circle(other)
    , sideCount(other.sideCount)
    , polyCoords(other.polyCoords)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonIn N" << numOfPolygon <<": Create by copy from " << other <<'\n';
    // for (std::vector<Coordinates>::iterator it = other.polyCoords.begin(); it != other.polyCoords.end(); it++) {
        // this->polyCoords.push_back(*it);
    // }
}

PolygonIn& PolygonIn::operator=(PolygonIn& other) {
    if ( this != &other ) {
        Circle::operator=(other);
        this->sideCount = other.sideCount;
        this->polyCoords = other.polyCoords;
        polygonCount++;
        numOfPolygon = polygonCount;
    }
    if(bDebug)
        std::cout << "PolygonIn N" << numOfPolygon <<": Create via operator \"=\""<<'\n';
    return *this;
}

/*
    for circle out of polygon:
    x = centreX + R * cos(startAngle + 2*Pi/n)
    y = centreY + R * sin(startAngle + 2*Pi/n)
*/
void PolygonIn::createCoordinates() {
    if(bDebug)
        std::cout<<"Create Polygon coordinates:\n";
    this->polyCoords.erase(this->polyCoords.begin(), this->polyCoords.end());
    double stepAng = Trig::Pi * 2.0 / (double)(this->sideCount);
    double startAng = Trig::Pi / 2.0;
    double endAng = Trig::Pi * 2.0 + startAng;
    for (double radAng = startAng; radAng < endAng; radAng+=stepAng) {
        double coordX = this->getCentre().getX() + this->getR() * cos(radAng);
        double coordY = this->getCentre().getY() + this->getR() * sin(radAng);
        this->polyCoords.push_back(Coordinates(coordX, coordY));
    }
    
    if(bDebug)
        visPolygon();
}

bool PolygonIn::operator==(const PolygonIn& other) const {
    return ( this == &other ) ||
           ( this->getCentre() == other.getCentre() &&
             this->getR() == other.getR() &&
             this->sideCount == other.sideCount );
}

PolygonIn& PolygonIn::setSideCount(int sides) {
    this->sideCount = sides;
    return *this;
}

int PolygonIn::getSideCount() const { return this->sideCount; }

void PolygonIn::visPolygon() const {
    std::cout<<"----------------------------------------------------------------------\n";
    // double stepAng = Trig::Pi * 2.0 / (double)(this->sideCount);
    // double startAng = Trig::Pi / 2.0;
    // double endAng = Trig::Pi * 2.0 + startAng;
    // for (double radAng = startAng; radAng < endAng; radAng+=stepAng) {
        // double coordX = this->getCentre().getX() + this->getR() * cos(radAng);
        // double coordY = this->getCentre().getY() + this->getR() * sin(radAng);
        // std::cout << '[' << coordX  << ", " << coordY << "], ";
    // }
    for ( int i=0; i < this->sideCount; i++) {
        std::cout<<"N"<< i <<":" << this->polyCoords[i] << ", ";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
}

void PolygonIn::printShort() const {
    std::cout << this->getCentre() << ' ' << this->getR() << ' ' << this->sideCount << ' ' << '\n';
}

void PolygonIn::print() const {
    std::cout << "PolygonIn:" << *this << '\n';
}

const std::vector<Coordinates>& PolygonIn::getCoordVector() const {
    return polyCoords;
}

std::ostream& operator<<(std::ostream& out, const PolygonIn& polygon) {
    out << "(Cntr:" << polygon.getCentre() << ", R:" << polygon.getR() << ", S:" << polygon.sideCount << ')';
     return out;
}

PolygonIn::~PolygonIn() {
    --polygonCount;
    if(bDebug) {
        std::cout << "Delete object PolygonIn N"<< numOfPolygon << '\n';
        if (polygonCount == 0) { std::cout << "All objects of class PolygonIn was deleted\n"; }
    }
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
    if(bDebug)
        std::cout <<  "PolygonOut N" << numOfPolygon <<": Create Default - Centre:" << this->getCentre() << " + R:" << this->getR() << " + Sides:" << this->sideCount << " + Color:" << this->polygonColor << '\n';
}
PolygonOut::PolygonOut(const Coordinates& newCentre, double newR, int sides, const Color& color)
    : Circle(newCentre, newR)
    , sideCount(sides)
    , polygonColor(color)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by params - Centre:" << newCentre <<" + R:"<< newR << " + Sides:" << sides << " + Color:" << color << '\n';
    createCoordinates();
}
PolygonOut::PolygonOut(double newX, double newY, double newR, int sides, const Color& color)
    : Circle(newX, newY, newR)
    , sideCount(sides)
    , polygonColor(color)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by x:" << newX << " + y:" << newY << " + R:" << newR << " + Sides:" << sides << " + Color:" << color <<'\n';
    createCoordinates();
}
PolygonOut::PolygonOut(const PolygonOut& other) 
    : Circle(other)
    , sideCount(other.sideCount)
    , polygonColor(other.polygonColor)
    , polyCoords(other.polyCoords)
{
    polygonCount++;
    numOfPolygon = polygonCount;
    if(bDebug)
        std::cout <<  "PolygonOut N" << numOfPolygon <<": Create by copy from " << other <<'\n';
}

PolygonOut& PolygonOut::operator=(PolygonOut& other) {
    if ( this != &other ) {
        Circle::operator=(other);
        this->sideCount = other.sideCount;
        this->polygonColor = other.polygonColor;
        this->polyCoords = other.polyCoords;
        polygonCount++;
        numOfPolygon = polygonCount;
    }
    if(bDebug)
        std::cout << "PolygonOut N" << numOfPolygon <<": Create via operator \"=\""<<'\n';
    return *this;
}

bool PolygonOut::operator<(const PolygonOut& other) const {
    return ( this->sideCount < other.sideCount );
}

/*
    radiusIn = radiusOut * cos(Pi/n) => radiusOut = radiusIn / cos(Pi/n)
    for circle out of polygon:
    x = centreX + R * cos(startAngle + 2*Pi/n)
    y = centreY + R * sin(startAngle + 2*Pi/n)
*/
void PolygonOut::createCoordinates() {
    if(bDebug)
        std::cout<<"Create Polygon coordinates:\n";
    this->polyCoords.erase(this->polyCoords.begin(), this->polyCoords.end());;
    double rOut = this->getR() / cos(Trig::Pi/(double)(this->sideCount));
    double stepAng = Trig::Pi * 2.0 / (double)(this->sideCount);
    double startAng = Trig::Pi / 2.0;
    double endAng = Trig::Pi * 2.0 + startAng;
    for (double radAng = startAng; radAng < endAng; radAng+=stepAng) {
        double coordX = this->getCentre().getX() + rOut * cos(radAng);
        double coordY = this->getCentre().getY() + rOut * sin(radAng);
        this->polyCoords.push_back(Coordinates(coordX, coordY));
    }
    if(bDebug)
        visPolygon();
}

PolygonOut& PolygonOut::setSideCount(int sides) {
    this->sideCount = sides;
    return *this;
}

int PolygonOut::getSideCount() const { return this->sideCount; }

const Color& PolygonOut::getColor() const { return this->polygonColor; }

PolygonOut& PolygonOut::setColor(const Color& newColor) {
    this->polygonColor = newColor;
    return *this;
}

void PolygonOut::visPolygon() const {
    std::cout<<"----------------------------------------------------------------------\n";
    /*double rOut = this->getR() / cos(Trig::Pi/(double)(this->sideCount));
    double stepAng = Trig::Pi * 2.0 / (double)(this->sideCount);
    double startAng = Trig::Pi / 2.0;
    double endAng = Trig::Pi * 2.0 + startAng;
    for (double radAng = startAng; radAng < endAng; radAng+=stepAng) {
        double coordX = this->getCentre().getX() + rOut * cos(radAng);
        double coordY = this->getCentre().getY() + rOut * sin(radAng);
        std::cout << '[' << coordX  << ", " << coordY << "], ";
    }*/
    for ( int i=0; i < this->sideCount; i++) {
        std::cout<<"N"<< i <<":" << this->polyCoords[i] << ", ";
    }
    std::cout<<"\n----------------------------------------------------------------------\n";
}

void PolygonOut::printShort() const {
    std::cout << this->getCentre() << ' ' << this->getR() << ' ' << this->sideCount << ' ' << this->polygonColor << '\n';
}

void PolygonOut::print() const {
    std::cout << "PolygonOut:" << *this <<'\n';
}

std::ostream& operator<<(std::ostream& out, const PolygonOut& polygon) {
    out << "(Cntr:" << polygon.getCentre() << ", R:" << polygon.getR() << ", S:" << polygon.sideCount << ", Color:" << polygon.getColor() << ')';
    return out;
}

PolygonOut::~PolygonOut() {
    --polygonCount;
    if(bDebug) {
        std::cout << "Delete object PolygonOut N" << numOfPolygon <<'\n';
        if (polygonCount == 0) { std::cout << "All objects of class PolygonOut was deleted\n"; }
    }
}
//-------------------------------------------------------------------------------------------------
