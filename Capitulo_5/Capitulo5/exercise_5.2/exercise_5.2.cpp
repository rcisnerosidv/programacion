#include <iostream>
#include "Includes.h"

using namespace std;


const double zero{ -273.15 };

double ctok(double c) {
	double k = c - zero;
	return k;
}

int main() {

	cout << "Enter a temperature in Celsius to convert it to Kelvin: " << endl;
	double c{ 0 };
	cin >> c;
	if (c < zero) error("Colder than absolute zero\n");
	double k = ctok(c);
	cout << k << endl;


	system("pause");
	return 0;
}