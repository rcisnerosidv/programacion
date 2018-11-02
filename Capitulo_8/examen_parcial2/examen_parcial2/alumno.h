#pragma once
#include <iostream>
#include <string>

using namespace std;

class Alumno {
public:
	string nombre;
	string grupo;
	double calif;

	Alumno();

	Alumno(string nombre, double calif, string grupo);

	~Alumno();

};