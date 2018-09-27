#include <iostream>


using namespace std;

int main() {

	cout << INT_MAX << endl;
	unsigned long long int num{ 1 }, sum{ 0 };
	int square{ 0 }, numInt{ 0 };

	for (int i = 0; i < 64; ++i) {

		num *= 2;
		numInt += num;
		sum += num;
		++square;

	}
	cout << "Total rice: " << sum << endl;
	cout << "Total rice (Using int): " << numInt << endl;
	cout << "Squares: " << square << endl;
	num = 1, sum = 0, square = 0;

	while (num <= INT_MAX) {

		num *= 2;
		sum += num;
		++square;
	}

	cout << "Largest number of squares in an Int: " << square << endl;
	num = 1, sum = 0, square = 0;
	double numDouble{ 0 };

	for (int i = 0; i < 64; ++i) {

		num *= 2;
		numDouble += num;
		sum += num;
		++square;

	}


	cout << "Total rice: " << num << endl;
	cout << "Total rice (Using double): " << numDouble << endl;
	cout << "Squares: " << square << endl;
	square = 0;
	numDouble = 1;

	while (numDouble <= DBL_MAX) {

		numDouble *= 2;
		sum += num;
		++square;

	}

	cout << "Largest number of squares in a Double: " << square << endl;
	system("pause");
	return 0;
}