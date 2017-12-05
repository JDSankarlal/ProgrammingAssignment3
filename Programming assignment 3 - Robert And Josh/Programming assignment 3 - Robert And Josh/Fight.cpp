#include "Classes.h" 
#include "keyInput.h" 
#include "Events.h" 
#include <iostream>
#include <string>

using namespace std;

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
	player1->hitPoints -= player2->damage;
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

void fight() {

	int modifiedAttack;
	bool stillPlaying = true;
	turn = 1;
	while (stillPlaying == true)
	{
		int turn = rand() % 2 + 1;
		if (turn == 1)
		{
			modifiedAttack = rollD20() + player1->attack;
			if (modifiedAttack >= player2->armor)
			{
				cout << "Player 1 attacks and hits!" << endl;
				applyDamageToP2();
				if (checkPlayer2Dead())
				{
					printf("Player 2 has fallen\nPlayer 1 is Victorious!\n");
					endGame();
					break;
				}

			}
			else
			{
				cout << "Player 1 attacks and Misses horribly" << endl;
			}
			checkPlayer2Dead();

			modifiedAttack = rollD20() + player2->attack;
			if (modifiedAttack >= player1->armor)
			{
				applyDamageToP1();
				cout << "Player 2 attacks and hits!" << endl;
				if (checkPlayer1Dead())
				{
					printf("Player 1 has fallen\nPlayer 2 is Victorious!\n");
					endGame();
					break;
				}
			}
			else
			{
				cout << "Player 2 attacks and Misses horribly" << endl;
			}
		}
		else
		{
			int modifiedAttack = rollD20() + player2->attack;
			if (modifiedAttack >= player1->armor)
			{
				applyDamageToP1();
				cout << "Player 2 attacks and hits!" << endl;
			}
			else
			{
				cout << "Player 2 attacks and Misses horribly" << endl;
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
				cout << "Player 1 attacks and hits!" << endl;
			}
			else
			{
				cout << "Player 1 attacks and Misses horribly" << endl;
			}
			checkPlayer2Dead();
			if (checkPlayer2Dead())
			{
				printf("Player 2 has fallen\nPlayer 1 is Victorious!\n");
				endGame();
				break;
			}
		}
		return turn;
	}
}
