#ifndef POINT_H
#define POINT_H

#include <iostream>

class Point {
    // дружественные методы ввода/вывода
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, Point& p);
    friend Point operator+ (Point p1, Point p2);
    friend Point& operator/ (Point& p1, int num);

    public:
        Point(); // инициализация по умолчанию без параметров
        Point(double x, double y); // инициализация c заданными координатами
        Point(std::istream &is);

        double dist(Point& other);
        double x_;
        double y_;
};

#endif // POINT_H