#include <iostream>

using namespace std;

int main() {
	constexpr double yen{ 0.0089 };
	constexpr double kroner{ 0.12 };
	constexpr double pound{ 1.32 };
	constexpr double cm_per_inch{ 2.54 };

	double amount{ 0 };

	char currency{ 0 };
	cout << "Please enter an amount followed by a currency " 
		 << "(y for yens, k for kroners, p for pounds)." << endl;
	cin >> amount >> currency;

	if (currency == 'y') {

		cout << amount << " Yen == " << yen << " dollars." << endl;
		cout << "Total: " << amount * yen << " dollars." << endl;

	}
	else if (currency == 'k') {
		cout << amount << " Kroner == " << kroner << " dollars." << endl;
		cout << "Total: " << amount * kroner << " dollars." << endl;
	}
	else if (currency == 'p'){
		cout << amount << " Pound == " << pound << " dollars." << endl;
		cout << "Total: " << amount * pound << " dollars." << endl;
	}
	else {
		cout << "Sorry, i don't know a currency called " << currency << endl;
	}

	system("pause");
	return 0;
}