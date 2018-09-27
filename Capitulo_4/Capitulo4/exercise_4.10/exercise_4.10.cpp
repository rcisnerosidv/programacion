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

	vector<int> primes;
	for (int i = 1; i <= 100; ++i) {
		
		if (isPrime(i) == true) {

			primes.push_back(i);

		}
		

	}
	
	for (unsigned int j = 0; j < primes.size(); ++j) {

		cout << primes[j] << ", ";
	}

	cout << endl;
	system("pause");
	return 0;
}