#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include <iostream>
#include "figure.h"

class Trapezoid: public Figure
{
	public:
		Trapezoid();
		Trapezoid(Point p1, Point p2, Point p3, Point p4);
		Trapezoid(std::istream &is);
		Trapezoid(const Trapezoid& other);
		
		Point Center() const;
		double Area();
		void Print(std::ostream& os);
		
		virtual ~Trapezoid();

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
};

#endif // TRAPEZOID_H