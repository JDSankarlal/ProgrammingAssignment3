#include "Classes.h" 
#include "keyInput.h" 
#include "Events.h" 
#include <iostream>
#include <string>

using namespace std;
Player* player1 = nullptr;
Player* player2 = nullptr;
//Character Select
void selection()
{
	int specialty;
	string name;
	int race;

	
	//Class
	cout << "\nPlease enter player 1's class from the following list"
		<< "\n 1. Fighter\n 2. Wizard\n 3. Rogue\n 4. Ranger";
	cout << endl;

	cin >> specialty; //Get player 1 class
	if (specialty == 1)
	{
		player1 = new Fighter; //creates player1 object
		player1->specialty = "Fighter";
	}
	else if (specialty == 2)
	{
		player1 = new Wizard; //creates player1 object
		player1->specialty = "Wizard";
	}
	else if (specialty == 3)
	{
		player1 = new Rogue; //creates player1 object
		player1->specialty = "Rogue";
	}
	else if (specialty == 4)
	{
		player1 = new Ranger; //creates player1 object
		player1->specialty = "Ranger";
	}
	else
	{
		cout << "Your input is invalid, player 1 will be defaulted to the Fighter class" << endl;
		player1= new Fighter;
		player1->specialty = "Fighter";
	}

	//Race
	cout << "\nPlease enter player 1's race from the following list"
		<< "\n 1. Human\n 2. Dwarf\n 3. Elf\n 4. Half-Orc";
	cout << endl;

	cin >> race; //Get player 1 Race
	if (race == 1)
	{
		player1->race = "Human";
	}
	else if (race == 2)
	{
		player1->race = "Dwarf";
	}
	else if (race == 3)
	{
		player1->race = "Elf";
	}
	else if (race == 4)
	{
		player1->race = "Half-Orc";
	}
	else
	{
		cout << "Your input is invalid, player 1 will be defaulted to Human" << endl;
		player1->race = "Human";
	}
	//Name
	cout << "Please enter player 1's name" << endl;
	cin >> player1->name; //Get player 1 name


	//Class
	cout << "\nPlease enter player 2's class from the following list"
		<< "\n 1. Fighter\n 2. Wizard\n 3. Rogue\n 4. Ranger";
	cout << endl;

	cin >> specialty; //Get player 2 class
	if (specialty == 1)
	{
		player2 = new Fighter; //creates player2 object
		player2->specialty = "Fighter";
	}
	else if (specialty == 2)
	{
		player2 = new Wizard; //creates player2 object
		player2->specialty = "Wizard";
	}
	else if (specialty == 3)
	{
		player2 = new Rogue; //creates player2 object
		player2->specialty = "Rogue";
	}
	else if (specialty == 4)
	{
		player2 = new Ranger; //creates player2 object
		player2->specialty = "Ranger";
	}
	else
	{
		cout << "Your input is invalid, player 2 will be defaulted to the Fighter class" << endl;
		player2 = new Fighter;
		player2->specialty = "Fighter";
	}

	 //Race
	cout << "\nPlease enter player 2's race from the following list"
		<< "\n 1. Human\n 2. Dwarf\n 3. Elf\n 4. Half-Orc";
	cout << endl;

	cin >> race; //Get player 2 Race
	if (race == 1)
	{
		player2->race = "Human";
	}
	else if (race == 2)
	{
		player2->race = "Dwarf";
	}
	else if (race == 3)
	{
		player2->race = "Elf";
	}
	else if (race == 4)
	{
		player2->race = "Half-Orc";
	}
	else
	{
		cout << "Your input is invalid, player 2 will be defaulted to Human" << endl;
		player2->race = "Human";
	}
	//Player 2 Selection
	cout << "Please enter player 2's name" << endl;
	cin >> player2->name; //Get player 2 name
	
	system("pause");

	system("cls");
}

void displayStats()
{
	cout << player1->name << " is a " << player1->specialty << " with " << player1->attack << " attack, " << player1->damage << " damage, " << player1->armor << " armor, and " << player1->health << " health\n" << endl;
	cout << player2->name << " is a " << player2->specialty << " with " << player2->attack << " attack, " << player2->damage << " damage, " << player2->armor << " armor, and " << player2->health << " health\n" << endl;
	system("pause");
}

