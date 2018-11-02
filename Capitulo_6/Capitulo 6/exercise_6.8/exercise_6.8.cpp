#include "Includes.h"

using namespace std;

int main() {
	char a = ' ', b = ' ', c = ' ', d = ' ', e;
	for (int i = 0; i < 4 && cin; ++i)
		if (cin >> e) {
			if (e >= '0' && e <= '9') {
				a = b; b = c; c = d; d = e;
			}
			else
				error("Invalid digit\n");
		}
	if (cin >> e)
		error("Too many digits or trailing characters\n");
	else if (d == ' ')
		error("No digits supplied\n");
	int n = 0;
	if (a != ' ') n += 1000 * (a - '0');
	if (b != ' ') n += 100 * (b - '0');
	if (c != ' ') n += 10 * (c - '0');
	if (d != ' ') n += d - '0';
	bool already = false;
	cout << n << " is";
	if (a == '1') {
		cout << " 1 thousand";
		already = true;
	}
	else if (a != ' ') {
		cout << " " << a << " thousands";
		already = true;
	}
	if (b == '1') {
		if (already) cout << " and";
		cout << " 1 hundred";
		already = true;
	}
	else if (b != ' ') {
		if (already) cout << " and";
		cout << " " << b << " hundreds";
		already = true;
	}
	if (c == '1') {
		if (already) cout << " and";
		cout << " 1 ten";
		already = true;
	}
	else if (c != ' ') {
		if (already) cout << " and";
		cout << " " << c << " tens";
		already = true;
	}
	if (d == '1') {
		if (already) cout << " and";
		cout << " 1 one";
		already = true;
	}
	else if (d != ' ') {
		if (already) cout << " and";
		cout << " " << d << " ones";
		already = true;
	}
	cout << endl;

	// keep_window_open();
	return 0;
}