#include <iostream>
#include "Includes.h"

using namespace std;


int main() {


	vector<double> distances;
	cout << "Enter the distance between two cities(press | to finish): " << endl;
	for (double distance{ 0 }; cin >> distance;)
	distances.push_back(distance);

	double sum{ 0 };
	for (double x : distances) sum += x;
	cout << "The sum of all distances is: " << sum << endl;
	cout << "The average of all distances is: " << sum / distances.size() << endl;

	sort(distances);
	cout << "The smalles distance between two cities is: " << distances[0] << endl;
	cout << "The greatest distance between two cities is: " << distances[distances.size() - 1] << endl;


	system("pause");
	return 0;
}

