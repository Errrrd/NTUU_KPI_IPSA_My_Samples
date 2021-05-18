/*
Порядок виконання роботи

Спільні вимоги до усіх варіантів.
Побудувати конкретний клас відповідно варіанту з врахуванням необхідності приховання даних. Якщо це не оговорено окремо, у кожному класі, що розробляється, передбачити:
- конструктори умовчання, з параметрами та копіювання;
- за наявності динамічних полів, у тому числі символьних рядків довільної довжини, у конструкторах передбачити виділення пам’яті;
- деструктор;
- функції-селектори для доступу окремо до кожного поля;
- дві функції для виведення на екран інформації про поточний стан об’єкту; одна – у вигляді рядка зі значеннями кожного з полів через пропуск, друга – у вигляді назви класу і значення одного з полів, яке найкраще ідентифікуватиме об’єкт; якщо клас містить масив, інформація про кожний елемент масиву подається окремим рядком у першій з функцій;
- функції-модифікатори окремо для кожного з полів з повертанням посилання на модифікований об’єкт.

Варіант20.
Тип «Координати» визначити як клас, що містить закриті числові поля з двома координатами, усі функції реалізувати відповідно загальним вимогам. Тип «Коло» визначити як клас, що містить:
- закрите поле з координатами, закриті числові поля з радіусом та ознакою візуалізації;
- усі функції реалізувати відповідно загальним вимогам.

У тестовому прикладі створити об’єкти типу «Координати» та «Коло» відповідно загальним вимогам і вивести інформацію про них у повному та скороченому вигляді.
*/
#ifndef CIRCLE_H
#define CIRCLE_H

// в заголовочному файлі клас визначається для вказівки компілятору, що такий тип існує та заголовок буде підключений в файлі реалізації, це побавить від можливих проблем при лінковці, так як визначення класу працює швидше ніж пошук та підключення заголовочних файлів.
class Coordinates; 

class Circle {
    friend std::ostream& operator<<(std::ostream&, const Circle&);
    
    private:
        static int circleCount;
        
        Coordinates centre;
        double r;
        
    public:
        Circle();
        Circle(Coordinates& centre, double r=1);
        Circle(double x, double y, double r=1);
        Circle(const Circle& other);
        
        Circle& operator=(Circle& other);
        
        Circle& setR(double newR);
        Circle& setCentre(const Coordinates& centre);
        Circle& setCentreXY(double x=0, double y=0);
        
        inline double getR() const { return r; }
        inline Coordinates& getCentre() { return centre; }
        
        void visCircle() const;
        
        void printCircleShort() const;
        void printCircle() const;
        
        ~Circle();
};

std::ostream& operator<<(std::ostream&, const Circle&);

#endif
