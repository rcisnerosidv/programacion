#include <iostream>
#include <vector>

using namespace std;

bool isPrime(int num) {

	int div{ 0 };
	for (int i = 1; i <= num; ++i) {
		if (num % i == 0) {
			++div;
		}
	}
	if (div != 2) {
		return false;
	}
	else {
		return true;
	}
}

int main() {

	cout << "Enter how many primes you want: " << endl;
	int count{ 0 }, n{ 0 };
	cin >> n;

	vector<int> primes;
	int max = n * 5;
	for (int i = 1; i <= max; ++i) {

		if (isPrime(i) == true) {

			primes.push_back(i);

		}


	}

	for (int j = 0; j < n; ++j) {

		cout << primes[j] << ", ";
	}

	cout << endl;

	system("pause");
	return 0;
}