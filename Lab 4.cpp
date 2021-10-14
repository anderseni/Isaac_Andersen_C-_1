/*
	Isaac Andersen
	Due: October 13, 2021
	Lab Name: Lab 4 Temperature Output
	Description: Design and write a C++ program that inputs a series of hourly temperature from a file,
	and outputs a bar chart (using stars) of the temperatures. The temperature should be printed to the
	left of the corresponding bar, and there should be a heading that gives the scale of the chart.
	The range of temperatures should be from  -30 to 120. Because it is hard to display 150 characters
	on the screen, you should have each star represent a range of 3 degrees. That way, the bars will be
	at most 50 characters wide. Use meaningful variable names, proper indentation, and appropriate comments.
	Thoroughly test the program using your own data sets. Make sure to vet the values from the input file.
*/

#include <iostream> // Import Statements
#include <fstream> // Import Statements
#include <iomanip> // Import Statements
using namespace std; // Dictates Namespace

int main() // Main Function Initialization
{
	ifstream infile;
	float ar[24];
	infile.open("input.dat"); // Opens the data file
	cout << setw(34) << "Temperature Range\n";
	cout << "      -30   -15   0   15   30   45   60   75   90   105   120" << endl;
	while (1) // Starts the main loop.
	{
		int temp; // Setup for variables
		infile >> temp;
		string starOutput = "";
		string blankSpace = "";
		int dif;
		if (!infile) // Checks for an input file
		{
			break;
		}
		cout << setw(5) << temp << "  ";
		if (temp >= 0) // Checks for temperatures above 0
		{
			if (temp > 120) // Checks if the temperature is above 120
			{
				cout << "ERROR: TEMPERATURE OUTSIDE OF RANGE!" << endl;
				
			}
			
			else // If the temperature is between 0 and 120, begins the printing loop
			{
				dif = 120 - temp;
				for (int i = 0; i < round(temp / 3); i++) // Generates the number of stars for each temp above zero
				{
					starOutput += "*";
				}
				for (int i = 0; i <= round(dif / 3); i++) // Generates the extra blank space
				{
					blankSpace += " ";
				}
				cout << "|" << "          " << "|" << starOutput << blankSpace << "|" << endl; // Outputs the temperature in stars
			}
		}
		else // If the temperature is below 0, begins the other check loops
		{
			if (temp < -30) // Checks if the temp is below -30
			{
				cout << "ERROR: TEMPERATURE OUTSIDE OF RANGE!" << endl;
				
			}
			else // If temp is between -30 and 0, begins the output loops
			{
				dif = abs(-30 - temp); // Sets variables for later use
				temp = abs(temp);
				
				for (int i = 0; i < round(temp / 3); i++) // Generates the star output based on temp
				{
					starOutput += "*";
				}
				for (int i = 0; i <= round(dif / 3); i++) // Generates the extra space
				{
					blankSpace += " ";
				}
				string moreSpace = ""; // Initializes another variable
				for (int i = 0; i <= 120 / 3; i++) // Adds the new space after 0 for alignment
				{
					moreSpace += " ";
				}
				if (temp == 30) // Checks if temp is = to 30, -30 is changed to an absolute previously
				{
					cout << "|" << starOutput << "|" << moreSpace << "|" << endl;
				}
				else // Outputs the stars and blank space
				{
					cout << "|" << blankSpace << starOutput << "|" << moreSpace << "|" << endl;
				}
			}
		}
	}
	infile.close(); // Closes the input file
}