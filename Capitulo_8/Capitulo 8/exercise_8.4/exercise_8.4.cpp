#include "Includes.h"

using namespace std;

void print(const vector<int> & vec, const string message) {
	cout << message << ":" << endl;
	for (int i = 0; i < int(vec.size()); ++i) {
		if (i > 0) cout << " ";
		cout << vec[i];
	}
	cout << endl;
}

void fibonacci(int x, int y, vector<int> & v, int n) {
	if (x < 0 || y < 1 || y < x || n < 2)
		error("Invalid arguments to fibonacci");
	v.push_back(x);
	v.push_back(y);
	for (int i = 2; i < n; ++i) {
		int k = v[i - 2] + v[i - 1];
		if (k < v[i - 1]) break;
		v.push_back(k);
	}
}

int main() {
	cout << "Input two starting values and the count" << endl;
	int x, y, n;
	cin >> x >> y >> n;
	vector<int> v;
	fibonacci(x, y, v, n);
	if (int(v.size()) < n)
		cout << "The limit was reached after " << v.size() <<
		" values at " << v[v.size() - 1] << endl;
	else
		print(v, "Fibonacci values");
}