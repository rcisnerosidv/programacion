#include <iostream>
#include "Includes.h"

using namespace std;

int main() {
	try {

		cout << "How many numbers are there?\n";
		int count{ -1 };
		

		if (!(cin >> count) || count <= 0)
			error("Bad count");
		vector<double> values(count);

		for (int i = 0; i < count; ++i)
			if (!(cin >> values[i]))
				error("Bad value or too few values");

		int used{ 0 };
		double total{ 0 };
		cout << "How many do you want to sum?\n";

		if (!(cin >> used) || used < 1 || used > count)
			error("Bad number to sum");
		vector<double> diffs(used - 1);

		for (int i = 0; i < used; ++i) {
			total += values[i];
			if (i > 0) diffs[i - 1] = values[i] - values[i - 1];
		}


		cout << "The total is " << total << endl;
		cout << "The differences are:\n";

		for (int i = 0; i < used - 1; ++i) cout << diffs[i] << endl;
	
	}
	catch (exception &e) {
		cerr << "Error: " << e.what() << "\n";
	
		return 1;
	}
	catch (...) {
		error("Unexpected exception");

		return 2;
	}


	system("pause");
	return 0;
}