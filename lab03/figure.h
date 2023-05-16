#ifndef FIGURE_H
#define FIGURE_H

#include "point.h"

class Figure {
    public:
        virtual Point Center() const = 0;
        virtual void Print(std::ostream& os) = 0;
        virtual double Area() = 0;
        double calcTriangleArea(Point p1, Point p2, Point p3);
        virtual ~Figure() {};
};

#endif // FIGURE_H