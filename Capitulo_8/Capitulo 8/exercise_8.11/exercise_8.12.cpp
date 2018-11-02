#include "Includes.h"


double myrand() {
	static unsigned long long seed = 123456789;
	seed = (302875106592253 * seed + 1) & 0xffffffffffffffff;
	return double(seed) / 18446744073709551616.0;
}

double maxv(const vector<double> & arg) {
	if (int(arg.size()) == 0) error("No elements in vector");
	double x = arg[0];
	for (int i = 0; i < int(arg.size()); ++i)
		if (arg[i] > x) x = arg[i];
	return x;
}

void sort(vector<double> & arg) {
	int n = int(arg.size()), k = n;
	double d;
	while (k > 1) {
		k = k / 3 + 1;
		for (int i = k; i < n; ++i) {
			int j = i;
			while (j >= k && arg[j - k] > arg[j]) {
				d = arg[j];
				arg[j] = arg[j - k];
				arg[j - k] = d;
				j -= k;
			}
		}
	}
}

void stats(const vector<double> & arg, double & mean,
	double & var, double & min, double & median, double & max) {
	int n = int(arg.size());
	if (n < 2) error("Too few elements in vector");
	mean = var = 0.0;
	min = max = arg[0];
	for (int i = 0; i < n; ++i) {
		mean += arg[i];
		if (arg[i] > max) max = arg[i];
		if (arg[i] < min) min = arg[i];
	}
	mean /= arg.size();
	for (int i = 0; i < n; ++i)
		var += (arg[i] - mean)*(arg[i] - mean) / arg.size();
	vector<double> temp = arg;
	sort(temp);
	if (n % 2 == 0)
		median = (temp[n / 2] + temp[n / 2 + 1])
		/ 2.0;
	else
		median = temp[n / 2 + 1];
}

int main() {
	vector<double> mutter;
	for (int i = 0; i < 20; ++i) {
		mutter.push_back(2.0*myrand() - 1.0);
		cout << mutter[i] << endl;
	}
	cout << "Maximum is " << maxv(mutter) << endl;
	double mean, var, min, median, max;
	stats(mutter, mean, var, min, median, max);
	cout << "Mean = " << mean << ", variance = " << var <<
		", min = " << min << endl << "    median = " << median <<
		", max = " << max << endl;
	system("pause");
	return 0;
}