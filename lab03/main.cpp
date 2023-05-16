#include <iostream>
#include <vector>

#include "rhombus.h"
#include "rectangle.h"
#include "trapezoid.h"
#include "point.h"

using namespace std;

int main() {
    vector<Figure*> figures;
    for (;;) {
        int command;
        cin >> command;
        if (command == 0) {
            break;
        } else if (command == 1) {
            int figure_type;
            cin >> figure_type;
            Figure* ptr;
            if (figure_type == 0) {
                cout << "Enter rhombus 'vertices' coordinates: ";
                ptr = new Rhombus(cin);
            } else if (figure_type == 1) {
                cout << "Enter rectangle 'vertices' coordinates: ";
                ptr = new Rectangle(cin);
            }  else {
                cout << "Enter trapezoid 'vertices' coordinates: ";
	            ptr = new Trapezoid(cin);
            }
            figures.push_back(ptr);
        } else if (command == 2) {
            cout << "Centers:\n";
            for (Figure* ptr: figures) {
                Point p = ptr->Center();
                cout << p << "\n" << endl;
            }
        } else if (command == 3) {
            cout << "Areas:\n";
            for (Figure* ptr: figures) {
                cout << ptr->Area() << endl << endl;
            }
        } else if (command == 4) {
            cout << "Figures:\n";
            for (Figure* ptr: figures) {
                ptr->Print(cout);
                cout << endl;
            }
        }
    }
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
}