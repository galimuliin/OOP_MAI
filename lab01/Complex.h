#pragma once

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

class Complex {
    // ������������� ������ �����/������
    friend std::istream& operator>>(std::istream& is, Complex& p);
    friend std::ostream& operator<<(std::ostream& os, Complex& p);
    friend Complex operator+ (Complex& p1, Complex& p2);
    friend Complex operator- (Complex& p1, Complex& p2);
    friend Complex operator* (Complex& p1, Complex& p2);
    friend Complex operator/ (Complex& p1, Complex& p2);
    friend Complex operator== (Complex& p1, Complex& p2);

public:
    Complex(); // ������������� �� ��������� ��� ����������
    Complex(double r, double phi); // ������������� c ��������� ������������
    Complex(std::istream& is);
    double r_;
    double phi_;
};

#endif // COMPLEX_H