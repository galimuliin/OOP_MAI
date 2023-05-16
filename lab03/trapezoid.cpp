#include "trapezoid.h"

#include <iostream>
#include <cmath>

Trapezoid::Trapezoid()
    : p1(0.0, 0.0), p2(0.0, 0.0), p3(0.0, 0.0), p4(0.0, 0.0) {
  std::cout << "Default trapezoid created" << std::endl;
}

Trapezoid::Trapezoid(Point a, Point b, Point c, Point d)
    : p1(a), p2(b), p3(c), p4(d) {
  std::cout << "Trapezoid created by parameters" << std::endl;
}

Trapezoid::Trapezoid(std::istream &is) {
  is >> p1 >> p2 >> p3 >> p4;
}

Trapezoid::Trapezoid(const Trapezoid& other)
    : Trapezoid(other.p1, other.p2, other.p3, other.p4) {
  std::cout << "Trapezoid copy created" << std::endl;
}

Point Trapezoid::Center() const {
    Point result;
    result = p1 + p2 + p3 + p4;
    result = result / 4;
    return result;
}

double Trapezoid::Area() {
    return calcTriangleArea(p1,p2,p3)+calcTriangleArea(p3,p4,p1);
}

void Trapezoid::Print(std::ostream& os) {
    os << "Trapezoid: ";
    os << p1 << ", ";
    os << p2 << ", ";
    os << p3 << ", ";
    os << p4 << std::endl;
}

Trapezoid::~Trapezoid() {
  //std::cout << "Rectangle deleted" << std::endl;
}