#include <iostream>

using namespace std;


int main() {
	
	cout << "Quadratic equation: ax2 + bx + c" << endl;
	cout << "Enter the values for a, b and c separated by a space: " << endl;
	double a{ 0 }, b{ 0 }, c{ 0 };
	cin >> a >> b >> c;

	double x1{ 0 }, x2{ 0 };
	double squareR = ((b * b) - (4 * a*c));

	if (((b * b) - (4 * a*c)) < 0) {

		cout << "Error, negative square root. " << endl;

	}
	else if (a == 0) {

		cout << "Error, cant divide by zero. " << endl;

	}
	else {
		x1 = ((-1 * b) + (sqrt(squareR))) / (2 * a);
		x2 = ((-1 * b) - (sqrt(squareR))) / (2 * a);

		cout << "x1: " << x1 << endl;
		cout << "x2: " << x2 << endl;
	}


	system("pause");
	return 0;
}