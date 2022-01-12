#include <iostream>

#include "helper.h"
#include "tvirob.h"
#include "tpvirob.h"

//---------------------------------------------------------------------------------------------------------
int TPvirob::tpvirobCount = 0;

TPvirob::TPvirob(std::string tpvirobName, int countTests, int countStandart)
    : Tvirob(tpvirobName, countTests, countStandart)
{
    tpvirobCount++;
    numOfTpvirob = tpvirobCount;
    calculateQuality();
    if (bDebug)
        std::cout << "TPvirob N" << numOfTpvirob << '\n';
}

void TPvirob::calculateQuality()
{
    countPUnStandart = getCountTests() - getCountStandart();
    tpvirobQuality = getQuality() - 2 * double(countPUnStandart) / double(getCountStandart());
    //return tpvirobQuality;
}

double TPvirob::getPQuality()
{
    return tpvirobQuality;
}

void TPvirob::print() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << *this << ", tpvirobQuality:" << this->tpvirobQuality << std::endl;

}

/*
std::ostream& operator<<(std::ostream& out, const TPvirob& tpv)
{
    out << "[" << tpv.getName() << "], countTests:" << tpv.getCountTests() << ", countStandart:" << tpv.getCountStandart() << ", countUnStandart:" << tpv.getCountUnStandart() << ", tpvQuality:" << tpv.tpvirobQuality << std::endl;
    return out;
}*/

TPvirob::~TPvirob() {
    --tpvirobCount;
    if (bDebug) {
        std::cout << "Delete object TPvirob N" << numOfTpvirob << '\n';
        if (tpvirobCount == 0) { std::cout << "All objects of class TPvirob was deleted\n"; }
    }
}
