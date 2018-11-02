#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_until_ss(const vector<string> v, const string quit) {
	bool b = false;
	for (int i = 0; i < int(v.size()); ++i) {
		if (v[i] == quit) {
			if (b) return;
			b = true;
		}
		else
			cout << v[i] << endl;
	}
	if (b)
		cout << "Only one '" << quit << "' found" << endl;
	else
		cout << "No '" << quit << "'s found" << endl;
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
	print_until_ss(words, "q");
	system("pause");
	return 0;
}