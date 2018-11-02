#include <iostream>

using namespace std;

int main() {

	cout << "Input a guess of 4 different digits\n";
	char a = '3', b = '7', c = '1', d = '0';
	bool no = true;
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

	system("pause");
	return 0;
}