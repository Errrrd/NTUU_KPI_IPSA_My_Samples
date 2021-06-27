#include <iostream>

#include "helper.h"
#include "coordinates.h"
#include "circle.h"
#include "color.h"
#include "polygon.h"
#include "image.h"

int Image::imageCount = 0;

Image::Image() {
    
    this->circles = nullptr;
    this->countOfCircle = 0;
    imageCount++;
    numOfImage = imageCount;
}

Image::Image(Circle& cr) {
    this->circles = new Circle*[1];
    this->circles[0] = &cr;
    this->countOfCircle = 1;
}

Circle& Image::operator[](const int i) {
    return getCircle(i);
}

int Image::getSize() const {
    return this->countOfCircle;
}

Image& Image::addCircle(Circle& cr) {
    Circle** oldCircles = this->circles;
    bool bNotAdded = true;
    
    this->circles = new Circle*[this->countOfCircle + 1];
    for (int i=0; i < this->countOfCircle; i++) {
        if (oldCircles[i] == &cr) { bNotAdded = false; }
        this->circles[i] = oldCircles[i];
    }
    if (bNotAdded) {
        this->circles[this->countOfCircle] = &cr;
        this->countOfCircle++;
    } else {
        std::cout << "Warning! Item " << &cr << " aka " << cr << " already added!!!\n";
    }
    
    if (oldCircles != nullptr ) {
        delete[] oldCircles;
    }

    return *this;
}

Image& Image::deleteCircle(const int idx) {
    if (0 == this->countOfCircle || idx >= this->countOfCircle || idx < 0) {
        return *this;
    }
    else if (1 == this->countOfCircle && 0 == idx) {
        delete[] this->circles;
        this->circles = nullptr;
    } else if (1 < this->countOfCircle) {
        Circle** oldCircles = this->circles;
        
        this->countOfCircle--;
        this->circles = new Circle*[this->countOfCircle];
        for (int i=0, j=0; i <= this->countOfCircle; i++) {
            if( i != idx ) { 
                this->circles[j] = oldCircles[i];
                j++;
            }
        }
        if (oldCircles != nullptr ) { delete[] oldCircles; }
    }
    return *this;
}

Circle& Image::getCircle(const int i) {
    Circle* cr = nullptr;
    
    if ( i < this->countOfCircle ) {
        cr = this->circles[i];
    }
    
    return *cr;
}

void Image::printShort() const {
    for (int i = 0; i < this->countOfCircle; i++) {
        //this->circles[i]->printShort();
        this->circles[i]->printShort();
    }
}

void Image::print() const {
    for (int i = 0; i < this->countOfCircle; i++) {
        //this->circles[i]->printShort();
        this->circles[i]->print();
    }
}

Image::~Image() {
    --imageCount;
    if (this->circles != nullptr ) {
        delete[] this->circles;
    }
    if(bDebug) {
        std::cout << "Delete object Image N"<< numOfImage << '\n';
        if (imageCount == 0) { std::cout << "All objects of class Image was deleted\n"; }
    }
}


std::ostream& operator<<(std::ostream& out, const Image& img) {
    int last = img.countOfCircle - 1;
    out << "Img: N " << img.numOfImage << ", figures:" << img.countOfCircle << std::endl;
    if (img.circles != nullptr) {
        for (int i = 0; i < last; i++) {
            out << *(img.circles[i]) << '\n';
        }
        out << *(img.circles[last]) << std::endl;
    }
    return out;
}