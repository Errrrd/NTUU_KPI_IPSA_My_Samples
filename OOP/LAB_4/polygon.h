#ifndef POLYGON_H
#define POLYGON_H

#include <vector>

class Coordinates;
class Circle;
class Color;
class PolygonIn;
class PolygonOut;


//-------------------------------------------------------------------------------
class PolygonIn : public Circle {
    friend std::ostream& operator<<(std::ostream&, const PolygonIn&);
    
    private:
        static int polygonCount;
        int numOfPolygon;
        int sideCount;
        std::vector<Coordinates> polyCoords;
    
    protected:
        virtual void createCoordinates(); 
    
    public:
        PolygonIn();
        PolygonIn(const Coordinates& centre, double r=1, int sides = 3);
        PolygonIn(double x, double y, double r=1, int sides = 3);
        PolygonIn(const PolygonIn& other);
        PolygonIn(const PolygonOut& other);
        
        PolygonIn& operator=(PolygonIn& other);
        PolygonIn& operator=(PolygonOut& other);
        bool operator==(const PolygonIn& other) const;

        PolygonIn& setSideCount(int sides);

        virtual int getSideCount() const;
        
        void visPolygon() const;
        
        virtual void printShort() const;
        virtual void print() const;
        //void printPolygon() const;
        
        const std::vector<Coordinates>& getCoordVector() const;
        
        virtual ~PolygonIn();
};

std::ostream& operator<<(std::ostream&, const PolygonIn&);
//-------------------------------------------------------------------------------

//-------------------------------------------------------------------------------
class PolygonOut : public Circle {
    friend std::ostream& operator<<(std::ostream&, const PolygonOut&);
    
    private:
        static int polygonCount;
        
        int numOfPolygon;
        int sideCount;
        Color polygonColor;
        std::vector<Coordinates> polyCoords;
        
        void createCoordinates(); 
    public:
        PolygonOut();
        PolygonOut(const Coordinates& centre, double r=1, int sides=3, const Color& color={1.0f,1.0f,1.0f});
        PolygonOut(double x, double y, double r=1, int sides=3, const Color& color={1.0f,1.0f,1.0f});
        PolygonOut(const PolygonOut& other);
        PolygonOut(const PolygonIn& other);
        
        PolygonOut& operator=(PolygonOut& other);
        PolygonOut& operator=(PolygonIn& other);
        bool operator<(const PolygonOut& other) const;
        
        PolygonOut& setSideCount(int sides);
        PolygonOut& setColor(const Color& newColor);
        
        virtual int getSideCount() const;
        virtual const Color& getColor() const;
        
        
        
        void visPolygon() const;
        
        virtual void printShort() const;
        virtual void print() const;
        //void printPolygon() const;
        
        virtual ~PolygonOut();
};

std::ostream& operator<<(std::ostream&, const PolygonOut&);
//-------------------------------------------------------------------------------
#endif
