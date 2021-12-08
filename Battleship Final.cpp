/*
*	Name: Isaac Andersen
*	Due: December 8, 2021
*	Description:For this lab you will make a simple battleship game. If you’re not familiar 
	with the game, some quick internet searches should help. For this lab, you will need four 
	10 x 10 grids (two for the user and two for the computer). The program will begin with 
	setup. The program will need to randomly place the computers 5 ships, making sure the 
	ships do not overlap or go off the board. 
*/


#include <iostream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Vector2 {
public:
	int x = 0, y = 0;
	Vector2(int newX, int newY) {
		x = newX;
		y = newY;
	}
	Vector2() {}
};
int stringToInt(string s) {
	stringstream g(s);
	int x = 0;
	g >> x;
	return x;
}
int letterToIndex(char l) {
	l = toupper(l);
	switch (l) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	default:
		return -1;
	}
}
char getYesOrNo() {
	string garbageString = "a";
	while (toupper(garbageString[0]) != 'Y' && toupper(garbageString[0]) != 'N') {
		cin >> garbageString;
		char ans = garbageString[0];
		if (toupper(ans) != 'Y' && toupper(ans) != 'N')
			cout << "Please enter y/n: ";
	}
	return toupper(garbageString[0]);
}
//Takes in a string representing player input and returns a 2-Dimensional Vector representing its position on the board
Vector2 playerInputToCoords(string input) {
	if (input.length() == 2) {
		if (letterToIndex(input[0]) != -1) {
			string new_string;
			new_string.push_back(input[1]);
			return Vector2(letterToIndex(input[0]), stringToInt(new_string) - 1);
		}
		else if (letterToIndex(input[1]) != -1) {
			string new_string;
			new_string.push_back(input[0]);
			return Vector2(letterToIndex(input[1]), stringToInt(new_string) - 1);
		}
		else {
			return Vector2(-1, -1);
		}
	}
	else if (input.length() == 3) {
		if (input[0] == '1' && input[1] == '0') {
			//10A
			return Vector2(letterToIndex(input[2]), 9);
		}
		else if (input[1] == '1' && input[2] == '0') {
			//A10
			return Vector2(letterToIndex(input[0]), 9);
		}
		else {
			return Vector2(-1, -1);
		}
	}
	else {
		return Vector2(-1, -1);
	}
}

