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

#include <iostream> // Adds the I/O Library
#include <fstream> // Adds the fstream library
#include <math.h> // Adds the math library

using namespace std; // Dictates the namespace

int main() // Initializes everything
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

	int i1, i2, i3, i4; // Creates the variables for the inputs

	cout << "I need you to give me 4 numbers. What is the first one: "; // Outputs prompt

	cin >> i1; // Takes input for the first variable

	cout << "\nWhat is the second number: "; // Outputs a prompt for a second number

	cin >> i2; // Takes input for the second variable

	cout << "\nNext what is your third number: "; // Outputs a prompt for a third number

	cin >> i3; // Takes input for the third variable

	cout << "\nAnd now what is your final number: " << endl; // Outputs a promt for the fourth and final number

	cin >> i4; // Takes input for the fourth variable

	float mean2 = (i1 + i2 + i3 + i4) / 4; // Calculates the mean

	float psdi = (((i1 - mean) * (i1 - mean)) + ((i2 - mean) * (i2 - mean)) + ((i3 - mean) * (i3 - mean)) + ((i4 - mean) * (i4 - mean))) / 4; // Calculates the population standard deviation

	float psdo = pow(psdi, 0.5); // Calculates the population standard deviation

	cout << "Thank you for the numbers, I used them to calculate a mean and population standard deviation." << "\nMean: " << mean2 << "\nPopulation Standard Deviation: " << psdo; // Outputs the Mean and SPD

	return 0;
}