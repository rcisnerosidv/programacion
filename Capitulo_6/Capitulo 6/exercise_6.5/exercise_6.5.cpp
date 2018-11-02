#include "Includes.h"

using namespace std;

string word() {
	string temp;
	if (cin >> temp)
		return temp;
	else
		return "";
}

bool noun() {
	string next = word();
	if (next == "the") next = word();
	return (next == "birds" || next == "fish" || next == "C++");
}

bool verb() {
	string next = word();
	return (next == "rules" || next == "fly" || next == "swim");
}

bool con(string next) {
	return (next == "and" || next == "or" || next == "but");
}


string sentence() {
	while (true) {
		if (!noun())
			error("Noun expected\n");
		if (!verb())
			error("Verb expected\n");
		string next = word();
		if (!con(next)) return next;
	}
}

int main() {
	string next;
	next = sentence();
	if (next != ".")
		error("Sentence not terminated with a period\n");
	else if (word() != "")
		error("Sentence followed by unexpected text\n");
	cout << "That appears to be a sentence!\n";

	return 0;
}