void drawGrid()
{
	
	//const int SIZE;
	//the grid for now
	cout << player1->name << " VS." << player2->name << "\n" << endl;
	char grid[5][5] = { { '*','*','*','*','*' },//grid. Needs Lines between the stars tho
						{ '*','*','*','*','*' },
						{ '*','*','*','*','*' }, 
						{ '*','*','*','*','*' },
						{ '*','*','*','*','*' } };
	int thing1[2] = { 2,0 };//placeholder for player1->position since that would only take 1 number for some reason

	player1->position[2] = { 1 }; //sets player 1 initial position, should be taking 2 numbers but won't for some reason

	char player = '@'; //Sets the character @ to be the player on the grid
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == thing1[0] && j == thing1[1])
				cout << player;//prints the player over the grid
			else
				cout << grid[i][j];//prints the grid
			cout << " ";
		}
		cout << endl;
	}
	if (turn == 1)
	{
		if (Events::keyDown(Events::Left))
		{

		}
	}
}

//battle function
int rollD20()
{
	int d20 = rand() % 20 + 1;
	return d20;
}

void applyDamageToP1()
{
	player1->health -= player2->damage;
	cout << player1->name << " was hit and took " << player2->damage << " damage" << endl;
}
void applyDamageToP2()
{
	player1->health -= player2->damage;
	cout << player2->name << " was hit and took " << player1->damage << " damage" << endl;
}

bool checkPlayer1Dead()
{
	return (player1->health <= 0);
}
bool checkPlayer2Dead()
{
	return (player2->health <= 0);
}

void endGame()
{
	//Set up the end of the game
	cout << "Thanks for playing!" << endl;
	stillPlaying = false;
}

bool fight() { //fight function

	int modifiedAttack; // attack + diceroll
	while (stillPlaying == true)
	{
		int turn = rand() % 2 + 1; //sets turn randomly
		if (turn == 1) //if turn = 1 then attack
		{
			modifiedAttack = rollD20() + player1->attack;
			if (modifiedAttack >= player2->armor) //if hit apply damage
			{
				cout << player1->name << "attacks and hits!" << endl;
				applyDamageToP2();
				if (checkPlayer2Dead()) //if damage check if dead
				{
					printf("Player 2 has fallen\nPlayer 1 is Victorious!\n");
					endGame();
					break;
				}

			}
			else //else misses
			{
				cout << player1->name << " attacks and Misses horribly" << endl;
			}
			checkPlayer2Dead();

			//repeat for p2
			modifiedAttack = rollD20() + player2->attack;
			if (modifiedAttack >= player1->armor)
			{
				applyDamageToP1();
				cout << player2->name << "attacks and hits!" << endl;
				if (checkPlayer1Dead())
				{
					printf("Player 1 has fallen\nPlayer 2 is Victorious!\n");
					endGame();
					break;
				}
			}
			else
			{
				cout << player2->name << " attacks and Misses horribly" << endl;
			}
		}

		//if the turn = 2 at the start then do it in reverse order
		else
		{
			int modifiedAttack = rollD20() + player2->attack;
			if (modifiedAttack >= player1->armor)
			{
				applyDamageToP1();
				cout << player2->name << "attacks and hits!" << endl;
			}
			else
			{
				cout << player2->name << " attacks and Misses horribly" << endl;
			}
			checkPlayer1Dead();
			if (checkPlayer1Dead())
			{
				printf("Player 1 has fallen\nPlayer 2 is Victorious!\n");
				endGame();
				break;
			}

			modifiedAttack = rollD20() + player1->attack;
			if (modifiedAttack >= player2->armor)
			{
				applyDamageToP2();
				cout << player1->name << "attacks and hits!" << endl;
			}
			else
			{
				cout << player1->name << " attacks and Misses horribly" << endl;
			}
			checkPlayer2Dead();
			if (checkPlayer2Dead())
			{
				printf("Player 2 has fallen\nPlayer 1 is Victorious!\n");
				endGame();
				break;
			}
		}
		return turn; //return turn
	}
}

//Main
void main()
{
	srand(time(NULL));
	selection(); //Call the character Select for player 1
	displayStats(); //Calls display stats function
	fight();//calls fight function
	drawGrid();//Calls the grid
	system("pause"); //Pause
}