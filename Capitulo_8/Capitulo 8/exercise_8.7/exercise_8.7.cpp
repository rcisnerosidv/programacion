#include "Includes.h"

void sort(vector<string> & names, vector<double> & ages) {
	int n = int(names.size()), k = n;
	string s;
	double d;
	while (k > 1) {
		k = k / 3 + 1;
		for (int i = k; i < n; ++i) {
			int j = i;
			while (j >= k && names[j - k] > names[j]) {
				s = names[j];
				d = ages[j];
				names[j] = names[j - k];
				ages[j] = ages[j - k];
				names[j - k] = s;
				ages[j - k] = d;
				j -= k;
			}
		}
	}
}

int main() {
	vector<string> names;
	string x;
	cout << "Type a list of names, separated by spaces, and finish by" <<
		endl << "typing the 'name' EOF" << endl;
	while (true) {
		cin >> x;
		if (!cin) error("Unexpected end of file or error on stdin");
		if (x == "EOF") break;
		names.push_back(x);
	}
	vector<double> ages;
	for (int i = 0; i < int(names.size()); ++i) {
		double y;
		cout << "What is " << names[i] << "'s age?" << endl;
		cin >> y;
		ages.push_back(y);
	}
	sort(names, ages);
	for (int i = 0; i < int(names.size()); ++i)
		cout << names[i] << " is " << ages[i] << endl;
}