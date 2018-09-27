#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	cout << "The prime numbers between 1 and 100 are: " << endl;
	vector<bool> prime;

	for (int i = 0; i < 100; ++i) {
		prime.push_back(true);
	}

	for (int i = 2; i < 100; ++i) {
		if (prime[i]) {
			for (int j = 2; i*j < 100; ++j) {
				prime[i*j] = false;
			}
		}
	}

	for (int i = 2; i < 100; ++i) {
		if (prime[i]) {
			cout << i << ", ";
		}
	}
	cout << endl;
	system("pause");
	return 0;
}