#include "Complex.h"

#include <cmath>

const double PI = 3.1415926535;

Complex::Complex() : r_(0.0), phi_(0.0) {} // ������������� �� ��������� � ������ ���������

Complex::Complex(double x, double y) : r_(x), phi_(y) {} // ������������� � ��������� ������������

Complex::Complex(std::istream& is) {
    is >> r_ >> phi_;
}

std::istream& operator>>(std::istream& is, Complex& p) {
    is >> p.r_ >> p.phi_;
    return is;
}

std::ostream& operator<<(std::ostream& os, Complex& p) {
    os << "(" << p.r_ << ", " << p.phi_ << ")";
    return os;
}

Complex operator+ (Complex& p1, Complex& p2)
{
    Complex res;
    res.r_ = pow(p1.r_ * cos(p1.phi_) + p2.r_ * cos(p2.phi_), 2);
    res.r_ = res.r_ + pow(p1.r_ * sin(p1.phi_) + p2.r_ * sin(p2.phi_), 2);
    res.r_ = sqrt(res.r_);
    res.phi_ = asin((p1.r_ * sin(p1.phi_) + p2.r_ * sin(p2.phi_)) / res.r_);
    return res;
}

Complex operator- (Complex& p1, Complex& p2)
{
    Complex copy_obj;
    copy_obj.r_ = p2.r_;
    copy_obj.phi_ = p2.phi_ + PI;
    Complex res;
    res.r_ = pow(p1.r_ * cos(p1.phi_) + copy_obj.r_ * cos(copy_obj.phi_), 2);
    res.r_ = res.r_ + pow(p1.r_ * sin(p1.phi_) + copy_obj.r_ * sin(copy_obj.phi_), 2);
    res.r_ = sqrt(res.r_);
    res.phi_ = PI + asin((p1.r_ * sin(p1.phi_) + copy_obj.r_ * sin(copy_obj.phi_)) / res.r_);
    return res;
}

Complex operator* (Complex& p1, Complex& p2)
{
    Complex res;
    res.r_ = p1.r_ * p2.r_;
    res.phi_ = p1.phi_ + p2.phi_;
    return res;
}

Complex operator/ (Complex& p1, Complex& p2)
{
    Complex res;
    res.r_ = p1.r_ / p2.r_;
    res.phi_ = p1.phi_ - p2.phi_;
    return res;
}

bool operator== (const Complex& p1, const Complex& p2)
{
    bool eq = p1.r_ == p2.r_ && p1.phi_ == p2.phi_;
    if (!eq) return false;
    return true;
}