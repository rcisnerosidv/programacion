#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {

	vector<string> valuesStr = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };
	vector<string> valuesInt = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

	cout << "Enter a digit to convert it to string or viceversa. " << endl;
	string value = "";

	while (cin >> value) {
		bool check = false;
		for (int i = 0; i < valuesStr.size(); i++) {
			if (value == valuesStr[i]) {

				cout << valuesInt[i] << endl;
				check = true;
			}
			else if (value == valuesInt[i]) {

				cout << valuesStr[i] << endl;
				check = true;
			}

		}

		if (check == false) {

			cout << "Not a number i know. " << endl;

		}

	}

	system("pause");
	return 0;
}
