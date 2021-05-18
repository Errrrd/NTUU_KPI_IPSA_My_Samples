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
#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
    friend std::ostream& operator<<(std::ostream&, const Coordinates&);
    
    private:
        static int coordCount;
        
        double x, y;
    
    public:
        Coordinates();
        Coordinates(double x, double y=0);
        Coordinates(const Coordinates& other);
        
        Coordinates& operator=(const Coordinates& other);
        
        bool operator==(const Coordinates& other) const;
        bool operator!=(const Coordinates& other) const;
        
        Coordinates& setX(double newX);
        Coordinates& setY(double newY);
        
        inline double getX() const { return x; }
        inline double getY() const { return y; }
        
        double getDistance(const Coordinates& other) const;
        
        void printCoordShort() const;
        void printCoordinates() const;
        
        ~Coordinates();
};

std::ostream& operator<<(std::ostream&, const Coordinates&);

#endif
