#include <iostream>
#include "Includes.h"

using namespace std;

const int czero{ -273 }, fzero = (9 * czero) / 5 + 32;

int ctof(int c) {
	if (c < czero) error("Colder than absolute zero\n");
	if (c % 5 != 0)
		error("The conversion cant be done exactly\n");
	return (9 * c) / 5 + 32;
}

int ftoc(int f) {
	if (f < fzero) error("Colder than absolute zero\n");
	if ((f - 32) % 9 != 0)
		error("The conversion cant be done exactly\n");
	return (f - 32) * 5 / 9;
}

int main() {
	int a{ 0 };
	char s = 0;
	cin >> a >> s;
	if (s == 'c')
		cout << a << " Celsius is " << ctof(a) << " Fahrenheit\n";
	else if (s == 'f')
		cout << a << " Fahrenheit is " << ftoc(a) << " Celsius\n";
	else
		error("Unknown unit\n");


	system("pause");
	return 0;
}