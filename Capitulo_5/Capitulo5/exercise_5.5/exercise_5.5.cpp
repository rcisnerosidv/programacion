#include <iostream>
#include "Includes.h"

using namespace std;

const double czero{ -273.15 }, fzero = (9 * czero) / 5 + 32;

double ctof(double c) {
	if (c < czero) error("Colder than absolute zero\n");
	return (9 * c) / 5 + 32;
}

double ftoc(double f) {
	if (f < fzero) error("Colder than absolute zero\n");
	return (f - 32) * 5 / 9;
}

int main() {
	cout << "Enter a temperature and unit separated by a space to convert Celsius to Kelvin, or viceversa:  " << endl;
	double a{ 0 };
	char s = 0;
	cin >> a >> s;
	if (s == 'c')
		cout << a << " Celsius is " << ctof(a) << " Fahrenheit\n";
	else if (s == 'f')
		cout << a << " Fahrenheit is " << ftoc(a) << " Celsius\n";
	else
		error("Unknown temperature scale\n");


	system("pause");
	return 0;
}