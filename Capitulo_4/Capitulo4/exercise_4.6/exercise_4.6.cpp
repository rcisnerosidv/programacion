#include <iostream>
#include <vector>
#include <string>

using namespace std;

int convert(string value1) {

	vector<string> valuesStr = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> valuesInt = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	int num{ 0 };
	bool check = false;
	for (int i = 0; i < valuesStr.size(); i++) {
		if (value1 == valuesStr[i]) {

			num = stoi(valuesInt[i]);
			check = true;
		}
		else if (value1 == valuesInt[i]) {

			num = stoi(valuesInt[i]);
			check = true;
		}
	}
	if (check == false) {

		cout << "Not a number i know" << endl;

	}

	return num;

}


int main() {
	
	
	cout << "Enter two numbers separated by a space and a operator(+, -, *, /): " << endl;
	string val1 = "", val2 = "";
	char operation = 0;
	cin >> val1 >> val2 >> operation;

	int num1 = convert(val1);
	int num2 = convert(val2);

	switch (operation) {

	case '+':

		cout << "The result of " << num1 << " + " << num2 << " is: " << num1 + num2 << endl;
		break;
		
	case '-':

		cout << "The result of " << num1 << " - " << num2 << " is: " << num1 - num2 << endl;
		break;

	case '*':

		cout << "The result of " << num1 << " * " << num2 << " is: " << num1 * num2 << endl;
		break;

	case '/':

		if (num2 == 0) {

			cout << "Can't divide by zero. " << endl;

		}
		else {

			cout << "The result of " << num1 << " / " << num2 << " is: " << num1 / num2 << endl;
		}
		break;
	}
	
	system("pause");
	return 0;
}

