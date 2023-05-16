#include "point.h"

#include <cmath>

Point::Point() : x_(0.0), y_(0.0) {} // инициализация по умолчанию в начале координат

Point::Point(double x, double y) : x_(x), y_(y) {} // инициализация с заданными координатами

Point::Point(std::istream &is) {
    is >> x_ >> y_;
}

double Point::dist(Point& other) {
    double dx = (other.x_ - x_);
    double dy = (other.y_ - y_);
    return std::sqrt(dx*dx + dy*dy);
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x_ >> p.y_;
    return is;
}

std::ostream& operator<<(std::ostream& os, Point& p) {
    os << "(" << p.x_ << ", " << p.y_ << ")";
    return os;
}

Point operator+ (Point p1, Point p2) {
	Point p;
	p.x_ = p1.x_ + p2.x_;
	p.y_ = p1.y_ + p2.y_;
	return p;
}

Point& operator/ (Point& p, int num) {
	p.x_ = p.x_ / num;
	p.y_ = p.y_ / num;
	return p;
}