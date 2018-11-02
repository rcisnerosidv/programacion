#include "Includes.h"


double myrand() {
	static unsigned long long seed = 123456789;
	seed = (302875106592253 * seed + 1) & 0xffffffffffffffff;
	return double(seed) / 18446744073709551616.0;
}

double sum(const vector<double> & price,
	const vector<double> & weight) {
	if (price.size() != weight.size())
		error("The vector lengths do not match");
	double t = 0.0;
	for (int i = 0; i < int(price.size()); ++i)
		t += price[i] * weight[i];
	return t;
}

int main() {
	vector<double> price, weight;
	for (int i = 0; i < 20; ++i) {
		price.push_back(int(5000.0*myrand()) / 100.0);
		weight.push_back(int(200000.0*myrand()) / 1000.0);
		cout << price[i] << " " << weight[i] << endl;
	}
	cout << "Sum of products is " << sum(price, weight) << endl;
	system("pause");
	return 0;
}