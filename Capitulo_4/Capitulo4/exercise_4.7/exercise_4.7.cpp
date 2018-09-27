#include <iostream>

using namespace std;

int main() {

	unsigned long long int num{ 1 }, suma{ 0 };
	int square{ 0 };

	for(int i = 0; i < 64 ; ++i){
	
		num *= 2;
		suma += num;
		++square;
		
	}

	cout << "Total rice: " << suma << endl;
	cout << "Squares: " << square << endl;
	num = 1, suma = 0, square = 0;

	while (num <= 1000) {

		num *= 2;
		suma += num;
		++square;

	}
	
	cout << "How many squares for 1000 rice: " << square << endl;
	num = 1, suma = 0, square = 0;

	while (num <= 1000000) {

		num *= 2;
		suma += num;
		++square;

	}

	cout << "How many squares for 1,000,000 rice: " << square << endl;
	num = 1, suma = 0, square = 0;

	while (num <= 1000000000) {

		num *= 2;
		suma += num;
		++square;

	}

	cout << "How many squares for 1,000,000,000 rice: " << square << endl;

	system("pause");
	return 0;
}