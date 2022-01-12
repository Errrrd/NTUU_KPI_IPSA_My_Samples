#ifndef TPVIROB_H
#define TPVIROB_H
#include <string>

/*
2. Побудувати батьківський клас Tvirob з полями : назва виробу, кількість випробувань виробу на якість, кількість виробів, які успішно пройшли випробування, кількість таких з них, які виявилися нестандартними.Метод класу визначає якість за формулою :
Q = кількість випробувань виробу / кількість успішних випробувань.
Побудувати похідний клас TPvirob, який крім батьківських полів має додаткове поле(P) – кількість виробів, які не відповідають стандарту(за розміром, кольором тощо) та визначає якість виробу за новою формулою :
Qр = Q – 2 * P / кількість випробувань виробу на якість.
Оголосити та визначити елементи класів в окремих файлах. У головному модулі створити об’єкти з вказівником та без нього і вивести інформацію у вікно форми. При написанні програми застосувати поняття поліморфізму класів.

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
