#include <iostream>
#include <math.h>

#include "Complex.h"
using namespace std;

int main() {
	Complex a;
	Complex b;
	cin >> a >> b;
	Complex c;
	c = a + b;
	cout << c.r_ << c.phi_ << endl;

};