class ShipPositions {
private:
	int size;
	Vector2 positions[5];
public:
	ShipPositions() {
		size = 0;
	}
	ShipPositions(Vector2 pos1, Vector2 pos2) { init(2, pos1, pos2, Vector2(), Vector2(), Vector2()); }
	ShipPositions(Vector2 pos1, Vector2 pos2, Vector2 pos3) { init(3, pos1, pos2, pos3, Vector2(), Vector2()); }
	ShipPositions(Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4) { init(4, pos1, pos2, pos3, pos4, Vector2()); }
	ShipPositions(Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4, Vector2 pos5) { init(5, pos1, pos2, pos3, pos4, pos5); }
	ShipPositions(int newSize, Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4, Vector2 pos5) { init(newSize, pos1, pos2, pos3, pos4, pos5); }
	void init(int newSize, Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, Vector2 p5) {
		size = newSize;
		positions[0] = p1;
		positions[1] = p2;
		positions[2] = p3;
		positions[3] = p4;
		positions[4] = p5;
	}
	Vector2 getPosition(int index) {
		return positions[index];
	}
	int getSize() {
		return size;
	}
};
class Grid {
private:
	char grid[10][10];
	//Returns the uppercase version of the letter in the alphabet at the provided index
	char getChar(int index) {
		//If the index is not between 0 and 9 (inclusively), it returns the default value '-'
		if (index < 0 || index > 9)
			return '-';
		return toupper("abcdefghij"[index]);
	}
public:
	Grid() {
		empty();
	}
	//Iterates through every space and sets it to water
	void empty() {
		for (int x = 0; x < 10; x++) {
			for (int y = 0; y < 10; y++) {
				grid[x][y] = '~';
			}
		}
	}
	//Prints the map to the screen
	void print() {
		cout << "   ";
		for (int index = 0; index < 10; index++) {
			cout << " " << index + 1;
		}
		cout << "\n";
		for (int y = 0; y < 10; y++) {
			cout << " " << getChar(y) << " ";
			for (int x = 0; x < 10; x++) {
				cout << " " << grid[x][y];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	//Returns the character on the space at the given position
	char getSpace(Vector2 position) {
		return grid[position.y][position.x];
	}
	//Prints the map to the screen but hides non-hit ships
	void printIncognito() {
		cout << "   ";
		for (int index = 0; index < 10; index++) {
			cout << " " << index + 1;
		}
		cout << "\n";
		for (int y = 0; y < 10; y++) {
			cout << " " << getChar(y) << " ";
			for (int x = 0; x < 10; x++) {
				if (grid[x][y] == '#')
					cout << " ~";
				else
					cout << " " << grid[x][y];
			}
			cout << "\n";
		}
		cout << "\n";
	}
	//Takes in a Ship that has been set and puts it onto the grid
	void setShip(ShipPositions ship) {
		for (int i = 0; i < ship.getSize(); i++) {
			grid[ship.getPosition(i).y][ship.getPosition(i).x] = '#';
		}
	}
	//Takes a position and returns a boolean representing whether or not that space had a ship on it
	bool hit(string space) {
		Vector2 pos = playerInputToCoords(space);
		//cout << pos.x << ", " << pos.y << endl;
		//cout << pos.x << ", " << pos.y << endl;
		int x = pos.y;
		int y = pos.x;
		bool toReturn = grid[x][y] == '#';
		if (toReturn)
			grid[x][y] = 'H';
		else
			grid[x][y] = 'M';
		return toReturn;
	}
	//Returns the space at the given position
	char getSpace(int x, int y) {
		return grid[y][x];
	}
	bool hit(Vector2 position) {
		if (!canHit(position)) return false;
		if (grid[position.y][position.x] == '#') {
			grid[position.y][position.x] = 'H';
			return true;
		}
		else {
			grid[position.y][position.x] = 'M';
			return false;
		}
	}
	bool canHit(Vector2 position) {
		if (position.x >= 0 && position.x < 10 && position.y >= 0 && position.y < 10)
			if (grid[position.y][position.x] != 'H' && grid[position.y][position.x] != 'M')
				return true;
		return false;
	}
};

class Ship {
private:
	int size;
	string name;
	Vector2 positions[5];
public:
	Ship(string newName, int newSize) {
		size = newSize;
		name = newName;
	}
	Ship() {}
	~Ship() {

	}
	//Takes in a position of the ship, the direction it faces, and the current Grid, and returns whether or not
	bool canPlaceAt(Vector2 position, char direction, Grid grid) {
		Vector2 pos = position;
		for (int i = 0; i < size; i++) {
			if (pos.x < 0 || pos.y < 0 || pos.x > 9 || pos.y > 9 || grid.getSpace(pos) != '~')
				return false;
			if (toupper(direction) == 'V')
				pos.x++;
			else
				pos.y++;
		}
		return true;
	}
	//Sets all of the positions
	bool placeAt(Vector2 position, char direction, Grid grid) {
		if (!canPlaceAt(position, direction, grid)) return false;
		Vector2 pos = position;
		for (int i = 0; i < size; i++) {
			positions[i] = pos;
			if (toupper(direction) == 'V')
				pos.x++;
			else
				pos.y++;
		}
		return true;
	}
	string getName() { return name; }
	int getSize() { return size; }
	Vector2 getPosition(int positionIndex) {
		return positions[positionIndex];
	}
	void reset() {

	}
	ShipPositions convertToSP() {
		return ShipPositions(size, positions[0], positions[1], positions[2], positions[3], positions[4]);
	}
};

class Player {
private:
	//Helps the program distinguish between the player and the computer
	bool isCPU;
	Grid grid;
	Ship placedShips[5] = {
		Ship("Carrier", 5),
		Ship("Battleship", 4),
		Ship("Cruiser", 3),
		Ship("Submarine", 3),
		Ship("Destroyer", 2)
	};
	//Call when Player object is created
	void init() {
		reset();
	}
	//Automates setting the ships
	void CPUSetShips() {
		for (int i = 0; i < 5; i++) {
			Vector2 position = Vector2(-1, 30);
			char dir = 'Z';
			while (!placedShips[i].placeAt(position, dir, grid)) {
				position = Vector2(rand() % 10, rand() % 10);
				dir = 'H';
				if (rand() % 2 == 0)
					dir = 'V';
			}
			grid.setShip(placedShips[i].convertToSP());
		}
	}
	//Manages putting the ships onto the board
	void setShips() {
		if (isCPU) {
			CPUSetShips();
		}
		else {
			cout << "Would you like the computer to auto-place your ships? y/n: ";
			char ans = getYesOrNo();
			if (ans == 'Y')
				CPUSetShips();
			else {
				int index = 0;
				string position = "asd";
				string orientation = "no";
				while (index < 5) {
					while (!placedShips[index].placeAt(playerInputToCoords(position), toupper(orientation[0]), grid)) {
						print();
						cout << "Please enter a position for your " << placedShips[index].getName() << " (size " << placedShips[index].getSize() << "): ";
						while (playerInputToCoords(position).x == -1) {
							cin >> position;
							if (playerInputToCoords(position).x == -1)
								cout << "Please enter a valid position (examples: 1A, A1): ";
						}
						cout << "Please enter an orientation for your ship (V: Vertical, H: Horizontal): ";
						while (toupper(orientation[0]) != 'V' && toupper(orientation[0]) != 'H') {
							cin >> orientation;
							if (toupper(orientation[0]) != 'V' && toupper(orientation[0]) != 'H')
								cout << "Please enter a valid orientation. (V: Vertical, H: Horizontal): ";
						}
						if (!placedShips[index].placeAt(playerInputToCoords(position), toupper(orientation[0]), grid)) {
							cout << "Ship cannot be placed at the provided position and orientation. Please try again" << endl;
							position = "asd";
							orientation = "no";
						}
					}
					grid.setShip(placedShips[index].convertToSP());
					index++;
					position = "asd";
					orientation = "no";
				}
			}
		}
	}
	//Sets up all default values for the Player
	void reset() {
		grid.empty();
		for (int i = 0; i < 5; i++) {
			placedShips[i].reset();
		}
	}
public:
	//Default assumes this Player is not a CPU
	Player() {
		isCPU = false;
		init();
	}
	//Takes in a bool representing whether or not this Player is a CPU
	Player(bool CPU) {
		isCPU = true;
		init();
	}
	//Called every turn, and manages moves that the player or CPU take
	Vector2 takeTurn(Player other) {
		if (isCPU) {
			//grid.printIncognito();
			Vector2 position = Vector2(-1, -1);
			while (position.x == -1 || !other.grid.canHit(position)) {
				position.x = rand() % 10;
				position.y = rand() % 10;
			}
			bool hit = other.grid.hit(position);
			if (hit)
				cout << "Computer hit you!" << endl;
			else
				cout << "Computer missed!" << endl;
			return position;
		}
		else {
			cout << "CPU's Board:" << endl;
			other.printIncognito();
			cout << "Your Board:" << endl;
			grid.print();
			Vector2 position = Vector2(-1, -1);
			string ans = "asd";
			cout << "Enter a position to fire at: ";
			while (position.x == -1 || !other.grid.canHit(position)) {
				cin >> ans;
				while (playerInputToCoords(ans).x == -1) {
					if (playerInputToCoords(ans).x == -1)
						cout << "Please enter a valid position on the board (examples: 1A, A1): ";
					cin >> ans;
				}
				position = playerInputToCoords(ans);
				if (position.x == -1 || !other.grid.canHit(position))
					cout << "That space has already been shot at. Please try a different space: ";
			}
			if (other.grid.hit(position))
				cout << "Hit!" << endl;
			else
				cout << "Miss!" << endl;
			return position;
		}
	}
	//Prints the grid
	void print() {
		grid.print();
	}
	//Prints the grid, leaving out the positions of non-located ships
	void printIncognito() {
		grid.printIncognito();
	}
	//Calls the grid hit function
	void hit(Vector2 position) {
		grid.hit(position);
	}
	//Returns true if this Player's ships are all destroyed, and false if they are not
	bool isDefeated() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				if (grid.getSpace(i, j) == '#')
					return false;
			}
		}
		return true;
	}
	//Called at beginning of every game, manages default values, and sets the ships
	void setup() {
		reset();
		setShips();
	}
};

