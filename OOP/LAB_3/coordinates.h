#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
    friend std::ostream& operator<<(std::ostream&, const Coordinates&);
    friend std::istream& operator>>(std::istream&, Coordinates&);
    
    private:
        static int coordCount;
        
        int numOfCoords;
        double x, y;
        
    public:
        Coordinates();
        Coordinates(double x, double y=0);
        Coordinates(const Coordinates& other);
        
        Coordinates& operator=(const Coordinates& other);
        
        bool operator==(const Coordinates& other) const;
        bool operator!=(const Coordinates& other) const;
        
        Coordinates operator+(const Coordinates& other);
        void operator++(int);
        
        
        Coordinates& setX(double newX);
        Coordinates& setY(double newY);
        
        inline double getX() const { return x; }
        inline double getY() const { return y; }
        
        double getDistance(const Coordinates& other) const;
        
        void printShort() const;
        void print() const;
        
        ~Coordinates();
};

std::ostream& operator<<(std::ostream&, const Coordinates&);
std::istream& operator>>(std::istream&, Coordinates&);
// - арифметичні оператори “+” та “++”для класу «Координати» за
// значеннями одразу двох полів;
// - оператори форматного уведення-виведення – для класів «Коло» та
// «Координати».
#endif
