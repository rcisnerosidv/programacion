#include <iostream>

using namespace std;


double ctok(double c) {
	double k = c + 273.15;
	return k;
}

int main() {
	double c{ 0 };
	cout << "Enter a temperature in Celsius to convert it to Kelvin: " << endl;
	cin >> c;
	double k = ctok(c);
	cout <<"Kelvin: " << k << endl;


	system("pause");
	return 0;
}