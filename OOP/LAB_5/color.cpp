#include <iostream>

#include "helper.h"
#include "color.h"

int Color::colorCount = 0;

Color::Color()
    : r(0.0f)
    , g(0.0f)
    , b(0.0f)
{
    if(bDebug)
        std::cout << "Color: Create Default (0.0f|0.0f|0.0f)"<<'\n';
}

Color::Color(float newR, float newG, float newB)\
    : r(newR)
    , g(newG)
    , b(newB)
{
    colorCount++;
    numOfColors = colorCount;
    if(bDebug)
        std::cout << "Color N"<< numOfColors <<": Create by R|G|B:[" << newR << '|' << newG << '|' << newB <<"]\n";
}

Color::Color(const Color& other)
    : r(other.r)
    , g(other.g)
    , b(other.b)
{
    colorCount++;
    numOfColors = colorCount;
    if(bDebug)
        std::cout << "Color N" << numOfColors << ": Create by copy from " << other <<'\n';
}

Color& Color::operator=(const Color& other) {
    if ( this != &other ) {
        this->r = other.r;
        this->g = other.g;
        this->b = other.b;
        colorCount++;
        numOfColors = colorCount;
    }
    if(bDebug)
        std::cout << "Color N" << numOfColors << ": Create via operator \"=\""<<'\n';
    return *this;
}

void Color::printColor() const { std::cout << "Color:" << *this <<'\n'; }

std::ostream& operator<<(std::ostream& out, const Color& color) {
out << "RGB[" << color.r << '|' << color.g << '|' << color.b << ']';
    return out;
}

Color::~Color() {
    if(bDebug) {
        std::cout << "Delete object Color N" << colorCount-- << "\n";
        if (colorCount == 0) { std::cout << "All objects of class Color was deleted\n"; }
    }
}
