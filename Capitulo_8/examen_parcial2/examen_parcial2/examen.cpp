#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "alumno.h"

using namespace std;

void swap(string *xp, string *yp)
{
	string temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void nameSort(vector<Alumno> alumno) {
	for (int i{ 0 }; i < alumno.size() - 1; ++i) {

		for (int j{ 0 }; j < alumno.size() - i - 1; j++) {
			if (alumno[j].nombre > alumno[j + 1].nombre)
				swap(&alumno[j].nombre, &alumno[j + 1].nombre);
		}
	}
	for (int i{ 0 }; i < alumno.size(); ++i) {
		ofstream outFile(alumno[i] + "grupos.txt", ios::out);
		for (int j{ 0 }; j < alumno.size; ++j) {
			outFile << alumno[i].nombre << " " << alumno[i].calif << " " << alumno[i].grupo << "," << endl;
		}
	}
}



int main() {
	
	ifstream inFile("alumnos.txt", ios_base::in);
	vector<Alumno> original{};
	string buffer;
	while (getline(inFile, buffer)) {
		string nombre;
		string grupo;
		double calif;
		inFile >> nombre >> calif >> grupo;
		Alumno alumno_objeto(nombre, calif, grupo);
		original.push_back(alumno_objeto);

	}

	nameSort(original);

	for (int i{ 0 }; i < original.size(); ++i) {
		cout << original[i].nombre;
		cout << " " << original[i].calif;
		cout << " " << original[i].grupo << endl;
	}



	system("pause");
	return 0;
}
