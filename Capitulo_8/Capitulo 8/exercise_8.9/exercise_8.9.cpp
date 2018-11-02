#include "Includes.h"


double myrand() {
	static unsigned long long seed = 123456789;
	seed = (302875106592253 * seed + 1) & 0xffffffffffffffff;
	return double(seed) / 18446744073709551616.0;
}
int randint() {
	return int((double(0x7fffffff) + 1.0)*myrand());
}

int rand_in_range(int a, int b) {
	// This doesn't check that a is less than b, but it should
	return a + int((double(b) - double(a))*myrand());
}

int main() {
	cout << "Type in some bounds or just use control-D" << endl;
	int a, b;
	cin >> a >> b;
	if (!cin)
		for (int i = 0; i < 20; ++i)
			cout << randint() << endl;
	else if (a >= b)
		error("The bounds are invalid");
	else
		for (int i = 0; i < 20; ++i)
			cout << rand_in_range(a, b) << endl;
	system("pause");
	return 0;
}