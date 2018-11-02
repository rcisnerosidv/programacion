#include <iostream>
#include "Includes.h"

using namespace std;


int main() {
	bool init = true;
	const double m_cm{ 100 }, in_cm{ 2.54 }, ft_in{ 12 };
	double small{ 0 }, large{ 0 }, total{ 0 }, a{ 0 };
	string unit="";
	vector<double> values;

	cout << "Enter a value with a unit to convert: " << endl;

	while (cin >> a >> unit) {
		cout << a << unit << "\n";
		if (unit == "m")
			a = a;
		else if (unit == "cm")
			a = a / m_cm;
		else if (unit == "in")
			a = in_cm * a / m_cm;
		else if (unit == "ft")
			a = ft_in * in_cm*a / m_cm;
		else {
			cout << "Invalid unit - ignored\n";
			unit = "???";
		}
		values.push_back(a);
		total += a;
		if (init) {
			small = a;
			large = a;
			init = false;
		}
		else if (a < small) {
			cout << "The smallest so far\n";
			small = a;
		}
		else if (a > large) {
			cout << "The largest so far\n";
			large = a;
		}
	}
	cout << "Smallest: " << small << ", largest: " << large <<
		", total: " << total << "\n";
	sort(values.begin(), values.end());
	cout << "Values: ";
	for (int i = 0; i < values.size(); ++i)
		cout << values[i] << " ";
	cout << "\n";


	system("pause");
	return 0;
}