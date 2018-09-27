#include <iostream>
#include "Includes.h"

using namespace std;

const double zero{ -273.15 };

double ctok(double c) {
	if (c < zero) error("Colder than absolute zero\n");
	double k = c - zero;
	return k;
}

double ktoc(double k) {
	if (k < 0.0) error("Colder than absolute zero\n");
	double c = k + zero;
	return c;
}

int main() {

	cout << "Enter a temperature in Celsius to convert it to Kelvin: " << endl;
	double a{ 0 };
	char s = 0;
	cin >> a >> s;
	if (s == 'c')
		cout << a << " Celsius is " << ctok(a) << " Kelvin\n";
	else if (s == 'k')
		cout << a << " Kelvin is " << ktoc(a) << " Celsius\n";
	else
		error("Unknown temperature scale\n");

	system("pause");
	return 0
}