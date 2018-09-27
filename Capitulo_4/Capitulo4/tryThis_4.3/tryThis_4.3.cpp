#include <iostream>

using namespace std;

int main() {

	char value = 'a';
	int num{ 97 };

	while (value <= 'z') {
		cout << value << "\t" << num << endl;
		++value;
		++num;
	}

	system("pause");
	return 0;
}