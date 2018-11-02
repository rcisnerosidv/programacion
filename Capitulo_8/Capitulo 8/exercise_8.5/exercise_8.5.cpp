#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print(const vector<int> & vec, const string message) {
	cout << message << ":" << endl;
	for (int i = 0; i < int(vec.size()); ++i) {
		if (i > 0) cout << " ";
		cout << vec[i];
	}
	cout << endl;
}

void reverse_1(const vector<int> & in, vector<int> & out) {
	int n = int(in.size());
	while (n > 0) {
		--n;
		out.push_back(in[n]);
	}
}

void reverse_2(vector<int> & vec) {
	int n = int(vec.size());
	for (int i = 0; i < n / 2; ++i) {
		int k = vec[i];
		vec[i] = vec[n - 1 - i];
		vec[n - 1 - i] = k;
	}
}

int main() {
	cout << "Input a vector of integers" << endl;
	vector<int> v;
	while (true) {
		int n;
		cin >> n;
		if (!cin) break;
		v.push_back(n);
	}
	vector<int> w;
	reverse_1(v, w);
	print(v, "Input vector");
	print(w, "Output vector");
	reverse_2(v);
	print(v, "Reversed vector");
}