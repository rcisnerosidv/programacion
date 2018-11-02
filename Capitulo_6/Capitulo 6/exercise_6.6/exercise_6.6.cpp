#include "Includes.h"

using namespace std;

class Word {
	string pending;
public:
	Word(string word) : pending(word) {}
	string get() {
		string temp = pending;
		pending = "";
		if (temp == "") cin >> temp;
		return temp;
	}
	void putback(string word) {
		if (pending != "")
			error("Too many calls to putback()");
		else
			pending = word;
	}
};

Word object("");

bool expression();

bool primary() {
	string word = object.get();
	if (word == "true")
		return true;
	else if (word == "false")
		return false;
	else if (word == "(") {
		bool temp = expression();
		if (object.get() != ")")
			error(") expected but not found");
		return temp;
	}
	else
		error("Unrecognised token");
}

bool expr_2() {
	bool left = primary();
	while (true) {
		string next = object.get();
		if (next == "")
			return left;
		else if (next == "&")
			left &= primary();
		else {
			object.putback(next);
			return left;
		}
	}
}

bool expr_1() {
	bool left = expr_2();
	while (true) {
		string next = object.get();
		if (next == "")
			return left;
		else if (next == "^")
			left ^= expr_2();
		else {
			object.putback(next);
			return left;
		}
	}
}

bool expression() {
	bool left = expr_1();
	while (true) {
		string next = object.get();
		if (next == ";" || next == "")
			return left;
		else if (next == ")") {
			object.putback(next);
			return left;
		}
		else if (next == "|")
			left |= expr_1();
		else
			error("Operator expected\n");
	}
}

int main() {
	while (cin)
		cout << "That evaluates to " << expression() << endl;

	return 0;
}