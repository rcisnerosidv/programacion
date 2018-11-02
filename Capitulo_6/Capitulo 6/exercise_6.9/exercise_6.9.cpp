#include "Includes.h"

int main() {
	int n, m;
	char c;
	cout << "How many objects are there in all?\n";
	if (!(cin >> n) || n < 0 || n > 100)
		error("The number of objects must be between 0 and 100 inclusive");
	cout << "How many objects are there in the selection?\n";
	if (!(cin >> m) || m < 0 || m > n)
		error("The number of objects must be between 0 and the total inclusive");
	cout << "Do you want combinations or permutations?  Type 'p' or 'c'.\n";
	if (!(cin >> c) || (c != 'c' && c != 'p'))
		error("Only the letters 'c' or 'p' are allowed");
	double val = 1.0;
	if (c == 'c') {
		for (int i = 1; i <= m; ++i) val *= double(n - m + i) / i;
		cout << "The number of combinations is " << val << endl;
	}
	else {
		for (int i = 1; i <= m; ++i) val *= double(n - m + i);
		cout << "The number of permutations is " << val << endl;
	}

	return 0;
}