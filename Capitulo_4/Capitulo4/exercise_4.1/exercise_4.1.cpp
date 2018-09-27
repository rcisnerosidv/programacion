#include <iostream>
#include "Includes.h"



using namespace std;


int main(){

	vector<double> temps;
	for (double temp; cin >> temp;) {
		temps.push_back(temp);
		sort(temps);
		cout << "Median temperature: " << temps[temps.size() / 2] << endl;
	}

	double sum{ 0 };
	for (double x : temps)sum += x;
	cout << "Average temperature: " << sum / temps.size() << endl;




	system("pause");
	return 0;
}