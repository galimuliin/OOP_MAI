#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <iostream>

#include "figure.h"

class Rectangle : public Figure {

    public:
        Rectangle();  // инициализация по умолчанию без параметров
        Rectangle(Point a, Point b, Point c, Point d); // инициализация c заданными координатами
        Rectangle(std::istream &is);
        Rectangle(const Rectangle& other);

        Point Center() const;
        double Area();
        void Print(std::ostream& os);

        virtual ~Rectangle();

    private:
        Point p1;
        Point p2;
        Point p3;
        Point p4;
};

#endif // RECTANGLE_H