#include <iostream>
#include <fstream>
#include <string>;
using namespace std;

/////////////////////////////////
// By: Justin Perez            //
//                             //
// 5-2 Assignment              //
/////////////////////////////////



//Makes a new file called Celsius Temp to store the values into. 
ofstream CFile("CelsiusTemperature.txt");

int Convert(int& F, int& C) {
	//The Math equation to convert Fahrenheit to Celsius
	C = (F - 32) * 5 / 9;

	return (C);
}

void static ConvertTxt(string City, int C) {
	//Converts Values into Txt File. 
	CFile << City << " " << C << endl;	
}



int main() {

	ifstream inputFile("FahrenheitTemperature.txt");

	//City Location
	string City;

	//Fahrenheit
	int F;

	//Celsius 
	int C = 0;

	//Mainly for debug & if the file doesn't run.
	if (!inputFile.is_open()) {
		cout << "Could not open file FahrenheitTemperature.txt" << endl;
		return 1;
	}
	
	while (inputFile >> City >> F) {
		cout << City << " " << F << endl;
		cout << "In Celsuis would be..." << endl;
		Convert(F, C);
		cout << City << " " << C << endl << endl;
		ConvertTxt(City, C);
	}
	
	return 0;
}