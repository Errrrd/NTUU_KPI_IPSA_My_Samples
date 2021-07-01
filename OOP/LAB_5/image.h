#ifndef IMAGE_H
#define IMAGE_H

class Coordinates;
class Circle;
class Color;
class PolygonIn;
class PolygonOut;

class Image {
    friend std::ostream& operator<<(std::ostream&, const Image&);
    private:
        static int imageCount;
        int numOfImage;
        int countOfCircle;
        Circle** circles;
        
    public:
        Image();
        Image(Circle& cr);
        
        Circle& operator[](const int i);
        int getSize() const;
        Image& addCircle(Circle& cr);
        Image& deleteCircle(const int idx);
        Circle& getCircle(const int i);

        virtual void printShort() const;
        virtual void print() const;
        
        virtual ~Image();
};

std::ostream& operator<<(std::ostream&, const Image&);

#endif
