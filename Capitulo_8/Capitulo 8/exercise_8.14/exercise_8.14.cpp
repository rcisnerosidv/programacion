#include "Includes.h"



struct limits {
	string first, last, shortest, longest;
};

void sizes(const vector<string> & words, vector<int> & lengths,
	limits & data) {
	if (int(words.size()) == 0) error("The input vector is empty");
	if (int(lengths.size()) != 0) error("The output vector is not empty");
	data.first = words[0];
	data.last = words[0],
		data.shortest = words[0];
	data.longest = words[0];
	int min = int(data.shortest.size()), max = int(data.longest.size());
	for (int i = 0; i < int(words.size()); ++i) {
		int n = int(words[i].size());
		lengths.push_back(n);
		if (words[i] < data.first) data.first = words[i];
		if (words[i] > data.last) data.last = words[i];
		if (n < min) {
			data.shortest = words[i];
			min = n;
		}
		if (n > max) {
			data.longest = words[i];
			max = n;
		}
	}
}

int main() {
	vector<string> words;
	string x;
	cout << "Type a list of words, separated by spaces, and finish by" <<
		endl << "typing control-D" << endl;
	while (true) {
		cin >> x;
		if (!cin) break;
		words.push_back(x);
	}
	vector<int> n;
	limits a;
	sizes(words, n, a);
	cout << "First " << a.first << ", last " << a.last <<
		", shortest " << a.shortest << ", longest " << a.longest << endl;
	for (int i = 0; i < int(words.size()); ++i)
		cout << words[i] << " is " << n[i] << " characters" << endl;
	system("pause");
	return 0;
}