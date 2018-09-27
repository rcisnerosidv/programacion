#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

	cout << "Enter a word to see if is listed as a bad word: " << endl;
	string word = "";
	vector<string> disliked = {"broccoli", "menudo", "liver"};
	cin >> word;
	bool cond = false;

	for (int i = 0; i < disliked.size(); ++i) {

		if (word == disliked[i] ) {

			cout << "BLEEP" << endl;
			cond = true;
		}

	}

	if (cond == false) {
		cout << word << endl;
	}




	system("pause");
	return 0;
}