#include <iostream>

using namespace std;

int main() {

	char value = 'a';
	int num{ 97 };

	for (int i = 0; value <= 'z'; ++i) {
		cout << value << "\t" << num << endl;
		++value;
		++num;
	}

	system("pause");
	return 0;
}