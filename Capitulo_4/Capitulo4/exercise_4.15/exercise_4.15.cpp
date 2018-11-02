#include <iostream>
#include "Includes.h"


using namespace std;

int main() {
	vector<int> table;
	int a{ 0 };
	cout << "Enter a set of positive integers to know de mode: " << endl;
	while (cin >> a) table.push_back(a);
	sort(table.begin(), table.end());
	if (table[0] <= 0)
		cout << "Only postive integers can be handled\n";
	else {
		int mode{ 0 }, max{ 0 }, first{ 0 }, curr = { 0 }, temp{ 0 };
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
		cout << "The mode is " << mode << endl;
	}

	system("pause");
	return 0;
}