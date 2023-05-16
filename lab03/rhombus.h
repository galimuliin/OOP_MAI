#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <iostream>

#include "figure.h"

class Rhombus : public Figure {

	public:
		Rhombus();
		Rhombus(Point a, Point b, Point c, Point d);
		Rhombus(std::istream &is);
		Rhombus(const Rhombus& other);
		
		Point Center() const;
		double Area();
		void Print(std::ostream& os);

		virtual ~Rhombus();

	private:
		Point p1;
		Point p2;
		Point p3;
		Point p4;
};

#endif // RHOMBUS_H