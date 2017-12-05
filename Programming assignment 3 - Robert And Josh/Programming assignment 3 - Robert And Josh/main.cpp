#include "Classes.h"
#include <iostream>
#include <string>

using namespace std;

//Character Select
void selection()
{
	//Name
	cout << "Please enter player 1's name" << endl; 
	cin >> player1->name; //Get player 1 name

	//Race
	cout << "\nPlease enter player 1's race from the following list"
		<< "\n 1. Human\n 2. Dwarf\n 3. Elf\n 4. Half-Orc";
	cout << endl;
	cin >> player1->race; //Get player 1 Race

	//Class
	cout << "\nPlease enter player 1's class from the following list"
		<< "\n 1. Fighter\n 2. Wizard\n 3. Rogue\n 4. Ranger";
	cout << endl;
	cin >> player1->specialty; //Get player 1 class
	system("cls");
}

void drawGrid()
{
	//const int SIZE;
	//the grid for now
	char grid[5][5] = { { '*','*','*','*','*' },//grid. Needs Lines between the stars tho
						{ '*','*','*','*','*' },
						{ '*','*','*','*','*' }, 
						{ '*','*','*','*','*' },
						{ '*','*','*','*','*' } };
	int thing[2] = { 2,0 };//placeholder for player1->position since that would only take 1 number for some reason

	player1->position[2] = { 1 }; //sets player 1 initial position, should be taking 2 numbers but won't for some reason

	char player = '@'; //Sets the character @ to be the player on the grid
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == thing[0] && j == thing[1])
				cout << player;//prints the player over the grid
			else
				cout << grid[i][j];//prints the grid
			cout << " ";
		}
		cout << endl;
	}

}
//Main
void main()
{
	selection(); //Call the character Select for player 1

	drawGrid();//Calls the grid
	system("pause"); //Pause
}