#include <iostream>

#include "employee.h"
// якщо за основним місцем роботи зарплатня працівника не перевищує 300 гривень, то вона не оподатковується, інакше – податок становить 15 % від зарплатні. Але, якщо працівник працює за сумісництвом, то незалежно від розміру зарплатні відраховується податок у 20 %. Використати цей об’єкт для обчислення фактичної зарплатні, яку отримає окремий працівник, та величини сплачуваного податку.

int Employee::EmployeeCount = 0;

Employee::Employee(std::string firstName, std::string secondName, std::string lastName, WorkType workType, double fullSalary)
    : firstName(firstName)
    , secondName(secondName)
    , lastName(lastName)
    , workType(workType)
{
    calculateTaxAndSalary(fullSalary);
    if (bDebug)
        std::cout << "Employee N" << numOfEmployee << '\n';
}

void Employee::calculateTaxAndSalary(double fullSalary) {
    if (workType == WorkType::SIMPLE) {
        if (fullSalary > 300)   { this->taxRate = 0.15; }
        else                    { this->taxRate = 0.0; }
    } else                      { this->taxRate = 0.2; }
    this->tax = fullSalary * this->taxRate;
    this->salary = fullSalary * (1.0-this->taxRate);
}


void Employee::print() const {
    //std::cout << typeid(*this).name() << ':' << *this <<'\n';
    std::cout << "Employee:" << *this;
}

std::ostream& operator<<(std::ostream& out, const Employee& Employee) {
out << "[" << Employee.firstName << ' ' << Employee.secondName << ' ' << Employee.lastName << "], salary:" << Employee.salary << ", tax rate:" << Employee.taxRate << ", tax:" << Employee.tax << (Employee.workType ? ", PART TIME WORK": ", SIMPLE WORK") << std::endl;
    return out;
}

Employee::~Employee() {
    --EmployeeCount;
    if(bDebug) {
        std::cout << "Delete object Employee N"<< numOfEmployee << '\n';
        if (EmployeeCount == 0) { std::cout << "All objects of class Employee was deleted\n"; }
    }
}
