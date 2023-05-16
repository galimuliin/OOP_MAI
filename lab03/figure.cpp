#include "figure.h"

#include <cmath>

double Figure::calcTriangleArea(Point p1, Point p2, Point p3)
{
	return abs((p1.x_-p3.x_)*(p2.y_-p3.y_)-(p2.x_-p3.x_)*(p1.y_-p3.y_))/2.0;
}