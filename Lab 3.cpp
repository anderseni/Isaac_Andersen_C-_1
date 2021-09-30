/*
	Isaac Andersen
	Due: September 29, 2021
	Lab Name: Lab 3 User and File I/O
	Description: Write an interactive C++ program that computes and outputs the mean and  population standard
	deviation of a set of four integers that are inputted by a file called “inMeanStd.dat” and the user
	(should handle both). Although the individual values are integers, the results are floating-point values.
	Be sure to use proper formatting and appropriate comments in your code. Provide appropriate prompts to the user.
	The output should be to the screen for the user inputted values and to a file called “outMeanStd.dat”.
	The programs output should be labeled clearly and formatted neatly. You must calculate the mean and standard
	deviation in separate functions.
*/

#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
	ifstream infile;
	infile.open("inMeanSTD.dat"); //Opens a file to pull info from

	ofstream outfile;
	outfile.open("outMeanStd.dat"); //Opens a file to write info to

	float input1, input2, input3, input4; // Sets the inputs as floats

	infile >> input1 >> input2 >> input3 >> input4; // Pulls inputs the the open input file

	float mean = (input1 + input2 + input3 + input4) / 4; // Calculates the mean

	float psd1 = (((input1 - mean) * (input1 - mean)) + ((input2 - mean) * (input2 - mean)) + ((input3 - mean) * (input3 - mean)) + ((input4 - mean) * (input4 - mean))) / 4; // Calculates the population standard deviation

	float psd2 = pow(psd1, 0.5); // Calculates the population standard deviation

	outfile << "The mean is equal to: " << mean << "\nThe population standard deviation is equal to: " << psd2; // Writes both the Mean and SPD

	int i1, i2, i3, i4;

	cout << "I need you to give me 4 numbers. What is the first one: ";

	cin >> i1;

	cout << "\nWhat is the second number: ";

	cin >> i2;

	cout << "\nNext what is your third number: ";

	cin >> i3;

	cout << "\nAnd now what is your final number: ";

	cin >> i4;

	float mean2 = (i1 + i2 + i3 + i4) / 4; // Calculates the mean

	float psdi = (((i1 - mean) * (i1 - mean)) + ((i2 - mean) * (i2 - mean)) + ((i3 - mean) * (i3 - mean)) + ((i4 - mean) * (i4 - mean))) / 4; // Calculates the population standard deviation

	float psdo = pow(psdi, 0.5); // Calculates the population standard deviation

	cout << "Thank you for the numbers, I used them to calculate a mean and population standard deviation." << "\nMean: " << mean2 << "\nPopulation Standard Deviation: " << psdo;

	return 0;
}