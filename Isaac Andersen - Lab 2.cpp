/*
	Isaac Andersen
	Due: Tuesday 7, 2021
	Lab Name: Lab 2 Exploring Output
	Description: This lab is designed to get you familiar output to the command prompt using C++.
*/

#include <iostream>

using namespace std;

int main()
{
	//Output schedule to screen
	const string m = "Monday";
	const string tu = "Tuesday";
	const string w = "Wednesday";
	const string th = "Thursday";
	const string f = "Friday";
	const string fct = "08:20"; // First Class Time = fct
	const string fcna = "Principles of Macroeconomics";
	const string fcnb = "Python";
	const string sct = "10:00";
	const string scn = "C++";
	const string tct = "11:36";
	const string tcn = "American Government";
	const string foct = "01:02";
	const string focn = "Cinema and Composition";
	const string fict = "02:37";
	const string ficn = "Concert Band";
	cout << m << "\n\t" << fct << "\t" << fcna << "\n\t" << sct << "\t" << scn << "\n\t" << tct << "\t" << tcn << "\n\t" << foct << "\t" << focn << "\n\t" << fict << "\t" << ficn << endl;

	cout << tu << "\n\t" << fct << "\t" << fcnb << "\n\t" << sct << "\t" << scn << "\n\t" << tct << "\t" << tcn << "\n\t" << foct << "\t" << focn << "\n\t" << fict << "\t" << ficn << endl;

	cout << w << "\n\t" << fct << "\t" << fcna << "\n\t" << sct << "\t" << scn << "\n\t" << tct << "\t" << tcn << "\n\t" << foct << "\t" << focn << "\n\t" << fict << "\t" << ficn << endl;

	cout << th << "\n\t" << fct << "\t" << fcnb << "\n\t" << sct << "\t" << scn << "\n\t" << tct << "\t" << tcn << "\n\t" << foct << "\t" << focn << "\n\t" << fict << "\t" << ficn << endl;

	cout << f << "\n\t" << fct << "\t" << fcna << "\n\t" << sct << "\t" << scn << "\n\t" << tct << "\t" << tcn << "\n\t" << foct << "\t" << focn << "\n\t" << fict << "\t" << ficn << endl;
	const string ch1 = "*   *   *   *   \n";
	const string ch2 = "  *   *   *   *   \n";
		
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			cout << ch1;
		}
		else {
			cout << ch2;
		}
	}
}