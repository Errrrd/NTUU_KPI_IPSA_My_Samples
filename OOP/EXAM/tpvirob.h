#ifndef TPVIROB_H
#define TPVIROB_H
#include <string>

/*
2. ���������� ����������� ���� Tvirob � ������ : ����� ������, ������� ����������� ������ �� �����, ������� ������, �� ������ ������� ������������, ������� ����� � ���, �� ��������� ��������������.����� ����� ������� ����� �� �������� :
Q = ������� ����������� ������ / ������� ������� �����������.
���������� �������� ���� TPvirob, ���� ��� ����������� ���� �� ��������� ����(P) � ������� ������, �� �� ���������� ���������(�� �������, �������� ����) �� ������� ����� ������ �� ����� �������� :
Q� = Q � 2 * P / ������� ����������� ������ �� �����.
��������� �� ��������� �������� ����� � ������� ������. � ��������� ����� �������� �ᒺ��� � ���������� �� ��� ����� � ������� ���������� � ���� �����. ��� �������� �������� ����������� ������� ����������� �����.

*/
//#include "tvirob.h"
class Tvirob;

class TPvirob : public Tvirob {
    //friend std::ostream& operator<<(std::ostream&, const TPvirob&);
private:
    static int tpvirobCount;

    int numOfTpvirob;

    int countPUnStandart;
    double tpvirobQuality;
protected:
    virtual void calculateQuality();
public:
    TPvirob(std::string tvirobName, int countTests, int countStandart);

    double getPQuality();
    virtual void print() const;

    virtual ~TPvirob();
};

//std::ostream& operator<<(std::ostream&, const TPvirob&);

#endif
