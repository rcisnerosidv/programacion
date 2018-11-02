#include <iostream>

using namespace std;


int main() {
	
	cout << "Enter 2 numbers separated by a space, followed by the operation (+, -, *, /): " << endl;
	double num1{ 0 }, num2{ 0 };
	char operation = 0;
	cin >> num1 >> num2 >> operation;

	switch (operation) {

	case '+':

		cout << "The result is: " << num1 + num2 << endl;
		break;

	case '-':

		cout << "The result is: " << num1 - num2 << endl;
		break;

	case '*':

		cout << "The result is: " << num1 * num2 << endl;
		break;

	case '/':

		if (num2 != 0) {

			cout << "The result is: " << num1 / num2 << endl;

		}
		else {
			cout << "Cannot divide by zero. " << endl;
		}
		
	}


	system("pause");
	return 0;
}