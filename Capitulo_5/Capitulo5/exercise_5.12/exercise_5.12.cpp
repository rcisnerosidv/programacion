#include <iostream>
#include "Includes.h"

using namespace std;


int moo(char a, char b, char c, char d) {
	bool no = true;
	cout << "Input a guess of 4 different digits\n";
	while (no) {
		char p = 0, q = 0, r = 0, s = 0;
		cin >> p >> q >> r >> s;
		if (p < '0' || p > '9' || q < '0' || q > '9' ||
			r < '0' || r > '9' || s < '0' || s > '9' ||
			p == q || p == r || p == s ||
			q == r || q == s || r == s)
			cout << "Sorry - that's invalid - try again\n";
		else {
			int m{ 0 }, n{ 0 };
			if (p == a) ++m;
			if (q == b) ++m;
			if (r == c) ++m;
			if (s == d) ++m;
			if (p == b) ++n;
			if (p == c) ++n;
			if (p == d) ++n;
			if (q == a) ++n;
			if (q == c) ++n;
			if (q == d) ++n;
			if (r == a) ++n;
			if (r == b) ++n;
			if (r == d) ++n;
			if (s == a) ++n;
			if (s == b) ++n;
			if (s == c) ++n;
			if (m == 0 && n == 0)
				cout << "That's a duck\n";
			else if (m == 4) {
				cout << "Moo!\n";
				no = false;
			}
			else {
				for (int i = 0; i < m; ++i) cout << 'b';
				for (int i = 0; i < n; ++i) cout << 'c';
			}
			cout << '\n';
		}
	}
	return 0;
}

int main() {
	char a = 0, b = 0, c = 0, d = 0;
	while (cin) {
		a = '0' + randint(10);
		b = a;
		while (b == a) b = '0' + randint(10);
		c = a;
		while (c == a || c == b) c = '0' + randint(10);
		d = a;
		while (d == a || d == b || d == c) d = '0' + randint(10);
		moo(a, b, c, d);
	}

	system("pause");
	return 0;
}