int main() {
	int losses = 0;
	int wins = 0;
	srand(time(NULL));
	Player player = Player();
	Player computer = Player(true);
	bool isPlaying = true;
	//GarbageString is responsible for taking in an entire string for input so that cin retrieves just one value instead of many
	string garbageString;
	char playAgainChar;
	while (isPlaying) {
		playAgainChar = '-';
		player.setup();
		computer.setup();
		while (true) {
			string ans;
			cout << "Press 'y' to surrender, and anything else to continue: ";
			cin >> ans;
			if (toupper(ans[0]) == 'Y') {
				losses++;
				break;
			}
			computer.hit(player.takeTurn(computer));
			if (computer.isDefeated()) {
				wins++;
				cout << "Player won!" << endl;
				break;
			}
			player.hit(computer.takeTurn(player));
			if (player.isDefeated()) {
				losses++;
				cout << "Computer won!" << endl;
				break;
			}
		}
		cout << endl << "Stats:" << endl << "  WINS:   " << wins << endl << "  LOSSES: " << losses << endl;
		while (toupper(playAgainChar) != 'Y' && toupper(playAgainChar) != 'N') {
			cout << "\nWould you like to play again? y/n: ";
			cin >> garbageString;
			playAgainChar = garbageString[0];
			if (toupper(playAgainChar) != 'Y' && toupper(playAgainChar) != 'N')
				cout << "Please enter y/n: ";
		}
		if (toupper(playAgainChar) == 'N')
			break;
	}
	return 0;
}