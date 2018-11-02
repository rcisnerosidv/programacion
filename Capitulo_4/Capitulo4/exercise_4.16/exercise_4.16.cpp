#include <iostream>
#include "Includes.h"

int main() {
	vector<string> table;
	string a = "";
	cout << "Enter a set of strings to know the max, min and mode: " << endl;


	while (cin >> a) table.push_back(a);
	sort(table.begin(), table.end());
	string mode = "", temp;
	int max{ 0 }, first{ 0 }, curr{ 0 };
	while (curr < table.size()) {
		first = curr;
		temp = table[curr];
		while (curr < table.size() && table[curr] == temp)
			++curr;
		if (curr - first > max) {
			mode = temp;
			max = curr - first;
		}
	}


	cout << "The minimum is " << table[0] << endl;
	cout << "The mode is " << mode << endl;
	cout << "The maximum is " << table[table.size() - 1] << endl;

	system("pause");
	return 0;
}
