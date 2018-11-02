#include <iostream>

using namespace std;

int square(int num) {
	int sqr{ 0 };
	for (int i = 0; i < num; ++i) {
		sqr += num;
	}

	return sqr;
}

int main() {
	
	cout << "Enter a number to know the square: " << endl;
	int num{ 0 };
	cin >> num;

	cout << "Square: " << square(num) << endl;

	system("pause");
	return 0;
}