/*
	Name : Isaac Andersen
	Due: December 13, 2021
	Description: Write a C++ program that reads characters representing binary (base 2) 
	numbers from a data file called BinaryIn.dat and translates them to decimal (base 10) 
	numbers. The binary and decimal numbers should be output in two columns with 
	appropriate headings.

*/


#include <fstream>
#include <iostream>
#include <string>
#include <regex>
#include <iomanip>

using namespace std;
int binaryToDecimal(string binary);
bool isNumber(string a);
string removeStartingSpaces(string a);
int main() {
	ifstream inputFile;
	inputFile.open("C:/Users/ICCC Student/source/repos/binary.dat");
	string line;
	cout << "  " << fixed << setw(20) << left << "Binary Number" << "  |  " << "Decimal Equivelant\n";
	while (getline(inputFile, line))//While there is still something inside the file to retrieve
	{
		line = removeStartingSpaces(line);//Removes whitespace from the beginning of the string
		if (isNumber(line)) {//If the string can be converted to a number, it is binary
			cout << "  " << fixed << setw(20) << left << line << "  |  " << binaryToDecimal(line) << "\n";
		}
		else {
			cout << "  " << fixed << setw(20) << left << "Bad Digit On Input" << "  |  " << "\n";
		}
	}
	inputFile.close();
}
int binaryToDecimal(string bin) {
	int total = 0;
	for (int i = 0; i < bin.size(); i++)//Iterates through every character in the string
	{
		string a = bin.substr(i, 1);//Gets the character at i
		if (a == "1") {
			int count = 1;
			for (int j = 0; j < bin.size() - i - 1; j++)//Multiplies count by 2 for every digit between the current digit and the end
			{
				count *= 2;
			}
			total += count;//Adds count to total, and moves on to the next character
		}
		else if (a != "0") {//Something went terribly wrong if your binary had anything except 0s and 1s
			cout << "ERROR";
			break;
		}
	}

	return total;
}
string removeStartingSpaces(string a) {
	return regex_replace(a, regex("^ +"), "");
}
bool isNumber(string a) {
	string::const_iterator it = a.begin();
	while (it != a.end() && isdigit(*it)) ++it;
	return !a.empty() && it == a.end();
}