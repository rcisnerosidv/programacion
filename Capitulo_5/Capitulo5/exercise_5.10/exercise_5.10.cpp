#include <iostream>
#include "Includes.h"

using namespace std;

int main() {

	int a{ 0 }, b{ 1 }, c{ 0 };
	try {
		while ((c = a + b) > 0) {
			a = b;
			b = c;
		}
	}
	catch (...) {
							// Ignora toda excepcion
	}
	cout << "The largest number that fits is " << b << endl;
	

	system("pause");
	return 0;
}