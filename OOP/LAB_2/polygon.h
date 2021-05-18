#ifndef POLYGON_H
#define POLYGON_H

class Coordinates;
class Circle;
class Color;

//-------------------------------------------------------------------------------
class PolygonIn : public Circle {
    friend std::ostream& operator<<(std::ostream&, const PolygonIn&);
    
    private:
        static int polygonCount;
        
        int numOfPolygon;
        int sideCount;
        
    public:
        PolygonIn();
        PolygonIn(const Coordinates& centre, double r=1, int sides = 3);
        PolygonIn(double x, double y, double r=1, int sides = 3);
        PolygonIn(const PolygonIn& other);
        
        PolygonIn& operator=(PolygonIn& other);

        PolygonIn& setSideCount(int sides);

        virtual int getSideCount() const;
        
        //void visPolygonIn() const;
        
        void printPolygonInShort() const;
        void printPolygonIn() const;
        
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
        
    public:
        PolygonOut();
        PolygonOut(const Coordinates& centre, double r=1, int sides=3, const Color& color={1.0f,1.0f,1.0f});
        PolygonOut(double x, double y, double r=1, int sides=3, const Color& color={1.0f,1.0f,1.0f});
        PolygonOut(const PolygonOut& other);
        
        PolygonOut& operator=(PolygonOut& other);
        
        PolygonOut& setSideCount(int sides);
        PolygonOut& setColor(const Color& newColor);
        
        virtual int getSideCount() const;
        virtual const Color& getColor() const;
        
        
        
        //void visPolygonOut() const;
        
        void printPolygonOutShort() const;
        void printPolygonOut() const;
        
        virtual ~PolygonOut();
};

std::ostream& operator<<(std::ostream&, const PolygonOut&);
//-------------------------------------------------------------------------------
#endif
