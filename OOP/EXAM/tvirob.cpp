#include <iostream>

#include "helper.h"
#include "tvirob.h"

int Tvirob::tvirobCount = 0;

void  Tvirob::calculateQuality()
{
    countUnStandart = countTests - countStandart;
    tvirobQuality = double(countTests) / double(countStandart);
    //return tvirobQuality;
}

Tvirob::Tvirob(std::string tvirobName, int countTests, int countStandart)
    : tvirobName(tvirobName)
    , countTests(countTests)
    , countStandart(countStandart)
{
    tvirobCount++;
    numOfTvirob = tvirobCount;
    calculateQuality();
    if (bDebug)
        std::cout << "Tvirob N" << numOfTvirob << '\n';
}
int  Tvirob::getCountTests() {
    return countTests;
}
int  Tvirob::getCountStandart() {
    return countStandart;
}
int  Tvirob::getCountUnStandart() {
    return countUnStandart;
}
std::string  Tvirob::getName() {
    return tvirobName;
}
double Tvirob::getQuality()
{
    return tvirobQuality;
}

void Tvirob::print() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << "Tvirob:" << *this;
}

std::ostream& operator<<(std::ostream& out, const Tvirob& Tvirob) {
out << "[" << Tvirob.tvirobName <<"], countTests:" << Tvirob.countTests << ", countStandart:" << Tvirob.countStandart << ", countUnStandart:" << Tvirob.countUnStandart << ", tvirobQuality:" << Tvirob.tvirobQuality << std::endl;
    return out;
}

Tvirob::~Tvirob() {
    --tvirobCount;
    if(bDebug) {
        std::cout << "Delete object Tvirob N"<< numOfTvirob << '\n';
        if (tvirobCount == 0) { std::cout << "All objects of class Tvirob was deleted\n"; }
    }
}

