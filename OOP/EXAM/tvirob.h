#ifndef TVIROB_H
#define TVIROB_H
#include <string>

/*
2. ���������� ����������� ���� Tvirob � ������ : ����� ������, ������� ����������� ������ �� �����, ������� ������, �� ������ ������� ������������, ������� ����� � ���, �� ��������� ��������������.����� ����� ������� ����� �� �������� :
Q = ������� ����������� ������ / ������� ������� �����������.
���������� �������� ���� TPvirob, ���� ��� ����������� ���� �� ��������� ����(P) � ������� ������, �� �� ���������� ���������(�� �������, �������� ����) �� ������� ����� ������ �� ����� �������� :
Q� = Q � 2 * P / ������� ����������� ������ �� �����.
��������� �� ��������� �������� ����� � ������� ������. � ��������� ����� �������� �ᒺ��� � ���������� �� ��� ����� � ������� ���������� � ���� �����. ��� �������� �������� ����������� ������� ����������� �����.

*/

class Tvirob {
    friend std::ostream& operator<<(std::ostream&, const Tvirob&);
    
    private:
        static int tvirobCount;

        int numOfTvirob;
        
        int countTests, countStandart, countUnStandart;
        double tvirobQuality;
        
        std::string tvirobName;
    protected:
        virtual void calculateQuality();
    public:
        Tvirob(std::string tvirobName, int countTests, int countStandart);
        virtual double getQuality();
        virtual int getCountTests();
        virtual int getCountStandart();
        virtual int getCountUnStandart();
        virtual std::string getName();
        virtual void print() const;
        
        virtual ~Tvirob();
};

std::ostream& operator<<(std::ostream&, const Tvirob&);
#endif
