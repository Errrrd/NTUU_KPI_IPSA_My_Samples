#include <iostream>
#include <cmath>

#include "helper.h"
#include "coordinates.h"

int Coordinates::coordCount = 0;

Coordinates::Coordinates()
    : x(0.0)
    , y(0.0)
{
    coordCount++;
    numOfCoords = coordCount;
    if(bDebug)
        std::cout << "Coordinates N" << numOfCoords << ": Create Default"<<'\n';
}

Coordinates::Coordinates(double newX, double newY)
    : x(newX)
    , y(newY)
{
    coordCount++;
    numOfCoords = coordCount;
    if(bDebug)
        std::cout << "Coordinates N" << numOfCoords << ": Create by x=" << newX << " + y=" << newY <<'\n';
}

Coordinates::Coordinates(const Coordinates& other)
    : x(other.x)
    , y(other.y)
{
    coordCount++;
    numOfCoords = coordCount;
    if(bDebug)
        std::cout << "Coordinates N" << numOfCoords << ": Create by copy from " << other <<'\n';
}

Coordinates& Coordinates::operator=(const Coordinates& other) {
    if ( this != &other ) {
        this->x = other.x;
        this->y = other.y;
        coordCount++;
        numOfCoords = coordCount;
    }
    if(bDebug)
        std::cout << "Coordinates N" << numOfCoords << ": Create via operator \"=\""<<'\n';
    return *this;
}

bool Coordinates::operator==(const Coordinates& other) const {
    return (this == &other) || (this->x == other.x && this->y == other.y);
}

bool Coordinates::operator!=(const Coordinates& other) const {
    return !(*this == other);
}

Coordinates& Coordinates::setX(double newX) {
    this->x = newX;
    return *this;
}

Coordinates& Coordinates::setY(double newY) {
    this->y = newY;
    return *this;
}

double Coordinates::getDistance(const Coordinates& other) const {
    return hypot(this->x - other.x, this->y - other.y);
}

void Coordinates::printCoordShort() const {
    std::cout << this->x << ' ' << this->y << '\n';
}

void Coordinates::printCoordinates() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << "Coordinates:" << *this <<'\n';
}

std::ostream& operator<<(std::ostream& out, const Coordinates& coord) {
out << '[' << coord.x << ", " << coord.y << ']';
    return out;
}

Coordinates::~Coordinates() {
    --coordCount;
    if(bDebug) {
        std::cout << "Delete object Coordinates N" << numOfCoords << '\n';
        if (coordCount == 0) { std::cout << "All objects of class Coordinates was deleted\n"; }
    }
}
