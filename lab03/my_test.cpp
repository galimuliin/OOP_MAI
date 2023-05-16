#include <iostream>
#include <vector>

#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "point.h"

using namespace std;


int main() {
    vector<Figure*> figures;

    cout << "Enter rhombus vertices' coordinates: "; // -2 0 0 2 2 0 0 -2
    Rhombus t1(cin);
    Point center = t1.Center();
    cout << "Center of rhombus: " << center << endl;
    t1.Print(cout);
    cout << "Area:" << t1.Area() << endl;
    figures.push_back(&t1);

    cout << "Enter rectangle vertices' coordinates: "; // 0 0 5 0 5 -2 0 -2
    Rectangle r1(cin);
    center = r1.Center();
    cout << "Center of rectangle: " << center << endl;
    r1.Print(cout);
    cout << "Area:" << r1.Area() << endl;
    figures.push_back(&r1);

    cout << "Enter trapezoid vertices' coordinates: "; // -1 0 -2 1 2 1 1 0
    Trapezoid s1(cin);
    center = s1.Center();
    cout << "Center of trapezoid: " << center << endl;
    s1.Print(cout);
    cout << "Area:" << s1.Area() << endl;
    figures.push_back(&s1);

    cout << "Enter rectangle vertices' coordinates: "; // -2.5 3 2.5 3 2.5 -3 -2.5 -3
    Rectangle r2(cin);
    center = r2.Center();
    cout << "Center of rectangle: " << center << endl;
    r2.Print(cout);
    cout << "Area:" << r2.Area() << endl;
    figures.push_back(&r2);

    cout << "\nFigures in container:" << endl;
    for (int i = 0; i < figures.size(); i++)
    {
      figures[i]->Print(cout);
    }


    return 0;
}