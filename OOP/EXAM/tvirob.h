#ifndef TVIROB_H
#define TVIROB_H
#include <string>

/*
2. Побудувати батьківський клас Tvirob з полями : назва виробу, кількість випробувань виробу на якість, кількість виробів, які успішно пройшли випробування, кількість таких з них, які виявилися нестандартними.Метод класу визначає якість за формулою :
Q = кількість випробувань виробу / кількість успішних випробувань.
Побудувати похідний клас TPvirob, який крім батьківських полів має додаткове поле(P) – кількість виробів, які не відповідають стандарту(за розміром, кольором тощо) та визначає якість виробу за новою формулою :
Qр = Q – 2 * P / кількість випробувань виробу на якість.
Оголосити та визначити елементи класів в окремих файлах. У головному модулі створити об’єкти з вказівником та без нього і вивести інформацію у вікно форми. При написанні програми застосувати поняття поліморфізму класів.

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
