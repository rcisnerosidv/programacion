#include "Includes.h"

using namespace std;

int moo(char a, char b, char c, char d) {
	bool no = true;
	cout << "Input a guess of 4 different letters\n";
	while (no) {
		char p, q, r, s;
		cin >> p >> q >> r >> s;
		if (p < 'a' || p > 'z' || q < 'a' || q > 'z' ||
			r < 'a' || r > 'z' || s < 'a' || s > 'z' ||
			p == q || p == r || p == s ||
			q == r || q == s || r == s)
			cout << "Sorry - that's invalid - try again\n";
		else {
			int m = 0, n = 0;
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
				for (int i = 0; i < m; ++i) cout << 'B';
				for (int i = 0; i < n; ++i) cout << 'C';
			}
			cout << '\n';
		}
	}
	return 0;
}

int main() {
	char a, b, c, d;
	while (cin) {
		a = 'a' + randint(26);
		b = a;
		while (b == a) b = 'a' + randint(26);
		c = a;
		while (c == a || c == b) c = 'a' + randint(26);
		d = a;
		while (d == a || d == b || d == c) d = 'a' + randint(26);
		moo(a, b, c, d);
	}

	return 0;
}