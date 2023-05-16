#include "rhombus.h"

#include <iostream>
#include <cmath>

Rhombus::Rhombus()
    : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), p4(0.0, 0.0) {
  std::cout << "Default Rhombus created" << std::endl;
}

Rhombus::Rhombus(Point a, Point b, Point c, Point d)
    : p1(a), p2(b), p3(c), p4(d) {
  std::cout << "Rhombus created by parameters" << std::endl;
}

Rhombus::Rhombus(std::istream &is) {
  is >> p1 >> p2 >> p3 >> p4;
}

Point Rhombus::Center() const {
    Point result;
    result = p1 + p2 + p3 + p4;
    result = result / 4;
    return result;
}

double Rhombus::Area() {
    double p12 = p1.dist(p3);
    double p23 = p2.dist(p4);
    double p = p12 * p23 / 2;
    return p;
}

void Rhombus::Print(std::ostream& os) {
    os << "Rhombus: ";
    os << p1 << ", ";
    os << p2 << ", ";
    os << p3 << ", ";
    os << p4 << std::endl;
}

Rhombus::~Rhombus() {
  //std::cout << "Rectangle deleted" << std::endl;
}