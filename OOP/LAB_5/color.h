#ifndef COLOR_H
#define COLOR_H

class Color {
    friend std::ostream& operator<<(std::ostream&, const Color&);
    private:
        static int colorCount;
        int numOfColors;
    public:
        float r,g,b;
        Color();
        Color(float r, float g=1.0f, float b=1.0f);
        Color(const Color& other);
        
        Color& operator=(const Color& other);
        
        void printColor() const;
        
        virtual ~Color();
};

std::ostream& operator<<(std::ostream&, const Color&);

#endif
