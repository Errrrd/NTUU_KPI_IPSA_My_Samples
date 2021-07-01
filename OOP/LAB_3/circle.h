#ifndef CIRCLE_H
#define CIRCLE_H

// в заголовочному файлі клас визначається для вказівки компілятору, що такий тип існує та заголовок буде підключений в файлі реалізації, це побавить від можливих проблем при лінковці, так як визначення класу працює швидше ніж пошук та підключення заголовочних файлів.
class Coordinates; 

class Circle {
    friend std::ostream& operator<<(std::ostream&, const Circle&);
    friend std::istream& operator>>(std::istream&, Circle&);
    
    private:
        static int circleCount;
        
        int numOfCircle;
        Coordinates centre;
        double r;
        
    public:
        Circle();
        Circle(const Coordinates& centre, double r=1);
        Circle(double x, double y, double r=1);
        Circle(const Circle& other);
        
        Circle& operator=(Circle& other);
        
        bool operator==(const Circle& other) const;
        
        Circle& setR(double newR);
        Circle& setCentre(const Coordinates& centre);
        Circle& setCentreXY(double x=0, double y=0);
        
        virtual double getR() const;
        virtual const Coordinates& getCentre() const;
        
        void visCircle() const;
        
        void printShort() const;
        void print() const;
        
        virtual ~Circle();
};

std::ostream& operator<<(std::ostream&, const Circle&);
std::istream& operator>>(std::istream&, Circle&);

#endif
