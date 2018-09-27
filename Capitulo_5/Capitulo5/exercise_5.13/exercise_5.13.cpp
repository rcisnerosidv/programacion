#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {


	vector<string> days(7), days1(7), days2(7), days3(7);
	vector<int> values(7);
	days[0] = "Sunday";
	days[1] = "Monday";
	days[2] = "Tuesday";
	days[3] = "Wednesday";
	days[4] = "Thursday";
	days[5] = "Friday";
	days[6] = "Saturday";
	days1[0] = "sunday";
	days1[1] = "monday";
	days1[2] = "tuesday";
	days1[3] = "wednesday";
	days1[4] = "thursday";
	days1[5] = "friday";
	days1[6] = "saturday";
	days2[0] = "Sun";
	days2[1] = "Mon";
	days2[2] = "Tue";
	days2[3] = "Wed";
	days2[4] = "Thu";
	days2[5] = "Fri";
	days2[6] = "Sat";
	days3[0] = "sun";
	days3[1] = "mon";
	days3[2] = "tue";
	days3[3] = "wed";
	days3[4] = "thu";
	days3[5] = "fri";
	days3[6] = "sat";


	for (int i = 0; i < 7; ++i) values[i] = 0;
	int invalid{ 0 }, value{ 0 };
	string day = "";

	while (cin >> day >> value) {
		bool ok = false;
		for (int i = 0; i < 7; ++i)
			if (day == days[i] || day == days1[i] ||
				day == days2[i] || day == days3[i]) {
				values[i] += value;
				ok = true;
			}
		if (!ok) invalid += value;
	}

	for (int i = 0; i < 7; ++i)
		cout << days[i] << " " << values[i] << endl;
	cout << "Invalid " << invalid << endl;


	system("pause");
	return 0;
}