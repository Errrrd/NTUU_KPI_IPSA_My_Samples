#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>

static bool bDebug = false;

enum WorkType {
    SIMPLE=0, //0
    PART_TIME=1, //1
    UNCNOWN = 100 //nothing
};

class Employee {
    friend std::ostream& operator<<(std::ostream&, const Employee&);
    
    private:
        static int EmployeeCount;

        int numOfEmployee;
        double salary, taxRate, tax;
        WorkType workType;
        
        std::string firstName, secondName, lastName;
    protected:
        virtual void calculateTaxAndSalary(double fullSalary);
    public:
        Employee(std::string firstName, std::string secondName, std::string lastName, WorkType workType, double fullSalary);
        virtual void print() const;
        
        virtual ~Employee();
};

std::ostream& operator<<(std::ostream&, const Employee&);

#endif
