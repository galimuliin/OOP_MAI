#include "rectangle.h"

#include <iostream>
#include <cmath>

Rectangle::Rectangle()
    : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), p4(0.0, 0.0) {  // можно, но длиннее p1(Point(0.0, 0.0))
  std::cout << "Default rectangle created" << std::endl;
}

Rectangle::Rectangle(Point a, Point b, Point c, Point d)
    : p1(a), p2(b), p3(c), p4(d) {
  std::cout << "Rectangle created by parameters" << std::endl;
}

Rectangle::Rectangle(std::istream &is) {
  is >> p1 >> p2 >> p3 >> p4;
}

Rectangle::Rectangle(const Rectangle& other)
    : Rectangle(other.p1, other.p2, other.p3, other.p4) {
  std::cout << "Rectangle copy created" << std::endl;
}

Point Rectangle::Center() const {
    Point result;
    result = p1 + p2 + p3 + p4;
    result = result / 4;
    return result;
}

double Rectangle::Area() {
    double p12 = p1.dist(p2);
    double p23 = p2.dist(p3);
    double p = p12 * p23;
    return p;
}

void Rectangle::Print(std::ostream& os) {
    os << "Rectangle: ";
    os << p1 << ", ";
    os << p2 << ", ";
    os << p3 << ", ";
    os << p4 << std::endl;
}

Rectangle::~Rectangle() {
  //std::cout << "Rectangle deleted" << std::endl;
}