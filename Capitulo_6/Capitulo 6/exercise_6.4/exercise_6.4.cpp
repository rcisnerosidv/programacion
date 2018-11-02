#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Name_value {
public:
	string name;
	int score;
};

int main() {
	vector<Name_value> entries;
	Name_value entry;
	bool found = false;

	while (!found && cin >> entry.name >> entry.score) {
		for (int n = 0; n < entries.size(); ++n)
			if (entries[n].name == entry.name) found = true;
		if (!found)
			entries.push_back(entry);
	}
	if (found)
		cout << entry.name << " was entered twice\n";
	else
		for (int n = 0; n < entries.size(); ++n)
			cout << entries[n].name << " " << entries[n].score << endl;

	return 0;
}