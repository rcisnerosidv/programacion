#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print(const vector<string> & vec, const string message) {
	cout << message << ":" << endl;
	for (int i = 0; i < int(vec.size()); ++i) {
		if (i > 0) cout << " ";
		cout << vec[i];
	}
	cout << endl;
}

void reverse_1(const vector<string> & in, vector<string> & out) {
	int n = int(in.size());
	while (n > 0) {
		--n;
		out.push_back(in[n]);
	}
}

void reverse_2(vector<string> & vec) {
	int n = int(vec.size());
	for (int i = 0; i < n / 2; ++i) {
		string k = vec[i];
		vec[i] = vec[n - 1 - i];
		vec[n - 1 - i] = k;
	}
}

int main() {
	cout << "Input a vector of strings" << endl;
	vector<string> v;
	while (true) {
		string n;
		cin >> n;
		if (!cin) break;
		v.push_back(n);
	}
	vector<string> w;
	reverse_1(v, w);
	print(v, "Input vector");
	print(w, "Output vector");
	reverse_2(v);
	print(v, "Reversed vector");
	system("pause");
	return 0;
}