#include <iostream>


using namespace std;


int main() {

	cout << "Pick a number between 1 and 100. " << endl;
	int number{ 0 };
	cin >> number;
	bool cond = false;
	int guess{ 50 }, min{ 1 }, max{ 100 };
	while (cond == false) {

		cout << "Is your number: " << guess << "? (y for yes, n for no)" << endl;
		char option{ 0 };
		cin >> option;

		switch (option) {

		case 'y':
			cout << "I won!!" << endl;
			cond = true;
			break;

		case 'n':
			cout << "Is it higher or lower? (h for higher, l for lower " << endl;
			char guess_option;
			cin >> guess_option;
			switch (guess_option) {

			case 'h':
				min = guess;
				guess = (min + max) / 2;
				break;

			case 'l':
				max = guess;
				guess = (min + max) / 2;
			}



		}
	}


	system("pause");
	return 0;
}

