#include <iostream>
#include "Includes.h"

using namespace std;


int main() {
	try {
		int count{ -1 };
		cout << "How many numbers are there?\n";
		if (!(cin >> count) || count <= 0)
			error("Bad count");
		vector<int> values(count);
		for (int i = 0; i < count; ++i)
			if (!(cin >> values[i]))
				error("Bad value or too few values");
		int used{ -1 }, total{ 0 };
		cout << "How many do you want to sum?\n";
		if (!(cin >> used) || used < 0 || used > count)
			error("Bad number to sum");
		for (int i = 0; i < used; ++i) total += values[i];
		cout << "The total is " << total << endl;
	
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