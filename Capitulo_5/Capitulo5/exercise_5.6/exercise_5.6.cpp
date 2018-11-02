#include <iostream>

using namespace std;


int main() {
	double a{ 0 }, b{ 0 }, c{ 0 };
	cout << "Enter 3 numbers separated by a space\n";
	while (cin >> a >> b >> c) {
		if (a == 0.0)
			cout << "First number can´t be zero\n";
		else {
			cout << "The equation is " << a << ".x^2+" <<
				b << ".x+" << c << endl;
			double d = b * b - 4.0*a*c;
			if (d < 0.0)
				cout << "There are no real solutions\n";
			else {
				double p = (-b - sqrt(d)) / (2.0*a),
					q = (-b + sqrt(d)) / (2.0*a);
				cout << "x1: " << p << endl;
				cout << "x2: " << q << endl;
				cout << "The equation is x^2+" << -(p + q) <<
					".x+" << p * q << endl;
			}
		}
	}

	system("pause");
	return 0;
}