#include <iostream>
#include <vector>

using namespace std;

int main() {

	cout << "Enter the max value to find prime numbers. " << endl;
	int max{ 0 };
	cin >> max;
	vector<bool> prime;

	for (int i = 0; i < max; ++i) {
		prime.push_back(true);
	}

	for (int i = 2; i < max; ++i) {
		if (prime[i]) {
			for (int j = 2; i*j < max; ++j) {
				prime[i*j] = false;
			}
		}
	}

	for (int i = 2; i < max; ++i) {
		if (prime[i]) {
			cout << i << ", ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}