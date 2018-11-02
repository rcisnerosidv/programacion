#include <iostream>;
#include <vector>;


using namespace std;

int main() {
	
	vector<char> options = { 'r', 'p', 's' };

	for (int i = 0; i < options.size(); ++i) {
		cout << "Let´s play rock, paper, scissors" << endl;
		cout << "Choose one (r, p, s): " << endl;
		char pick = 0;
		cin >> pick;

		switch (pick) {
		case 'r':
			if (options[i] == 'r') {
				
				cout << "Tie! " << endl;
			}
			else if (options[i] == 'p') {

				cout << "Paper beats rock, You lose!" << endl;
			}
			else if (options[i] == 's') {

				cout << "Rock beats scissors, You win! " << endl;
			}
			break;

		case 'p':
			if (options[i] == 'p') {

				cout << "Tie! " << endl;
			}
			else if (options[i] == 's') {

				cout << "Scissors beats paper, You lose!" << endl;
			}
			else if (options[i] == 'r') {

				cout << "Paper beats rock, You win! " << endl;
			}
			break;

		case 's':
			if (options[i] == 's') {

				cout << "Tie! " << endl;
			}
			else if (options[i] == 'r') {

				cout << "Rock beats scissors, You lose!" << endl;
			}
			else if (options[i] == 'p') {

				cout << "Scissors beats paper, You win! " << endl;
			}
			break;
		}

	}

	system("pause");
	return 0;
}