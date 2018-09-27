#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

	int score{ 0 };
	string name = "";
	vector<string> names;
	vector<int> scores;
	cout << "Enter NoName 0 to terminate the program. " << endl;
	cout << "Enter a name followed by a score separated by a space: " << endl;
	do {
		
		cin >> name >> score;
		for (int i = 0; i < names.size(); ++i) {

			if (names[i] == name) {
				cout << "Error, each name must be unique. " << endl;
				break;
			}
			else {
				if (name != "NoName" && score != 0) {
					names.push_back(name);
					scores.push_back(score);
				}
			}
		}
	} while (name != "NoName" && score != 0);


	cout << "================================" << endl;
	cout << endl;

	for (int i = 0; i < names.size(); ++i) {

		cout << names[i] << ": " << scores[i] << endl;

	}
	




	system("pause");
	return 0;
}